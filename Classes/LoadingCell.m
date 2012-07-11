//
//  LoadingCell.m
//  AFV
//
//  Created by Kaveh G. on 2/7/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "LoadingCell.h"

#define label_offset_while_loading	132

@implementation LoadingCell

@synthesize activityIndicator;
@synthesize loadingLabel;

- (void)resizeContent
{
	if (activityIndicator.isAnimating) {
		
		[loadingLabel sizeToFit];
		CGRect frame = loadingLabel.frame;
		frame.origin.x = label_offset_while_loading;
		loadingLabel.frame = frame;		
	}
	else {
		
		[loadingLabel sizeToFit];
		loadingLabel.center = self.contentView.center;
	}
	
}


- (void)dealloc {
	
	[activityIndicator release];
	[loadingLabel release];
	
    [super dealloc];
}


@end
