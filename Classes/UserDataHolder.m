//
//  UserDataHolder.m
//  AFV
//
//  Created by kiwitech on 17/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "UserDataHolder.h"

@implementation UserDataHolder
@synthesize sFirstName;
@synthesize sLastName;
@synthesize sEmail;
@synthesize sBirthDate;
@synthesize sAddress;
@synthesize sCity;
@synthesize sState;
@synthesize sZip;
@synthesize sCountry;
@synthesize sPhone1;
@synthesize sPhone2;
@synthesize sGender;


- (void)dealloc {
    
    [sFirstName release];
    [sLastName release];
    [sEmail release];
    [sBirthDate release];
    [sAddress release];
    [sCity release];
    [sState release];
    [sZip release];
    [sCountry release];
    [sPhone1 release];
    [sPhone2 release];
    [sGender release];
    
    [super dealloc];
}

- (void)encodeWithCoder:(NSCoder *)encoder {
    
    [encoder encodeObject:sFirstName forKey:@"sFirstName"];
    [encoder encodeObject:sLastName forKey:@"sLastName"];
    [encoder encodeObject:sEmail forKey:@"sEmail"];
    [encoder encodeObject:sBirthDate forKey:@"sBirthDate"];
    [encoder encodeObject:sAddress forKey:@"sAddress"];
    [encoder encodeObject:sCity forKey:@"sCity"];
    [encoder encodeObject:sState forKey:@"sState"];
    [encoder encodeObject:sZip forKey:@"sZip"];
    [encoder encodeObject:sCountry forKey:@"sCountry"];
    [encoder encodeObject:sPhone1 forKey:@"sPhone1"];
    [encoder encodeObject:sPhone2 forKey:@"sPhone2"];
    [encoder encodeObject:sGender forKey:@"sGender"];
}

- (id)initWithCoder:(NSCoder *)decoder {
    
    // If parent class also adopts NSCoding, replace [super init]
    // with [super initWithCoder:decoder] to properly initialize.
	
    if(self = [super init]) {
        
        self.sFirstName = [decoder decodeObjectForKey:@"sFirstName"];
        self.sLastName = [decoder decodeObjectForKey:@"sLastName"];
        self.sEmail = [decoder decodeObjectForKey:@"sEmail"];
        self.sBirthDate = [decoder decodeObjectForKey:@"sBirthDate"];
        self.sAddress = [decoder decodeObjectForKey:@"sAddress"];
        self.sCity = [decoder decodeObjectForKey:@"sCity"];
        self.sState = [decoder decodeObjectForKey:@"sState"];
        self.sZip = [decoder decodeObjectForKey:@"sZip"];
        self.sCountry = [decoder decodeObjectForKey:@"sCountry"];
        self.sPhone1 = [decoder decodeObjectForKey:@"sPhone1"];
        self.sPhone2 = [decoder decodeObjectForKey:@"sPhone2"];
        self.sGender = [decoder decodeObjectForKey:@"sGender"];
    }
    
    return self;
}


@end
