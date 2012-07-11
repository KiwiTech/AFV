//
//  CachedImageView.m
//  AFV
//
//  Created by Kaveh G. on 2/6/11.
//  Copyright 2010 Teleca. All rights reserved.
//

#import "CachedImageView.h"
#import "NSString+Hash.h"
#import <QuartzCore/CALayer.h>


@interface  CachedImageView()

@property (nonatomic, retain) NSURLConnection* connection;
@property (nonatomic, retain) NSMutableData* data;

@end


@interface  CachedImageView(private)

- (void)defaultInit;
- (void)loadCachedImage;
- (void)loadImageFromURL:(NSURL*)url;
- (void)loadImageFromPath:(NSString *)path;
- (UIImage*)getResizedImage:(UIImage*)downloadedImage;

@end

@implementation CachedImageView(private)

- (void)defaultInit {
	
	// Initialization code
	self.contentMode = UIViewContentModeScaleAspectFit;
	isCached = NO;
	
	// Create the loading indicator
	loadingIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:loadingIndicatorStyle];
	loadingIndicator.hidesWhenStopped = YES;
	loadingIndicator.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin;
	CGRect frame = loadingIndicator.frame;
	frame.origin.x = (self.frame.size.width - frame.size.width) / 2.0;
	frame.origin.y = (self.frame.size.height - frame.size.height)/ 2.0;
	loadingIndicator.frame = frame;
	
	[self addSubview:loadingIndicator];
}


- (UIImage*)getResizedImage:(UIImage*)downloadedImage
{

	UIImage* retImage = downloadedImage;
	
	// resze the image if needed
	if (downloadedImage.size.width > maxImageSize.width || downloadedImage.size.height > maxImageSize.height)
	{
        CGSize itemSize = CGSizeMake(maxImageSize.width, maxImageSize.height);
		UIGraphicsBeginImageContext(itemSize);
		CGRect imageRect = CGRectMake(0.0, 0.0, itemSize.width, itemSize.height);
		[downloadedImage drawInRect:imageRect];
		retImage = UIGraphicsGetImageFromCurrentImageContext();
		UIGraphicsEndImageContext();
    }
	
	return retImage;
}

#pragma mark -
#pragma mark Private image loading

- (void)loadCachedImage {
	
	// retain the delegate
	[(id)self.delegate retain];
	
	// Notify the Delegate
	[self.delegate imageDownloadWillBegin];
	
	// Validate image path
	if (self.imageUrl == nil) {
#ifdef DEBUG
		NSLog(@"Error: Cannot access image at: %@", self.imageUrl);
#endif
		return;
	}
	
	// First check our cache to see if the object exists
	BOOL isDir = NO;
	NSFileManager *fileManager = [[NSFileManager alloc] init];
	if ([fileManager fileExistsAtPath:self.imagePath isDirectory:&isDir] == NO) {
		// If the image doesn't exist we need to create it
#ifdef DEBUG
		NSLog(@"Creating cache image: %@", self.imagePath);
#endif
		[self loadImageFromURL:self.imageUrl];
	}
	else {
#ifdef DEBUG
		NSLog(@"Image found in cache: %@", self.imagePath);
#endif
		isCached = YES;
		[self loadImageFromPath:self.imagePath];
	}
	[fileManager release];	
}

- (void)loadImageFromURL:(NSURL*)url {	
	// Load the image from the URL async
	if (!url)
		return;
	
	[loadingIndicator startAnimating];
	
	// Clear the previous connection and data
	[connection cancel];
	self.connection = nil;
	self.data = nil;
	
	// Create the new request
	NSURLRequest* request = [NSURLRequest requestWithURL:url
											 cachePolicy:NSURLRequestReturnCacheDataElseLoad
										 timeoutInterval:60.0];
	
	connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:NO];
	[connection scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
	[connection start];
	
}

- (void)loadImageFromPath:(NSString *)path
{
	[loadingIndicator stopAnimating];
	
	// Remove all previous animation
	if(fadeInOnUpdate)
		[self.layer removeAllAnimations];
	
	UIImage *img = [self getResizedImage:[UIImage imageWithContentsOfFile:path]];
	
	[self performSelectorOnMainThread:@selector(setImage:) withObject:img waitUntilDone:NO];
	
	// Notify the Delegate
	[self.delegate imageDownloadDidFinish];
	
	// Relesae the delegate
	[(id)self.delegate release];
}

@end


@implementation CachedImageView

@synthesize imageUrl;
@synthesize imagePath;
@synthesize isCached;
@synthesize loadingIndicator;
@synthesize connection;
@synthesize data;
@synthesize fadeInOnUpdate;
@synthesize delegate = _delegate;


#pragma mark -
#pragma mark Init

+ (void)initializeImageCaching:(BOOL)clearCache
{
	
	// Create the images directory if it doesn't exist
	NSError* error = nil;
	NSFileManager *fileManager = [[NSFileManager alloc] init];
	
	// Get the document directory path
	NSString *docDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
	docDir = [docDir stringByAppendingPathComponent:@"images"];
	
	BOOL isDir = YES;
	if ([fileManager fileExistsAtPath:docDir isDirectory:&isDir] == NO) {		
		//Create the directory
		DLog(@"Creating cache image directory: %@", docDir);

		if ([fileManager createDirectoryAtPath:docDir withIntermediateDirectories:YES attributes:nil error:&error] == NO){
			DLog(@"Unable to create cache directory: %@",[error localizedDescription]);
		}
	}
	else {
		
		if(clearCache)
		{
			// Delete all files in the cache directory
			NSDirectoryEnumerator *dirEnum = [fileManager enumeratorAtPath:docDir];
			
			id filePath;
			while ((filePath = [dirEnum nextObject])) {
				if ([fileManager removeItemAtPath:[docDir stringByAppendingPathComponent:(NSString *)filePath] 
											error:&error] == NO) {
					DLog(@"Unable to delete file: %@",[error localizedDescription]);
				}
			}
		}
	}
	
	[fileManager release];
	
	
}

- (id)initWithFrame:(CGRect)frame {
    if ((self = [super initWithFrame:frame])) {
		
		loadingIndicatorStyle = UIActivityIndicatorViewStyleWhite;

        // Initialization code
		[self defaultInit];
    }
    return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder {
    if ((self = [super initWithCoder:aDecoder])) {
		
		loadingIndicatorStyle = UIActivityIndicatorViewStyleWhite;
		
        // Initialization code
		[self defaultInit];
    }
    return self;
}

- (id)initWithActivityInidcatorStyle:(UIActivityIndicatorViewStyle)style
{
	if ((self = [self init])) {
		
		loadingIndicatorStyle = style;
		
		// Initialization code
		[self defaultInit];

	}
	return self;	
}

- (id)initWithFrame:(CGRect)frame activityInidcatorStyle:(UIActivityIndicatorViewStyle)style
{
	if ((self = [self initWithFrame:frame])) {
		
		loadingIndicatorStyle = style;
		
		// Initialization code
		[self defaultInit];

	}
	return self;	
}




- (void)dealloc {
	
	[imageUrl release];
	[imagePath release];
	[loadingIndicator release];
	
	[connection cancel];
    [connection release];
    [data release];	
	
    [super dealloc];
}

#pragma mark -
#pragma mark Public image loading

- (void)reset {
	// Clear the previous connection
	[connection cancel];
	self.connection = nil;
	self.data = nil;
	
	// Clear the properties
	self.imageUrl = nil;
	self.imagePath = nil;
	isCached = NO;
	self.image = nil;
	
}


- (void)loadCachedImageWithImageUrl:(NSString *)url usingMaxImageSize:(CGSize)size
{
	maxImageSize = size;

	self.imageUrl = [NSURL URLWithString:url];
	self.imagePath = [CachedImageView generatePathForImageUrl:self.imageUrl];
	[self loadCachedImage];		
}

- (void)loadImageNamed:(NSString *)name
{
	[loadingIndicator stopAnimating];
	
	if(fadeInOnUpdate)
	{
		// Remove all previous animation
		[self.layer removeAllAnimations];
		// Set the image
		self.alpha = 0.0;
	}

	self.image = [UIImage imageNamed:name];
	
	if(fadeInOnUpdate)
	{
		[UIView beginAnimations:nil context:nil];
		[UIView setAnimationDuration:0.5];
		self.alpha = 1.0;
		[UIView commitAnimations];	
	}
}



+ (NSString *)generatePathForImageUrl:(NSURL *)url
{
	// Get the document directory path
	NSString *docDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
	docDir = [docDir stringByAppendingPathComponent:@"images"];
	// Create the hash of the filename
	NSString *path = [[[url absoluteString] md5Hash] stringByAppendingPathExtension:@"jpg"];
	// Combine the directory path and filename
	path = [docDir stringByAppendingPathComponent:path];
	return path;	
}



#pragma mark -
#pragma mark NSURLConnectionDelegate

- (void)connection:(NSURLConnection *)theConnection	didReceiveData:(NSData *)incrementalData
{
	if (theConnection != connection)
		return;
	
	if (!data) {
		data = [[NSMutableData alloc] initWithCapacity:1024];
	}
	[data appendData:incrementalData];
}

- (void)connection:(NSURLConnection *)theConnection didFailWithError:(NSError *)error
{
	if (theConnection != connection)
		return;
	
	// Log the error
	NSLog(@"Unable to create cache image: %@",[error localizedDescription]);
	
	[loadingIndicator stopAnimating];
	
	if(fadeInOnUpdate)
	{
		// Remove all previous animation
		[self.layer removeAllAnimations];
		self.alpha = 0.0;
	}
	
	// Set the image
	self.image = [UIImage imageNamed:@"img-image-unavailable.png"];
	
	if(fadeInOnUpdate)
	{
		// Fade in the new image
		[UIView beginAnimations:nil context:nil];
		[UIView setAnimationDuration:0.5];
		self.alpha = 1.0;
		[UIView commitAnimations];
	}
	
	
	// Release the connection
	[connection cancel];
	self.connection = nil;
	
	// Release the data
	self.data = nil;
	
}

- (void)connectionDidFinishLoading:(NSURLConnection*)theConnection
{
	if (theConnection != connection)
		return;
	
	// Use the downloaded data to load the image
	UIImage *downloadedImage = [UIImage imageWithData:data];
	UIImage *img = [self getResizedImage:downloadedImage];
		
	[loadingIndicator stopAnimating];
	
	if(fadeInOnUpdate)
	{
		// Remove all previous animation
		[self.layer removeAllAnimations];
		// Set the image
		self.alpha = 0.0;
	}

	
	// Set the image
	isCached = YES;
	[self performSelectorOnMainThread:@selector(setImage:) withObject:img waitUntilDone:YES];
	
	
	if(fadeInOnUpdate)
	{
		// Fade in the new image
		[UIView beginAnimations:nil context:nil];
		[UIView setAnimationDuration:0.5];
		self.alpha = 1.0;
		[UIView commitAnimations];
	}
	
	// Notify the Delegate
	[self.delegate imageDownloadDidFinish];

	// Relesae the delegate
	[(id)self.delegate release];

	// cache the image asynchronously
	NSDictionary* threadData = [NSDictionary dictionaryWithObjects:[NSArray arrayWithObjects:self.imagePath, data, nil] 
														   forKeys:[NSArray arrayWithObjects:@"imagePath", @"imageData", nil]];
	[NSThread detachNewThreadSelector:@selector(writeToFileAsync:) toTarget:self withObject:threadData];

	
	// Release the connection
	[connection cancel];
	self.connection = nil;
}

#pragma mark -
#pragma mark NSURLConnectionDelegate

-(void)writeToFileAsync:(NSDictionary*)threadData
{
	[NSThread setThreadPriority:0.0];
	
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	NSData *imageData = [threadData objectForKey:@"imageData"];
	NSString* path = [threadData objectForKey:@"imagePath"];


	@synchronized([UIApplication sharedApplication])
	{
		if (![imageData writeToFile:path atomically:YES])
		{
#ifdef DEBUG			
			NSLog(@"Unable to create cache image: %@",path);
#endif
		}


	}
	
	[pool release];
	
	
}

@end
