//
//  HTTPPostRequest.h
//  AFV
//
//  Created by Kaveh G. on 2/17/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef enum {
	HTTPPostRequestStatus_Connection_Failed = 0,
	HTTPPostRequestStatus_Connection_Succeeded,
	HTTPPostRequestStatus_Connection_Stoped,
	HTTPPostRequestStatus_Connection_Canceled,
	HTTPPostRequestStatus_File_Read_Error,
	HTTPPostRequestStatus_Network_Write_Error,
	HTTPPostRequestStatus_Stream_Open_Error,
	HTTPPostRequestStatus_HTTP_Response_Error
} HTTPPostRequestStatus;


@protocol HTTPPostRequestDelegate;

@interface HTTPPostRequest : NSObject <NSStreamDelegate>
{
    
    NSURLConnection *           _connection;
    NSData *                    _bodyPrefixData;
    NSInputStream *             _fileStream;
    NSData *                    _bodySuffixData;
    NSOutputStream *            _producerStream;
    NSInputStream *             _consumerStream;
    const uint8_t *             _buffer;
    uint8_t *                   _bufferOnHeap;
    size_t                      _bufferOffset;
    size_t                      _bufferLimit;
	NSMutableData*				_data;
	
	id<HTTPPostRequestDelegate> _delegate;
	
#if TARGET_OS_IPHONE && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_4_0
	UIBackgroundTaskIdentifier backgroundTask;
#endif
	
}

@property (nonatomic, retain)   NSMutableData* responseData;
@property(nonatomic,assign) id<HTTPPostRequestDelegate> delegate;

- (void)startSend:(NSString *)filePath withParameters:(NSDictionary*)parameters;
- (void)stopSendWithStatus:(HTTPPostRequestStatus)status;
- (BOOL)isSending;


@end


@protocol HTTPPostRequestDelegate

- (void)HTTPPostRequestSendDidStart;
- (void)HTTPPostRequestProgressChanged:(CGFloat)progress;
- (void)HTTPPostRequestSendDidStopWithStatus:(HTTPPostRequestStatus)status;

@end
