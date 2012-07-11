//
//  ABCRegWebDelegate.h
//  ABCRegWeb
//
//  Created by Martin Ma on 7/19/10.
//  Copyright 2010 ABC. All rights reserved.
//
#import "ABCRegSession.h"

typedef enum {
	ABCRegResultSuccess = 1,
	ABCRegResultUnknownError,
	ABCRegResultConnectionError,
	ABCRegResultInvalidParamsError,
	ABCRegResultInvalidTOUToken,
	ABCRegResultServersideError
} ABCRegResults;

@protocol ABCRegWebDelegate;

@protocol ABCRegWebDelegate <NSObject>

@required

@optional
- (BOOL)ABCRegWeb:(id)sender shouldStartLoadWithRequest:(NSURLRequest *)request;
- (BOOL)ABCRegWeb:(id)sender shouldStartLoadExternalRequest:(NSURLRequest *)request;
- (BOOL)ABCRegWeb:(id)sender shouldLoadUpgradeScreen:(ABCRegType)type;
- (void)ABCRegWeb:(id)sender willSendLoginParams:(NSDictionary *)params;
- (void)ABCRegWebDidFinishProcessing:(id)sender;
- (void)ABCRegWeb:(id)sender didFailWithError:(ABCRegResults)error;

//- (void)request:(ABCRegRequest *)request didFailWithError:(NSDictionary *)errors;
//- (UIView *)loadingScreenInABCRegWebView:(ABCRegWebView *)webview;

@end