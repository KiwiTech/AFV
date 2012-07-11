//
//  UploadViewController.h
//  AFV
//
//  Created by Kaveh G. on 2/3/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UploadVideoDetailViewController.h"
#import "KalturaRegistrationView.h"


@interface UploadViewController : UIViewController<UIImagePickerControllerDelegate, UINavigationControllerDelegate> {

	UIButton* loginButton;
	UIButton* webLinkButton;
	UIButton* shootVideoButton;
	UIButton* uploadExistingVideoButton;
	UIView* loginView;
	UIView* videoOptionsView;
	
	@private
	BOOL shouldPresentVideoDetailView;
	UploadVideoDetailViewController* uploadVideoDetailViewController;
}

@property(nonatomic, retain) IBOutlet UIButton* loginButton;
@property(nonatomic, retain) IBOutlet UIButton* webLinkButton;
@property(nonatomic, retain) IBOutlet UIButton* shootVideoButton;
@property(nonatomic, retain) IBOutlet UIButton* uploadExistingVideoButton;
@property(nonatomic, retain) IBOutlet UIView* loginView;
@property(nonatomic, retain) IBOutlet UIView* videoOptionsView;


-(IBAction)loginButtonAction:(id)sender;
-(IBAction)webLinkButtonAction:(id)sender;
-(IBAction)shootVideoButtonAction:(id)sender;
-(IBAction)uploadExistingVideoButtonAction:(id)sender;


@end
