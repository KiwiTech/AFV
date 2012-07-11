//
//  VideoItem.m
//  AFV
//
//  Created by Kaveh G. on 2/3/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "VideoItem.h"


@implementation VideoItem

@synthesize title;
@synthesize videoUrl;
@synthesize description;
@synthesize thumbnailUrl;
@synthesize ABCSiteURL;
@synthesize favoriteTimeStamp;

-(void)dealloc
{
	[title release];
	[videoUrl release];
	[description release];
	[thumbnailUrl release];
	[ABCSiteURL release];
	[favoriteTimeStamp release];
	
	[super dealloc];
}



@end
