//
//  AFVAppDelegate.m
//  AFV
//
//  Created by Kaveh G. on 1/26/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "AFVAppDelegate.h"
#import "CachedImageView.h"
#import <AVFoundation/AVFoundation.h>
#import "GADBannerView.h"
#import "FlurryAnalytics.h"

@implementation AFVAppDelegate

@synthesize window;
@synthesize tabBarController;
@synthesize internetReachability;

#pragma mark -
#pragma mark Application lifecycle

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
    

	self.internetReachability = [Reachability reachabilityForInternetConnection];
	
	// Add the default app background to the tab bar
	UIImageView* appBackgroundView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"img-app-bg.png"]];
	CGRect frame = appBackgroundView.frame;
	frame.origin.y = 20;
	appBackgroundView.frame = frame;
	[tabBarController.view insertSubview:appBackgroundView atIndex:0];
	[appBackgroundView release];

    // Add the tab bar controller's view to the window and display.
    [self.window addSubview:tabBarController.view];
    [self.window makeKeyAndVisible];

	// set playback audio session
	NSError* error = nil;
	[[AVAudioSession sharedInstance] setCategory:AVAudioSessionCategoryPlayback error:&error];

	// Setup image caching
	[CachedImageView initializeImageCaching:YES];
	
    // Stat Flurry
	[FlurryAnalytics startSession:@"ZIGK9C76TEANKMSZ313N"];
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
}


- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
}


#pragma mark -
#pragma mark UITabBarControllerDelegate methods

// Optional UITabBarControllerDelegate method.
- (void)tabBarController:(UITabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController {

	[self.tabBarController.tabBar setNeedsDisplay];

}

+ (void)insertAdInController:(UIViewController*)controller atOffset:(int)offset
{
	GADBannerView *bannerView_ = [[GADBannerView alloc]
								  initWithFrame:CGRectMake(0.0,
                                                           offset - GAD_SIZE_320x50.height,
                                                           GAD_SIZE_320x50.width,
                                                           GAD_SIZE_320x50.height)];
	
	bannerView_.adUnitID = @"a14ea6df6106823";
	bannerView_.rootViewController = controller;
	[controller.view addSubview:bannerView_];
	
	GADRequest *request = [GADRequest request];
#ifdef DEBUG
	request.testDevices = [NSArray arrayWithObjects:
						   GAD_SIMULATOR_ID,                                           // Simulator
						   nil];
#endif 
	
	[bannerView_ loadRequest:request];
	[bannerView_ release];
}


#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
}


- (void)dealloc {
    [tabBarController release];
    [window release];
	
	[internetReachability release];
	
    [super dealloc];
}

@end

