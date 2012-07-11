//
//  ABCRegistrationView.h
//  AFV
//
//  Created by Kaveh on 3/3/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface KalturaRegistrationView : UIView <UIWebViewDelegate>{

	
}

@property(nonatomic,retain) IBOutlet UIWebView *webView;
@property(nonatomic,retain) IBOutlet UIButton* closeButton;
@property(nonatomic,retain) IBOutlet UIActivityIndicatorView* loadingView;


- (IBAction)closeActin:(id)sender;

@end

