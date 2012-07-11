//
//  LoginViewController.h
//  AFV
//
//  Created by Kaveh on 2/8/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LoginViewController : UIViewController<UITextFieldDelegate> {

	UITextField* usernameTextField;
	UITextField* passwordTextField;
	UIButton* loginButton;
	UIButton* webLinkButton;
	UIActivityIndicatorView* activityIndicator;

	@private
	BOOL needRegistration;
}

@property(nonatomic, retain) IBOutlet UITextField* usernameTextField;
@property(nonatomic, retain) IBOutlet UITextField* passwordTextField;
@property(nonatomic, retain) IBOutlet UIButton* loginButton;
@property(nonatomic, retain) IBOutlet UIButton* webLinkButton;
@property(nonatomic, retain) IBOutlet UIActivityIndicatorView* activityIndicator;


-(IBAction)loginButtonAction:(id)sender;
-(IBAction)webLinkButtonAction:(id)sender;
-(IBAction)cancelAction:(id)sender;

@end
