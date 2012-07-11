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
@interface KalturaAnnotationOrderBy : NSObject
+ (NSString*)END_TIME_ASC;
+ (NSString*)END_TIME_DESC;
+ (NSString*)DURATION_ASC;
+ (NSString*)DURATION_DESC;
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
@interface KalturaAnnotationBaseFilter : KalturaCuePointFilter
@property (nonatomic,copy) NSString* parentIdEqual;
@property (nonatomic,copy) NSString* parentIdIn;
@property (nonatomic,copy) NSString* textLike;
@property (nonatomic,copy) NSString* textMultiLikeOr;
@property (nonatomic,copy) NSString* textMultiLikeAnd;
@property (nonatomic,assign) int endTimeGreaterThanOrEqual;
@property (nonatomic,assign) int endTimeLessThanOrEqual;
@property (nonatomic,assign) int durationGreaterThanOrEqual;
@property (nonatomic,assign) int durationLessThanOrEqual;
- (KalturaFieldType)getTypeOfParentIdEqual;
- (KalturaFieldType)getTypeOfParentIdIn;
- (KalturaFieldType)getTypeOfTextLike;
- (KalturaFieldType)getTypeOfTextMultiLikeOr;
- (KalturaFieldType)getTypeOfTextMultiLikeAnd;
- (KalturaFieldType)getTypeOfEndTimeGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfEndTimeLessThanOrEqual;
- (KalturaFieldType)getTypeOfDurationGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfDurationLessThanOrEqual;
- (void)setEndTimeGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setEndTimeLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setDurationGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setDurationLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaAnnotationFilter : KalturaAnnotationBaseFilter
@end

@interface KalturaAnnotation : KalturaCuePoint
@property (nonatomic,copy) NSString* parentId;	// insertonly
@property (nonatomic,copy) NSString* text;
// End time in milliseconds
@property (nonatomic,assign) int endTime;
// Duration in milliseconds
@property (nonatomic,assign,readonly) int duration;
- (KalturaFieldType)getTypeOfParentId;
- (KalturaFieldType)getTypeOfText;
- (KalturaFieldType)getTypeOfEndTime;
- (KalturaFieldType)getTypeOfDuration;
- (void)setEndTimeFromString:(NSString*)aPropVal;
- (void)setDurationFromString:(NSString*)aPropVal;
@end

@interface KalturaAnnotationListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaAnnotation elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

///////////////////////// services /////////////////////////
// Annotation service - Video Annotation
// DEPRECATED - use cuePoint service instead
@interface KalturaAnnotationService : KalturaServiceBase
// Allows you to add an annotation object associated with an entry
- (KalturaAnnotation*)addWithAnnotation:(KalturaAnnotation*)aAnnotation;
// Update annotation by id
- (KalturaAnnotation*)updateWithId:(NSString*)aId withAnnotation:(KalturaAnnotation*)aAnnotation;
// List annotation objects by filter and pager
- (KalturaAnnotationListResponse*)listWithFilter:(KalturaAnnotationFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaAnnotationListResponse*)listWithFilter:(KalturaAnnotationFilter*)aFilter;
- (KalturaAnnotationListResponse*)list;
// Allows you to add multiple cue points objects by uploading XML that contains multiple cue point definitions
- (KalturaCuePointListResponse*)addFromBulkWithFileData:(NSString*)aFileData;
// Download multiple cue points objects as XML definitions
- (NSString*)serveBulkWithFilter:(KalturaCuePointFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (NSString*)serveBulkWithFilter:(KalturaCuePointFilter*)aFilter;
- (NSString*)serveBulk;
// Retrieve an CuePoint object by id
- (KalturaCuePoint*)getWithId:(NSString*)aId;
// count cue point objects by filter
- (int)countWithFilter:(KalturaCuePointFilter*)aFilter;
- (int)count;
// delete cue point by id, and delete all children cue points
- (void)deleteWithId:(NSString*)aId;
@end

@interface KalturaAnnotationClientPlugin : KalturaClientPlugin
{
	KalturaAnnotationService* _annotation;
}

@property (nonatomic, assign) KalturaClientBase* client;
@property (nonatomic, readonly) KalturaAnnotationService* annotation;
@end

