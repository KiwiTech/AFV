//
//  LoginViewController.m
//  AFV
//
//  Created by Kaveh on 2/8/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "LoginViewController.h"
#import <QuartzCore/QuartzCore.h>	
#import "KalturaRegistrationView.h"

@implementation LoginViewController

@synthesize usernameTextField;
@synthesize passwordTextField;
@synthesize loginButton;
@synthesize webLinkButton;
@synthesize activityIndicator;

#pragma mark -
#pragma mark helper methods

- (void)dismissView
{
	loginButton.enabled = YES;
	[activityIndicator stopAnimating];
	[self dismissModalViewControllerAnimated:YES];
	
}

- (void)updateView
{
	[self dismissView];
}

-(void)loginFailed{
    
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:@"userEmail"];
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:@"userPassword"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Login Error" message:@"Invalid username/password, please try again." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
    [alert release];
    
    loginButton.enabled = YES;
    [activityIndicator stopAnimating];
  
  
}

-(void)startLogin{
    
    if ([[Client instance] login]) {
        
        [self dismissView];
    } else {
    
        [self loginFailed];                
    }
}

#pragma mark -
#pragma mark UI Actions


-(IBAction)loginButtonAction:(id)sender
{
	needRegistration = NO;
	loginButton.enabled = NO;
	[activityIndicator startAnimating];
	
    if ([usernameTextField.text length] > 0 && [passwordTextField.text length] > 0) {
        
        [[NSUserDefaults standardUserDefaults] setObject:usernameTextField.text forKey:@"userEmail"];
        [[NSUserDefaults standardUserDefaults] setObject:passwordTextField.text forKey:@"userPassword"];
        [[NSUserDefaults standardUserDefaults] synchronize];

        [self performSelector:@selector(startLogin) withObject:nil afterDelay:0.2];
    }else {
        
        [self loginFailed];
    }
}

-(IBAction)webLinkButtonAction:(id)sender
{
    NSArray *topLevelObjects = [[NSBundle mainBundle] loadNibNamed:@"KalturaRegistrationView" owner:nil options:nil];
	if (topLevelObjects && topLevelObjects.count > 0 && [[topLevelObjects objectAtIndex:0] isKindOfClass:[KalturaRegistrationView class]]) {
        
        KalturaRegistrationView* kalturaRegistrationView = [topLevelObjects objectAtIndex:0];
		
		UIWindow* window = [UIApplication sharedApplication].keyWindow;
		if (!window) {
			window = [[UIApplication sharedApplication].windows objectAtIndex:0];
		}
		
		[window addSubview:kalturaRegistrationView];
        
    }
}

-(IBAction)cancelAction:(id)sender
{
    if ([self canPerformAction:@selector(startLogin) withSender:nil]) {
        [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(startLogin) object: nil];
    }
        [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
	
	[self dismissModalViewControllerAnimated:YES];
}

#pragma mark -
#pragma mark UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{

	[textField resignFirstResponder];
	
	return YES;
	
}
#pragma mark -
#pragma mark View cleanup

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc. that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];

	self.usernameTextField = nil;
	self.passwordTextField = nil;
	self.loginButton = nil;
	self.webLinkButton = nil;
	self.activityIndicator = nil;
}


- (void)dealloc {
	
	[usernameTextField release];
	[passwordTextField release];
	[loginButton release];
	[webLinkButton release];
	[activityIndicator release];
	
    [super dealloc];
}


@end
