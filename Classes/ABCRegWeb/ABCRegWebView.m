//
//  ABCRegWebView.m
//  ABCRegWeb
//
//  Created by Martin Ma on 7/1/10.
//  Copyright 2010 ABC. All rights reserved.
//

#import "ABCRegWebView.h"

//-------------------------------------------------------------------------------
// ABC Registration ApplicationId URLs
//	+ contact ABC Commuinity Tech for new app ids
//-------------------------------------------------------------------------------
static NSString *kABCRegAppId = @"abccom";
static NSString *kABCRegQuery = @"cid=iOSReg&redirect=abcreg%3A%2F%2Fsuccess";
static NSString *kABCRegUrl = @"https://abc.go.com/service/register";

@implementation ABCRegWebView

@synthesize delegate = _delegate,
			loading = _loading,
			thankyouHtml = _thankyouHtml,
			action = _action,
			type = _type,
			allowBounces = _allowBounces,
			applicationId = _applicationId,
			orientation = _orientation;

- (ABCRegWebView *)initWithFrame:(CGRect)frame {
    if ((self = [super initWithFrame:frame])) {
		[self initABCRegWebView];
    }
    return self;
}

- (ABCRegWebView *)initWithCoder:(NSCoder *)aDecoder {
    if ((self = [super initWithCoder:aDecoder])) {
		[self initABCRegWebView];
    }
    return self;
}

- (void)initABCRegWebView {

	// Initialize data
	_thankyouHtml = @"<html><head><style>body{color:#EEE;background-color:transparent;}</style></head><body><p>Thank you!</p><p>You're now logged in.</p></body></html>";
	_action = ABCRegActionLogin;
	_type = ABCRegTypeLite;
	_allowBounces = NO;
	_applicationId = kABCRegAppId;
}

- (void)loadABCRegRequest {
	[self loadABCRegRequest:_action type:_type];
}

- (void)loadABCRegRequest:(ABCRegAction)action {
	[self loadABCRegRequest:action type:_type];
}

- (void)loadABCRegRequest:(ABCRegAction)action type:(ABCRegType)type {
	_action = action;
	_type = type;
	
	// Get ABCReg WebView URL
	NSURL *url = [self buildRegUrlForAction:action type:type];
	NSURLRequest *request = [NSURLRequest requestWithURL:url];
	
	if (_webview == nil) {
		_webview = [[UIWebView alloc] initWithFrame:CGRectMake(0, 0, self.frame.size.width, self.frame.size.height)];
		_webview.delegate = self;
		_webview.backgroundColor = [UIColor clearColor];
		[_webview setOpaque:NO];
		_webview.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleRightMargin |UIViewAutoresizingFlexibleTopMargin |UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleBottomMargin;
		UIScrollView *webscroll = [[_webview subviews] lastObject];
	
		// Set allowBounce for UIScrollView in ABCRegWebView
		[webscroll setAlwaysBounceHorizontal:NO];
		[webscroll setAlwaysBounceVertical:NO];
		[webscroll setBounces:_allowBounces];
		
		[self addSubview:_webview];
	}
	
	_webview.hidden = YES;
	[_webview loadRequest:request];
}

- (void)setOrientation:(UIInterfaceOrientation)newOrientation {
	if (UIInterfaceOrientationIsPortrait(newOrientation)) {
		[_webview stringByEvaluatingJavaScriptFromString:@"abcdm.abccom.Utils.removeBodyClass('landscape');abcdm.abccom.Utils.addBodyClass('portrait');"];
	} else {
		[_webview stringByEvaluatingJavaScriptFromString:@"abcdm.abccom.Utils.removeBodyClass('portrait');abcdm.abccom.Utils.addBodyClass('landscape');"];
	}

	_orientation = newOrientation;
}

//-------------------------------------------------------------------------------
// UIWebViewDelegate
//-------------------------------------------------------------------------------
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
	NSURL *url = request.URL;
	NSLog(@"%@", url);

	// ABCREG iApp callback
	if ([url.scheme isEqualToString:@"abcreg"]) {
		NSString *host = url.host;
		
		// Handle TOS out-of-date error
		if ([host isEqualToString:@"errortos"]) {
			// Response to error delegate
			if ([_delegate respondsToSelector:@selector(ABCRegWeb:didFailWithError:)]) {    
				[_delegate ABCRegWeb:self didFailWithError:ABCRegResultInvalidTOUToken];
			}
			
			return NO;
		}
		
		// Handle server-side error pages 4xx/5xx
		if ([host isEqualToString:@"errorpage"]) {
			// Response to error delegate
			if ([_delegate respondsToSelector:@selector(ABCRegWeb:didFailWithError:)]) {    
				[_delegate ABCRegWeb:self didFailWithError:ABCRegResultServersideError];
			}
			
			return NO;
		}
		
		// Trigger login delegates and fire success event
		if ([host isEqualToString:@"login"]) {
			// Response to login delegate
			if ([_delegate respondsToSelector:@selector(ABCRegWeb:willSendLoginParams:)]) {    
				[_delegate ABCRegWeb:self willSendLoginParams:[[ABCRegSession session] parseQuerystring:url.query]];
			}
			
			// Make sure we store the session
			host = @"success";
		}
		
		if ([host isEqualToString:@"success"]) {
            [[ABCRegSession session] setWithCookies];
                                      
			// Check if user need to upgrade
			if ([[ABCRegSession session] type] < _type) {
				// Clear session
				[[ABCRegSession session] clearSession];
				
				// Try to upgrade
				if ([_delegate respondsToSelector:@selector(ABCRegWeb:shouldLoadUpgradeScreen:)]) {    
					if ([_delegate ABCRegWeb:self shouldLoadUpgradeScreen:_type]) {
						[self loadABCRegRequest:ABCRegActionUpgrade type:_type];
						return NO;
					};
				}
				
			}			
			// Debug:
			//NSLog(@"SWID: %@", [[ABCRegSession session] swid]);
			//NSLog(@"BLUE: %@", [[ABCRegSession session] blue]);
			//NSLog(@"LastLogin: %@", [[ABCRegSession session] lastLogin]);
			
			[webView loadHTMLString:_thankyouHtml baseURL:nil];
			
			// Response to delegate
			if ([_delegate respondsToSelector:@selector(ABCRegWebDidFinishProcessing:)]) {    
				[_delegate ABCRegWebDidFinishProcessing:self];
			}
			
			return NO;
		}
    }
	
	// External links
	if ([self isSafariLink:url.absoluteString]) {
		if ([_delegate respondsToSelector:@selector(ABCRegWeb:shouldStartLoadExternalRequest:)]) {    
			return [_delegate ABCRegWeb:self shouldStartLoadExternalRequest:request];
		}
	}
	
	// New login links, workaround to bypass Sociallink Login for now
	if ([url.absoluteString rangeOfString:@"register/login/"].location != NSNotFound) {
		[self loadABCRegRequest:ABCRegActionLogin type:_type];
        return NO;
	}
	
	// Response to delegate
	if ([_delegate respondsToSelector:@selector(ABCRegWeb:shouldStartLoadWithRequest:)]) {    
		return [_delegate ABCRegWeb:self shouldStartLoadWithRequest:request];
	}
	
	return YES;
}

- (void)webViewDidStartLoad:(UIWebView *) webView {
	[UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
	_loading.center = CGPointMake(self.frame.size.width/2, self.frame.size.height/2);
	[self addSubview:_loading];
}

- (void)webViewDidFinishLoad:(UIWebView *)webView {
	[UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
	[_loading removeFromSuperview];
	
	// Set webview orientation on didFinishLoad
	[self setOrientation:_orientation];
	_webview.hidden = NO;
	
	//Modify login form on load
	if (_action == ABCRegActionLogin) {
		[_webview stringByEvaluatingJavaScriptFromString:@"$('#submit').click(function(){$('#redirect').val('abcreg://login?'+$('#abc-form-register').serialize());});"];
	}	
    
	//Hide recaptcha audio on load
	[_webview stringByEvaluatingJavaScriptFromString:@"$('#recaptcha_widget .recaptcha_only_if_image').hide();"];

}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error {
	if ([_delegate respondsToSelector:@selector(ABCRegWeb:didFailWithError:)]) {    
		[_delegate ABCRegWeb:self didFailWithError:ABCRegResultConnectionError];
	}
	[UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
	[_loading removeFromSuperview];
}

- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)script {
	return [_webview stringByEvaluatingJavaScriptFromString:script];
}

- (NSURL *)buildRegUrlForAction:(ABCRegAction)action type:(ABCRegType)type {
	NSString *url = kABCRegUrl;
	url = [url stringByAppendingFormat:@"/%@/type/%@?applicationid=%@&%@", [[ABCRegSession session] ABCRegActionToString:action], [[ABCRegSession session] ABCRegTypeToString:type], _applicationId, kABCRegQuery];
	return [NSURL URLWithString:url];
}

- (BOOL)isSafariLink:(NSString *)url {
	BOOL result = NO;
	NSArray *externalLinks = [[NSArray alloc] initWithObjects:@"http://disney.go.com/corporate/legal/terms.html",
							  @"https://register.go.com/go/send",
							  @"https://register.go.com/global/abc/termsOfUse",
							  @"http://abc.go.com/site/faq#FaqRegSupport",
                              @"http://www.google.com/recaptcha",
							  nil];
	
	for (int i=0; i<externalLinks.count; i++) {
		NSRange urlRange = [url rangeOfString:[externalLinks objectAtIndex:i] options:NSCaseInsensitiveSearch];
		if (urlRange.location != NSNotFound) {
			result = YES;
			break;
		}
	}
	
	[externalLinks release];
	return result;
}

// DEBUG Methods
- (void)prepopulateForm {
	[_webview stringByEvaluatingJavaScriptFromString:@"var now=new Date();var username='benfrank'+now.getFullYear()+now.getMonth()+now.getDate()+now.getHours()+now.getMinutes();$('#emailaddress').val(username+'@martin.ma');$('#username').val(username);$('#gspw').val('test');$('#gspwConfirm').val('test');$('#firstname').val('Firstname');$('#lastname').val('Lastname');$('#birthday-year').val('1922');$('#gender').val('M');$('#phonenumber').val('818-321-1231');$('#line1').val('500 S Buena Vista St');$('#line2').val('ABC Building');$('#city').val('Burbank');$('#postalcode').val('91521');$('#stateprovince').val('CA');$('#accountcountrycode').val('US');$('#login').val('benfrank001');"];
}


- (void)dealloc {
	[_webview release];
	[_loading release];
	[_thankyouHtml release];
    [super dealloc];
}


@end
