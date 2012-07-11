//
//  FacebookManager.m
//  AFV
//
//  Created by Kaveh G. on 2/20/11.
//  Copyright 2011 Teleca USA. All rights reserved.
//

#import "FacebookManager.h"
#import "FBConnect.h"

static FacebookManager* fbManager = nil;

@implementation FacebookManager
@synthesize facebook;

#pragma mark -
#pragma mark Singleton methods

+ (const FacebookManager *)sharedInstance{

	if(fbManager == nil)
		fbManager = [[super allocWithZone:NULL] init];

	if(fbManager.facebook == nil)
		fbManager.facebook = [[[Facebook alloc] initWithAppId:@"199000230126658"] autorelease];

	return fbManager;
}


+ (id)allocWithZone:(NSZone *)zone
{
    return [[self sharedInstance] retain];
}

- (id)copyWithZone:(NSZone *)zone
{
    return self;
}

- (id)retain
{
    return self;
}

- (NSUInteger)retainCount
{
    return NSUIntegerMax;  //denotes an object that cannot be released
}

- (void)release
{
    //do nothing
}

- (id)autorelease
{
    return self;
}


-(void)dealloc
{
	[facebook release];
	[super dealloc];
}


#pragma mark -
#pragma mark Public methods

- (void)updateFacebookFeedWithParams:(NSMutableDictionary*)params{
	
	if(NO && !facebook){
		DLog(@"DA200: Requesting Facebook stream update, but facebook is not initialized or the user is not logged in");

		UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Facebook Login" 
														message:@"You are not currently logged into your Facebook account. You must login before posting to Facebook, would you like to login now?" 
														delegate:self 
														cancelButtonTitle:@"NO" 
														otherButtonTitles:@"YES",nil];
		[alert show];
		[alert release];

		return;
	}
	
	[facebook dialog:@"feed"
			andParams:params
		  andDelegate:self];
}

-(void)loginUseExistingSession:(BOOL) useExisting{
	
	if(facebook == nil){
		DLog(@"DA201: Requesting Facebook login, but facebook is not initialized");
		
		UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Unable to login to Facebook due to Application Error" message:@"An application error has occured. Message DA201." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
		[alert show];
		[alert release];
		
		return;
	}
		
	if(!(useExisting && [facebook isSessionValid])){
		NSArray* permissions =  [NSArray arrayWithObjects:
								 @"read_stream", @"offline_access",nil];

		[facebook authorize:permissions delegate:self]; 
	}
}

- (void)logout{
	if(facebook)
		[facebook logout:self];
}

-(void)handleOpenURL:(NSURL*) url{
	if(facebook)
		[facebook handleOpenURL:url];
}


#pragma mark FBSessionDelegate_methods
/**
 * Called when the user successfully logged in.
 */
- (void)fbDidLogin{
	DLog(@"FB Logged in");
}

/**
 * Called when the user dismissed the dialog without logging in.
 */
- (void)fbDidNotLogin:(BOOL)cancelled{
	DLog(@"FB Cancelled Login");
}

/**
 * Called when the user logged out.
 */
- (void)fbDidLogout{
	DLog(@"FB Logged Out");
}


#pragma mark FBRequestDelegate_methods
/**
 * Called just before the request is sent to the server.
 */
- (void)requestLoading:(FBRequest *)request{
	DLog(@"Requesting data from facebook");
}

/**
 * Called when the server responds and begins to send back data.
 */
- (void)request:(FBRequest *)request didReceiveResponse:(NSURLResponse *)response{
	DLog(@"Log http level errors here");
	
}

/**
 * Called when an error prevents the request from completing successfully.
 */
- (void)request:(FBRequest *)request didFailWithError:(NSError *)error{
	DLog(@"There was an error requesting information from facebook: %@", [error localizedDescription]);

}

- (void)request:(FBRequest *)request didLoad:(id)result{
	DLog(@"Request did load");

}

- (void)request:(FBRequest *)request didLoadRawResponse:(NSData *)data
{
	DLog(@"Request didLoadRawResponse");
	
}


#pragma mark FBRequestDelegate_methods
/**
 * Called when the dialog succeeds and is about to be dismissed.
 */
- (void)dialogDidComplete:(FBDialog *)dialog{
	DLog(@"Dialog did complete");
}

/**
 * Called when the dialog succeeds with a returning url.
 */
- (void)dialogCompleteWithUrl:(NSURL *)url{
	DLog(@"Dialog did complete with URL: %@", [url description]);
}

/**
 * Called when the dialog get canceled by the user.
 */
- (void)dialogDidNotCompleteWithUrl:(NSURL *)url{
	DLog(@"Dialog did not complete with URL: %@", [url description]);
}

/**
 * Called when the dialog is cancelled and is about to be dismissed.
 */
- (void)dialogDidNotComplete:(FBDialog *)dialog{
	DLog(@"Dialog did not complete");
}

/**
 * Called when dialog failed to load due to an error.
 */
- (void)dialog:(FBDialog*)dialog didFailWithError:(NSError *)error{
	DLog(@"Dialog did fail with error: %@", [error localizedDescription]);
}

/**
 * Asks if a link touched by a user should be opened in an external browser.
 *
 * If a user touches a link, the default behavior is to open the link in the Safari browser,
 * which will cause your app to quit.  You may want to prevent this from happening, open the link
 * in your own internal browser, or perhaps warn the user that they are about to leave your app.
 * If so, implement this method on your delegate and return NO.  If you warn the user, you
 * should hold onto the URL and once you have received their acknowledgement open the URL yourself
 * using [[UIApplication sharedApplication] openURL:].
 */
- (BOOL)dialog:(FBDialog*)dialog shouldOpenURLInExternalBrowser:(NSURL *)url{
	DLog(@"User wants to open the following link %@:", [url description]);
	return YES;
}

@end
