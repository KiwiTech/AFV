//
//  ChannelsViewController.h
//  AFV
//
//  Created by Kaveh G. on 1/26/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface ChannelsViewController : UIViewController<UITableViewDelegate,UITableViewDataSource> {

    UITableView* tableView;
	NSMutableArray* channels;
	
	@private
	BOOL loadingData;

}

@property(nonatomic,retain) IBOutlet UITableView* tableView;
@property(nonatomic, retain) NSMutableArray* channels;

@end
