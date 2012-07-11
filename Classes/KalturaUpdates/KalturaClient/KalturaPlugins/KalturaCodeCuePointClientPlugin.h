// ===================================================================================================
//                           _  __     _ _
//                          | |/ /__ _| | |_ _  _ _ _ __ _
//                          | ' </ _` | |  _| || | '_/ _` |
//                          |_|\_\__,_|_|\__|\_,_|_| \__,_|
//
// This file is part of the Kaltura Collaborative Media Suite which allows users
// to do with audio, video, and animation what Wiki platfroms allow them to do with
// text.
//
// Copyright (C) 2006-2011  Kaltura Inc.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// @ignore
// ===================================================================================================
#import "../KalturaClient.h"
#import "KalturaCuePointClientPlugin.h"

///////////////////////// enums /////////////////////////
@interface KalturaCodeCuePointOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)START_TIME_ASC;
+ (NSString*)START_TIME_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

///////////////////////// classes /////////////////////////
@interface KalturaCodeCuePointBaseFilter : KalturaCuePointFilter
@property (nonatomic,copy) NSString* codeLike;
@property (nonatomic,copy) NSString* codeMultiLikeOr;
@property (nonatomic,copy) NSString* codeMultiLikeAnd;
@property (nonatomic,copy) NSString* codeEqual;
@property (nonatomic,copy) NSString* codeIn;
@property (nonatomic,copy) NSString* descriptionLike;
@property (nonatomic,copy) NSString* descriptionMultiLikeOr;
@property (nonatomic,copy) NSString* descriptionMultiLikeAnd;
- (KalturaFieldType)getTypeOfCodeLike;
- (KalturaFieldType)getTypeOfCodeMultiLikeOr;
- (KalturaFieldType)getTypeOfCodeMultiLikeAnd;
- (KalturaFieldType)getTypeOfCodeEqual;
- (KalturaFieldType)getTypeOfCodeIn;
- (KalturaFieldType)getTypeOfDescriptionLike;
- (KalturaFieldType)getTypeOfDescriptionMultiLikeOr;
- (KalturaFieldType)getTypeOfDescriptionMultiLikeAnd;
@end

@interface KalturaCodeCuePointFilter : KalturaCodeCuePointBaseFilter
@end

@interface KalturaCodeCuePoint : KalturaCuePoint
@property (nonatomic,copy) NSString* code;
@property (nonatomic,copy) NSString* description;
- (KalturaFieldType)getTypeOfCode;
- (KalturaFieldType)getTypeOfDescription;
@end

///////////////////////// services /////////////////////////
