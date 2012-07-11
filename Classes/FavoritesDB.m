//
//  FavoritesDB.m
//  AFV
//
//  Created by Kaveh on 2/13/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "FavoritesDB.h"
#import "NSString+Hash.h"

static FavoritesDB *sharedFavoritesDBInstance = nil;

@implementation FavoritesDB
@synthesize favorites;


#pragma mark -
#pragma mark Helper methods

+ (void)saveFavoritesAsync:(NSDictionary*)dic
{

	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	NSDictionary* favoritesDic = [FavoritesDB sharedInstance].favorites;
	
	if(favoritesDic)
	{
		@synchronized(favoritesDic)
		{
			NSString *docDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
			NSString *path = [docDir stringByAppendingPathComponent:favorites_file];
			
			NSMutableDictionary* savedDic = [NSMutableDictionary dictionaryWithCapacity:[[favoritesDic allKeys] count]];
			
			for(NSString* key in [favoritesDic allKeys])
			{
				if([key isKindOfClass:[NSString class]])
				{
					VideoItem* videoItem = [favoritesDic objectForKey:key];
					
					if([videoItem isKindOfClass:[VideoItem class]])
					{
						NSMutableDictionary* videoDic = [NSMutableDictionary dictionaryWithCapacity:4];
						
						[videoDic setObject:videoItem.title forKey:@"title"];
						[videoDic setObject:videoItem.description forKey:@"description"];
						[videoDic setObject:videoItem.videoUrl forKey:@"videoUrl"];
						[videoDic setObject:videoItem.thumbnailUrl forKey:@"thumbnailUrl"];
						[videoDic setObject:videoItem.favoriteTimeStamp forKey:@"saveTimeStamp"];
						[videoDic setObject:videoItem.ABCSiteURL forKey:@"ABCSiteURL"];
						
						[savedDic setObject:videoDic forKey:key];
						
					}
					
				}
				
			}
			
			[savedDic writeToFile:path atomically:YES];
		
		}
		
	}
	
	[pool release];
	
}

#pragma mark -
#pragma mark Static methods

+ (BOOL)isFavorite:(VideoItem*)videoItem
{
	if(!videoItem)
		return NO;
	
	return ([[FavoritesDB sharedInstance].favorites objectForKey:[videoItem.videoUrl md5Hash]])?YES:NO;
}
+ (BOOL)addFavorite:(VideoItem*)videoItem
{
	if(![FavoritesDB sharedInstance].favorites || !videoItem)
		return NO;
	
	// set the video timestamp
	videoItem.favoriteTimeStamp = [NSDate date];
	
	[[FavoritesDB sharedInstance].favorites setObject:videoItem forKey:[videoItem.videoUrl md5Hash]];
	[NSThread detachNewThreadSelector:@selector(saveFavoritesAsync:) toTarget:self withObject:[NSDictionary dictionaryWithDictionary:[FavoritesDB sharedInstance].favorites]];
	
	return YES;	
}
+ (BOOL)removeFavorite:(VideoItem*)videoItem
{

	if(![FavoritesDB sharedInstance].favorites || !videoItem)
		return NO;
	
	// remove the video timestamp
	videoItem.favoriteTimeStamp = nil;

	[[FavoritesDB sharedInstance].favorites removeObjectForKey:[videoItem.videoUrl md5Hash]];
	[NSThread detachNewThreadSelector:@selector(saveFavoritesAsync:) toTarget:self withObject:[NSDictionary dictionaryWithDictionary:[FavoritesDB sharedInstance].favorites]];
		
	return YES;	
}


#pragma mark -
#pragma mark Singleton life managment

+ (FavoritesDB*)sharedInstance
{
    if (sharedFavoritesDBInstance == nil) {
        sharedFavoritesDBInstance = [[super allocWithZone:NULL] init];
		
		// Load the saved favorites
		NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
		NSString *documentsDirectory = [paths objectAtIndex:0];
		NSString* path = [documentsDirectory stringByAppendingPathComponent: favorites_file];
		
		sharedFavoritesDBInstance.favorites = [NSMutableDictionary dictionary];

		// Populate favorites from disk
		if ([[NSFileManager defaultManager] fileExistsAtPath:path]) 
		{
			NSDictionary* savedDic = [NSDictionary dictionaryWithContentsOfFile:path];
			
			// create the video objects
			for(NSString* key in [savedDic allKeys])
			{
				if([key isKindOfClass:[NSString class]])
				{
					NSDictionary* videoDic = [savedDic objectForKey:key];
					
					if([videoDic isKindOfClass:[NSDictionary class]])
					{
						VideoItem* videoItem = [[VideoItem alloc] init];
						
						videoItem.title = [videoDic valueForKey:@"title"];
						videoItem.description = [videoDic valueForKey:@"description"];
						videoItem.videoUrl = [videoDic valueForKey:@"videoUrl"];
						videoItem.thumbnailUrl = [videoDic valueForKey:@"thumbnailUrl"];
						videoItem.favoriteTimeStamp = [videoDic objectForKey:@"saveTimeStamp"];
						videoItem.ABCSiteURL = [videoDic objectForKey:@"ABCSiteURL"];
						
						[sharedFavoritesDBInstance.favorites setObject:videoItem forKey:key];
						[videoItem release];
						
					}
					
				}
			
			}
			
		}
		
    }
    return sharedFavoritesDBInstance;
}

+ (id)allocWithZone:(NSZone *)zone
{
    return [[self sharedInstance] retain];
}

- (id)copyWithZone:(NSZone *)zone
{
    return self;
}

- (id)retain
{
    return self;
}

- (NSUInteger)retainCount
{
    return NSUIntegerMax;  //denotes an object that cannot be released
}

- (void)release
{
    //do nothing
}

- (id)autorelease
{
    return self;
}


-(void)dealloc
{
	[favorites release];
	[super dealloc];
}


@end
