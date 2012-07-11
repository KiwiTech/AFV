//
//  UploadConfirmationViewController.h
//  AFV
//
//  Created by Kaveh on 2/19/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>


@interface UploadConfirmationViewController : UIViewController {

	UILabel* clipIDLabel;
	UILabel* instructionsLabel;
	
}

@property(nonatomic,retain) IBOutlet UILabel* clipIDLabel;
@property(nonatomic,retain) IBOutlet UILabel* instructionsLabel;



-(IBAction)doneAction:(id)sender;

@end
