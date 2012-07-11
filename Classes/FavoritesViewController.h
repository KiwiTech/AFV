//
//  FavoritesViewController.h
//  AFV
//
//  Created by Kaveh G. on 1/26/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VideoItemCell.h"


@interface FavoritesViewController : UITableViewController<VideoItemCellDelegate> {

	NSArray* items;
	
}

@property(nonatomic, retain) NSArray* items;

@end
