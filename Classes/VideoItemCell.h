//
//  VideoItemCell.h
//  AFV
//
//  Created by Kaveh G. on 2/8/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CachedImageView.h"


@protocol VideoItemCellDelegate;

@interface VideoItemCell : UITableViewCell<CachedImageViewDelegate> {

	UILabel* titleLabel;
	UILabel* descriptionLabel;
	CachedImageView* cachedImageView;
    
	UIImageView* playImageView;
	
	id<VideoItemCellDelegate> _delegate;
}

@property(nonatomic, retain) IBOutlet UILabel* titleLabel;
@property(nonatomic, retain) IBOutlet UILabel* descriptionLabel;
@property(nonatomic, retain) IBOutlet CachedImageView* cachedImageView;
@property (nonatomic, retain) IBOutlet UIWebView*      webView;
@property(nonatomic, retain) IBOutlet UIImageView* playImageView;

@property(assign) id<VideoItemCellDelegate> delegate;


- (IBAction)accessoryButtonAction:(id)sender withEvent:(UIEvent *)event;

@end


@protocol VideoItemCellDelegate

- (void)accessoryButtonActionWithEvent:(UIEvent*)event;

@end
