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
#import "KalturaMetadataClientPlugin.h"

///////////////////////// enums /////////////////////////
@interface KalturaConfigurableDistributionProfileOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaDistributionAction : NSObject
+ (int)SUBMIT;
+ (int)UPDATE;
+ (int)DELETE;
+ (int)FETCH_REPORT;
@end

@interface KalturaDistributionErrorType : NSObject
+ (int)MISSING_FLAVOR;
+ (int)MISSING_THUMBNAIL;
+ (int)MISSING_METADATA;
+ (int)INVALID_DATA;
@end

@interface KalturaDistributionFieldRequiredStatus : NSObject
+ (int)NOT_REQUIRED;
+ (int)REQUIRED_BY_PROVIDER;
+ (int)REQUIRED_BY_PARTNER;
@end

@interface KalturaDistributionProfileActionStatus : NSObject
+ (int)DISABLED;
+ (int)AUTOMATIC;
+ (int)MANUAL;
@end

@interface KalturaDistributionProfileOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaDistributionProfileStatus : NSObject
+ (int)DISABLED;
+ (int)ENABLED;
+ (int)DELETED;
@end

@interface KalturaDistributionProtocol : NSObject
+ (int)FTP;
+ (int)SCP;
+ (int)SFTP;
+ (int)HTTP;
+ (int)HTTPS;
@end

@interface KalturaDistributionProviderOrderBy : NSObject
@end

@interface KalturaDistributionProviderType : NSObject
+ (NSString*)GENERIC;
+ (NSString*)SYNDICATION;
+ (NSString*)MSN;
+ (NSString*)YOUTUBE;
+ (NSString*)YOUTUBE_API;
+ (NSString*)DAILYMOTION;
+ (NSString*)PODCAST;
+ (NSString*)TVCOM;
+ (NSString*)FREEWHEEL;
+ (NSString*)FREEWHEEL_GENERIC;
+ (NSString*)HULU;
+ (NSString*)DOUBLECLICK;
+ (NSString*)SYNACOR_HBO;
+ (NSString*)AVN;
+ (NSString*)COMCAST_MRSS;
+ (NSString*)IDETIC;
+ (NSString*)TIME_WARNER;
+ (NSString*)YAHOO;
+ (NSString*)NDN;
+ (NSString*)UVERSE;
+ (NSString*)VERIZON_VCAST;
+ (NSString*)QUICKPLAY;
+ (NSString*)FTP;
+ (NSString*)FTP_SCHEDULED;
+ (NSString*)ATT_UVERSE;
@end

@interface KalturaDistributionValidationErrorType : NSObject
+ (int)CUSTOM_ERROR;
+ (int)STRING_EMPTY;
+ (int)STRING_TOO_LONG;
+ (int)STRING_TOO_SHORT;
+ (int)INVALID_FORMAT;
@end

@interface KalturaEntryDistributionFlag : NSObject
+ (int)NONE;
+ (int)SUBMIT_REQUIRED;
+ (int)DELETE_REQUIRED;
+ (int)UPDATE_REQUIRED;
+ (int)ENABLE_REQUIRED;
+ (int)DISABLE_REQUIRED;
@end

@interface KalturaEntryDistributionOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)SUBMITTED_AT_ASC;
+ (NSString*)SUBMITTED_AT_DESC;
+ (NSString*)SUNRISE_ASC;
+ (NSString*)SUNRISE_DESC;
+ (NSString*)SUNSET_ASC;
+ (NSString*)SUNSET_DESC;
@end

@interface KalturaEntryDistributionStatus : NSObject
+ (int)PENDING;
+ (int)QUEUED;
+ (int)READY;
+ (int)DELETED;
+ (int)SUBMITTING;
+ (int)UPDATING;
+ (int)DELETING;
+ (int)ERROR_SUBMITTING;
+ (int)ERROR_UPDATING;
+ (int)ERROR_DELETING;
+ (int)REMOVED;
+ (int)IMPORT_SUBMITTING;
+ (int)IMPORT_UPDATING;
@end

@interface KalturaEntryDistributionSunStatus : NSObject
+ (int)BEFORE_SUNRISE;
+ (int)AFTER_SUNRISE;
+ (int)AFTER_SUNSET;
@end

@interface KalturaGenericDistributionProfileOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaGenericDistributionProviderActionOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaGenericDistributionProviderOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaGenericDistributionProviderParser : NSObject
+ (int)XSL;
+ (int)XPATH;
+ (int)REGEX;
@end

@interface KalturaGenericDistributionProviderStatus : NSObject
+ (int)ACTIVE;
+ (int)DELETED;
@end

@interface KalturaSyndicationDistributionProfileOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaSyndicationDistributionProviderOrderBy : NSObject
@end

///////////////////////// classes /////////////////////////
@interface KalturaContentDistributionSearchItem : KalturaSearchItem
@property (nonatomic,assign) BOOL noDistributionProfiles;
@property (nonatomic,assign) int distributionProfileId;
@property (nonatomic,assign) int distributionSunStatus;	// enum KalturaEntryDistributionSunStatus
@property (nonatomic,assign) int entryDistributionFlag;	// enum KalturaEntryDistributionFlag
@property (nonatomic,assign) int entryDistributionStatus;	// enum KalturaEntryDistributionStatus
@property (nonatomic,assign) BOOL hasEntryDistributionValidationErrors;
// Comma seperated validation error types
@property (nonatomic,copy) NSString* entryDistributionValidationErrors;
- (KalturaFieldType)getTypeOfNoDistributionProfiles;
- (KalturaFieldType)getTypeOfDistributionProfileId;
- (KalturaFieldType)getTypeOfDistributionSunStatus;
- (KalturaFieldType)getTypeOfEntryDistributionFlag;
- (KalturaFieldType)getTypeOfEntryDistributionStatus;
- (KalturaFieldType)getTypeOfHasEntryDistributionValidationErrors;
- (KalturaFieldType)getTypeOfEntryDistributionValidationErrors;
- (void)setNoDistributionProfilesFromString:(NSString*)aPropVal;
- (void)setDistributionProfileIdFromString:(NSString*)aPropVal;
- (void)setDistributionSunStatusFromString:(NSString*)aPropVal;
- (void)setEntryDistributionFlagFromString:(NSString*)aPropVal;
- (void)setEntryDistributionStatusFromString:(NSString*)aPropVal;
- (void)setHasEntryDistributionValidationErrorsFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionProfileBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int statusEqual;	// enum KalturaDistributionProfileStatus
@property (nonatomic,copy) NSString* statusIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionProfileFilter : KalturaDistributionProfileBaseFilter
@end

@interface KalturaConfigurableDistributionProfileBaseFilter : KalturaDistributionProfileFilter
@end

@interface KalturaConfigurableDistributionProfileFilter : KalturaConfigurableDistributionProfileBaseFilter
@end

@interface KalturaGenericDistributionProfileBaseFilter : KalturaDistributionProfileFilter
@end

@interface KalturaGenericDistributionProfileFilter : KalturaGenericDistributionProfileBaseFilter
@end

@interface KalturaSyndicationDistributionProfileBaseFilter : KalturaDistributionProfileFilter
@end

@interface KalturaSyndicationDistributionProfileFilter : KalturaSyndicationDistributionProfileBaseFilter
@end

@interface KalturaDistributionProviderBaseFilter : KalturaFilter
@property (nonatomic,copy) NSString* typeEqual;	// enum KalturaDistributionProviderType
@property (nonatomic,copy) NSString* typeIn;
- (KalturaFieldType)getTypeOfTypeEqual;
- (KalturaFieldType)getTypeOfTypeIn;
@end

@interface KalturaDistributionProviderFilter : KalturaDistributionProviderBaseFilter
@end

@interface KalturaGenericDistributionProviderBaseFilter : KalturaDistributionProviderFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,assign) BOOL isDefaultEqual;
@property (nonatomic,copy) NSString* isDefaultIn;
@property (nonatomic,assign) int statusEqual;	// enum KalturaGenericDistributionProviderStatus
@property (nonatomic,copy) NSString* statusIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfIsDefaultEqual;
- (KalturaFieldType)getTypeOfIsDefaultIn;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setIsDefaultEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaGenericDistributionProviderFilter : KalturaGenericDistributionProviderBaseFilter
@end

@interface KalturaSyndicationDistributionProviderBaseFilter : KalturaDistributionProviderFilter
@end

@interface KalturaSyndicationDistributionProviderFilter : KalturaSyndicationDistributionProviderBaseFilter
@end

@interface KalturaEntryDistributionBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int submittedAtGreaterThanOrEqual;
@property (nonatomic,assign) int submittedAtLessThanOrEqual;
@property (nonatomic,copy) NSString* entryIdEqual;
@property (nonatomic,copy) NSString* entryIdIn;
@property (nonatomic,assign) int distributionProfileIdEqual;
@property (nonatomic,copy) NSString* distributionProfileIdIn;
@property (nonatomic,assign) int statusEqual;	// enum KalturaEntryDistributionStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,assign) int dirtyStatusEqual;	// enum KalturaEntryDistributionFlag
@property (nonatomic,copy) NSString* dirtyStatusIn;
@property (nonatomic,assign) int sunriseGreaterThanOrEqual;
@property (nonatomic,assign) int sunriseLessThanOrEqual;
@property (nonatomic,assign) int sunsetGreaterThanOrEqual;
@property (nonatomic,assign) int sunsetLessThanOrEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfSubmittedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfSubmittedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfEntryIdEqual;
- (KalturaFieldType)getTypeOfEntryIdIn;
- (KalturaFieldType)getTypeOfDistributionProfileIdEqual;
- (KalturaFieldType)getTypeOfDistributionProfileIdIn;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfDirtyStatusEqual;
- (KalturaFieldType)getTypeOfDirtyStatusIn;
- (KalturaFieldType)getTypeOfSunriseGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfSunriseLessThanOrEqual;
- (KalturaFieldType)getTypeOfSunsetGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfSunsetLessThanOrEqual;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setSubmittedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setSubmittedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setDistributionProfileIdEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
- (void)setDirtyStatusEqualFromString:(NSString*)aPropVal;
- (void)setSunriseGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setSunriseLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setSunsetGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setSunsetLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaEntryDistributionFilter : KalturaEntryDistributionBaseFilter
@end

@interface KalturaGenericDistributionProviderActionBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int genericDistributionProviderIdEqual;
@property (nonatomic,copy) NSString* genericDistributionProviderIdIn;
@property (nonatomic,assign) int actionEqual;	// enum KalturaDistributionAction
@property (nonatomic,copy) NSString* actionIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfGenericDistributionProviderIdEqual;
- (KalturaFieldType)getTypeOfGenericDistributionProviderIdIn;
- (KalturaFieldType)getTypeOfActionEqual;
- (KalturaFieldType)getTypeOfActionIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setGenericDistributionProviderIdEqualFromString:(NSString*)aPropVal;
- (void)setActionEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaGenericDistributionProviderActionFilter : KalturaGenericDistributionProviderActionBaseFilter
@end

@interface KalturaDistributionThumbDimensions : KalturaObjectBase
@property (nonatomic,assign) int width;
@property (nonatomic,assign) int height;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionProfile : KalturaObjectBase
// Auto generated unique id
@property (nonatomic,assign,readonly) int id;
// Profile creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Profile last update date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* providerType;	// enum KalturaDistributionProviderType, insertonly
@property (nonatomic,copy) NSString* name;
@property (nonatomic,assign) int status;	// enum KalturaDistributionProfileStatus
@property (nonatomic,assign) int submitEnabled;	// enum KalturaDistributionProfileActionStatus
@property (nonatomic,assign) int updateEnabled;	// enum KalturaDistributionProfileActionStatus
@property (nonatomic,assign) int deleteEnabled;	// enum KalturaDistributionProfileActionStatus
@property (nonatomic,assign) int reportEnabled;	// enum KalturaDistributionProfileActionStatus
// Comma separated flavor params ids that should be auto converted
@property (nonatomic,copy) NSString* autoCreateFlavors;
// Comma separated thumbnail params ids that should be auto generated
@property (nonatomic,copy) NSString* autoCreateThumb;
// Comma separated flavor params ids that should be submitted if ready
@property (nonatomic,copy) NSString* optionalFlavorParamsIds;
// Comma separated flavor params ids that required to be readt before submission
@property (nonatomic,copy) NSString* requiredFlavorParamsIds;
// Thumbnail dimensions that should be submitted if ready
@property (nonatomic,retain) NSMutableArray* optionalThumbDimensions;	// of KalturaDistributionThumbDimensions elements
// Thumbnail dimensions that required to be readt before submission
@property (nonatomic,retain) NSMutableArray* requiredThumbDimensions;	// of KalturaDistributionThumbDimensions elements
// If entry distribution sunrise not specified that will be the default since entry creation time, in seconds
@property (nonatomic,assign) int sunriseDefaultOffset;
// If entry distribution sunset not specified that will be the default since entry creation time, in seconds
@property (nonatomic,assign) int sunsetDefaultOffset;
// The best Kaltura data center to be used to execute the distribution job
@property (nonatomic,assign) int recommendedDcForExecute;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfProviderType;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfSubmitEnabled;
- (KalturaFieldType)getTypeOfUpdateEnabled;
- (KalturaFieldType)getTypeOfDeleteEnabled;
- (KalturaFieldType)getTypeOfReportEnabled;
- (KalturaFieldType)getTypeOfAutoCreateFlavors;
- (KalturaFieldType)getTypeOfAutoCreateThumb;
- (KalturaFieldType)getTypeOfOptionalFlavorParamsIds;
- (KalturaFieldType)getTypeOfRequiredFlavorParamsIds;
- (KalturaFieldType)getTypeOfOptionalThumbDimensions;
- (NSString*)getObjectTypeOfOptionalThumbDimensions;
- (KalturaFieldType)getTypeOfRequiredThumbDimensions;
- (NSString*)getObjectTypeOfRequiredThumbDimensions;
- (KalturaFieldType)getTypeOfSunriseDefaultOffset;
- (KalturaFieldType)getTypeOfSunsetDefaultOffset;
- (KalturaFieldType)getTypeOfRecommendedDcForExecute;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setSubmitEnabledFromString:(NSString*)aPropVal;
- (void)setUpdateEnabledFromString:(NSString*)aPropVal;
- (void)setDeleteEnabledFromString:(NSString*)aPropVal;
- (void)setReportEnabledFromString:(NSString*)aPropVal;
- (void)setSunriseDefaultOffsetFromString:(NSString*)aPropVal;
- (void)setSunsetDefaultOffsetFromString:(NSString*)aPropVal;
- (void)setRecommendedDcForExecuteFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionFieldConfig : KalturaObjectBase
// A value taken from a connector field enum which associates the current configuration to that connector field
// Field enum class should be returned by the provider's getFieldEnumClass function.
@property (nonatomic,copy) NSString* fieldName;
// A string that will be shown to the user as the field name in error messages related to the current field
@property (nonatomic,copy) NSString* userFriendlyFieldName;
// An XSLT string that extracts the right value from the Kaltura entry MRSS XML.
// The value of the current connector field will be the one that is returned from transforming the Kaltura entry MRSS XML using this XSLT string.
@property (nonatomic,copy) NSString* entryMrssXslt;
// Is the field required to have a value for submission ?
@property (nonatomic,assign) int isRequired;	// enum KalturaDistributionFieldRequiredStatus
// Trigger distribution update when this field changes or not ?
@property (nonatomic,assign) BOOL updateOnChange;
// Entry column or metadata xpath that should trigger an update
// TODO: find a better solution for this
@property (nonatomic,retain) NSMutableArray* updateParams;	// of KalturaString elements
// Is this field config is the default for the distribution provider?
@property (nonatomic,assign,readonly) BOOL isDefault;
- (KalturaFieldType)getTypeOfFieldName;
- (KalturaFieldType)getTypeOfUserFriendlyFieldName;
- (KalturaFieldType)getTypeOfEntryMrssXslt;
- (KalturaFieldType)getTypeOfIsRequired;
- (KalturaFieldType)getTypeOfUpdateOnChange;
- (KalturaFieldType)getTypeOfUpdateParams;
- (NSString*)getObjectTypeOfUpdateParams;
- (KalturaFieldType)getTypeOfIsDefault;
- (void)setIsRequiredFromString:(NSString*)aPropVal;
- (void)setUpdateOnChangeFromString:(NSString*)aPropVal;
- (void)setIsDefaultFromString:(NSString*)aPropVal;
@end

@interface KalturaConfigurableDistributionProfile : KalturaDistributionProfile
@property (nonatomic,retain) NSMutableArray* fieldConfigArray;	// of KalturaDistributionFieldConfig elements
@property (nonatomic,retain) NSMutableArray* itemXpathsToExtend;	// of KalturaString elements
- (KalturaFieldType)getTypeOfFieldConfigArray;
- (NSString*)getObjectTypeOfFieldConfigArray;
- (KalturaFieldType)getTypeOfItemXpathsToExtend;
- (NSString*)getObjectTypeOfItemXpathsToExtend;
@end

@interface KalturaGenericDistributionProfileAction : KalturaObjectBase
@property (nonatomic,assign) int protocol;	// enum KalturaDistributionProtocol
@property (nonatomic,copy) NSString* serverUrl;
@property (nonatomic,copy) NSString* serverPath;
@property (nonatomic,copy) NSString* username;
@property (nonatomic,copy) NSString* password;
@property (nonatomic,assign) BOOL ftpPassiveMode;
@property (nonatomic,copy) NSString* httpFieldName;
@property (nonatomic,copy) NSString* httpFileName;
- (KalturaFieldType)getTypeOfProtocol;
- (KalturaFieldType)getTypeOfServerUrl;
- (KalturaFieldType)getTypeOfServerPath;
- (KalturaFieldType)getTypeOfUsername;
- (KalturaFieldType)getTypeOfPassword;
- (KalturaFieldType)getTypeOfFtpPassiveMode;
- (KalturaFieldType)getTypeOfHttpFieldName;
- (KalturaFieldType)getTypeOfHttpFileName;
- (void)setProtocolFromString:(NSString*)aPropVal;
- (void)setFtpPassiveModeFromString:(NSString*)aPropVal;
@end

@interface KalturaGenericDistributionProfile : KalturaDistributionProfile
@property (nonatomic,assign) int genericProviderId;	// insertonly
@property (nonatomic,retain) KalturaGenericDistributionProfileAction* submitAction;
@property (nonatomic,retain) KalturaGenericDistributionProfileAction* updateAction;
@property (nonatomic,retain) KalturaGenericDistributionProfileAction* deleteAction;
@property (nonatomic,retain) KalturaGenericDistributionProfileAction* fetchReportAction;
@property (nonatomic,copy) NSString* updateRequiredEntryFields;
@property (nonatomic,copy) NSString* updateRequiredMetadataXPaths;
- (KalturaFieldType)getTypeOfGenericProviderId;
- (KalturaFieldType)getTypeOfSubmitAction;
- (NSString*)getObjectTypeOfSubmitAction;
- (KalturaFieldType)getTypeOfUpdateAction;
- (NSString*)getObjectTypeOfUpdateAction;
- (KalturaFieldType)getTypeOfDeleteAction;
- (NSString*)getObjectTypeOfDeleteAction;
- (KalturaFieldType)getTypeOfFetchReportAction;
- (NSString*)getObjectTypeOfFetchReportAction;
- (KalturaFieldType)getTypeOfUpdateRequiredEntryFields;
- (KalturaFieldType)getTypeOfUpdateRequiredMetadataXPaths;
- (void)setGenericProviderIdFromString:(NSString*)aPropVal;
@end

@interface KalturaSyndicationDistributionProfile : KalturaDistributionProfile
@property (nonatomic,copy) NSString* xsl;
@property (nonatomic,copy,readonly) NSString* feedId;
- (KalturaFieldType)getTypeOfXsl;
- (KalturaFieldType)getTypeOfFeedId;
@end

@interface KalturaDistributionProfileListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaDistributionProfile elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionValidationError : KalturaObjectBase
@property (nonatomic,assign) int action;	// enum KalturaDistributionAction
@property (nonatomic,assign) int errorType;	// enum KalturaDistributionErrorType
@property (nonatomic,copy) NSString* description;
- (KalturaFieldType)getTypeOfAction;
- (KalturaFieldType)getTypeOfErrorType;
- (KalturaFieldType)getTypeOfDescription;
- (void)setActionFromString:(NSString*)aPropVal;
- (void)setErrorTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionValidationErrorInvalidData : KalturaDistributionValidationError
@property (nonatomic,copy) NSString* fieldName;
@property (nonatomic,assign) int validationErrorType;	// enum KalturaDistributionValidationErrorType
// Parameter of the validation error
// For example, minimum value for KalturaDistributionValidationErrorType::STRING_TOO_SHORT validation error
@property (nonatomic,copy) NSString* validationErrorParam;
- (KalturaFieldType)getTypeOfFieldName;
- (KalturaFieldType)getTypeOfValidationErrorType;
- (KalturaFieldType)getTypeOfValidationErrorParam;
- (void)setValidationErrorTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionValidationErrorInvalidMetadata : KalturaDistributionValidationErrorInvalidData
@property (nonatomic,assign) int metadataProfileId;
- (KalturaFieldType)getTypeOfMetadataProfileId;
- (void)setMetadataProfileIdFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionValidationErrorMissingFlavor : KalturaDistributionValidationError
@property (nonatomic,copy) NSString* flavorParamsId;
- (KalturaFieldType)getTypeOfFlavorParamsId;
@end

@interface KalturaDistributionValidationErrorMissingMetadata : KalturaDistributionValidationError
@property (nonatomic,copy) NSString* fieldName;
- (KalturaFieldType)getTypeOfFieldName;
@end

@interface KalturaDistributionValidationErrorMissingThumbnail : KalturaDistributionValidationError
@property (nonatomic,retain) KalturaDistributionThumbDimensions* dimensions;
- (KalturaFieldType)getTypeOfDimensions;
- (NSString*)getObjectTypeOfDimensions;
@end

@interface KalturaEntryDistribution : KalturaObjectBase
// Auto generated unique id
@property (nonatomic,assign,readonly) int id;
// Entry distribution creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Entry distribution last update date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
// Entry distribution submission date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int submittedAt;
@property (nonatomic,copy) NSString* entryId;	// insertonly
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,assign) int distributionProfileId;	// insertonly
@property (nonatomic,assign,readonly) int status;	// enum KalturaEntryDistributionStatus
@property (nonatomic,assign,readonly) int sunStatus;	// enum KalturaEntryDistributionSunStatus
@property (nonatomic,assign,readonly) int dirtyStatus;	// enum KalturaEntryDistributionFlag
// Comma separated thumbnail asset ids
@property (nonatomic,copy) NSString* thumbAssetIds;
// Comma separated flavor asset ids
@property (nonatomic,copy) NSString* flavorAssetIds;
// Entry distribution publish time as Unix timestamp (In seconds)
@property (nonatomic,assign) int sunrise;
// Entry distribution un-publish time as Unix timestamp (In seconds)
@property (nonatomic,assign) int sunset;
// The id as returned from the distributed destination
@property (nonatomic,copy,readonly) NSString* remoteId;
// The plays as retrieved from the remote destination reports
@property (nonatomic,assign,readonly) int plays;
// The views as retrieved from the remote destination reports
@property (nonatomic,assign,readonly) int views;
@property (nonatomic,retain) NSMutableArray* validationErrors;	// of KalturaDistributionValidationError elements
@property (nonatomic,assign,readonly) int errorType;	// enum KalturaBatchJobErrorTypes
@property (nonatomic,assign,readonly) int errorNumber;
@property (nonatomic,copy,readonly) NSString* errorDescription;
@property (nonatomic,assign,readonly) int hasSubmitResultsLog;	// enum KalturaNullableBoolean
@property (nonatomic,assign,readonly) int hasSubmitSentDataLog;	// enum KalturaNullableBoolean
@property (nonatomic,assign,readonly) int hasUpdateResultsLog;	// enum KalturaNullableBoolean
@property (nonatomic,assign,readonly) int hasUpdateSentDataLog;	// enum KalturaNullableBoolean
@property (nonatomic,assign,readonly) int hasDeleteResultsLog;	// enum KalturaNullableBoolean
@property (nonatomic,assign,readonly) int hasDeleteSentDataLog;	// enum KalturaNullableBoolean
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfSubmittedAt;
- (KalturaFieldType)getTypeOfEntryId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfDistributionProfileId;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfSunStatus;
- (KalturaFieldType)getTypeOfDirtyStatus;
- (KalturaFieldType)getTypeOfThumbAssetIds;
- (KalturaFieldType)getTypeOfFlavorAssetIds;
- (KalturaFieldType)getTypeOfSunrise;
- (KalturaFieldType)getTypeOfSunset;
- (KalturaFieldType)getTypeOfRemoteId;
- (KalturaFieldType)getTypeOfPlays;
- (KalturaFieldType)getTypeOfViews;
- (KalturaFieldType)getTypeOfValidationErrors;
- (NSString*)getObjectTypeOfValidationErrors;
- (KalturaFieldType)getTypeOfErrorType;
- (KalturaFieldType)getTypeOfErrorNumber;
- (KalturaFieldType)getTypeOfErrorDescription;
- (KalturaFieldType)getTypeOfHasSubmitResultsLog;
- (KalturaFieldType)getTypeOfHasSubmitSentDataLog;
- (KalturaFieldType)getTypeOfHasUpdateResultsLog;
- (KalturaFieldType)getTypeOfHasUpdateSentDataLog;
- (KalturaFieldType)getTypeOfHasDeleteResultsLog;
- (KalturaFieldType)getTypeOfHasDeleteSentDataLog;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setSubmittedAtFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setDistributionProfileIdFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setSunStatusFromString:(NSString*)aPropVal;
- (void)setDirtyStatusFromString:(NSString*)aPropVal;
- (void)setSunriseFromString:(NSString*)aPropVal;
- (void)setSunsetFromString:(NSString*)aPropVal;
- (void)setPlaysFromString:(NSString*)aPropVal;
- (void)setViewsFromString:(NSString*)aPropVal;
- (void)setErrorTypeFromString:(NSString*)aPropVal;
- (void)setErrorNumberFromString:(NSString*)aPropVal;
- (void)setHasSubmitResultsLogFromString:(NSString*)aPropVal;
- (void)setHasSubmitSentDataLogFromString:(NSString*)aPropVal;
- (void)setHasUpdateResultsLogFromString:(NSString*)aPropVal;
- (void)setHasUpdateSentDataLogFromString:(NSString*)aPropVal;
- (void)setHasDeleteResultsLogFromString:(NSString*)aPropVal;
- (void)setHasDeleteSentDataLogFromString:(NSString*)aPropVal;
@end

@interface KalturaEntryDistributionListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaEntryDistribution elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaDistributionProvider : KalturaObjectBase
@property (nonatomic,copy,readonly) NSString* type;	// enum KalturaDistributionProviderType
@property (nonatomic,copy) NSString* name;
@property (nonatomic,assign) BOOL scheduleUpdateEnabled;
@property (nonatomic,assign) BOOL availabilityUpdateEnabled;
@property (nonatomic,assign) BOOL deleteInsteadUpdate;
@property (nonatomic,assign) int intervalBeforeSunrise;
@property (nonatomic,assign) int intervalBeforeSunset;
@property (nonatomic,copy) NSString* updateRequiredEntryFields;
@property (nonatomic,copy) NSString* updateRequiredMetadataXPaths;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfScheduleUpdateEnabled;
- (KalturaFieldType)getTypeOfAvailabilityUpdateEnabled;
- (KalturaFieldType)getTypeOfDeleteInsteadUpdate;
- (KalturaFieldType)getTypeOfIntervalBeforeSunrise;
- (KalturaFieldType)getTypeOfIntervalBeforeSunset;
- (KalturaFieldType)getTypeOfUpdateRequiredEntryFields;
- (KalturaFieldType)getTypeOfUpdateRequiredMetadataXPaths;
- (void)setScheduleUpdateEnabledFromString:(NSString*)aPropVal;
- (void)setAvailabilityUpdateEnabledFromString:(NSString*)aPropVal;
- (void)setDeleteInsteadUpdateFromString:(NSString*)aPropVal;
- (void)setIntervalBeforeSunriseFromString:(NSString*)aPropVal;
- (void)setIntervalBeforeSunsetFromString:(NSString*)aPropVal;
@end

@interface KalturaGenericDistributionProvider : KalturaDistributionProvider
// Auto generated
@property (nonatomic,assign,readonly) int id;
// Generic distribution provider creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Generic distribution provider last update date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,assign) BOOL isDefault;
@property (nonatomic,assign,readonly) int status;	// enum KalturaGenericDistributionProviderStatus
@property (nonatomic,copy) NSString* optionalFlavorParamsIds;
@property (nonatomic,copy) NSString* requiredFlavorParamsIds;
@property (nonatomic,retain) NSMutableArray* optionalThumbDimensions;	// of KalturaDistributionThumbDimensions elements
@property (nonatomic,retain) NSMutableArray* requiredThumbDimensions;	// of KalturaDistributionThumbDimensions elements
@property (nonatomic,copy) NSString* editableFields;
@property (nonatomic,copy) NSString* mandatoryFields;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfIsDefault;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfOptionalFlavorParamsIds;
- (KalturaFieldType)getTypeOfRequiredFlavorParamsIds;
- (KalturaFieldType)getTypeOfOptionalThumbDimensions;
- (NSString*)getObjectTypeOfOptionalThumbDimensions;
- (KalturaFieldType)getTypeOfRequiredThumbDimensions;
- (NSString*)getObjectTypeOfRequiredThumbDimensions;
- (KalturaFieldType)getTypeOfEditableFields;
- (KalturaFieldType)getTypeOfMandatoryFields;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setIsDefaultFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
@end

@interface KalturaSyndicationDistributionProvider : KalturaDistributionProvider
@end

@interface KalturaDistributionProviderListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaDistributionProvider elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaGenericDistributionProviderListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaGenericDistributionProvider elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaGenericDistributionProviderAction : KalturaObjectBase
// Auto generated
@property (nonatomic,assign,readonly) int id;
// Generic distribution provider action creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Generic distribution provider action last update date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,assign) int genericDistributionProviderId;	// insertonly
@property (nonatomic,assign) int action;	// enum KalturaDistributionAction, insertonly
@property (nonatomic,assign,readonly) int status;	// enum KalturaGenericDistributionProviderStatus
@property (nonatomic,assign) int resultsParser;	// enum KalturaGenericDistributionProviderParser
@property (nonatomic,assign) int protocol;	// enum KalturaDistributionProtocol
@property (nonatomic,copy) NSString* serverAddress;
@property (nonatomic,copy) NSString* remotePath;
@property (nonatomic,copy) NSString* remoteUsername;
@property (nonatomic,copy) NSString* remotePassword;
@property (nonatomic,copy) NSString* editableFields;
@property (nonatomic,copy) NSString* mandatoryFields;
@property (nonatomic,copy,readonly) NSString* mrssTransformer;
@property (nonatomic,copy,readonly) NSString* mrssValidator;
@property (nonatomic,copy,readonly) NSString* resultsTransformer;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfGenericDistributionProviderId;
- (KalturaFieldType)getTypeOfAction;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfResultsParser;
- (KalturaFieldType)getTypeOfProtocol;
- (KalturaFieldType)getTypeOfServerAddress;
- (KalturaFieldType)getTypeOfRemotePath;
- (KalturaFieldType)getTypeOfRemoteUsername;
- (KalturaFieldType)getTypeOfRemotePassword;
- (KalturaFieldType)getTypeOfEditableFields;
- (KalturaFieldType)getTypeOfMandatoryFields;
- (KalturaFieldType)getTypeOfMrssTransformer;
- (KalturaFieldType)getTypeOfMrssValidator;
- (KalturaFieldType)getTypeOfResultsTransformer;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setGenericDistributionProviderIdFromString:(NSString*)aPropVal;
- (void)setActionFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setResultsParserFromString:(NSString*)aPropVal;
- (void)setProtocolFromString:(NSString*)aPropVal;
@end

@interface KalturaGenericDistributionProviderActionListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaGenericDistributionProviderAction elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

///////////////////////// services /////////////////////////
// Distribution Profile service
@interface KalturaDistributionProfileService : KalturaServiceBase
// Add new Distribution Profile
- (KalturaDistributionProfile*)addWithDistributionProfile:(KalturaDistributionProfile*)aDistributionProfile;
// Get Distribution Profile by id
- (KalturaDistributionProfile*)getWithId:(int)aId;
// Update Distribution Profile by id
- (KalturaDistributionProfile*)updateWithId:(int)aId withDistributionProfile:(KalturaDistributionProfile*)aDistributionProfile;
// Update Distribution Profile status by id
- (KalturaDistributionProfile*)updateStatusWithId:(int)aId withStatus:(int)aStatus;
// Delete Distribution Profile by id
- (void)deleteWithId:(int)aId;
// List all distribution providers
- (KalturaDistributionProfileListResponse*)listWithFilter:(KalturaDistributionProfileFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaDistributionProfileListResponse*)listWithFilter:(KalturaDistributionProfileFilter*)aFilter;
- (KalturaDistributionProfileListResponse*)list;
- (KalturaDistributionProfileListResponse*)listByPartnerWithFilter:(KalturaPartnerFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaDistributionProfileListResponse*)listByPartnerWithFilter:(KalturaPartnerFilter*)aFilter;
- (KalturaDistributionProfileListResponse*)listByPartner;
@end

// Entry Distribution service
@interface KalturaEntryDistributionService : KalturaServiceBase
// Add new Entry Distribution
- (KalturaEntryDistribution*)addWithEntryDistribution:(KalturaEntryDistribution*)aEntryDistribution;
// Get Entry Distribution by id
- (KalturaEntryDistribution*)getWithId:(int)aId;
// Validates Entry Distribution by id for submission
- (KalturaEntryDistribution*)validateWithId:(int)aId;
// Update Entry Distribution by id
- (KalturaEntryDistribution*)updateWithId:(int)aId withEntryDistribution:(KalturaEntryDistribution*)aEntryDistribution;
// Delete Entry Distribution by id
- (void)deleteWithId:(int)aId;
// List all distribution providers
- (KalturaEntryDistributionListResponse*)listWithFilter:(KalturaEntryDistributionFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaEntryDistributionListResponse*)listWithFilter:(KalturaEntryDistributionFilter*)aFilter;
- (KalturaEntryDistributionListResponse*)list;
// Submits Entry Distribution to the remote destination
- (KalturaEntryDistribution*)submitAddWithId:(int)aId withSubmitWhenReady:(BOOL)aSubmitWhenReady;
- (KalturaEntryDistribution*)submitAddWithId:(int)aId;
// Submits Entry Distribution changes to the remote destination
- (KalturaEntryDistribution*)submitUpdateWithId:(int)aId;
// Submits Entry Distribution report request
- (KalturaEntryDistribution*)submitFetchReportWithId:(int)aId;
// Deletes Entry Distribution from the remote destination
- (KalturaEntryDistribution*)submitDeleteWithId:(int)aId;
// Retries last submit action
- (KalturaEntryDistribution*)retrySubmitWithId:(int)aId;
// Serves entry distribution sent data
- (NSString*)serveSentDataWithId:(int)aId withActionType:(int)aActionType;
// Serves entry distribution returned data
- (NSString*)serveReturnedDataWithId:(int)aId withActionType:(int)aActionType;
@end

// Distribution Provider service
@interface KalturaDistributionProviderService : KalturaServiceBase
// List all distribution providers
- (KalturaDistributionProviderListResponse*)listWithFilter:(KalturaDistributionProviderFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaDistributionProviderListResponse*)listWithFilter:(KalturaDistributionProviderFilter*)aFilter;
- (KalturaDistributionProviderListResponse*)list;
@end

// Generic Distribution Provider service
@interface KalturaGenericDistributionProviderService : KalturaServiceBase
// Add new Generic Distribution Provider
- (KalturaGenericDistributionProvider*)addWithGenericDistributionProvider:(KalturaGenericDistributionProvider*)aGenericDistributionProvider;
// Get Generic Distribution Provider by id
- (KalturaGenericDistributionProvider*)getWithId:(int)aId;
// Update Generic Distribution Provider by id
- (KalturaGenericDistributionProvider*)updateWithId:(int)aId withGenericDistributionProvider:(KalturaGenericDistributionProvider*)aGenericDistributionProvider;
// Delete Generic Distribution Provider by id
- (void)deleteWithId:(int)aId;
// List all distribution providers
- (KalturaGenericDistributionProviderListResponse*)listWithFilter:(KalturaGenericDistributionProviderFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaGenericDistributionProviderListResponse*)listWithFilter:(KalturaGenericDistributionProviderFilter*)aFilter;
- (KalturaGenericDistributionProviderListResponse*)list;
@end

// Generic Distribution Provider Actions service
@interface KalturaGenericDistributionProviderActionService : KalturaServiceBase
// Add new Generic Distribution Provider Action
- (KalturaGenericDistributionProviderAction*)addWithGenericDistributionProviderAction:(KalturaGenericDistributionProviderAction*)aGenericDistributionProviderAction;
// Add MRSS transform file to generic distribution provider action
- (KalturaGenericDistributionProviderAction*)addMrssTransformWithId:(int)aId withXslData:(NSString*)aXslData;
// Add MRSS transform file to generic distribution provider action
- (KalturaGenericDistributionProviderAction*)addMrssTransformFromFileWithId:(int)aId withXslFile:(NSString*)aXslFile;
// Add MRSS validate file to generic distribution provider action
- (KalturaGenericDistributionProviderAction*)addMrssValidateWithId:(int)aId withXsdData:(NSString*)aXsdData;
// Add MRSS validate file to generic distribution provider action
- (KalturaGenericDistributionProviderAction*)addMrssValidateFromFileWithId:(int)aId withXsdFile:(NSString*)aXsdFile;
// Add results transform file to generic distribution provider action
- (KalturaGenericDistributionProviderAction*)addResultsTransformWithId:(int)aId withTransformData:(NSString*)aTransformData;
// Add MRSS transform file to generic distribution provider action
- (KalturaGenericDistributionProviderAction*)addResultsTransformFromFileWithId:(int)aId withTransformFile:(NSString*)aTransformFile;
// Get Generic Distribution Provider Action by id
- (KalturaGenericDistributionProviderAction*)getWithId:(int)aId;
// Get Generic Distribution Provider Action by provider id
- (KalturaGenericDistributionProviderAction*)getByProviderIdWithGenericDistributionProviderId:(int)aGenericDistributionProviderId withActionType:(int)aActionType;
// Update Generic Distribution Provider Action by provider id
- (KalturaGenericDistributionProviderAction*)updateByProviderIdWithGenericDistributionProviderId:(int)aGenericDistributionProviderId withActionType:(int)aActionType withGenericDistributionProviderAction:(KalturaGenericDistributionProviderAction*)aGenericDistributionProviderAction;
// Update Generic Distribution Provider Action by id
- (KalturaGenericDistributionProviderAction*)updateWithId:(int)aId withGenericDistributionProviderAction:(KalturaGenericDistributionProviderAction*)aGenericDistributionProviderAction;
// Delete Generic Distribution Provider Action by id
- (void)deleteWithId:(int)aId;
// Delete Generic Distribution Provider Action by provider id
- (void)deleteByProviderIdWithGenericDistributionProviderId:(int)aGenericDistributionProviderId withActionType:(int)aActionType;
// List all distribution providers
- (KalturaGenericDistributionProviderActionListResponse*)listWithFilter:(KalturaGenericDistributionProviderActionFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaGenericDistributionProviderActionListResponse*)listWithFilter:(KalturaGenericDistributionProviderActionFilter*)aFilter;
- (KalturaGenericDistributionProviderActionListResponse*)list;
@end

@interface KalturaContentDistributionClientPlugin : KalturaClientPlugin
{
	KalturaDistributionProfileService* _distributionProfile;
	KalturaEntryDistributionService* _entryDistribution;
	KalturaDistributionProviderService* _distributionProvider;
	KalturaGenericDistributionProviderService* _genericDistributionProvider;
	KalturaGenericDistributionProviderActionService* _genericDistributionProviderAction;
}

@property (nonatomic, assign) KalturaClientBase* client;
@property (nonatomic, readonly) KalturaDistributionProfileService* distributionProfile;
@property (nonatomic, readonly) KalturaEntryDistributionService* entryDistribution;
@property (nonatomic, readonly) KalturaDistributionProviderService* distributionProvider;
@property (nonatomic, readonly) KalturaGenericDistributionProviderService* genericDistributionProvider;
@property (nonatomic, readonly) KalturaGenericDistributionProviderActionService* genericDistributionProviderAction;
@end

