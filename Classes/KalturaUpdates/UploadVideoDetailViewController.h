//
//  UploadVideoDetailViewController.h
//  AFV
//
//  Created by Kaveh on 2/10/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HTTPPostRequest.h"

@interface UploadVideoDetailViewController : UIViewController<UITextFieldDelegate,KalturaClientDelegate, ASIProgressDelegate,UITextViewDelegate> {

	UIImageView* imageView;
	UITextField* titleTextField;
	UITextField* descriptionTextField;
	UITextView* descriptionTextView;
	UIButton* playButton;
	UIView* uploadProgressOverlayView;
	UIProgressView* progressView;
	UIButton* uploadButton;
	
	UIImage* videoThumbnail;
	NSURL* videoFileURL;
//	HTTPPostRequest* postRequest;
	KalturaUploadToken* token;
    long long fileSize;
    long long uploadedSize;
    
	@private
	BOOL isTitleEmpty;
	BOOL isDescriptionEmpty;
    
	
}

@property(nonatomic, retain) IBOutlet UIImageView* imageView;
@property(nonatomic, retain) IBOutlet UITextField* titleTextField;
@property(nonatomic, retain) IBOutlet UITextField* descriptionTextField;
@property(nonatomic, retain) IBOutlet UITextView* descriptionTextView;
@property(nonatomic, retain) IBOutlet UIButton* playButton;
@property(nonatomic, retain) IBOutlet UIView* uploadProgressOverlayView;
@property(nonatomic, retain) IBOutlet UIProgressView* progressView;
@property(nonatomic, retain) IBOutlet UIButton* uploadButton;
//@property(nonatomic, retain) IBOutlet UIBarButtonItem* cancelButton;

@property(nonatomic, retain) UIImage* videoThumbnail;
@property(nonatomic, retain) NSURL* videoFileURL;
//@property(nonatomic, retain) HTTPPostRequest* postRequest;

-(IBAction)playAction:(id)sender;
-(IBAction)uploadAction:(id)sender;
-(IBAction)cancelAction:(id)sender;

@end
