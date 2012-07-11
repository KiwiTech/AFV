//
//  VideoItem.h
//  AFV
//
//  Created by Kaveh G. on 2/3/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface VideoItem : NSObject {

	NSString* title;
	NSString* videoUrl;
	NSString* description;
	NSString* thumbnailUrl;
	NSString* ABCSiteURL;
	NSDate* favoriteTimeStamp;
	
}

@property(nonatomic, retain) NSString* title;
@property(nonatomic, retain) NSString* videoUrl;
@property(nonatomic, retain) NSString* description;
@property(nonatomic, retain) NSString* thumbnailUrl;
@property(nonatomic, retain) NSString* ABCSiteURL;
@property(nonatomic, retain) NSDate* favoriteTimeStamp;

@end
