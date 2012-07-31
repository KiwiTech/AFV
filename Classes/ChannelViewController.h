//
//  ChannelViewController.h
//  AFV
//
//  Created by Kaveh G. on 2/8/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VideoItemCell.h"

@interface ChannelViewController : UIViewController<UITableViewDelegate,UITableViewDataSource,VideoItemCellDelegate> {

    UITableView* tableView;
	NSMutableArray* items;
	NSString* channelID;
	int videoCount;
	int errorStartOffset;
	
	@private 
	BOOL loadingData;

}

@property(nonatomic,retain) IBOutlet UITableView* tableView;
@property(nonatomic, retain) NSMutableArray* items;
@property(nonatomic, retain) NSString* channelID;
@property(nonatomic, assign) int videoCount;

@end
