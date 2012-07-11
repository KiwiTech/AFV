//
//  ABCRegistrationView.m
//  AFV
//
//  Created by Kaveh on 3/3/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "KalturaRegistrationView.h"
#import <QuartzCore/QuartzCore.h>

@implementation KalturaRegistrationView

#define KALTURA_REGISTRATION_URL @"http://corp.kaltura.com/free-trial"

@synthesize closeButton;
@synthesize loadingView;
@synthesize webView;

- (void) awakeFromNib
{

	// bloom animation
	CAKeyframeAnimation * animation;
	animation = [CAKeyframeAnimation animationWithKeyPath:@"transform"];
	animation.duration = 0.5;
	animation.fillMode = kCAFillModeForwards;
	
	NSMutableArray *values = [NSMutableArray arrayWithObjects:
							  [NSNumber valueWithCATransform3D:CATransform3DScale (self.layer.transform, 0.01, 0.01, 1.0)]
							  ,[NSNumber valueWithCATransform3D:CATransform3DScale (self.layer.transform, 1.08, 1.08, 1.0)]
							  ,[NSNumber valueWithCATransform3D:CATransform3DScale (self.layer.transform, 0.8, 0.8, 1.0)]
							  ,[NSNumber valueWithCATransform3D:CATransform3DScale (self.layer.transform, 1.0, 1.0, 1.0)]
							  ,nil];
	
	NSMutableArray *keyTimes = [NSMutableArray arrayWithObjects:
								[NSNumber numberWithFloat:0.0f]
								,[NSNumber numberWithFloat:0.3f]
								,[NSNumber numberWithFloat:0.7f]								
								,[NSNumber numberWithFloat:1.0f]
								,nil];
	
	NSArray *timingFunctions = [NSArray arrayWithObjects:
								[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseOut], 
								[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut],
								[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut],
								nil];
	
	
	animation.values = values;
	animation.keyTimes = keyTimes;
	animation.timingFunctions = timingFunctions;
	
	[self.layer addAnimation:animation forKey:@"transform"];
	
    NSURL *kalturaURL = [NSURL URLWithString:KALTURA_REGISTRATION_URL];
    NSURLRequest *kalturaRequest = [NSURLRequest requestWithURL:kalturaURL];
	[webView loadRequest:kalturaRequest];
    webView.delegate = self;
    webView.scalesPageToFit = YES;
}

#pragma mark -
#pragma mark UI Actions

- (IBAction)closeActin:(id)sender
{
	
	[UIApplication sharedApplication].networkActivityIndicatorVisible = NO;

	[UIView beginAnimations:nil context:nil];
	[UIView setAnimationDelegate:self];
	[UIView setAnimationDidStopSelector:@selector(fadeAnimationFinished:finished:context:)];
	[UIView setAnimationDuration:0.3];
	
	self.alpha = 0.0;
	
	[UIView commitAnimations];						
	
	
}

- (void)fadeAnimationFinished:(NSString *)animationID finished:(BOOL)finished context:(void *)context
{
	[self removeFromSuperview];
}


#pragma WebView Delegate

- (void)webViewDidFinishLoad:(UIWebView *)webView{
    
    [loadingView stopAnimating];
    [loadingView removeFromSuperview];
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error{
    
    [loadingView stopAnimating];
    [loadingView removeFromSuperview];
}

#pragma mark -
#pragma mark Cleanup


- (void)dealloc {
	
    [webView release];
	[closeButton release];
	[loadingView release];
	 
    [super dealloc];
}


@end
