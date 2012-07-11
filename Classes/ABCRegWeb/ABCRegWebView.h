//
//  ABCRegWebView.h
//  ABCRegWeb
//
//  Created by Martin Ma on 7/1/10.
//  Copyright 2010 ABC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ABCRegWebDelegate.h"
#import "ABCRegSession.h"

@interface ABCRegWebView : UIView <UIWebViewDelegate> {
	id<ABCRegWebDelegate> _delegate;
	UIWebView *_webview;
	UIView *_loading;
	NSString *_thankyouHtml;
	ABCRegAction _action;
	ABCRegType _type;
	BOOL _allowBounces;
	NSString *_applicationId;
	UIInterfaceOrientation _orientation;
}

@property (nonatomic, assign) id<ABCRegWebDelegate> delegate;
//@property (nonatomic, retain) UIWebView *webview;

// Customized webview loading screen
@property (nonatomic, retain) UIView *loading;

// Customizable thank you screen after register/login/upgrade
@property (nonatomic, retain) NSString *thankyouHtml;

// Customizable webview bounces
@property (nonatomic, assign) BOOL allowBounces;

// Customizable ABCReg applicationid
@property (nonatomic, retain) NSString *applicationId;

@property (nonatomic, assign) UIInterfaceOrientation orientation;
@property (nonatomic, assign, readonly) ABCRegAction action;
@property (nonatomic, assign, readonly) ABCRegType type;

- (void)initABCRegWebView;
- (void)loadABCRegRequest;
- (void)loadABCRegRequest:(ABCRegAction)action;
- (void)loadABCRegRequest:(ABCRegAction)action type:(ABCRegType)type;
- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)script;
- (void)prepopulateForm;



//-------------------------------------------------------------------------------
// Utilities method to build ABC Registration URL
// @params:
//	+ (NSString *)action (NSString *)type
// @return:
//	+ (NSString *)result
//-------------------------------------------------------------------------------
- (NSURL *)buildRegUrlForAction:(ABCRegAction)action type:(ABCRegType)type;

//-------------------------------------------------------------------------------
// Utilities method to check if a centain URL is an external url that should open
// in Safari Only
// @params:
//	+ (NSString *)url
// @return:
//	+ (BOOL)result
//-------------------------------------------------------------------------------
- (BOOL)isSafariLink:(NSString *)url;

@end
