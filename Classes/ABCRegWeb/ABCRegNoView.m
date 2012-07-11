    //
//  ABCRegNoView.m
//  ABCRegWeb
//
//  Created by Martin Ma on 7/18/10.
//  Copyright 2010 ABC. All rights reserved.
//

#import "ABCRegNoView.h"

static NSString *kABCRegLoginUrl = @"https://abc.go.com/service/regapi/login";

@implementation ABCRegNoView
@synthesize delegate =_delegate;

- (id)init {
	return [self initWithDelegate:nil];
}

- (id)initWithDelegate:(id<ABCRegWebDelegate>)delegate {
	[super init];
	
	_receivedData = [[NSMutableData alloc] init];
	_type = ABCRegTypeLite;
	_delegate = delegate;
	
	return self;
}

- (void)login:(NSString *)login  password:(NSString *)password {
	[self login:login password:password type:_type];
}

- (void)login:(NSString *)login  password:(NSString *)password type:(ABCRegType)type {
	_type = type;
	
	// Build login URL
	NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:kABCRegLoginUrl]];
	
	// Non-configurable params
	[request setHTTPMethod:@"POST"];
	[request setTimeoutInterval:30];
	
	// Build request body
	NSString *body = [NSString stringWithFormat:@"login=%@&gspw=%@", login, password];
	[request setHTTPBody:[body dataUsingEncoding:NSUTF8StringEncoding]];
	
	// Create connection and fire request
	NSURLConnection *connection = [NSURLConnection connectionWithRequest:request delegate:self];
	
	// Response to delegate
	if ([_delegate respondsToSelector:@selector(ABCRegWeb:shouldStartLoadWithRequest:)]) {    
		if ([_delegate ABCRegWeb:self shouldStartLoadWithRequest:request]) {
			[connection start];
		}
	}
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
	[_receivedData appendData:data];
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
	if ([_delegate respondsToSelector:@selector(ABCRegWeb:didFailWithError:)]) {    
		[_delegate ABCRegWeb:self didFailWithError:ABCRegResultConnectionError];
	}
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
	NSString *response = [[NSString alloc] initWithData:_receivedData encoding:NSUTF8StringEncoding];
	//NSLog(@"%@", response);
	NSRange match;
	match = [response rangeOfString:@"\"response\":true"];
    [response release];
    
	if (match.location == NSNotFound) {
		if ([_delegate respondsToSelector:@selector(ABCRegWeb:didFailWithError:)]) {    
			[_delegate ABCRegWeb:self didFailWithError:ABCRegResultInvalidParamsError];
		}
	} else {
		[[ABCRegSession session] setWithCookies];
		
		// Check if user need to upgrade
		if ([[ABCRegSession session] type] < _type) {
			// Clear session
			[[ABCRegSession session] clearSession];
			
			// Try to upgrade
			if ([_delegate respondsToSelector:@selector(ABCRegWeb:shouldLoadUpgradeScreen:)]) {    
				if ([_delegate ABCRegWeb:self shouldLoadUpgradeScreen:_type]) {
					return;
				};
			}
			
		}

		
		if ([_delegate respondsToSelector:@selector(ABCRegWebDidFinishProcessing:)]) {    
			[_delegate ABCRegWebDidFinishProcessing:self];
		}
	}

	//NSLog(@"%@", [[ABCRegSession session] username]);
	//NSLog(@"%@", response);
}


- (void)dealloc {
	[_receivedData release];
    [super dealloc];
}


@end
