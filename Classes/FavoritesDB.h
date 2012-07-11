//
//  FavoritesDB.h
//  AFV
//
//  Created by Kaveh on 2/13/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VideoItem.h"

@interface FavoritesDB : NSObject {

	NSMutableDictionary* favorites;
}

@property(nonatomic,retain) NSMutableDictionary* favorites;

+ (FavoritesDB*)sharedInstance;
+ (BOOL)isFavorite:(VideoItem*)videoItem;
+ (BOOL)addFavorite:(VideoItem*)videoItem;
+ (BOOL)removeFavorite:(VideoItem*)videoItem;

@end
