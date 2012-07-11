//
//  UploadConfirmationViewController.m
//  AFV
//
//  Created by Kaveh on 2/19/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "UploadConfirmationViewController.h"

@implementation UploadConfirmationViewController

@synthesize clipIDLabel;
@synthesize instructionsLabel;


#pragma mark -
#pragma mark View loading

- (void)viewDidLoad {
    [super viewDidLoad];
	

}


#pragma mark -
#pragma mark UI actions

-(IBAction)doneAction:(id)sender
{
	[self.navigationController popToRootViewControllerAnimated:YES];
}

#pragma mark -
#pragma mark Cleanup

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc. that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];

	self.clipIDLabel = nil;
	self.instructionsLabel = nil;
}


- (void)dealloc {
	
	[clipIDLabel release];
	[instructionsLabel release];

    [super dealloc];
}


@end
