//
//  NSString+Hash.h
//  AFV
//
//  Created by Kaveh G. on 2/6/11.
//  Copyright 2010 Teleca. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (Hash) 

- (NSString *)md5Hash;
+ (NSString *)md5Hash:(NSString *)clearText;

@end
