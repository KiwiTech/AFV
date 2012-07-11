//
//  CachedImageView.h
//  AFV
//
//  Created by Kaveh G. on 2/6/11.
//  Copyright 2010 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>

#define default_image_width		MAXFLOAT
#define default_image_height	MAXFLOAT
#define default_image_size		CGSizeMake(MAXFLOAT, MAXFLOAT)

@protocol CachedImageViewDelegate;

@interface CachedImageView : UIImageView {
	
	NSURL *imageUrl;
	NSString *imagePath;
	BOOL fadeInOnUpdate;
	id<CachedImageViewDelegate> _delegate;
	
	@private
	BOOL isCached;
	UIActivityIndicatorView *loadingIndicator;
	UIActivityIndicatorViewStyle loadingIndicatorStyle;
	NSURLConnection* connection;
    NSMutableData* data;
	CGSize maxImageSize;
}

@property (nonatomic, retain) NSURL *imageUrl;
@property (nonatomic, retain) NSString *imagePath;
@property (nonatomic, readonly) BOOL isCached;
@property (nonatomic, readonly) UIActivityIndicatorView *loadingIndicator;
@property (assign) BOOL fadeInOnUpdate;
@property (assign) id<CachedImageViewDelegate> delegate;


+ (void)initializeImageCaching:(BOOL)clearCache;
+ (NSString *)generatePathForImageUrl:(NSURL *)url;
- (id)initWithActivityInidcatorStyle:(UIActivityIndicatorViewStyle)style;
- (id)initWithFrame:(CGRect)frame activityInidcatorStyle:(UIActivityIndicatorViewStyle)style;
- (void)reset;
- (void)loadImageNamed:(NSString *)name;
- (void)loadCachedImageWithImageUrl:(NSString *)url usingMaxImageSize:(CGSize)size;

@end


@protocol CachedImageViewDelegate

- (void)imageDownloadWillBegin;
- (void)imageDownloadDidFinish;

@end
