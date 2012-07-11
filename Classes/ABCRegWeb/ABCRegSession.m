    //
//  ABCRegSession.m
//  ABCReg
//
//  Created by Martin Ma on 5/21/10.
//  Copyright 2010 ABC. All rights reserved.
//

#import "ABCRegSession.h"


static ABCRegSession *sharedSession = nil;

//-------------------------------------------------------------------------------
// Implementation
//-------------------------------------------------------------------------------
@implementation ABCRegSession

@synthesize delegates = _delegates, swid = _swid, username = _username, type = _type, tokens = _tokens, firstLastName = _firstLastName, blue = _blue, red = _red, lastLogin = _lastLogin;


+ (ABCRegSession *)session {
	@synchronized(self)
    {
		if (sharedSession == nil)
			sharedSession = [[ABCRegSession alloc] init];
    }
    return sharedSession;
}

+ (void)setSession:(ABCRegSession *)session {
	sharedSession = session;
}

- (ABCRegSession *)init {
	[super init];
	
	_abcRegActions = [[NSArray arrayWithObjects:@"login-form", @"register", @"upgrade", nil] retain];
	_abcRegTypes = [[NSArray arrayWithObjects:@"sdlt", @"slt", @"lt", @"ht", nil] retain];
	
	return [self initWithUserInfo:nil
						 username:nil
							 type:nil
						   tokens:nil
					firstLastName:nil
							 blue:nil
							  red:nil];
}

- (void)clearSession {
    [self initWithUserInfo:nil
                  username:nil
                      type:nil
                    tokens:nil
             firstLastName:nil
                      blue:nil
                       red:nil];
}

- (ABCRegSession *)initWithQueryString:(NSString *)query {
	NSMutableDictionary *user = [[[NSMutableDictionary alloc] init] autorelease];
	NSDictionary *params = [self parseQuerystring:query];
	if ([params valueForKey:@"uc"] != nil) {
		NSDictionary *temp = [self parseQuerystring:[params valueForKey:@"uc"]];
		if ([temp valueForKey:@"tokens"] != nil) {
			[temp setValue:[[temp valueForKey:@"tokens"] componentsSeparatedByString:@"|"] forKey:@"tokens"];
			[user addEntriesFromDictionary:temp];
		}
	}
	//NSLog(@"outside: %@", user);
	return [self initWithUserObject:user];
}

- (ABCRegSession *)setWithCookies {
	NSArray *cookies = [NSArray arrayWithObjects:@"BLUE", @"RED", @"SWID", @"__uc", nil];
	NSMutableDictionary *dUserInfo = [[NSMutableDictionary alloc] init];
	NSHTTPCookie *cookie;
	
	for (cookie in [[NSHTTPCookieStorage sharedHTTPCookieStorage] cookies]) {
		if ([cookies containsObject:[cookie name]]) {
			//NSLog(@"%@", [self handleRegCookie:cookie]);
			[dUserInfo addEntriesFromDictionary:[self handleRegCookie:cookie]];
		}
	}
    NSDictionary *dInfo = [NSDictionary dictionaryWithDictionary:dUserInfo];
	[dUserInfo release];
    
	return [self initWithUserObject:dInfo];
}

- (ABCRegSession *)initWithUserObject:(NSDictionary *)user {
	//NSLog(@"%@", user);
	return [self initWithUserInfo:[user valueForKey:@"swid"]
						 username:[user valueForKey:@"id"]
							 type:(NSString *)[user valueForKey:@"type"]
						   tokens:[user valueForKey:@"tokens"]
					firstLastName:[user valueForKey:@"firstlastname"]
							 blue: [user valueForKey:@"blue"]
							  red:[user valueForKey:@"red"]];
}

- (ABCRegSession *)initWithUserInfoWithoutFirstLastName:(NSString *)swid username:(NSString *)username type:(NSString *)type tokens:(NSMutableArray *)tokens blue:(NSString *)blue red:(NSString *)red {
	return [self initWithUserInfo:swid
						 username:username
							 type:type
						   tokens:tokens
					firstLastName:nil
							 blue:blue
							  red:red];
}

- (ABCRegSession *)initWithUserInfo:(NSString *)swid username:(NSString *)username type:(NSString *)type tokens:(NSMutableArray *)tokens firstLastName:(NSString *)firstLastName blue:(NSString *)blue red:(NSString *)red {
	_swid = swid;
	_username = username;
	_type = [self ABCRegTypeFromString:type];
	_tokens = tokens;
	_firstLastName = firstLastName;
	_blue = blue;
	_red = red;
	_lastLogin = [NSDate date];
	
	return self;
}

// Utility Method for Querystring Parsing 
- (NSDictionary *)parseQuerystring:(NSString *)query {
	return [self parseQuerystring:query withDelimiter:@"&"];
}


- (NSDictionary *)parseQuerystring:(NSString *)query withDelimiter:(NSString *)delimiter {
    NSMutableDictionary *dict = [[[NSMutableDictionary alloc] initWithCapacity:6] autorelease];
    NSArray *pairs = [query componentsSeparatedByString:delimiter];
	//NSLog(@"%@", pairs);
	
    for (NSString *pair in pairs) {
        NSArray *elements = [pair componentsSeparatedByString:@"="];
        NSString *key = [[elements objectAtIndex:0] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        NSString *val = [[elements objectAtIndex:1] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        
        [dict setObject:val forKey:key];
    }
    return dict;
}

// NSHTTPCookie handling
- (NSDictionary *)handleRegCookie:(NSHTTPCookie *)cookie {
	NSMutableDictionary *dCookies = [[NSMutableDictionary alloc] init];
	
	if ([[cookie name] isEqualToString:@"BLUE"]) {
		[dCookies setObject:[cookie value] forKey:@"blue"];
	} else if ([[cookie name] isEqualToString:@"SWID"]) {
		[dCookies setObject:[cookie value] forKey:@"swid"];
	} else if ([[cookie name] isEqualToString:@"RED"]) {
		[dCookies setObject:[cookie value] forKey:@"red"];
	} else if ([[cookie name] isEqualToString:@"__uc"]) {
		NSDictionary *userInfo = [[ABCRegSession session] parseQuerystring:[[cookie value] stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
		//NSLog(@"userInfo: %@", userInfo);
		
		// Username
		[dCookies setObject:[userInfo valueForKey:@"u"] forKey:@"id"];
		// User type
		[dCookies setObject:[userInfo valueForKey:@"t"] forKey:@"type"];
		// User Firstname,L
		[dCookies setObject:[userInfo valueForKey:@"f"] forKey:@"firstlastname"];
		// User token
		NSString *tokens = [userInfo valueForKey:@"s"];
		[dCookies setObject:[tokens componentsSeparatedByString:@"|"] forKey:@"tokens"];
		
	}
	
	NSDictionary *result =  [NSDictionary dictionaryWithDictionary:dCookies];
    [dCookies release];
    return result;
}


// Registration type and action convertion 
- (NSString *)ABCRegActionToString:(ABCRegAction)action {
	return [_abcRegActions objectAtIndex:action];
}
- (ABCRegAction)ABCRegActionFromString:(NSString *)aString {
	return (ABCRegAction)[_abcRegActions indexOfObject:aString];
}
- (NSString *)ABCRegTypeToString:(ABCRegType)type {
	return [_abcRegTypes objectAtIndex:type];
}
- (ABCRegType)ABCRegTypeFromString:(NSString *)aString {
	return (ABCRegType)[_abcRegTypes indexOfObject:aString];
}


- (void)dealloc {
	if (sharedSession == self) {
		sharedSession = nil;
	}
	[_delegates release];
	[_swid release];
	[_username release];
	[_tokens release];
	[_firstLastName release];
	[_blue release];
	[_red release];
	[_abcRegActions release];
	[_abcRegTypes release];
    [super dealloc];
}


@end
