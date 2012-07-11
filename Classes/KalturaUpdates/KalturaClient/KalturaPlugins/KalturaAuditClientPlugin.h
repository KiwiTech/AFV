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

///////////////////////// enums /////////////////////////
@interface KalturaAuditTrailAction : NSObject
+ (NSString*)CREATED;
+ (NSString*)COPIED;
+ (NSString*)CHANGED;
+ (NSString*)DELETED;
+ (NSString*)VIEWED;
+ (NSString*)CONTENT_VIEWED;
+ (NSString*)FILE_SYNC_CREATED;
+ (NSString*)RELATION_ADDED;
+ (NSString*)RELATION_REMOVED;
@end

@interface KalturaAuditTrailChangeXmlNodeType : NSObject
+ (int)CHANGED;
+ (int)ADDED;
+ (int)REMOVED;
@end

@interface KalturaAuditTrailContext : NSObject
+ (int)CLIENT;
+ (int)SCRIPT;
+ (int)PS2;
+ (int)API_V3;
@end

@interface KalturaAuditTrailFileSyncType : NSObject
+ (int)FILE;
+ (int)LINK;
+ (int)URL;
@end

@interface KalturaAuditTrailObjectType : NSObject
+ (NSString*)ACCESS_CONTROL;
+ (NSString*)ADMIN_KUSER;
+ (NSString*)BATCH_JOB;
+ (NSString*)CATEGORY;
+ (NSString*)CONVERSION_PROFILE_2;
+ (NSString*)EMAIL_INGESTION_PROFILE;
+ (NSString*)ENTRY;
+ (NSString*)FILE_SYNC;
+ (NSString*)FLAVOR_ASSET;
+ (NSString*)THUMBNAIL_ASSET;
+ (NSString*)FLAVOR_PARAMS;
+ (NSString*)THUMBNAIL_PARAMS;
+ (NSString*)FLAVOR_PARAMS_CONVERSION_PROFILE;
+ (NSString*)FLAVOR_PARAMS_OUTPUT;
+ (NSString*)THUMBNAIL_PARAMS_OUTPUT;
+ (NSString*)KSHOW;
+ (NSString*)KSHOW_KUSER;
+ (NSString*)KUSER;
+ (NSString*)MEDIA_INFO;
+ (NSString*)MODERATION;
+ (NSString*)PARTNER;
+ (NSString*)ROUGHCUT;
+ (NSString*)SYNDICATION;
+ (NSString*)UI_CONF;
+ (NSString*)UPLOAD_TOKEN;
+ (NSString*)WIDGET;
+ (NSString*)METADATA;
+ (NSString*)METADATA_PROFILE;
+ (NSString*)USER_LOGIN_DATA;
+ (NSString*)USER_ROLE;
+ (NSString*)PERMISSION;
@end

@interface KalturaAuditTrailOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)PARSED_AT_ASC;
+ (NSString*)PARSED_AT_DESC;
@end

@interface KalturaAuditTrailStatus : NSObject
+ (int)PENDING;
+ (int)READY;
+ (int)FAILED;
@end

///////////////////////// classes /////////////////////////
@interface KalturaAuditTrailBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int parsedAtGreaterThanOrEqual;
@property (nonatomic,assign) int parsedAtLessThanOrEqual;
@property (nonatomic,assign) int statusEqual;	// enum KalturaAuditTrailStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,copy) NSString* auditObjectTypeEqual;	// enum KalturaAuditTrailObjectType
@property (nonatomic,copy) NSString* auditObjectTypeIn;
@property (nonatomic,copy) NSString* objectIdEqual;
@property (nonatomic,copy) NSString* objectIdIn;
@property (nonatomic,copy) NSString* relatedObjectIdEqual;
@property (nonatomic,copy) NSString* relatedObjectIdIn;
@property (nonatomic,copy) NSString* relatedObjectTypeEqual;	// enum KalturaAuditTrailObjectType
@property (nonatomic,copy) NSString* relatedObjectTypeIn;
@property (nonatomic,copy) NSString* entryIdEqual;
@property (nonatomic,copy) NSString* entryIdIn;
@property (nonatomic,assign) int masterPartnerIdEqual;
@property (nonatomic,copy) NSString* masterPartnerIdIn;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,copy) NSString* requestIdEqual;
@property (nonatomic,copy) NSString* requestIdIn;
@property (nonatomic,copy) NSString* userIdEqual;
@property (nonatomic,copy) NSString* userIdIn;
@property (nonatomic,copy) NSString* actionEqual;	// enum KalturaAuditTrailAction
@property (nonatomic,copy) NSString* actionIn;
@property (nonatomic,copy) NSString* ksEqual;
@property (nonatomic,assign) int contextEqual;	// enum KalturaAuditTrailContext
@property (nonatomic,copy) NSString* contextIn;
@property (nonatomic,copy) NSString* entryPointEqual;
@property (nonatomic,copy) NSString* entryPointIn;
@property (nonatomic,copy) NSString* serverNameEqual;
@property (nonatomic,copy) NSString* serverNameIn;
@property (nonatomic,copy) NSString* ipAddressEqual;
@property (nonatomic,copy) NSString* ipAddressIn;
@property (nonatomic,copy) NSString* clientTagEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfParsedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfParsedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfAuditObjectTypeEqual;
- (KalturaFieldType)getTypeOfAuditObjectTypeIn;
- (KalturaFieldType)getTypeOfObjectIdEqual;
- (KalturaFieldType)getTypeOfObjectIdIn;
- (KalturaFieldType)getTypeOfRelatedObjectIdEqual;
- (KalturaFieldType)getTypeOfRelatedObjectIdIn;
- (KalturaFieldType)getTypeOfRelatedObjectTypeEqual;
- (KalturaFieldType)getTypeOfRelatedObjectTypeIn;
- (KalturaFieldType)getTypeOfEntryIdEqual;
- (KalturaFieldType)getTypeOfEntryIdIn;
- (KalturaFieldType)getTypeOfMasterPartnerIdEqual;
- (KalturaFieldType)getTypeOfMasterPartnerIdIn;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfRequestIdEqual;
- (KalturaFieldType)getTypeOfRequestIdIn;
- (KalturaFieldType)getTypeOfUserIdEqual;
- (KalturaFieldType)getTypeOfUserIdIn;
- (KalturaFieldType)getTypeOfActionEqual;
- (KalturaFieldType)getTypeOfActionIn;
- (KalturaFieldType)getTypeOfKsEqual;
- (KalturaFieldType)getTypeOfContextEqual;
- (KalturaFieldType)getTypeOfContextIn;
- (KalturaFieldType)getTypeOfEntryPointEqual;
- (KalturaFieldType)getTypeOfEntryPointIn;
- (KalturaFieldType)getTypeOfServerNameEqual;
- (KalturaFieldType)getTypeOfServerNameIn;
- (KalturaFieldType)getTypeOfIpAddressEqual;
- (KalturaFieldType)getTypeOfIpAddressIn;
- (KalturaFieldType)getTypeOfClientTagEqual;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setParsedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setParsedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
- (void)setMasterPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setContextEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaAuditTrailFilter : KalturaAuditTrailBaseFilter
@end

@interface KalturaAuditTrailInfo : KalturaObjectBase
@end

@interface KalturaAuditTrailChangeItem : KalturaObjectBase
@property (nonatomic,copy) NSString* descriptor;
@property (nonatomic,copy) NSString* oldValue;
@property (nonatomic,copy) NSString* newValue;
- (KalturaFieldType)getTypeOfDescriptor;
- (KalturaFieldType)getTypeOfOldValue;
- (KalturaFieldType)getTypeOfNewValue;
@end

@interface KalturaAuditTrailChangeXmlNode : KalturaAuditTrailChangeItem
@property (nonatomic,assign) int type;	// enum KalturaAuditTrailChangeXmlNodeType
- (KalturaFieldType)getTypeOfType;
- (void)setTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaAuditTrailChangeInfo : KalturaAuditTrailInfo
@property (nonatomic,retain) NSMutableArray* changedItems;	// of KalturaAuditTrailChangeItem elements
- (KalturaFieldType)getTypeOfChangedItems;
- (NSString*)getObjectTypeOfChangedItems;
@end

@interface KalturaAuditTrailFileSyncCreateInfo : KalturaAuditTrailInfo
@property (nonatomic,copy) NSString* version;
@property (nonatomic,assign) int objectSubType;
@property (nonatomic,assign) int dc;
@property (nonatomic,assign) BOOL original;
@property (nonatomic,assign) int fileType;	// enum KalturaAuditTrailFileSyncType
- (KalturaFieldType)getTypeOfVersion;
- (KalturaFieldType)getTypeOfObjectSubType;
- (KalturaFieldType)getTypeOfDc;
- (KalturaFieldType)getTypeOfOriginal;
- (KalturaFieldType)getTypeOfFileType;
- (void)setObjectSubTypeFromString:(NSString*)aPropVal;
- (void)setDcFromString:(NSString*)aPropVal;
- (void)setOriginalFromString:(NSString*)aPropVal;
- (void)setFileTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaAuditTrailTextInfo : KalturaAuditTrailInfo
@property (nonatomic,copy) NSString* info;
- (KalturaFieldType)getTypeOfInfo;
@end

@interface KalturaAuditTrail : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int createdAt;
// Indicates when the data was parsed
@property (nonatomic,assign,readonly) int parsedAt;
@property (nonatomic,assign,readonly) int status;	// enum KalturaAuditTrailStatus
@property (nonatomic,copy) NSString* auditObjectType;	// enum KalturaAuditTrailObjectType
@property (nonatomic,copy) NSString* objectId;
@property (nonatomic,copy) NSString* relatedObjectId;
@property (nonatomic,copy) NSString* relatedObjectType;	// enum KalturaAuditTrailObjectType
@property (nonatomic,copy) NSString* entryId;
@property (nonatomic,assign,readonly) int masterPartnerId;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy,readonly) NSString* requestId;
@property (nonatomic,copy) NSString* userId;
@property (nonatomic,copy) NSString* action;	// enum KalturaAuditTrailAction
@property (nonatomic,retain) KalturaAuditTrailInfo* data;
@property (nonatomic,copy,readonly) NSString* ks;
@property (nonatomic,assign,readonly) int context;	// enum KalturaAuditTrailContext
// The API service and action that called and caused this audit
@property (nonatomic,copy,readonly) NSString* entryPoint;
@property (nonatomic,copy,readonly) NSString* serverName;
@property (nonatomic,copy,readonly) NSString* ipAddress;
@property (nonatomic,copy,readonly) NSString* userAgent;
@property (nonatomic,copy) NSString* clientTag;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,copy,readonly) NSString* errorDescription;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfParsedAt;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfAuditObjectType;
- (KalturaFieldType)getTypeOfObjectId;
- (KalturaFieldType)getTypeOfRelatedObjectId;
- (KalturaFieldType)getTypeOfRelatedObjectType;
- (KalturaFieldType)getTypeOfEntryId;
- (KalturaFieldType)getTypeOfMasterPartnerId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfRequestId;
- (KalturaFieldType)getTypeOfUserId;
- (KalturaFieldType)getTypeOfAction;
- (KalturaFieldType)getTypeOfData;
- (NSString*)getObjectTypeOfData;
- (KalturaFieldType)getTypeOfKs;
- (KalturaFieldType)getTypeOfContext;
- (KalturaFieldType)getTypeOfEntryPoint;
- (KalturaFieldType)getTypeOfServerName;
- (KalturaFieldType)getTypeOfIpAddress;
- (KalturaFieldType)getTypeOfUserAgent;
- (KalturaFieldType)getTypeOfClientTag;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfErrorDescription;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setParsedAtFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setMasterPartnerIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setContextFromString:(NSString*)aPropVal;
@end

@interface KalturaAuditTrailListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaAuditTrail elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

///////////////////////// services /////////////////////////
// Audit Trail service
@interface KalturaAuditTrailService : KalturaServiceBase
// Allows you to add an audit trail object and audit trail content associated with Kaltura object
- (KalturaAuditTrail*)addWithAuditTrail:(KalturaAuditTrail*)aAuditTrail;
// Retrieve an audit trail object by id
- (KalturaAuditTrail*)getWithId:(int)aId;
// List audit trail objects by filter and pager
- (KalturaAuditTrailListResponse*)listWithFilter:(KalturaAuditTrailFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaAuditTrailListResponse*)listWithFilter:(KalturaAuditTrailFilter*)aFilter;
- (KalturaAuditTrailListResponse*)list;
@end

@interface KalturaAuditClientPlugin : KalturaClientPlugin
{
	KalturaAuditTrailService* _auditTrail;
}

@property (nonatomic, assign) KalturaClientBase* client;
@property (nonatomic, readonly) KalturaAuditTrailService* auditTrail;
@end

