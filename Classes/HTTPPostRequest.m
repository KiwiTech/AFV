//
//  HTTPPostRequest.m
//  AFV
//
//  Created by Kaveh G. on 2/17/11.
//  Copyright 2011 Teleca. All rights reserved.
//


#import "HTTPPostRequest.h"
#include <sys/socket.h>
#include <unistd.h>
#include <CFNetwork/CFNetwork.h>

#pragma mark -
#pragma mark Utilities

static void CFStreamCreateBoundPairCompat(
    CFAllocatorRef      alloc, 
    CFReadStreamRef *   readStreamPtr, 
    CFWriteStreamRef *  writeStreamPtr, 
    CFIndex             transferBufferSize
)
{
    #pragma unused(transferBufferSize)
    int                 err;
    Boolean             success;
    CFReadStreamRef     readStream;
    CFWriteStreamRef    writeStream;
    int                 fds[2];
    
    assert(readStreamPtr != NULL);
    assert(writeStreamPtr != NULL);
    
    readStream = NULL;
    writeStream = NULL;
    
    // Create the UNIX domain socket pair.
    
    err = socketpair(AF_UNIX, SOCK_STREAM, 0, fds);
    if (err == 0) {
        CFStreamCreatePairWithSocket(alloc, fds[0], &readStream,  NULL);
        CFStreamCreatePairWithSocket(alloc, fds[1], NULL, &writeStream);
        
        // If we failed to create one of the streams, ignore them both.
        
        if ( (readStream == NULL) || (writeStream == NULL) ) {
            if (readStream != NULL) {
                CFRelease(readStream);
                readStream = NULL;
            }
            if (writeStream != NULL) {
                CFRelease(writeStream);
                writeStream = NULL;
            }
        }
        assert( (readStream == NULL) == (writeStream == NULL) );
        
        // Make sure that the sockets get closed (by us in the case of an error, 
        // or by the stream if we managed to create them successfull).
        
        if (readStream == NULL) {
            err = close(fds[0]);
            assert(err == 0);
            err = close(fds[1]);
            assert(err == 0);
        } else {
            success = CFReadStreamSetProperty(readStream, kCFStreamPropertyShouldCloseNativeSocket, kCFBooleanTrue);
            assert(success);
            success = CFWriteStreamSetProperty(writeStream, kCFStreamPropertyShouldCloseNativeSocket, kCFBooleanTrue);
            assert(success);
        }
    }
    
    *readStreamPtr = readStream;
    *writeStreamPtr = writeStream;
}


// A category on NSStream that provides a nice, Objective-C friendly way to create 
// bound pairs of streams.
@interface NSStream (BoundPairAdditions)

+ (void)createBoundInputStream:(NSInputStream **)inputStreamPtr outputStream:(NSOutputStream **)outputStreamPtr bufferSize:(NSUInteger)bufferSize;

@end

@implementation NSStream (BoundPairAdditions)

+ (void)createBoundInputStream:(NSInputStream **)inputStreamPtr outputStream:(NSOutputStream **)outputStreamPtr bufferSize:(NSUInteger)bufferSize
{
    CFReadStreamRef     readStream;
    CFWriteStreamRef    writeStream;

    assert( (inputStreamPtr != NULL) || (outputStreamPtr != NULL) );

    readStream = NULL;
    writeStream = NULL;

    if (YES) {
        CFStreamCreateBoundPairCompat(
            NULL, 
            ((inputStreamPtr  != nil) ? &readStream : NULL),
            ((outputStreamPtr != nil) ? &writeStream : NULL), 
            (CFIndex) bufferSize
        );
    } else {
        CFStreamCreateBoundPair(
            NULL, 
            ((inputStreamPtr  != nil) ? &readStream : NULL),
            ((outputStreamPtr != nil) ? &writeStream : NULL), 
            (CFIndex) bufferSize
        );
    }
    
    if (inputStreamPtr != NULL) {
        *inputStreamPtr  = [NSMakeCollectable(readStream) autorelease];
    }
    if (outputStreamPtr != NULL) {
        *outputStreamPtr = [NSMakeCollectable(writeStream) autorelease];
    }
}

@end
        
#pragma mark -
#pragma mark PostController

enum {
    kPostBufferSize = 32768
};


@interface HTTPPostRequest ()

// Private properties
@property (nonatomic, readonly) BOOL              isSending;
@property (nonatomic, retain)   NSURLConnection * connection;
@property (nonatomic, copy)     NSData *          bodyPrefixData;
@property (nonatomic, retain)   NSInputStream *   fileStream;
@property (nonatomic, copy)     NSData *          bodySuffixData;
@property (nonatomic, retain)   NSOutputStream *  producerStream;
@property (nonatomic, retain)   NSInputStream *   consumerStream;
@property (nonatomic, assign)   const uint8_t *   buffer;
@property (nonatomic, assign)   uint8_t *         bufferOnHeap;
@property (nonatomic, assign)   size_t            bufferOffset;
@property (nonatomic, assign)   size_t            bufferLimit;

	
@end


@implementation HTTPPostRequest

+ (void)releaseObj:(id)obj
{
    [obj release];
}


#pragma mark -
#pragma mark Core transfer code

@synthesize connection      = _connection;
@synthesize bodyPrefixData  = _bodyPrefixData;
@synthesize fileStream      = _fileStream;
@synthesize bodySuffixData  = _bodySuffixData;
@synthesize producerStream  = _producerStream;
@synthesize consumerStream  = _consumerStream;
@synthesize buffer          = _buffer;
@synthesize bufferOnHeap    = _bufferOnHeap;
@synthesize bufferOffset    = _bufferOffset;
@synthesize bufferLimit     = _bufferLimit;
@synthesize responseData	= _data;
@synthesize delegate		= _delegate;


- (BOOL)isSending
{
    return (self.connection != nil);
}

#pragma mark -
#pragma mark Helper methods

- (NSString *)_generateBoundaryString
{
    CFUUIDRef       uuid;
    CFStringRef     uuidStr;
    NSString *      result;
    
    uuid = CFUUIDCreate(NULL);
    assert(uuid != NULL);
    
    uuidStr = CFUUIDCreateString(NULL, uuid);
    assert(uuidStr != NULL);
    
    result = [NSString stringWithFormat:@"Boundary-%@", uuidStr];
    
    CFRelease(uuidStr);
    CFRelease(uuid);
    
    return result;
}


- (void)startSend:(NSString *)filePath withParameters:(NSDictionary*)parameters
{
	
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
	if ([[UIDevice currentDevice] respondsToSelector:@selector(isMultitaskingSupported)]) {
		backgroundTask = [[UIApplication sharedApplication] beginBackgroundTaskWithExpirationHandler:^{
			if (backgroundTask != UIBackgroundTaskInvalid)
			{
				[[UIApplication sharedApplication] endBackgroundTask:backgroundTask];
				backgroundTask = UIBackgroundTaskInvalid;
				[self.connection cancel];
			}
		}];
	}
#endif
	
	
    NSMutableURLRequest *   request;
    NSString *              boundaryStr;
    NSString *              contentType;
    NSString *              bodyPrefixStr;
    NSNumber *              fileLengthNum;
    unsigned long long      bodyLength;
    
    assert(filePath != nil);
    assert([[NSFileManager defaultManager] fileExistsAtPath:filePath]);
    assert( [filePath.pathExtension caseInsensitiveCompare:@"mov"] == NSOrderedSame || [filePath.pathExtension caseInsensitiveCompare:@"mp4"] == NSOrderedSame );
   
	// Determine the MIME type of the file.
	if ( [filePath.pathExtension caseInsensitiveCompare:@"mov"] == NSOrderedSame) {
		contentType = @"video/quicktime";
	} else if ( [filePath.pathExtension caseInsensitiveCompare:@"mp4"] == NSOrderedSame) {
		contentType = @"video/mp4";
	} else {
		assert(NO);
		contentType = nil;
	}
	
	
	boundaryStr = [self _generateBoundaryString];
	assert(boundaryStr != nil);
	
	bodyPrefixStr = [NSString stringWithFormat:
					 @
					 // empty preamble
					 "\r\n"
					 "--%@\r\n"
					 "Content-Disposition: form-data; name=\"media\"; filename=\"%@\"\r\n"
					 "Content-Type: %@\r\n"
					 "\r\n",
					 boundaryStr,
					 [filePath lastPathComponent],
					 contentType
					 ];
	

	// Build the parameter list
	NSMutableData* tempBodySuffixData = [NSMutableData data];
	for(NSString* parameter in [parameters allKeys])
	{
		[tempBodySuffixData appendData:[[NSString stringWithFormat:
										 @
										 "\r\n"
										 "--%@\r\n"
										 "Content-Disposition: form-data; name=\"%@\"\r\n"
										 "\r\n"
										 "%@\r\n"
										 "--%@--\r\n" 
										 ,
										 boundaryStr,
										 parameter,
										 [parameters valueForKey:parameter],
										 boundaryStr] dataUsingEncoding:NSASCIIStringEncoding]];
		
	}
	[tempBodySuffixData appendData:[[NSString stringWithString:
									 @
									 "\r\n"
									 //empty epilogue
									 ] dataUsingEncoding:NSASCIIStringEncoding]];
	
	
	
	self.bodyPrefixData = [bodyPrefixStr dataUsingEncoding:NSASCIIStringEncoding];
	self.bodySuffixData = tempBodySuffixData;
	
	fileLengthNum = (NSNumber *) [[[NSFileManager defaultManager] attributesOfItemAtPath:filePath error:NULL] objectForKey:NSFileSize];
	
	bodyLength =
	(unsigned long long) [self.bodyPrefixData length]
	+ [fileLengthNum unsignedLongLongValue]
	+ (unsigned long long) [self.bodySuffixData length];
	
	// Open a stream for the file we're going to send.  We open this stream 
	// straight away because there's no need to delay.
	
	self.fileStream = [NSInputStream inputStreamWithFileAtPath:filePath];
	assert(self.fileStream != nil);
	[self.fileStream open];
	
	// Open producer/consumer streams.  We open the producerStream straight 
	// away.  We leave the consumerStream alone; NSURLConnection will deal 
	// with it.
	
	[NSStream createBoundInputStream:&self->_consumerStream outputStream:&self->_producerStream bufferSize:32768];
	[self->_consumerStream retain];
	[self->_producerStream retain];
	assert(self.consumerStream != nil);
	assert(self.producerStream != nil);
	
	self.producerStream.delegate = self;
	[self.producerStream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
	[self.producerStream open];
	
	// Set up our state to send the body prefix first.
	
	self.buffer      = [self.bodyPrefixData bytes];
	self.bufferLimit = [self.bodyPrefixData length];
	
	// Open a connection for the URL, configured to POST the file.
	
	request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://abc.go.com/service/ugv/upload?noredirect&format=xml"]];
	assert(request != nil);
	
	[request setHTTPMethod:@"POST"];
	[request setHTTPBodyStream:self.consumerStream];
	
	[request setValue:[NSString stringWithFormat:@"multipart/form-data; boundary=\"%@\"", boundaryStr] forHTTPHeaderField:@"Content-Type"];
	[request setValue:[NSString stringWithFormat:@"%llu", bodyLength] forHTTPHeaderField:@"Content-Length"];
	
	self.connection = [NSURLConnection connectionWithRequest:request delegate:self];
	assert(self.connection != nil);
	
	[_delegate HTTPPostRequestSendDidStart];

}

- (void)stopSendWithStatus:(HTTPPostRequestStatus)status
{
    if (self.bufferOnHeap) {
        free(self.bufferOnHeap);
        self.bufferOnHeap = NULL;
    }
    self.buffer = NULL;
    self.bufferOffset = 0;
    self.bufferLimit  = 0;
    if (self.connection != nil) {
        [self.connection cancel];
        self.connection = nil;
    }
    self.bodyPrefixData = nil;
    if (self.producerStream != nil) {
        self.producerStream.delegate = nil;
        [self.producerStream removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        [self.producerStream close];
        self.producerStream = nil;
    }
    self.consumerStream = nil;
    if (self.fileStream != nil) {
        [self.fileStream close];
        self.fileStream = nil;
    }
    self.bodySuffixData = nil;

    [_delegate HTTPPostRequestSendDidStopWithStatus:status];
	
	
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
	if (backgroundTask != UIBackgroundTaskInvalid && [[UIDevice currentDevice] respondsToSelector:@selector(isMultitaskingSupported)]) {
		
		[[UIApplication sharedApplication] endBackgroundTask:backgroundTask];
		backgroundTask = UIBackgroundTaskInvalid;
	}
#endif
	
	
		
}

- (void)stream:(NSStream *)aStream handleEvent:(NSStreamEvent)eventCode
    // An NSStream delegate callback that's called when events happen on our 
    // network stream.
{
    assert(aStream == self.producerStream);

    switch (eventCode) {
        case NSStreamEventOpenCompleted: {

        } break;
        case NSStreamEventHasBytesAvailable: {
            assert(NO);     // should never happen for the output stream
        } break;
        case NSStreamEventHasSpaceAvailable: {
            // Check to see if we've run off the end of our buffer.  If we have, 
            // work out the next buffer of data to send.
            
            if (self.bufferOffset == self.bufferLimit) {

                // See if we're transitioning from the prefix to the file data.
                // If so, allocate a file buffer.
                
                if (self.bodyPrefixData != nil) {
                    self.bodyPrefixData = nil;

                    assert(self.bufferOnHeap == NULL);
                    self.bufferOnHeap = malloc(kPostBufferSize);
                    assert(self.bufferOnHeap != NULL);
                    self.buffer = self.bufferOnHeap;
                    
                    self.bufferOffset = 0;
                    self.bufferLimit  = 0;
                }
                
                // If we still have file data to send, read the next chunk. 
                
                if (self.fileStream != nil) {
                    NSInteger   bytesRead;
                    
                    bytesRead = [self.fileStream read:self.bufferOnHeap maxLength:kPostBufferSize];
                    
                    if (bytesRead == -1) {
                        [self stopSendWithStatus:HTTPPostRequestStatus_File_Read_Error];
                    } else if (bytesRead != 0) {
                        self.bufferOffset = 0;
                        self.bufferLimit  = bytesRead;
                    } else {
                        // If we hit the end of the file, transition to sending the 
                        // suffix.

                        [self.fileStream close];
                        self.fileStream = nil;
                        
                        assert(self.bufferOnHeap != NULL);
                        free(self.bufferOnHeap);
                        self.bufferOnHeap = NULL;
                        self.buffer       = [self.bodySuffixData bytes];

                        self.bufferOffset = 0;
                        self.bufferLimit  = [self.bodySuffixData length];
                    }
                }
                
                // If we've failed to produce any more data, we close the stream 
                // to indicate to NSURLConnection that we're all done.  We only do 
                // this if producerStream is still valid to avoid running it in the 
                // file read error case.
                
                if ( (self.bufferOffset == self.bufferLimit) && (self.producerStream != nil) ) {

                    self.producerStream.delegate = nil;
                    [self.producerStream close];
                }
            }
            
            // Send the next chunk of data in our buffer.
            
            if (self.bufferOffset != self.bufferLimit) {
                NSInteger   bytesWritten;
                bytesWritten = [self.producerStream write:&self.buffer[self.bufferOffset] maxLength:self.bufferLimit - self.bufferOffset];
                if (bytesWritten <= 0) {
                    [self stopSendWithStatus:HTTPPostRequestStatus_Network_Write_Error];
                } else {
                    self.bufferOffset += bytesWritten;
                }
            }
        } break;
        case NSStreamEventErrorOccurred: {
            [self stopSendWithStatus:HTTPPostRequestStatus_Stream_Open_Error];
        } break;
        case NSStreamEventEndEncountered: {
            assert(NO);
        } break;
        default: {
            assert(NO);
        } break;
    }
}

- (void)connection:(NSURLConnection *)theConnection didReceiveResponse:(NSURLResponse *)response
{
    NSHTTPURLResponse * httpResponse;
    
    httpResponse = (NSHTTPURLResponse *) response;
    assert( [httpResponse isKindOfClass:[NSHTTPURLResponse class]] );
    
    if ((httpResponse.statusCode / 100) != 2) {
        [self stopSendWithStatus:HTTPPostRequestStatus_HTTP_Response_Error];
    } 
}

- (void)connection:(NSURLConnection *)theConnection didReceiveData:(NSData *)incrementalData
{
    assert(theConnection == self.connection);

	if (!_data) {
		self.responseData = [[NSMutableData alloc] initWithCapacity:1024];
	}
	[_data appendData:incrementalData];
}

- (void)connection:(NSURLConnection *)connection didSendBodyData:(NSInteger)bytesWritten totalBytesWritten:(NSInteger)totalBytesWritten totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite
{
	[_delegate HTTPPostRequestProgressChanged:(CGFloat)totalBytesWritten / (CGFloat)totalBytesExpectedToWrite];
}

- (void)connection:(NSURLConnection *)theConnection didFailWithError:(NSError *)error
{
    [self stopSendWithStatus:HTTPPostRequestStatus_Connection_Failed];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)theConnection
{
    [self stopSendWithStatus:HTTPPostRequestStatus_Connection_Succeeded];
}


- (void)dealloc
{
	if([self isSending])
		[self stopSendWithStatus:HTTPPostRequestStatus_Connection_Stoped];
	
	[_data release];
	
    [super dealloc];
}

@end
