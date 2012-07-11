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
@interface KalturaMetadataObjectType : NSObject
+ (NSString*)ENTRY;
+ (NSString*)ANNOTATION;
+ (NSString*)AD_CUE_POINT;
+ (NSString*)CODE_CUE_POINT;
@end

@interface KalturaMetadataOrderBy : NSObject
+ (NSString*)METADATA_PROFILE_VERSION_ASC;
+ (NSString*)METADATA_PROFILE_VERSION_DESC;
+ (NSString*)VERSION_ASC;
+ (NSString*)VERSION_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaMetadataProfileCreateMode : NSObject
+ (int)API;
+ (int)KMC;
@end

@interface KalturaMetadataProfileOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaMetadataProfileStatus : NSObject
+ (int)ACTIVE;
+ (int)DEPRECATED;
+ (int)TRANSFORMING;
@end

@interface KalturaMetadataStatus : NSObject
+ (int)VALID;
+ (int)INVALID;
+ (int)DELETED;
@end

///////////////////////// classes /////////////////////////
@interface KalturaCompareMetadataCondition : KalturaCompareCondition
// May contain the full xpath to the field in two formats
@property (nonatomic,copy) NSString* xPath;
// Metadata profile id
@property (nonatomic,assign) int profileId;
- (KalturaFieldType)getTypeOfXPath;
- (KalturaFieldType)getTypeOfProfileId;
- (void)setProfileIdFromString:(NSString*)aPropVal;
@end

@interface KalturaMatchMetadataCondition : KalturaMatchCondition
// May contain the full xpath to the field in two formats
@property (nonatomic,copy) NSString* xPath;
// Metadata profile id
@property (nonatomic,assign) int profileId;
- (KalturaFieldType)getTypeOfXPath;
- (KalturaFieldType)getTypeOfProfileId;
- (void)setProfileIdFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataSearchItem : KalturaSearchOperator
@property (nonatomic,assign) int metadataProfileId;
@property (nonatomic,copy) NSString* orderBy;
- (KalturaFieldType)getTypeOfMetadataProfileId;
- (KalturaFieldType)getTypeOfOrderBy;
- (void)setMetadataProfileIdFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataBaseFilter : KalturaFilter
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,assign) int metadataProfileIdEqual;
@property (nonatomic,assign) int metadataProfileVersionEqual;
@property (nonatomic,assign) int metadataProfileVersionGreaterThanOrEqual;
@property (nonatomic,assign) int metadataProfileVersionLessThanOrEqual;
@property (nonatomic,copy) NSString* metadataObjectTypeEqual;	// enum KalturaMetadataObjectType
@property (nonatomic,copy) NSString* objectIdEqual;
@property (nonatomic,copy) NSString* objectIdIn;
@property (nonatomic,assign) int versionEqual;
@property (nonatomic,assign) int versionGreaterThanOrEqual;
@property (nonatomic,assign) int versionLessThanOrEqual;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int statusEqual;	// enum KalturaMetadataStatus
@property (nonatomic,copy) NSString* statusIn;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfMetadataProfileIdEqual;
- (KalturaFieldType)getTypeOfMetadataProfileVersionEqual;
- (KalturaFieldType)getTypeOfMetadataProfileVersionGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfMetadataProfileVersionLessThanOrEqual;
- (KalturaFieldType)getTypeOfMetadataObjectTypeEqual;
- (KalturaFieldType)getTypeOfObjectIdEqual;
- (KalturaFieldType)getTypeOfObjectIdIn;
- (KalturaFieldType)getTypeOfVersionEqual;
- (KalturaFieldType)getTypeOfVersionGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfVersionLessThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setMetadataProfileIdEqualFromString:(NSString*)aPropVal;
- (void)setMetadataProfileVersionEqualFromString:(NSString*)aPropVal;
- (void)setMetadataProfileVersionGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setMetadataProfileVersionLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setVersionEqualFromString:(NSString*)aPropVal;
- (void)setVersionGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setVersionLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataFilter : KalturaMetadataBaseFilter
@end

@interface KalturaMetadataProfileBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* metadataObjectTypeEqual;	// enum KalturaMetadataObjectType
@property (nonatomic,assign) int versionEqual;
@property (nonatomic,copy) NSString* nameEqual;
@property (nonatomic,copy) NSString* systemNameEqual;
@property (nonatomic,copy) NSString* systemNameIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int statusEqual;	// enum KalturaMetadataProfileStatus
@property (nonatomic,copy) NSString* statusIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfMetadataObjectTypeEqual;
- (KalturaFieldType)getTypeOfVersionEqual;
- (KalturaFieldType)getTypeOfNameEqual;
- (KalturaFieldType)getTypeOfSystemNameEqual;
- (KalturaFieldType)getTypeOfSystemNameIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setVersionEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataProfileFilter : KalturaMetadataProfileBaseFilter
@end

@interface KalturaMetadata : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,assign,readonly) int metadataProfileId;
@property (nonatomic,assign,readonly) int metadataProfileVersion;
@property (nonatomic,copy,readonly) NSString* metadataObjectType;	// enum KalturaMetadataObjectType
@property (nonatomic,copy,readonly) NSString* objectId;
@property (nonatomic,assign,readonly) int version;
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,assign,readonly) int status;	// enum KalturaMetadataStatus
@property (nonatomic,copy,readonly) NSString* xml;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfMetadataProfileId;
- (KalturaFieldType)getTypeOfMetadataProfileVersion;
- (KalturaFieldType)getTypeOfMetadataObjectType;
- (KalturaFieldType)getTypeOfObjectId;
- (KalturaFieldType)getTypeOfVersion;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfXml;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setMetadataProfileIdFromString:(NSString*)aPropVal;
- (void)setMetadataProfileVersionFromString:(NSString*)aPropVal;
- (void)setVersionFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaMetadata elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataProfile : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* metadataObjectType;	// enum KalturaMetadataObjectType
@property (nonatomic,assign,readonly) int version;
@property (nonatomic,copy) NSString* name;
@property (nonatomic,copy) NSString* systemName;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,assign,readonly) int status;	// enum KalturaMetadataProfileStatus
@property (nonatomic,copy,readonly) NSString* xsd;
@property (nonatomic,copy,readonly) NSString* views;
@property (nonatomic,copy,readonly) NSString* xslt;
@property (nonatomic,assign) int createMode;	// enum KalturaMetadataProfileCreateMode
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfMetadataObjectType;
- (KalturaFieldType)getTypeOfVersion;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfSystemName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfXsd;
- (KalturaFieldType)getTypeOfViews;
- (KalturaFieldType)getTypeOfXslt;
- (KalturaFieldType)getTypeOfCreateMode;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setVersionFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setCreateModeFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataProfileListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaMetadataProfile elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataProfileField : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,copy,readonly) NSString* xPath;
@property (nonatomic,copy,readonly) NSString* key;
@property (nonatomic,copy,readonly) NSString* label;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfXPath;
- (KalturaFieldType)getTypeOfKey;
- (KalturaFieldType)getTypeOfLabel;
- (void)setIdFromString:(NSString*)aPropVal;
@end

@interface KalturaMetadataProfileFieldListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaMetadataProfileField elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

///////////////////////// services /////////////////////////
// Metadata service
@interface KalturaMetadataService : KalturaServiceBase
// Allows you to add a metadata object and metadata content associated with Kaltura object
- (KalturaMetadata*)addWithMetadataProfileId:(int)aMetadataProfileId withObjectType:(NSString*)aObjectType withObjectId:(NSString*)aObjectId withXmlData:(NSString*)aXmlData;
// Allows you to add a metadata object and metadata file associated with Kaltura object
- (KalturaMetadata*)addFromFileWithMetadataProfileId:(int)aMetadataProfileId withObjectType:(NSString*)aObjectType withObjectId:(NSString*)aObjectId withXmlFile:(NSString*)aXmlFile;
// Allows you to add a metadata xml data from remote URL
- (KalturaMetadata*)addFromUrlWithMetadataProfileId:(int)aMetadataProfileId withObjectType:(NSString*)aObjectType withObjectId:(NSString*)aObjectId withUrl:(NSString*)aUrl;
// Allows you to add a metadata xml data from remote URL.
// Enables different permissions than addFromUrl action.
- (KalturaMetadata*)addFromBulkWithMetadataProfileId:(int)aMetadataProfileId withObjectType:(NSString*)aObjectType withObjectId:(NSString*)aObjectId withUrl:(NSString*)aUrl;
// Retrieve a metadata object by id
- (KalturaMetadata*)getWithId:(int)aId;
// Update an existing metadata object with new XML content
- (KalturaMetadata*)updateWithId:(int)aId withXmlData:(NSString*)aXmlData withVersion:(int)aVersion;
- (KalturaMetadata*)updateWithId:(int)aId withXmlData:(NSString*)aXmlData;
- (KalturaMetadata*)updateWithId:(int)aId;
// Update an existing metadata object with new XML file
- (KalturaMetadata*)updateFromFileWithId:(int)aId withXmlFile:(NSString*)aXmlFile;
- (KalturaMetadata*)updateFromFileWithId:(int)aId;
// List metadata objects by filter and pager
- (KalturaMetadataListResponse*)listWithFilter:(KalturaMetadataFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaMetadataListResponse*)listWithFilter:(KalturaMetadataFilter*)aFilter;
- (KalturaMetadataListResponse*)list;
// Delete an existing metadata
- (void)deleteWithId:(int)aId;
// Mark existing metadata as invalid
// Used by batch metadata transform
- (void)invalidateWithId:(int)aId withVersion:(int)aVersion;
- (void)invalidateWithId:(int)aId;
// Serves metadata XML file
- (NSString*)serveWithId:(int)aId;
@end

// Metadata Profile service
@interface KalturaMetadataProfileService : KalturaServiceBase
// Allows you to add a metadata profile object and metadata profile content associated with Kaltura object type
- (KalturaMetadataProfile*)addWithMetadataProfile:(KalturaMetadataProfile*)aMetadataProfile withXsdData:(NSString*)aXsdData withViewsData:(NSString*)aViewsData;
- (KalturaMetadataProfile*)addWithMetadataProfile:(KalturaMetadataProfile*)aMetadataProfile withXsdData:(NSString*)aXsdData;
// Allows you to add a metadata profile object and metadata profile file associated with Kaltura object type
- (KalturaMetadataProfile*)addFromFileWithMetadataProfile:(KalturaMetadataProfile*)aMetadataProfile withXsdFile:(NSString*)aXsdFile withViewsFile:(NSString*)aViewsFile;
- (KalturaMetadataProfile*)addFromFileWithMetadataProfile:(KalturaMetadataProfile*)aMetadataProfile withXsdFile:(NSString*)aXsdFile;
// Retrieve a metadata profile object by id
- (KalturaMetadataProfile*)getWithId:(int)aId;
// Update an existing metadata object
- (KalturaMetadataProfile*)updateWithId:(int)aId withMetadataProfile:(KalturaMetadataProfile*)aMetadataProfile withXsdData:(NSString*)aXsdData withViewsData:(NSString*)aViewsData;
- (KalturaMetadataProfile*)updateWithId:(int)aId withMetadataProfile:(KalturaMetadataProfile*)aMetadataProfile withXsdData:(NSString*)aXsdData;
- (KalturaMetadataProfile*)updateWithId:(int)aId withMetadataProfile:(KalturaMetadataProfile*)aMetadataProfile;
// List metadata profile objects by filter and pager
- (KalturaMetadataProfileListResponse*)listWithFilter:(KalturaMetadataProfileFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaMetadataProfileListResponse*)listWithFilter:(KalturaMetadataProfileFilter*)aFilter;
- (KalturaMetadataProfileListResponse*)list;
// List metadata profile fields by metadata profile id
- (KalturaMetadataProfileFieldListResponse*)listFieldsWithMetadataProfileId:(int)aMetadataProfileId;
// Delete an existing metadata profile
- (void)deleteWithId:(int)aId;
// Update an existing metadata object definition file
- (KalturaMetadataProfile*)revertWithId:(int)aId withToVersion:(int)aToVersion;
// Update an existing metadata object definition file
- (KalturaMetadataProfile*)updateDefinitionFromFileWithId:(int)aId withXsdFile:(NSString*)aXsdFile;
// Update an existing metadata object views file
- (KalturaMetadataProfile*)updateViewsFromFileWithId:(int)aId withViewsFile:(NSString*)aViewsFile;
// Update an existing metadata object xslt file
- (KalturaMetadataProfile*)updateTransformationFromFileWithId:(int)aId withXsltFile:(NSString*)aXsltFile;
// Serves metadata profile XSD file
- (NSString*)serveWithId:(int)aId;
// Serves metadata profile view file
- (NSString*)serveViewWithId:(int)aId;
@end

@interface KalturaMetadataClientPlugin : KalturaClientPlugin
{
	KalturaMetadataService* _metadata;
	KalturaMetadataProfileService* _metadataProfile;
}

@property (nonatomic, assign) KalturaClientBase* client;
@property (nonatomic, readonly) KalturaMetadataService* metadata;
@property (nonatomic, readonly) KalturaMetadataProfileService* metadataProfile;
@end

