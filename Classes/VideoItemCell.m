//
//  VideoItemCell.m
//  AFV
//
//  Created by Kaveh G. on 2/8/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "VideoItemCell.h"


@implementation VideoItemCell

@synthesize titleLabel;
@synthesize descriptionLabel;
@synthesize cachedImageView;
@synthesize playImageView;
@synthesize delegate = _delegate;

#pragma mark -
#pragma mark CachedImageViewDelegate methods

- (void)imageDownloadWillBegin
{
	playImageView.hidden = YES;
	
}
- (void)imageDownloadDidFinish
{
	playImageView.hidden = NO;
}

#pragma mark -
#pragma mark UI actions

- (IBAction)accessoryButtonAction:(id)sender withEvent:(UIEvent *)event
{
	[self.delegate accessoryButtonActionWithEvent:event];
	
}

#pragma mark -
#pragma mark cleanup

- (void)dealloc {
	
	
	[titleLabel release];
	[descriptionLabel release];
	[cachedImageView release];
	[playImageView release];
	
    [super dealloc];
}


@end
