//
//  CustomTabBar.m
//  AFV
//
//  Created by Kaveh G. on 8/6/10.
//  Copyright 2010 Teleca. All rights reserved.
//

#import "CustomTabBar.h"


@implementation CustomTabBar

- (void) drawRect:(CGRect)rect {
	
	NSString* imageName=@"";
	
	switch ([self selectedItem].tag) {
		case 1:
			imageName = @"tab_bar_1.png";
			break;
		case 2:
			imageName = @"tab_bar_2.png";
			break;
		case 3:
			imageName = @"tab_bar_3.png";
			break;
		case 4:
			imageName = @"tab_bar_4.png";
			break;
			
		default:
			break;
	}
	
	// draw tab bar image
    UIImage *img  = [UIImage imageNamed:imageName];
    [img drawInRect:CGRectMake(0, 0, img.size.width, img.size.height)];
}

- (void)dealloc {
    [super dealloc];
}


@end
