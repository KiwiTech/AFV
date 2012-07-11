//
//  FeaturedViewController.h
//  AFV
//
//  Created by Kaveh G. on 2/1/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface FeaturedViewController : UIViewController<UIScrollViewDelegate> {

	UILabel* titleLabel;
	UIScrollView* scrollView;
	UIButton* leftButton;
	UIButton* rightButton;
	UIButton* playButton;
	UIButton* facebookButton;
	UIButton* favoriteButton;
	UIButton* reloadButton;
	UIView* loadingView;
	
	NSMutableArray* items;
	int currentPageIndex;

}

@property(nonatomic, retain) IBOutlet UILabel* titleLabel;
@property(nonatomic, retain) IBOutlet UIScrollView* scrollView;
@property(nonatomic, retain) IBOutlet UIButton* leftButton;
@property(nonatomic, retain) IBOutlet UIButton* rightButton;
@property(nonatomic, retain) IBOutlet UIButton* playButton;
@property(nonatomic, retain) IBOutlet UIButton* facebookButton;
@property(nonatomic, retain) IBOutlet UIButton* favoriteButton;
@property(nonatomic, retain) IBOutlet UIButton* reloadButton;
@property(nonatomic, retain) IBOutlet UIView* loadingView;

@property(nonatomic, retain) NSMutableArray* items;


-(IBAction)leftButtonAction:(id)sender;
-(IBAction)rightButtonAction:(id)sender;
-(IBAction)playButtonAction:(id)sender;
-(IBAction)facebookButtonAction:(id)sender;
-(IBAction)favoritesButtonAction:(id)sender;
-(IBAction)reloadButtonAction:(id)sender;

@end
