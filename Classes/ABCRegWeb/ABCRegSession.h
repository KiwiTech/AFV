//
//  ABCRegSession.h
//  ABCReg
//
//  Created by Martin Ma on 4/13/10.
//  Copyright 2010 ABC. All rights reserved.
//

/*
//-------------------------------------------------------------------------------
// ABC Registration type:
//	+ SuperduperLite: sdlt
//	+ SuperLite: slt
//	+ Lite: lt
//	+ Heavy: ht
//------------------------------------------------------------------------------- 
*/


typedef enum {
	ABCRegActionLogin,
	ABCRegActionRegister,
	ABCRegActionUpgrade
} ABCRegAction;

typedef enum {
	ABCRegTypeSuperDuperLite,
	ABCRegTypeSuperLite,
	ABCRegTypeLite,
	ABCRegTypeHeavy
} ABCRegType;
 
@protocol ABCRegSessionDelegate;

//-------------------------------------------------------------------------------
// ABCRegSession Object
//	@desc: ABCRegSession object contains all non-PII user info
//------------------------------------------------------------------------------- 
@interface ABCRegSession : NSObject {
	NSMutableArray *_delegates;
	NSString *_swid;
	NSString *_username;
	ABCRegType _type;
	NSMutableArray *_tokens;
	NSString *_firstLastName;
	NSString *_blue;
	NSString *_red;
	NSDate *_lastLogin;
	NSArray *_abcRegActions;
	NSArray *_abcRegTypes;
}


// Delegates that implement ABCRegSessionDelegate
@property (nonatomic, retain) NSMutableArray *delegates;

// ABCReg unique user id (SWID)
@property (nonatomic, retain) NSString *swid;

// ABCReg username
@property (nonatomic, retain) NSString *username;

// ABCReg user registration type
// @see above for typedef
@property (nonatomic, assign) ABCRegType type;

// ABCReg CSA tokens
@property (nonatomic, retain) NSMutableArray *tokens;

// ABCReg user first and last name initial
// @example: Martin,M
@property (nonatomic, retain) NSString *firstLastName;

// ABCReg user BLUE cookie
@property (nonatomic, retain) NSString *blue;

// ABCReg user RED cookie
@property (nonatomic, retain) NSString *red;

// ABCReg user last login time stamp
@property (nonatomic, retain) NSDate *lastLogin;



//-------------------------------------------------------------------------------
// The globally shared session instance
//-------------------------------------------------------------------------------
+ (ABCRegSession *)session;

+ (void)setSession:(ABCRegSession *)session;


//-------------------------------------------------------------------------------
// Begins a session for a user with/without registration info
//-------------------------------------------------------------------------------
- (ABCRegSession *)init;

- (ABCRegSession *)initWithQueryString:(NSString *)query;

- (ABCRegSession *)setWithCookies;

- (ABCRegSession *)initWithUserObject:(NSDictionary *)user;

- (ABCRegSession *)initWithUserInfo:(NSString *)swid username:(NSString *)username type:(NSString *)type tokens:(NSMutableArray *)tokens firstLastName:(NSString *)firstLastName blue:(NSString *)blue red:(NSString *)red;

- (ABCRegSession *)initWithUserInfoWithoutFirstLastName:(NSString *)swid username:(NSString *)username type:(NSString *)type tokens:(NSMutableArray *)tokens blue:(NSString *)blue red:(NSString *)red;

- (void)clearSession;

//-------------------------------------------------------------------------------
// Utilities method for querystring parsing
// @params:
//	+ (NSString *)query
// @return:
//	+ (NSDictionary *)result
//-------------------------------------------------------------------------------
- (NSDictionary *)parseQuerystring:(NSString *)query;
- (NSDictionary *)parseQuerystring:(NSString *)query withDelimiter:(NSString *)delimiter;
- (NSDictionary *)handleRegCookie:(NSHTTPCookie *)cookie;
- (NSString *)ABCRegActionToString:(ABCRegAction)action;
- (ABCRegAction)ABCRegActionFromString:(NSString *)aString;
- (NSString *)ABCRegTypeToString:(ABCRegType)type;
- (ABCRegType)ABCRegTypeFromString:(NSString *)aString;

@end
