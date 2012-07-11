//
//  FacebookManager.h
//  AFV
//
//  Created by Kaveh G. on 2/20/11.
//  Copyright 2011 Teleca USA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FBConnect.h"

@interface FacebookManager : NSObject<FBDialogDelegate, FBSessionDelegate, FBRequestDelegate> {
	Facebook *facebook;
}

@property(nonatomic, retain) Facebook *facebook;

+(FacebookManager*)sharedInstance;

-(void)updateFacebookFeedWithParams:(NSDictionary*)prompt;
-(void)logout;
-(void)handleOpenURL:(NSURL*) url;
-(void)loginUseExistingSession:(BOOL) useExisting;

@end
