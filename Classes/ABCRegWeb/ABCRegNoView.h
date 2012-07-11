//
//  ABCRegNoView.h
//  ABCRegWeb
//
//  Created by Martin Ma on 7/18/10.
//  Copyright 2010 ABC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ABCRegWebDelegate.h"
#import "ABCRegSession.h"

@interface ABCRegNoView : NSObject {
	id<ABCRegWebDelegate> _delegate;
	ABCRegType _type;
	NSMutableData *_receivedData;
}

@property (nonatomic, assign) id<ABCRegWebDelegate> delegate;

- (id)initWithDelegate:(id<ABCRegWebDelegate>)delegate;
- (void)login:(NSString *)login  password:(NSString *)password;
- (void)login:(NSString *)login  password:(NSString *)password type:(ABCRegType)type;

@end
