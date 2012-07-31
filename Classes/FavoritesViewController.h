//
//  FavoritesViewController.h
//  AFV
//
//  Created by Kaveh G. on 1/26/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VideoItemCell.h"


@interface FavoritesViewController : UIViewController<UITableViewDelegate,UITableViewDataSource,VideoItemCellDelegate> {

    UITableView* tableView;
	NSArray* items;
	
}

@property(nonatomic,retain) IBOutlet UITableView* tableView;
@property(nonatomic, retain) NSArray* items;

@end
