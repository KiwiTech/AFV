//
//  VideoDetailViewController.h
//  AFV
//
//  Created by Kaveh G. on 2/1/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CachedImageView.h"
#import "VideoItem.h"


@interface VideoDetailViewController : UIViewController {

	UILabel* titleLabel;
	UILabel* descriptonLabel;
	CachedImageView* thumbnailImageView;
	UIButton* playButton;
	UIButton* facebookButton;
	UIButton* favoriteButton;
	
	VideoItem* videoItem;
	
}

@property(nonatomic, retain) IBOutlet UILabel* titleLabel;
@property(nonatomic, retain) IBOutlet UILabel* descriptonLabel;
@property(nonatomic, retain) IBOutlet CachedImageView* thumbnailImageView;
@property(nonatomic, retain) IBOutlet UIButton* playButton;
@property(nonatomic, retain) IBOutlet UIButton* facebookButton;
@property(nonatomic, retain) IBOutlet UIButton* favoriteButton;

@property(nonatomic, retain) VideoItem* videoItem;
@property (nonatomic, retain) IBOutlet UIWebView*    webView;


-(IBAction)playButtonAction:(id)sender;
-(IBAction)facebookButtonAction:(id)sender;
-(IBAction)favoritesButtonAction:(id)sender;

@end
