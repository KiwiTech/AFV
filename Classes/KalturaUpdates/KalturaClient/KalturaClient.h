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
#import "KalturaClientBase.h"

#define API_VERSION @"3.1.4"

///////////////////////// enums /////////////////////////
@interface KalturaAccessControlActionType : NSObject
+ (NSString*)BLOCK;
+ (NSString*)PREVIEW;
@end

@interface KalturaAccessControlContextType : NSObject
+ (NSString*)PLAY;
+ (NSString*)DOWNLOAD;
+ (NSString*)THUMBNAIL;
@end

@interface KalturaAccessControlOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaAccessControlProfileOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaAdminUserOrderBy : NSObject
+ (NSString*)ID_ASC;
+ (NSString*)ID_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaApiActionPermissionItemOrderBy : NSObject
+ (NSString*)ID_ASC;
+ (NSString*)ID_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaApiParameterPermissionItemAction : NSObject
+ (NSString*)READ;
+ (NSString*)UPDATE;
+ (NSString*)INSERT;
+ (NSString*)USEAGE;
@end

@interface KalturaApiParameterPermissionItemOrderBy : NSObject
+ (NSString*)ID_ASC;
+ (NSString*)ID_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaAssetOrderBy : NSObject
+ (NSString*)SIZE_ASC;
+ (NSString*)SIZE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)DELETED_AT_ASC;
+ (NSString*)DELETED_AT_DESC;
@end

@interface KalturaAssetParamsOrderBy : NSObject
@end

@interface KalturaAssetParamsOrigin : NSObject
+ (int)CONVERT;
+ (int)INGEST;
+ (int)CONVERT_WHEN_MISSING;
@end

@interface KalturaAssetParamsOutputOrderBy : NSObject
@end

@interface KalturaAssetStatus : NSObject
+ (int)ERROR;
+ (int)QUEUED;
+ (int)READY;
+ (int)DELETED;
+ (int)IMPORTING;
@end

@interface KalturaAudioCodec : NSObject
+ (NSString*)NONE;
+ (NSString*)MP3;
+ (NSString*)AAC;
+ (NSString*)VORBIS;
+ (NSString*)WMA;
+ (NSString*)WMAPRO;
+ (NSString*)AMRNB;
+ (NSString*)MPEG2;
+ (NSString*)COPY;
@end

@interface KalturaBaseEntryOrderBy : NSObject
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)MODERATION_COUNT_ASC;
+ (NSString*)MODERATION_COUNT_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)RANK_ASC;
+ (NSString*)RANK_DESC;
+ (NSString*)START_DATE_ASC;
+ (NSString*)START_DATE_DESC;
+ (NSString*)END_DATE_ASC;
+ (NSString*)END_DATE_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

@interface KalturaBaseJobOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)PROCESSOR_EXPIRATION_ASC;
+ (NSString*)PROCESSOR_EXPIRATION_DESC;
+ (NSString*)EXECUTION_ATTEMPTS_ASC;
+ (NSString*)EXECUTION_ATTEMPTS_DESC;
+ (NSString*)LOCK_VERSION_ASC;
+ (NSString*)LOCK_VERSION_DESC;
@end

@interface KalturaBaseSyndicationFeedOrderBy : NSObject
+ (NSString*)PLAYLIST_ID_ASC;
+ (NSString*)PLAYLIST_ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)TYPE_ASC;
+ (NSString*)TYPE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaBatchJobErrorTypes : NSObject
+ (int)APP;
+ (int)RUNTIME;
+ (int)HTTP;
+ (int)CURL;
+ (int)KALTURA_API;
+ (int)KALTURA_CLIENT;
@end

@interface KalturaBatchJobOrderBy : NSObject
+ (NSString*)STATUS_ASC;
+ (NSString*)STATUS_DESC;
+ (NSString*)CHECK_AGAIN_TIMEOUT_ASC;
+ (NSString*)CHECK_AGAIN_TIMEOUT_DESC;
+ (NSString*)PROGRESS_ASC;
+ (NSString*)PROGRESS_DESC;
+ (NSString*)UPDATES_COUNT_ASC;
+ (NSString*)UPDATES_COUNT_DESC;
+ (NSString*)PRIORITY_ASC;
+ (NSString*)PRIORITY_DESC;
+ (NSString*)QUEUE_TIME_ASC;
+ (NSString*)QUEUE_TIME_DESC;
+ (NSString*)FINISH_TIME_ASC;
+ (NSString*)FINISH_TIME_DESC;
+ (NSString*)FILE_SIZE_ASC;
+ (NSString*)FILE_SIZE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)PROCESSOR_EXPIRATION_ASC;
+ (NSString*)PROCESSOR_EXPIRATION_DESC;
+ (NSString*)EXECUTION_ATTEMPTS_ASC;
+ (NSString*)EXECUTION_ATTEMPTS_DESC;
+ (NSString*)LOCK_VERSION_ASC;
+ (NSString*)LOCK_VERSION_DESC;
@end

@interface KalturaBatchJobStatus : NSObject
+ (int)PENDING;
+ (int)QUEUED;
+ (int)PROCESSING;
+ (int)PROCESSED;
+ (int)MOVEFILE;
+ (int)FINISHED;
+ (int)FAILED;
+ (int)ABORTED;
+ (int)ALMOST_DONE;
+ (int)RETRY;
+ (int)FATAL;
+ (int)DONT_PROCESS;
@end

@interface KalturaBatchJobType : NSObject
+ (NSString*)CONVERT;
+ (NSString*)IMPORT;
+ (NSString*)DELETE;
+ (NSString*)FLATTEN;
+ (NSString*)BULKUPLOAD;
+ (NSString*)DVDCREATOR;
+ (NSString*)DOWNLOAD;
+ (NSString*)OOCONVERT;
+ (NSString*)CONVERT_PROFILE;
+ (NSString*)POSTCONVERT;
+ (NSString*)PULL;
+ (NSString*)REMOTE_CONVERT;
+ (NSString*)EXTRACT_MEDIA;
+ (NSString*)MAIL;
+ (NSString*)NOTIFICATION;
+ (NSString*)CLEANUP;
+ (NSString*)SCHEDULER_HELPER;
+ (NSString*)BULKDOWNLOAD;
+ (NSString*)DB_CLEANUP;
+ (NSString*)PROVISION_PROVIDE;
+ (NSString*)CONVERT_COLLECTION;
+ (NSString*)STORAGE_EXPORT;
+ (NSString*)PROVISION_DELETE;
+ (NSString*)STORAGE_DELETE;
+ (NSString*)EMAIL_INGESTION;
+ (NSString*)METADATA_IMPORT;
+ (NSString*)METADATA_TRANSFORM;
+ (NSString*)FILESYNC_IMPORT;
+ (NSString*)CAPTURE_THUMB;
+ (NSString*)VIRUS_SCAN;
+ (NSString*)DISTRIBUTION_SUBMIT;
+ (NSString*)DISTRIBUTION_UPDATE;
+ (NSString*)DISTRIBUTION_DELETE;
+ (NSString*)DISTRIBUTION_FETCH_REPORT;
+ (NSString*)DISTRIBUTION_ENABLE;
+ (NSString*)DISTRIBUTION_DISABLE;
+ (NSString*)DISTRIBUTION_SYNC;
+ (NSString*)DROP_FOLDER_WATCHER;
+ (NSString*)DROP_FOLDER_HANDLER;
+ (NSString*)PARSE_CAPTION_ASSET;
@end

@interface KalturaBitRateMode : NSObject
+ (int)CBR;
+ (int)VBR;
@end

@interface KalturaBulkUploadAction : NSObject
+ (int)ADD;
+ (int)UPDATE;
+ (int)DELETE;
+ (int)REPLACE;
+ (int)TRANSFORM_XSLT;
@end

@interface KalturaBulkUploadResultObjectType : NSObject
+ (NSString*)ENTRY;
@end

@interface KalturaBulkUploadType : NSObject
+ (NSString*)CSV;
+ (NSString*)XML;
+ (NSString*)DROP_FOLDER_XML;
@end

@interface KalturaCategoryOrderBy : NSObject
+ (NSString*)DEPTH_ASC;
+ (NSString*)DEPTH_DESC;
+ (NSString*)FULL_NAME_ASC;
+ (NSString*)FULL_NAME_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaCommercialUseType : NSObject
+ (int)COMMERCIAL_USE;
+ (int)NON_COMMERCIAL_USE;
@end

@interface KalturaConditionType : NSObject
+ (NSString*)AUTHENTICATED;
+ (NSString*)COUNTRY;
+ (NSString*)IP_ADDRESS;
+ (NSString*)SITE;
+ (NSString*)USER_AGENT;
+ (NSString*)FIELD_MATCH;
+ (NSString*)FIELD_COMPARE;
+ (NSString*)METADATA_FIELD_MATCH;
+ (NSString*)METADATA_FIELD_COMPARE;
@end

@interface KalturaContainerFormat : NSObject
+ (NSString*)FLV;
+ (NSString*)MP4;
+ (NSString*)AVI;
+ (NSString*)MOV;
+ (NSString*)MP3;
+ (NSString*)_3GP;
+ (NSString*)OGG;
+ (NSString*)WMV;
+ (NSString*)WMA;
+ (NSString*)ISMV;
+ (NSString*)MKV;
+ (NSString*)WEBM;
+ (NSString*)MPEG;
+ (NSString*)MPEGTS;
+ (NSString*)APPLEHTTP;
+ (NSString*)SWF;
+ (NSString*)PDF;
+ (NSString*)JPG;
@end

@interface KalturaControlPanelCommandOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaControlPanelCommandStatus : NSObject
+ (int)PENDING;
+ (int)HANDLED;
+ (int)DONE;
+ (int)FAILED;
@end

@interface KalturaControlPanelCommandTargetType : NSObject
+ (int)DATA_CENTER;
+ (int)SCHEDULER;
+ (int)JOB_TYPE;
+ (int)JOB;
+ (int)BATCH;
@end

@interface KalturaControlPanelCommandType : NSObject
+ (int)STOP;
+ (int)START;
+ (int)CONFIG;
+ (int)KILL;
@end

@interface KalturaConversionProfileAssetParamsOrderBy : NSObject
@end

@interface KalturaConversionProfileOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaConversionProfileStatus : NSObject
+ (NSString*)DISABLED;
+ (NSString*)ENABLED;
+ (NSString*)DELETED;
@end

@interface KalturaCountryRestrictionType : NSObject
+ (int)RESTRICT_COUNTRY_LIST;
+ (int)ALLOW_COUNTRY_LIST;
@end

@interface KalturaDataEntryOrderBy : NSObject
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)MODERATION_COUNT_ASC;
+ (NSString*)MODERATION_COUNT_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)RANK_ASC;
+ (NSString*)RANK_DESC;
+ (NSString*)START_DATE_ASC;
+ (NSString*)START_DATE_DESC;
+ (NSString*)END_DATE_ASC;
+ (NSString*)END_DATE_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

@interface KalturaDirectoryRestrictionType : NSObject
+ (int)DONT_DISPLAY;
+ (int)DISPLAY_WITH_LINK;
@end

@interface KalturaDurationType : NSObject
+ (NSString*)NOT_AVAILABLE;
+ (NSString*)SHORT;
+ (NSString*)MEDIUM;
+ (NSString*)LONG;
@end

@interface KalturaEditorType : NSObject
+ (int)SIMPLE;
+ (int)ADVANCED;
@end

@interface KalturaEmailIngestionProfileStatus : NSObject
+ (int)INACTIVE;
+ (int)ACTIVE;
@end

@interface KalturaEntryModerationStatus : NSObject
+ (int)PENDING_MODERATION;
+ (int)APPROVED;
+ (int)REJECTED;
+ (int)FLAGGED_FOR_REVIEW;
+ (int)AUTO_APPROVED;
@end

@interface KalturaEntryReplacementStatus : NSObject
+ (NSString*)NONE;
+ (NSString*)APPROVED_BUT_NOT_READY;
+ (NSString*)READY_BUT_NOT_APPROVED;
+ (NSString*)NOT_READY_AND_NOT_APPROVED;
@end

@interface KalturaEntryStatus : NSObject
+ (NSString*)ERROR_IMPORTING;
+ (NSString*)ERROR_CONVERTING;
+ (NSString*)IMPORT;
+ (NSString*)PRECONVERT;
+ (NSString*)READY;
+ (NSString*)DELETED;
+ (NSString*)PENDING;
+ (NSString*)MODERATE;
+ (NSString*)BLOCKED;
+ (NSString*)NO_CONTENT;
+ (NSString*)INFECTED;
+ (NSString*)SCAN_FAILURE;
@end

@interface KalturaEntryType : NSObject
+ (NSString*)AUTOMATIC;
+ (NSString*)MEDIA_CLIP;
+ (NSString*)MIX;
+ (NSString*)PLAYLIST;
+ (NSString*)DATA;
+ (NSString*)LIVE_STREAM;
+ (NSString*)DOCUMENT;
@end

@interface KalturaFileSyncObjectType : NSObject
+ (NSString*)ENTRY;
+ (NSString*)UICONF;
+ (NSString*)BATCHJOB;
+ (NSString*)ASSET;
+ (NSString*)METADATA;
+ (NSString*)METADATA_PROFILE;
+ (NSString*)SYNDICATION_FEED;
+ (NSString*)CONVERSION_PROFILE;
+ (NSString*)FLAVOR_ASSET;
+ (NSString*)GENERIC_DISTRIBUTION_ACTION;
+ (NSString*)ENTRY_DISTRIBUTION;
+ (NSString*)DISTRIBUTION_PROFILE;
@end

@interface KalturaFlavorAssetOrderBy : NSObject
+ (NSString*)SIZE_ASC;
+ (NSString*)SIZE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)DELETED_AT_ASC;
+ (NSString*)DELETED_AT_DESC;
@end

@interface KalturaFlavorAssetStatus : NSObject
+ (int)CONVERTING;
+ (int)NOT_APPLICABLE;
+ (int)TEMP;
+ (int)WAIT_FOR_CONVERT;
+ (int)VALIDATING;
+ (int)ERROR;
+ (int)QUEUED;
+ (int)READY;
+ (int)DELETED;
+ (int)IMPORTING;
@end

@interface KalturaFlavorParamsOrderBy : NSObject
@end

@interface KalturaFlavorParamsOutputOrderBy : NSObject
@end

@interface KalturaFlavorReadyBehaviorType : NSObject
+ (int)INHERIT_FLAVOR_PARAMS;
+ (int)REQUIRED;
+ (int)OPTIONAL;
@end

@interface KalturaGender : NSObject
+ (int)UNKNOWN;
+ (int)MALE;
+ (int)FEMALE;
@end

@interface KalturaGenericSyndicationFeedOrderBy : NSObject
+ (NSString*)PLAYLIST_ID_ASC;
+ (NSString*)PLAYLIST_ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)TYPE_ASC;
+ (NSString*)TYPE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaGenericXsltSyndicationFeedOrderBy : NSObject
+ (NSString*)PLAYLIST_ID_ASC;
+ (NSString*)PLAYLIST_ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)TYPE_ASC;
+ (NSString*)TYPE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaGeoCoderType : NSObject
+ (NSString*)KALTURA;
@end

@interface KalturaGoogleSyndicationFeedAdultValues : NSObject
+ (NSString*)YES_;
+ (NSString*)NO_;
@end

@interface KalturaGoogleVideoSyndicationFeedOrderBy : NSObject
+ (NSString*)PLAYLIST_ID_ASC;
+ (NSString*)PLAYLIST_ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)TYPE_ASC;
+ (NSString*)TYPE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaITunesSyndicationFeedAdultValues : NSObject
+ (NSString*)YES_;
+ (NSString*)NO_;
+ (NSString*)CLEAN;
@end

@interface KalturaITunesSyndicationFeedCategories : NSObject
+ (NSString*)ARTS;
+ (NSString*)ARTS_DESIGN;
+ (NSString*)ARTS_FASHION_BEAUTY;
+ (NSString*)ARTS_FOOD;
+ (NSString*)ARTS_LITERATURE;
+ (NSString*)ARTS_PERFORMING_ARTS;
+ (NSString*)ARTS_VISUAL_ARTS;
+ (NSString*)BUSINESS;
+ (NSString*)BUSINESS_BUSINESS_NEWS;
+ (NSString*)BUSINESS_CAREERS;
+ (NSString*)BUSINESS_INVESTING;
+ (NSString*)BUSINESS_MANAGEMENT_MARKETING;
+ (NSString*)BUSINESS_SHOPPING;
+ (NSString*)COMEDY;
+ (NSString*)EDUCATION;
+ (NSString*)EDUCATION_TECHNOLOGY;
+ (NSString*)EDUCATION_HIGHER_EDUCATION;
+ (NSString*)EDUCATION_K_12;
+ (NSString*)EDUCATION_LANGUAGE_COURSES;
+ (NSString*)EDUCATION_TRAINING;
+ (NSString*)GAMES_HOBBIES;
+ (NSString*)GAMES_HOBBIES_AUTOMOTIVE;
+ (NSString*)GAMES_HOBBIES_AVIATION;
+ (NSString*)GAMES_HOBBIES_HOBBIES;
+ (NSString*)GAMES_HOBBIES_OTHER_GAMES;
+ (NSString*)GAMES_HOBBIES_VIDEO_GAMES;
+ (NSString*)GOVERNMENT_ORGANIZATIONS;
+ (NSString*)GOVERNMENT_ORGANIZATIONS_LOCAL;
+ (NSString*)GOVERNMENT_ORGANIZATIONS_NATIONAL;
+ (NSString*)GOVERNMENT_ORGANIZATIONS_NON_PROFIT;
+ (NSString*)GOVERNMENT_ORGANIZATIONS_REGIONAL;
+ (NSString*)HEALTH;
+ (NSString*)HEALTH_ALTERNATIVE_HEALTH;
+ (NSString*)HEALTH_FITNESS_NUTRITION;
+ (NSString*)HEALTH_SELF_HELP;
+ (NSString*)HEALTH_SEXUALITY;
+ (NSString*)KIDS_FAMILY;
+ (NSString*)MUSIC;
+ (NSString*)NEWS_POLITICS;
+ (NSString*)RELIGION_SPIRITUALITY;
+ (NSString*)RELIGION_SPIRITUALITY_BUDDHISM;
+ (NSString*)RELIGION_SPIRITUALITY_CHRISTIANITY;
+ (NSString*)RELIGION_SPIRITUALITY_HINDUISM;
+ (NSString*)RELIGION_SPIRITUALITY_ISLAM;
+ (NSString*)RELIGION_SPIRITUALITY_JUDAISM;
+ (NSString*)RELIGION_SPIRITUALITY_OTHER;
+ (NSString*)RELIGION_SPIRITUALITY_SPIRITUALITY;
+ (NSString*)SCIENCE_MEDICINE;
+ (NSString*)SCIENCE_MEDICINE_MEDICINE;
+ (NSString*)SCIENCE_MEDICINE_NATURAL_SCIENCES;
+ (NSString*)SCIENCE_MEDICINE_SOCIAL_SCIENCES;
+ (NSString*)SOCIETY_CULTURE;
+ (NSString*)SOCIETY_CULTURE_HISTORY;
+ (NSString*)SOCIETY_CULTURE_PERSONAL_JOURNALS;
+ (NSString*)SOCIETY_CULTURE_PHILOSOPHY;
+ (NSString*)SOCIETY_CULTURE_PLACES_TRAVEL;
+ (NSString*)SPORTS_RECREATION;
+ (NSString*)SPORTS_RECREATION_AMATEUR;
+ (NSString*)SPORTS_RECREATION_COLLEGE_HIGH_SCHOOL;
+ (NSString*)SPORTS_RECREATION_OUTDOOR;
+ (NSString*)SPORTS_RECREATION_PROFESSIONAL;
+ (NSString*)TECHNOLOGY;
+ (NSString*)TECHNOLOGY_GADGETS;
+ (NSString*)TECHNOLOGY_TECH_NEWS;
+ (NSString*)TECHNOLOGY_PODCASTING;
+ (NSString*)TECHNOLOGY_SOFTWARE_HOW_TO;
+ (NSString*)TV_FILM;
@end

@interface KalturaITunesSyndicationFeedOrderBy : NSObject
+ (NSString*)PLAYLIST_ID_ASC;
+ (NSString*)PLAYLIST_ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)TYPE_ASC;
+ (NSString*)TYPE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaIpAddressRestrictionType : NSObject
+ (int)RESTRICT_LIST;
+ (int)ALLOW_LIST;
@end

@interface KalturaLanguage : NSObject
+ (NSString*)AB;
+ (NSString*)AA;
+ (NSString*)AF;
+ (NSString*)SQ;
+ (NSString*)AM;
+ (NSString*)AR;
+ (NSString*)HY;
+ (NSString*)AS_;
+ (NSString*)AY;
+ (NSString*)AZ;
+ (NSString*)BA;
+ (NSString*)EU;
+ (NSString*)BN;
+ (NSString*)DZ;
+ (NSString*)BH;
+ (NSString*)BI;
+ (NSString*)BR;
+ (NSString*)BG;
+ (NSString*)MY;
+ (NSString*)BE;
+ (NSString*)KM;
+ (NSString*)CA;
+ (NSString*)ZH;
+ (NSString*)CO;
+ (NSString*)HR;
+ (NSString*)CS;
+ (NSString*)DA;
+ (NSString*)NL;
+ (NSString*)EN;
+ (NSString*)EO;
+ (NSString*)ET;
+ (NSString*)FO;
+ (NSString*)FA;
+ (NSString*)FJ;
+ (NSString*)FI;
+ (NSString*)FR;
+ (NSString*)FY;
+ (NSString*)GL;
+ (NSString*)GD;
+ (NSString*)GV;
+ (NSString*)KA;
+ (NSString*)DE;
+ (NSString*)EL;
+ (NSString*)KL;
+ (NSString*)GN;
+ (NSString*)GU;
+ (NSString*)HA;
+ (NSString*)HE;
+ (NSString*)IW;
+ (NSString*)HI;
+ (NSString*)HU;
+ (NSString*)IS;
+ (NSString*)ID;
+ (NSString*)IN;
+ (NSString*)IA;
+ (NSString*)IE;
+ (NSString*)IU;
+ (NSString*)IK;
+ (NSString*)GA;
+ (NSString*)IT;
+ (NSString*)JA;
+ (NSString*)JV;
+ (NSString*)KN;
+ (NSString*)KS;
+ (NSString*)KK;
+ (NSString*)RW;
+ (NSString*)KY;
+ (NSString*)RN;
+ (NSString*)KO;
+ (NSString*)KU;
+ (NSString*)LO;
+ (NSString*)LA;
+ (NSString*)LV;
+ (NSString*)LI;
+ (NSString*)LN;
+ (NSString*)LT;
+ (NSString*)MK;
+ (NSString*)MG;
+ (NSString*)MS;
+ (NSString*)ML;
+ (NSString*)MT;
+ (NSString*)MI;
+ (NSString*)MR;
+ (NSString*)MO;
+ (NSString*)MN;
+ (NSString*)NA;
+ (NSString*)NE;
+ (NSString*)NO_;
+ (NSString*)OC;
+ (NSString*)OR_;
+ (NSString*)OM;
+ (NSString*)PS;
+ (NSString*)PL;
+ (NSString*)PT;
+ (NSString*)PA;
+ (NSString*)QU;
+ (NSString*)RM;
+ (NSString*)RO;
+ (NSString*)RU;
+ (NSString*)SM;
+ (NSString*)SG;
+ (NSString*)SA;
+ (NSString*)SR;
+ (NSString*)SH;
+ (NSString*)ST;
+ (NSString*)TN;
+ (NSString*)SN;
+ (NSString*)SD;
+ (NSString*)SI;
+ (NSString*)SS;
+ (NSString*)SK;
+ (NSString*)SL;
+ (NSString*)SO;
+ (NSString*)ES;
+ (NSString*)SU;
+ (NSString*)SW;
+ (NSString*)SV;
+ (NSString*)TL;
+ (NSString*)TG;
+ (NSString*)TA;
+ (NSString*)TT;
+ (NSString*)TE;
+ (NSString*)TH;
+ (NSString*)BO;
+ (NSString*)TI;
+ (NSString*)TO;
+ (NSString*)TS;
+ (NSString*)TR;
+ (NSString*)TK;
+ (NSString*)TW;
+ (NSString*)UG;
+ (NSString*)UK;
+ (NSString*)UR;
+ (NSString*)UZ;
+ (NSString*)VI;
+ (NSString*)VO;
+ (NSString*)CY;
+ (NSString*)WO;
+ (NSString*)XH;
+ (NSString*)YI;
+ (NSString*)JI;
+ (NSString*)YO;
+ (NSString*)ZU;
@end

@interface KalturaLanguageCode : NSObject
+ (NSString*)AB;
+ (NSString*)AA;
+ (NSString*)AF;
+ (NSString*)SQ;
+ (NSString*)AM;
+ (NSString*)AR;
+ (NSString*)HY;
+ (NSString*)AS_;
+ (NSString*)AY;
+ (NSString*)AZ;
+ (NSString*)BA;
+ (NSString*)EU;
+ (NSString*)BN;
+ (NSString*)DZ;
+ (NSString*)BH;
+ (NSString*)BI;
+ (NSString*)BR;
+ (NSString*)BG;
+ (NSString*)MY;
+ (NSString*)BE;
+ (NSString*)KM;
+ (NSString*)CA;
+ (NSString*)ZH;
+ (NSString*)CO;
+ (NSString*)HR;
+ (NSString*)CS;
+ (NSString*)DA;
+ (NSString*)NL;
+ (NSString*)EN;
+ (NSString*)EO;
+ (NSString*)ET;
+ (NSString*)FO;
+ (NSString*)FA;
+ (NSString*)FJ;
+ (NSString*)FI;
+ (NSString*)FR;
+ (NSString*)FY;
+ (NSString*)GL;
+ (NSString*)GD;
+ (NSString*)GV;
+ (NSString*)KA;
+ (NSString*)DE;
+ (NSString*)EL;
+ (NSString*)KL;
+ (NSString*)GN;
+ (NSString*)GU;
+ (NSString*)HA;
+ (NSString*)HE;
+ (NSString*)IW;
+ (NSString*)HI;
+ (NSString*)HU;
+ (NSString*)IS;
+ (NSString*)ID;
+ (NSString*)IN;
+ (NSString*)IA;
+ (NSString*)IE;
+ (NSString*)IU;
+ (NSString*)IK;
+ (NSString*)GA;
+ (NSString*)IT;
+ (NSString*)JA;
+ (NSString*)JV;
+ (NSString*)KN;
+ (NSString*)KS;
+ (NSString*)KK;
+ (NSString*)RW;
+ (NSString*)KY;
+ (NSString*)RN;
+ (NSString*)KO;
+ (NSString*)KU;
+ (NSString*)LO;
+ (NSString*)LA;
+ (NSString*)LV;
+ (NSString*)LI;
+ (NSString*)LN;
+ (NSString*)LT;
+ (NSString*)MK;
+ (NSString*)MG;
+ (NSString*)MS;
+ (NSString*)ML;
+ (NSString*)MT;
+ (NSString*)MI;
+ (NSString*)MR;
+ (NSString*)MO;
+ (NSString*)MN;
+ (NSString*)NA;
+ (NSString*)NE;
+ (NSString*)NO_;
+ (NSString*)OC;
+ (NSString*)OR_;
+ (NSString*)OM;
+ (NSString*)PS;
+ (NSString*)PL;
+ (NSString*)PT;
+ (NSString*)PA;
+ (NSString*)QU;
+ (NSString*)RM;
+ (NSString*)RO;
+ (NSString*)RU;
+ (NSString*)SM;
+ (NSString*)SG;
+ (NSString*)SA;
+ (NSString*)SR;
+ (NSString*)SH;
+ (NSString*)ST;
+ (NSString*)TN;
+ (NSString*)SN;
+ (NSString*)SD;
+ (NSString*)SI;
+ (NSString*)SS;
+ (NSString*)SK;
+ (NSString*)SL;
+ (NSString*)SO;
+ (NSString*)ES;
+ (NSString*)SU;
+ (NSString*)SW;
+ (NSString*)SV;
+ (NSString*)TL;
+ (NSString*)TG;
+ (NSString*)TA;
+ (NSString*)TT;
+ (NSString*)TE;
+ (NSString*)TH;
+ (NSString*)BO;
+ (NSString*)TI;
+ (NSString*)TO;
+ (NSString*)TS;
+ (NSString*)TR;
+ (NSString*)TK;
+ (NSString*)TW;
+ (NSString*)UG;
+ (NSString*)UK;
+ (NSString*)UR;
+ (NSString*)UZ;
+ (NSString*)VI;
+ (NSString*)VO;
+ (NSString*)CY;
+ (NSString*)WO;
+ (NSString*)XH;
+ (NSString*)YI;
+ (NSString*)JI;
+ (NSString*)YO;
+ (NSString*)ZU;
@end

@interface KalturaLicenseType : NSObject
+ (int)UNKNOWN;
+ (int)NONE;
+ (int)COPYRIGHTED;
+ (int)PUBLIC_DOMAIN;
+ (int)CREATIVECOMMONS_ATTRIBUTION;
+ (int)CREATIVECOMMONS_ATTRIBUTION_SHARE_ALIKE;
+ (int)CREATIVECOMMONS_ATTRIBUTION_NO_DERIVATIVES;
+ (int)CREATIVECOMMONS_ATTRIBUTION_NON_COMMERCIAL;
+ (int)CREATIVECOMMONS_ATTRIBUTION_NON_COMMERCIAL_SHARE_ALIKE;
+ (int)CREATIVECOMMONS_ATTRIBUTION_NON_COMMERCIAL_NO_DERIVATIVES;
+ (int)GFDL;
+ (int)GPL;
+ (int)AFFERO_GPL;
+ (int)LGPL;
+ (int)BSD;
+ (int)APACHE;
+ (int)MOZILLA;
@end

@interface KalturaLiveStreamAdminEntryOrderBy : NSObject
+ (NSString*)MEDIA_TYPE_ASC;
+ (NSString*)MEDIA_TYPE_DESC;
+ (NSString*)PLAYS_ASC;
+ (NSString*)PLAYS_DESC;
+ (NSString*)VIEWS_ASC;
+ (NSString*)VIEWS_DESC;
+ (NSString*)DURATION_ASC;
+ (NSString*)DURATION_DESC;
+ (NSString*)MS_DURATION_ASC;
+ (NSString*)MS_DURATION_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)MODERATION_COUNT_ASC;
+ (NSString*)MODERATION_COUNT_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)RANK_ASC;
+ (NSString*)RANK_DESC;
+ (NSString*)START_DATE_ASC;
+ (NSString*)START_DATE_DESC;
+ (NSString*)END_DATE_ASC;
+ (NSString*)END_DATE_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

@interface KalturaLiveStreamEntryOrderBy : NSObject
+ (NSString*)MEDIA_TYPE_ASC;
+ (NSString*)MEDIA_TYPE_DESC;
+ (NSString*)PLAYS_ASC;
+ (NSString*)PLAYS_DESC;
+ (NSString*)VIEWS_ASC;
+ (NSString*)VIEWS_DESC;
+ (NSString*)DURATION_ASC;
+ (NSString*)DURATION_DESC;
+ (NSString*)MS_DURATION_ASC;
+ (NSString*)MS_DURATION_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)MODERATION_COUNT_ASC;
+ (NSString*)MODERATION_COUNT_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)RANK_ASC;
+ (NSString*)RANK_DESC;
+ (NSString*)START_DATE_ASC;
+ (NSString*)START_DATE_DESC;
+ (NSString*)END_DATE_ASC;
+ (NSString*)END_DATE_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

@interface KalturaMailJobOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)PROCESSOR_EXPIRATION_ASC;
+ (NSString*)PROCESSOR_EXPIRATION_DESC;
+ (NSString*)EXECUTION_ATTEMPTS_ASC;
+ (NSString*)EXECUTION_ATTEMPTS_DESC;
+ (NSString*)LOCK_VERSION_ASC;
+ (NSString*)LOCK_VERSION_DESC;
@end

@interface KalturaMediaEntryOrderBy : NSObject
+ (NSString*)MEDIA_TYPE_ASC;
+ (NSString*)MEDIA_TYPE_DESC;
+ (NSString*)PLAYS_ASC;
+ (NSString*)PLAYS_DESC;
+ (NSString*)VIEWS_ASC;
+ (NSString*)VIEWS_DESC;
+ (NSString*)DURATION_ASC;
+ (NSString*)DURATION_DESC;
+ (NSString*)MS_DURATION_ASC;
+ (NSString*)MS_DURATION_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)MODERATION_COUNT_ASC;
+ (NSString*)MODERATION_COUNT_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)RANK_ASC;
+ (NSString*)RANK_DESC;
+ (NSString*)START_DATE_ASC;
+ (NSString*)START_DATE_DESC;
+ (NSString*)END_DATE_ASC;
+ (NSString*)END_DATE_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

@interface KalturaMediaFlavorParamsOrderBy : NSObject
@end

@interface KalturaMediaFlavorParamsOutputOrderBy : NSObject
@end

@interface KalturaMediaInfoOrderBy : NSObject
@end

@interface KalturaMediaParserType : NSObject
+ (NSString*)MEDIAINFO;
+ (NSString*)FFMPEG;
+ (NSString*)REMOTE_MEDIAINFO;
@end

@interface KalturaMediaType : NSObject
+ (int)VIDEO;
+ (int)IMAGE;
+ (int)AUDIO;
+ (int)LIVE_STREAM_FLASH;
+ (int)LIVE_STREAM_WINDOWS_MEDIA;
+ (int)LIVE_STREAM_REAL_MEDIA;
+ (int)LIVE_STREAM_QUICKTIME;
@end

@interface KalturaMixEntryOrderBy : NSObject
+ (NSString*)PLAYS_ASC;
+ (NSString*)PLAYS_DESC;
+ (NSString*)VIEWS_ASC;
+ (NSString*)VIEWS_DESC;
+ (NSString*)DURATION_ASC;
+ (NSString*)DURATION_DESC;
+ (NSString*)MS_DURATION_ASC;
+ (NSString*)MS_DURATION_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)MODERATION_COUNT_ASC;
+ (NSString*)MODERATION_COUNT_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)RANK_ASC;
+ (NSString*)RANK_DESC;
+ (NSString*)START_DATE_ASC;
+ (NSString*)START_DATE_DESC;
+ (NSString*)END_DATE_ASC;
+ (NSString*)END_DATE_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

@interface KalturaModerationFlagStatus : NSObject
+ (int)PENDING;
+ (int)MODERATED;
@end

@interface KalturaModerationFlagType : NSObject
+ (int)SEXUAL_CONTENT;
+ (int)VIOLENT_REPULSIVE;
+ (int)HARMFUL_DANGEROUS;
+ (int)SPAM_COMMERCIALS;
@end

@interface KalturaModerationObjectType : NSObject
+ (int)ENTRY;
+ (int)USER;
@end

@interface KalturaNotificationOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)PROCESSOR_EXPIRATION_ASC;
+ (NSString*)PROCESSOR_EXPIRATION_DESC;
+ (NSString*)EXECUTION_ATTEMPTS_ASC;
+ (NSString*)EXECUTION_ATTEMPTS_DESC;
+ (NSString*)LOCK_VERSION_ASC;
+ (NSString*)LOCK_VERSION_DESC;
@end

@interface KalturaNotificationType : NSObject
+ (int)ENTRY_ADD;
+ (int)ENTR_UPDATE_PERMISSIONS;
+ (int)ENTRY_DELETE;
+ (int)ENTRY_BLOCK;
+ (int)ENTRY_UPDATE;
+ (int)ENTRY_UPDATE_THUMBNAIL;
+ (int)ENTRY_UPDATE_MODERATION;
+ (int)USER_ADD;
+ (int)USER_BANNED;
@end

@interface KalturaNullableBoolean : NSObject
+ (int)NULL_VALUE;
+ (int)FALSE_VALUE;
+ (int)TRUE_VALUE;
@end

@interface KalturaPartnerOrderBy : NSObject
+ (NSString*)ID_ASC;
+ (NSString*)ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)WEBSITE_ASC;
+ (NSString*)WEBSITE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)ADMIN_NAME_ASC;
+ (NSString*)ADMIN_NAME_DESC;
+ (NSString*)ADMIN_EMAIL_ASC;
+ (NSString*)ADMIN_EMAIL_DESC;
+ (NSString*)STATUS_ASC;
+ (NSString*)STATUS_DESC;
@end

@interface KalturaPartnerStatus : NSObject
+ (int)ACTIVE;
+ (int)BLOCKED;
+ (int)FULL_BLOCK;
@end

@interface KalturaPartnerType : NSObject
+ (int)KMC;
+ (int)WIKI;
+ (int)WORDPRESS;
+ (int)DRUPAL;
+ (int)DEKIWIKI;
+ (int)MOODLE;
+ (int)COMMUNITY_EDITION;
+ (int)JOOMLA;
+ (int)BLACKBOARD;
+ (int)SAKAI;
@end

@interface KalturaPermissionItemOrderBy : NSObject
+ (NSString*)ID_ASC;
+ (NSString*)ID_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaPermissionItemType : NSObject
+ (NSString*)API_ACTION_ITEM;
+ (NSString*)API_PARAMETER_ITEM;
@end

@interface KalturaPermissionOrderBy : NSObject
+ (NSString*)ID_ASC;
+ (NSString*)ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaPermissionStatus : NSObject
+ (int)ACTIVE;
+ (int)BLOCKED;
+ (int)DELETED;
@end

@interface KalturaPermissionType : NSObject
+ (int)NORMAL;
+ (int)SPECIAL_FEATURE;
+ (int)PLUGIN;
+ (int)PARTNER_GROUP;
@end

@interface KalturaPlayableEntryOrderBy : NSObject
+ (NSString*)PLAYS_ASC;
+ (NSString*)PLAYS_DESC;
+ (NSString*)VIEWS_ASC;
+ (NSString*)VIEWS_DESC;
+ (NSString*)DURATION_ASC;
+ (NSString*)DURATION_DESC;
+ (NSString*)MS_DURATION_ASC;
+ (NSString*)MS_DURATION_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)MODERATION_COUNT_ASC;
+ (NSString*)MODERATION_COUNT_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)RANK_ASC;
+ (NSString*)RANK_DESC;
+ (NSString*)START_DATE_ASC;
+ (NSString*)START_DATE_DESC;
+ (NSString*)END_DATE_ASC;
+ (NSString*)END_DATE_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

@interface KalturaPlaylistOrderBy : NSObject
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)MODERATION_COUNT_ASC;
+ (NSString*)MODERATION_COUNT_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)RANK_ASC;
+ (NSString*)RANK_DESC;
+ (NSString*)START_DATE_ASC;
+ (NSString*)START_DATE_DESC;
+ (NSString*)END_DATE_ASC;
+ (NSString*)END_DATE_DESC;
+ (NSString*)PARTNER_SORT_VALUE_ASC;
+ (NSString*)PARTNER_SORT_VALUE_DESC;
@end

@interface KalturaPlaylistType : NSObject
+ (int)DYNAMIC;
+ (int)STATIC_LIST;
+ (int)EXTERNAL;
@end

@interface KalturaReportOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaReportType : NSObject
+ (int)TOP_CONTENT;
+ (int)CONTENT_DROPOFF;
+ (int)CONTENT_INTERACTIONS;
+ (int)MAP_OVERLAY;
+ (int)TOP_CONTRIBUTORS;
+ (int)TOP_SYNDICATION;
+ (int)CONTENT_CONTRIBUTIONS;
+ (int)WIDGETS_STATS;
@end

@interface KalturaSchemaType : NSObject
+ (NSString*)SYNDICATION;
+ (NSString*)BULK_UPLOAD_XML;
+ (NSString*)BULK_UPLOAD_RESULT_XML;
+ (NSString*)DROP_FOLDER_XML;
+ (NSString*)SERVE_API;
+ (NSString*)INGEST_API;
@end

@interface KalturaSearchConditionComparison : NSObject
+ (NSString*)EQUAL;
+ (NSString*)GREATER_THAN;
+ (NSString*)GREATER_THAN_OR_EQUAL;
+ (NSString*)LESS_THAN;
+ (NSString*)LESS_THAN_OR_EQUAL;
+ (NSString*)EQUEL;
+ (NSString*)GREATER_THAN_OR_EQUEL;
+ (NSString*)LESS_THAN_OR_EQUEL;
@end

@interface KalturaSearchOperatorType : NSObject
+ (int)SEARCH_AND;
+ (int)SEARCH_OR;
@end

@interface KalturaSearchProviderType : NSObject
+ (int)FLICKR;
+ (int)YOUTUBE;
+ (int)MYSPACE;
+ (int)PHOTOBUCKET;
+ (int)JAMENDO;
+ (int)CCMIXTER;
+ (int)NYPL;
+ (int)CURRENT;
+ (int)MEDIA_COMMONS;
+ (int)KALTURA;
+ (int)KALTURA_USER_CLIPS;
+ (int)ARCHIVE_ORG;
+ (int)KALTURA_PARTNER;
+ (int)METACAFE;
+ (int)SEARCH_PROXY;
+ (int)PARTNER_SPECIFIC;
@end

@interface KalturaSessionType : NSObject
+ (int)USER;
+ (int)ADMIN;
@end

@interface KalturaSiteRestrictionType : NSObject
+ (int)RESTRICT_SITE_LIST;
+ (int)ALLOW_SITE_LIST;
@end

@interface KalturaSourceType : NSObject
+ (NSString*)FILE;
+ (NSString*)WEBCAM;
+ (NSString*)URL;
+ (NSString*)SEARCH_PROVIDER;
+ (NSString*)AKAMAI_LIVE;
+ (NSString*)MANUAL_LIVE_STREAM;
+ (NSString*)LIMELIGHT_LIVE;
@end

@interface KalturaStatsEventType : NSObject
+ (int)WIDGET_LOADED;
+ (int)MEDIA_LOADED;
+ (int)PLAY;
+ (int)PLAY_REACHED_25;
+ (int)PLAY_REACHED_50;
+ (int)PLAY_REACHED_75;
+ (int)PLAY_REACHED_100;
+ (int)OPEN_EDIT;
+ (int)OPEN_VIRAL;
+ (int)OPEN_DOWNLOAD;
+ (int)OPEN_REPORT;
+ (int)BUFFER_START;
+ (int)BUFFER_END;
+ (int)OPEN_FULL_SCREEN;
+ (int)CLOSE_FULL_SCREEN;
+ (int)REPLAY;
+ (int)SEEK;
+ (int)OPEN_UPLOAD;
+ (int)SAVE_PUBLISH;
+ (int)CLOSE_EDITOR;
+ (int)PRE_BUMPER_PLAYED;
+ (int)POST_BUMPER_PLAYED;
+ (int)BUMPER_CLICKED;
+ (int)PREROLL_STARTED;
+ (int)MIDROLL_STARTED;
+ (int)POSTROLL_STARTED;
+ (int)OVERLAY_STARTED;
+ (int)PREROLL_CLICKED;
+ (int)MIDROLL_CLICKED;
+ (int)POSTROLL_CLICKED;
+ (int)OVERLAY_CLICKED;
+ (int)PREROLL_25;
+ (int)PREROLL_50;
+ (int)PREROLL_75;
+ (int)MIDROLL_25;
+ (int)MIDROLL_50;
+ (int)MIDROLL_75;
+ (int)POSTROLL_25;
+ (int)POSTROLL_50;
+ (int)POSTROLL_75;
@end

@interface KalturaStatsKmcEventType : NSObject
+ (int)CONTENT_PAGE_VIEW;
+ (int)CONTENT_ADD_PLAYLIST;
+ (int)CONTENT_EDIT_PLAYLIST;
+ (int)CONTENT_DELETE_PLAYLIST;
+ (int)CONTENT_DELETE_ITEM;
+ (int)CONTENT_DELETE_MIX;
+ (int)CONTENT_EDIT_ENTRY;
+ (int)CONTENT_CHANGE_THUMBNAIL;
+ (int)CONTENT_ADD_TAGS;
+ (int)CONTENT_REMOVE_TAGS;
+ (int)CONTENT_ADD_ADMIN_TAGS;
+ (int)CONTENT_REMOVE_ADMIN_TAGS;
+ (int)CONTENT_DOWNLOAD;
+ (int)CONTENT_APPROVE_MODERATION;
+ (int)CONTENT_REJECT_MODERATION;
+ (int)CONTENT_BULK_UPLOAD;
+ (int)CONTENT_ADMIN_KCW_UPLOAD;
+ (int)CONTENT_CONTENT_GO_TO_PAGE;
+ (int)CONTENT_ENTRY_DRILLDOWN;
+ (int)CONTENT_OPEN_PREVIEW_AND_EMBED;
+ (int)ACCOUNT_CHANGE_PARTNER_INFO;
+ (int)ACCOUNT_CHANGE_LOGIN_INFO;
+ (int)ACCOUNT_CONTACT_US_USAGE;
+ (int)ACCOUNT_UPDATE_SERVER_SETTINGS;
+ (int)ACCOUNT_ACCOUNT_OVERVIEW;
+ (int)ACCOUNT_ACCESS_CONTROL;
+ (int)ACCOUNT_TRANSCODING_SETTINGS;
+ (int)ACCOUNT_ACCOUNT_UPGRADE;
+ (int)ACCOUNT_SAVE_SERVER_SETTINGS;
+ (int)ACCOUNT_ACCESS_CONTROL_DELETE;
+ (int)ACCOUNT_SAVE_TRANSCODING_SETTINGS;
+ (int)LOGIN;
+ (int)DASHBOARD_IMPORT_CONTENT;
+ (int)DASHBOARD_UPDATE_CONTENT;
+ (int)DASHBOARD_ACCOUNT_CONTACT_US;
+ (int)DASHBOARD_VIEW_REPORTS;
+ (int)DASHBOARD_EMBED_PLAYER;
+ (int)DASHBOARD_EMBED_PLAYLIST;
+ (int)DASHBOARD_CUSTOMIZE_PLAYERS;
+ (int)APP_STUDIO_NEW_PLAYER_SINGLE_VIDEO;
+ (int)APP_STUDIO_NEW_PLAYER_PLAYLIST;
+ (int)APP_STUDIO_NEW_PLAYER_MULTI_TAB_PLAYLIST;
+ (int)APP_STUDIO_EDIT_PLAYER_SINGLE_VIDEO;
+ (int)APP_STUDIO_EDIT_PLAYER_PLAYLIST;
+ (int)APP_STUDIO_EDIT_PLAYER_MULTI_TAB_PLAYLIST;
+ (int)APP_STUDIO_DUPLICATE_PLAYER;
+ (int)REPORTS_AND_ANALYTICS_BANDWIDTH_USAGE_TAB;
+ (int)REPORTS_AND_ANALYTICS_CONTENT_REPORTS_TAB;
+ (int)REPORTS_AND_ANALYTICS_USERS_AND_COMMUNITY_REPORTS_TAB;
+ (int)REPORTS_AND_ANALYTICS_TOP_CONTRIBUTORS;
+ (int)REPORTS_AND_ANALYTICS_MAP_OVERLAYS;
+ (int)REPORTS_AND_ANALYTICS_TOP_SYNDICATIONS;
+ (int)REPORTS_AND_ANALYTICS_TOP_CONTENT;
+ (int)REPORTS_AND_ANALYTICS_CONTENT_DROPOFF;
+ (int)REPORTS_AND_ANALYTICS_CONTENT_INTERACTIONS;
+ (int)REPORTS_AND_ANALYTICS_CONTENT_CONTRIBUTIONS;
+ (int)REPORTS_AND_ANALYTICS_VIDEO_DRILL_DOWN;
+ (int)REPORTS_AND_ANALYTICS_CONTENT_DRILL_DOWN_INTERACTION;
+ (int)REPORTS_AND_ANALYTICS_CONTENT_CONTRIBUTIONS_DRILLDOWN;
+ (int)REPORTS_AND_ANALYTICS_VIDEO_DRILL_DOWN_DROPOFF;
+ (int)REPORTS_AND_ANALYTICS_MAP_OVERLAYS_DRILLDOWN;
+ (int)REPORTS_AND_ANALYTICS_TOP_SYNDICATIONS_DRILL_DOWN;
+ (int)REPORTS_AND_ANALYTICS_BANDWIDTH_USAGE_VIEW_MONTHLY;
+ (int)REPORTS_AND_ANALYTICS_BANDWIDTH_USAGE_VIEW_YEARLY;
@end

@interface KalturaStorageProfileDeliveryStatus : NSObject
+ (int)ACTIVE;
+ (int)BLOCKED;
@end

@interface KalturaStorageProfileOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaStorageProfileProtocol : NSObject
+ (int)KALTURA_DC;
+ (int)FTP;
+ (int)SCP;
+ (int)SFTP;
+ (int)S3;
@end

@interface KalturaStorageProfileStatus : NSObject
+ (int)DISABLED;
+ (int)AUTOMATIC;
+ (int)MANUAL;
@end

@interface KalturaSyndicationFeedStatus : NSObject
+ (int)DELETED;
+ (int)ACTIVE;
@end

@interface KalturaSyndicationFeedType : NSObject
+ (int)GOOGLE_VIDEO;
+ (int)YAHOO;
+ (int)ITUNES;
+ (int)TUBE_MOGUL;
+ (int)KALTURA;
+ (int)KALTURA_XSLT;
@end

@interface KalturaThumbAssetOrderBy : NSObject
+ (NSString*)SIZE_ASC;
+ (NSString*)SIZE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
+ (NSString*)DELETED_AT_ASC;
+ (NSString*)DELETED_AT_DESC;
@end

@interface KalturaThumbAssetStatus : NSObject
+ (int)ERROR;
+ (int)QUEUED;
+ (int)READY;
+ (int)DELETED;
+ (int)IMPORTING;
@end

@interface KalturaThumbCropType : NSObject
+ (int)RESIZE;
+ (int)RESIZE_WITH_PADDING;
+ (int)CROP;
+ (int)CROP_FROM_TOP;
@end

@interface KalturaThumbParamsOrderBy : NSObject
@end

@interface KalturaThumbParamsOutputOrderBy : NSObject
@end

@interface KalturaTubeMogulSyndicationFeedCategories : NSObject
+ (NSString*)ARTS_AND_ANIMATION;
+ (NSString*)COMEDY;
+ (NSString*)ENTERTAINMENT;
+ (NSString*)MUSIC;
+ (NSString*)NEWS_AND_BLOGS;
+ (NSString*)SCIENCE_AND_TECHNOLOGY;
+ (NSString*)SPORTS;
+ (NSString*)TRAVEL_AND_PLACES;
+ (NSString*)VIDEO_GAMES;
+ (NSString*)ANIMALS_AND_PETS;
+ (NSString*)AUTOS;
+ (NSString*)VLOGS_PEOPLE;
+ (NSString*)HOW_TO_INSTRUCTIONAL_DIY;
+ (NSString*)COMMERCIALS_PROMOTIONAL;
+ (NSString*)FAMILY_AND_KIDS;
@end

@interface KalturaTubeMogulSyndicationFeedOrderBy : NSObject
+ (NSString*)PLAYLIST_ID_ASC;
+ (NSString*)PLAYLIST_ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)TYPE_ASC;
+ (NSString*)TYPE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaUiConfCreationMode : NSObject
+ (int)WIZARD;
+ (int)ADVANCED;
@end

@interface KalturaUiConfObjType : NSObject
+ (int)PLAYER;
+ (int)CONTRIBUTION_WIZARD;
+ (int)SIMPLE_EDITOR;
+ (int)ADVANCED_EDITOR;
+ (int)PLAYLIST;
+ (int)APP_STUDIO;
+ (int)KRECORD;
+ (int)PLAYER_V3;
+ (int)KMC_ACCOUNT;
+ (int)KMC_ANALYTICS;
+ (int)KMC_CONTENT;
+ (int)KMC_DASHBOARD;
+ (int)KMC_LOGIN;
+ (int)PLAYER_SL;
+ (int)CLIENTSIDE_ENCODER;
+ (int)KMC_GENERAL;
+ (int)KMC_ROLES_AND_PERMISSIONS;
+ (int)CLIPPER;
@end

@interface KalturaUiConfOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaUploadErrorCode : NSObject
+ (int)NO_ERROR;
+ (int)GENERAL_ERROR;
+ (int)PARTIAL_UPLOAD;
@end

@interface KalturaUploadTokenOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaUploadTokenStatus : NSObject
+ (int)PENDING;
+ (int)PARTIAL_UPLOAD;
+ (int)FULL_UPLOAD;
+ (int)CLOSED;
+ (int)TIMED_OUT;
+ (int)DELETED;
@end

@interface KalturaUserAgentRestrictionType : NSObject
+ (int)RESTRICT_LIST;
+ (int)ALLOW_LIST;
@end

@interface KalturaUserLoginDataOrderBy : NSObject
@end

@interface KalturaUserOrderBy : NSObject
+ (NSString*)ID_ASC;
+ (NSString*)ID_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaUserRoleOrderBy : NSObject
+ (NSString*)ID_ASC;
+ (NSString*)ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
+ (NSString*)UPDATED_AT_ASC;
+ (NSString*)UPDATED_AT_DESC;
@end

@interface KalturaUserRoleStatus : NSObject
+ (int)ACTIVE;
+ (int)BLOCKED;
+ (int)DELETED;
@end

@interface KalturaUserStatus : NSObject
+ (int)BLOCKED;
+ (int)ACTIVE;
+ (int)DELETED;
@end

@interface KalturaVideoCodec : NSObject
+ (NSString*)NONE;
+ (NSString*)VP6;
+ (NSString*)H263;
+ (NSString*)H264;
+ (NSString*)H264B;
+ (NSString*)H264M;
+ (NSString*)H264H;
+ (NSString*)FLV;
+ (NSString*)MPEG4;
+ (NSString*)THEORA;
+ (NSString*)WMV2;
+ (NSString*)WMV3;
+ (NSString*)WVC1A;
+ (NSString*)VP8;
+ (NSString*)MPEG2;
+ (NSString*)COPY;
@end

@interface KalturaWidgetOrderBy : NSObject
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

@interface KalturaWidgetSecurityType : NSObject
+ (int)NONE;
+ (int)TIMEHASH;
@end

@interface KalturaYahooSyndicationFeedAdultValues : NSObject
+ (NSString*)ADULT;
+ (NSString*)NON_ADULT;
@end

@interface KalturaYahooSyndicationFeedCategories : NSObject
+ (NSString*)ACTION;
+ (NSString*)ART_AND_ANIMATION;
+ (NSString*)ENTERTAINMENT_AND_TV;
+ (NSString*)FOOD;
+ (NSString*)GAMES;
+ (NSString*)HOW_TO;
+ (NSString*)MUSIC;
+ (NSString*)PEOPLE_AND_VLOGS;
+ (NSString*)SCIENCE_AND_ENVIRONMENT;
+ (NSString*)TRANSPORTATION;
+ (NSString*)ANIMALS;
+ (NSString*)COMMERCIALS;
+ (NSString*)FAMILY;
+ (NSString*)FUNNY_VIDEOS;
+ (NSString*)HEALTH_AND_BEAUTY;
+ (NSString*)MOVIES_AND_SHORTS;
+ (NSString*)NEWS_AND_POLITICS;
+ (NSString*)PRODUCTS_AND_TECH;
+ (NSString*)SPORTS;
+ (NSString*)TRAVEL;
@end

@interface KalturaYahooSyndicationFeedOrderBy : NSObject
+ (NSString*)PLAYLIST_ID_ASC;
+ (NSString*)PLAYLIST_ID_DESC;
+ (NSString*)NAME_ASC;
+ (NSString*)NAME_DESC;
+ (NSString*)TYPE_ASC;
+ (NSString*)TYPE_DESC;
+ (NSString*)CREATED_AT_ASC;
+ (NSString*)CREATED_AT_DESC;
@end

///////////////////////// classes /////////////////////////
@interface KalturaDynamicEnum : KalturaObjectBase
@end

@interface KalturaAccessControlAction : KalturaObjectBase
// The type of the access control action
@property (nonatomic,copy) NSString* type;	// enum KalturaAccessControlActionType
- (KalturaFieldType)getTypeOfType;
@end

@interface KalturaAccessControlBlockAction : KalturaAccessControlAction
@end

@interface KalturaAccessControlPreviewAction : KalturaAccessControlAction
@property (nonatomic,assign) int limit;
- (KalturaFieldType)getTypeOfLimit;
- (void)setLimitFromString:(NSString*)aPropVal;
@end

@interface KalturaCondition : KalturaObjectBase
// The type of the access control condition
@property (nonatomic,copy,readonly) NSString* type;	// enum KalturaConditionType
@property (nonatomic,assign) BOOL not;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfNot;
- (void)setNotFromString:(NSString*)aPropVal;
@end

// A representation to return an array of values
@interface KalturaValue : KalturaObjectBase
@end

// A string representation to return an array of strings
@interface KalturaStringValue : KalturaValue
@property (nonatomic,copy) NSString* value;
- (KalturaFieldType)getTypeOfValue;
@end

// A string representation to return evaluated dynamic value
@interface KalturaStringField : KalturaStringValue
@end

// Represents the current request country context as calculated based on the IP address
@interface KalturaCountryContextField : KalturaStringField
// The ip geo coder engine to be used
@property (nonatomic,copy) NSString* geoCoderType;	// enum KalturaGeoCoderType
- (KalturaFieldType)getTypeOfGeoCoderType;
@end

// Represents the current request IP address context
@interface KalturaIpAddressContextField : KalturaStringField
@end

// Represents the current request user agent context
@interface KalturaUserAgentContextField : KalturaStringField
@end

// An int representation to return an array of ints
@interface KalturaIntegerValue : KalturaValue
@property (nonatomic,assign) int value;
- (KalturaFieldType)getTypeOfValue;
- (void)setValueFromString:(NSString*)aPropVal;
@end

// An int representation to return evaluated dynamic value
@interface KalturaIntegerField : KalturaIntegerValue
@end

// Represents the current time context on Kaltura servers
@interface KalturaTimeContextField : KalturaIntegerField
// Time offset in seconds since current time
@property (nonatomic,assign) int offset;
- (KalturaFieldType)getTypeOfOffset;
- (void)setOffsetFromString:(NSString*)aPropVal;
@end

@interface KalturaAuthenticatedCondition : KalturaCondition
// The privelege needed to remove the restriction
@property (nonatomic,retain) NSMutableArray* privileges;	// of KalturaStringValue elements
- (KalturaFieldType)getTypeOfPrivileges;
- (NSString*)getObjectTypeOfPrivileges;
@end

@interface KalturaCompareCondition : KalturaCondition
// Value to evaluate against the field and operator
@property (nonatomic,retain) KalturaIntegerValue* value;
// Comparing operator
@property (nonatomic,copy) NSString* comparison;	// enum KalturaSearchConditionComparison
- (KalturaFieldType)getTypeOfValue;
- (NSString*)getObjectTypeOfValue;
- (KalturaFieldType)getTypeOfComparison;
@end

@interface KalturaFieldCompareCondition : KalturaCompareCondition
// Field to evaluate
@property (nonatomic,retain) KalturaIntegerField* field;
- (KalturaFieldType)getTypeOfField;
- (NSString*)getObjectTypeOfField;
@end

@interface KalturaMatchCondition : KalturaCondition
@property (nonatomic,retain) NSMutableArray* values;	// of KalturaStringValue elements
- (KalturaFieldType)getTypeOfValues;
- (NSString*)getObjectTypeOfValues;
@end

@interface KalturaCountryCondition : KalturaMatchCondition
// The ip geo coder engine to be used
@property (nonatomic,copy) NSString* geoCoderType;	// enum KalturaGeoCoderType
- (KalturaFieldType)getTypeOfGeoCoderType;
@end

@interface KalturaFieldMatchCondition : KalturaMatchCondition
// Field to evaluate
@property (nonatomic,retain) KalturaStringField* field;
- (KalturaFieldType)getTypeOfField;
- (NSString*)getObjectTypeOfField;
@end

@interface KalturaIpAddressCondition : KalturaMatchCondition
@end

@interface KalturaRegexCondition : KalturaMatchCondition
@end

@interface KalturaUserAgentCondition : KalturaRegexCondition
@end

@interface KalturaSiteCondition : KalturaMatchCondition
@end

@interface KalturaAccessControlContextTypeHolder : KalturaObjectBase
// The type of the access control condition context
@property (nonatomic,copy) NSString* type;	// enum KalturaAccessControlContextType
- (KalturaFieldType)getTypeOfType;
@end

@interface KalturaRule : KalturaObjectBase
// Message to be thrown to the player in case the rule fulfilled
@property (nonatomic,copy) NSString* message;
// Actions to be performed by the player in case the rule fulfilled
@property (nonatomic,retain) NSMutableArray* actions;	// of KalturaAccessControlAction elements
// Conditions to validate the rule
@property (nonatomic,retain) NSMutableArray* conditions;	// of KalturaCondition elements
// Indicates what contexts should be tested by this rule
@property (nonatomic,retain) NSMutableArray* contexts;	// of KalturaAccessControlContextTypeHolder elements
// Indicates that this rule is enough and no need to continue checking the rest of the rules
@property (nonatomic,assign) BOOL stopProcessing;
- (KalturaFieldType)getTypeOfMessage;
- (KalturaFieldType)getTypeOfActions;
- (NSString*)getObjectTypeOfActions;
- (KalturaFieldType)getTypeOfConditions;
- (NSString*)getObjectTypeOfConditions;
- (KalturaFieldType)getTypeOfContexts;
- (NSString*)getObjectTypeOfContexts;
- (KalturaFieldType)getTypeOfStopProcessing;
- (void)setStopProcessingFromString:(NSString*)aPropVal;
@end

@interface KalturaAccessControlProfile : KalturaObjectBase
// The id of the Access Control Profile
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int partnerId;
// The name of the Access Control Profile
@property (nonatomic,copy) NSString* name;
// System name of the Access Control Profile
@property (nonatomic,copy) NSString* systemName;
// The description of the Access Control Profile
@property (nonatomic,copy) NSString* description;
// Creation time as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Update time as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
// True if this access control profile is the partner default
@property (nonatomic,assign) int isDefault;	// enum KalturaNullableBoolean
// Array of access control rules
@property (nonatomic,retain) NSMutableArray* rules;	// of KalturaRule elements
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfSystemName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfIsDefault;
- (KalturaFieldType)getTypeOfRules;
- (NSString*)getObjectTypeOfRules;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setIsDefaultFromString:(NSString*)aPropVal;
@end

@interface KalturaSearchItem : KalturaObjectBase
@end

@interface KalturaSearchCondition : KalturaSearchItem
@property (nonatomic,copy) NSString* field;
@property (nonatomic,copy) NSString* value;
- (KalturaFieldType)getTypeOfField;
- (KalturaFieldType)getTypeOfValue;
@end

@interface KalturaSearchComparableCondition : KalturaSearchCondition
@property (nonatomic,copy) NSString* comparison;	// enum KalturaSearchConditionComparison
- (KalturaFieldType)getTypeOfComparison;
@end

@interface KalturaSearchOperator : KalturaSearchItem
@property (nonatomic,assign) int type;	// enum KalturaSearchOperatorType
@property (nonatomic,retain) NSMutableArray* items;	// of KalturaSearchItem elements
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfItems;
- (NSString*)getObjectTypeOfItems;
- (void)setTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaFilter : KalturaObjectBase
@property (nonatomic,copy) NSString* orderBy;
@property (nonatomic,retain) KalturaSearchItem* advancedSearch;
- (KalturaFieldType)getTypeOfOrderBy;
- (KalturaFieldType)getTypeOfAdvancedSearch;
- (NSString*)getObjectTypeOfAdvancedSearch;
@end

@interface KalturaAccessControlBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* systemNameEqual;
@property (nonatomic,copy) NSString* systemNameIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfSystemNameEqual;
- (KalturaFieldType)getTypeOfSystemNameIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
@end

// DEPRECATED - use KalturaAccessControlProfileFilter instead
@interface KalturaAccessControlFilter : KalturaAccessControlBaseFilter
@end

@interface KalturaAccessControlProfileBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* systemNameEqual;
@property (nonatomic,copy) NSString* systemNameIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfSystemNameEqual;
- (KalturaFieldType)getTypeOfSystemNameIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaAccessControlProfileFilter : KalturaAccessControlProfileBaseFilter
@end

@interface KalturaBaseJobBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,assign) int idGreaterThanOrEqual;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,copy) NSString* partnerIdNotIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int processorExpirationGreaterThanOrEqual;
@property (nonatomic,assign) int processorExpirationLessThanOrEqual;
@property (nonatomic,assign) int executionAttemptsGreaterThanOrEqual;
@property (nonatomic,assign) int executionAttemptsLessThanOrEqual;
@property (nonatomic,assign) int lockVersionGreaterThanOrEqual;
@property (nonatomic,assign) int lockVersionLessThanOrEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfPartnerIdNotIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfProcessorExpirationGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfProcessorExpirationLessThanOrEqual;
- (KalturaFieldType)getTypeOfExecutionAttemptsGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfExecutionAttemptsLessThanOrEqual;
- (KalturaFieldType)getTypeOfLockVersionGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfLockVersionLessThanOrEqual;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setIdGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setProcessorExpirationGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setProcessorExpirationLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setExecutionAttemptsGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setExecutionAttemptsLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setLockVersionGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setLockVersionLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaBaseJobFilter : KalturaBaseJobBaseFilter
@end

@interface KalturaBatchJobBaseFilter : KalturaBaseJobFilter
@property (nonatomic,copy) NSString* entryIdEqual;
@property (nonatomic,copy) NSString* jobTypeEqual;	// enum KalturaBatchJobType
@property (nonatomic,copy) NSString* jobTypeIn;
@property (nonatomic,copy) NSString* jobTypeNotIn;
@property (nonatomic,assign) int jobSubTypeEqual;
@property (nonatomic,copy) NSString* jobSubTypeIn;
@property (nonatomic,copy) NSString* jobSubTypeNotIn;
@property (nonatomic,assign) int onStressDivertToEqual;
@property (nonatomic,copy) NSString* onStressDivertToIn;
@property (nonatomic,copy) NSString* onStressDivertToNotIn;
@property (nonatomic,assign) int statusEqual;	// enum KalturaBatchJobStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,copy) NSString* statusNotIn;
@property (nonatomic,assign) int abortEqual;
@property (nonatomic,assign) int checkAgainTimeoutGreaterThanOrEqual;
@property (nonatomic,assign) int checkAgainTimeoutLessThanOrEqual;
@property (nonatomic,assign) int progressGreaterThanOrEqual;
@property (nonatomic,assign) int progressLessThanOrEqual;
@property (nonatomic,assign) int updatesCountGreaterThanOrEqual;
@property (nonatomic,assign) int updatesCountLessThanOrEqual;
@property (nonatomic,assign) int priorityGreaterThanOrEqual;
@property (nonatomic,assign) int priorityLessThanOrEqual;
@property (nonatomic,assign) int priorityEqual;
@property (nonatomic,copy) NSString* priorityIn;
@property (nonatomic,copy) NSString* priorityNotIn;
@property (nonatomic,assign) int twinJobIdEqual;
@property (nonatomic,copy) NSString* twinJobIdIn;
@property (nonatomic,copy) NSString* twinJobIdNotIn;
@property (nonatomic,assign) int bulkJobIdEqual;
@property (nonatomic,copy) NSString* bulkJobIdIn;
@property (nonatomic,copy) NSString* bulkJobIdNotIn;
@property (nonatomic,assign) int parentJobIdEqual;
@property (nonatomic,copy) NSString* parentJobIdIn;
@property (nonatomic,copy) NSString* parentJobIdNotIn;
@property (nonatomic,assign) int rootJobIdEqual;
@property (nonatomic,copy) NSString* rootJobIdIn;
@property (nonatomic,copy) NSString* rootJobIdNotIn;
@property (nonatomic,assign) int queueTimeGreaterThanOrEqual;
@property (nonatomic,assign) int queueTimeLessThanOrEqual;
@property (nonatomic,assign) int finishTimeGreaterThanOrEqual;
@property (nonatomic,assign) int finishTimeLessThanOrEqual;
@property (nonatomic,assign) int errTypeEqual;	// enum KalturaBatchJobErrorTypes
@property (nonatomic,copy) NSString* errTypeIn;
@property (nonatomic,copy) NSString* errTypeNotIn;
@property (nonatomic,assign) int errNumberEqual;
@property (nonatomic,copy) NSString* errNumberIn;
@property (nonatomic,copy) NSString* errNumberNotIn;
@property (nonatomic,assign) int fileSizeLessThan;
@property (nonatomic,assign) int fileSizeGreaterThan;
@property (nonatomic,assign) BOOL lastWorkerRemoteEqual;
@property (nonatomic,assign) int schedulerIdEqual;
@property (nonatomic,copy) NSString* schedulerIdIn;
@property (nonatomic,copy) NSString* schedulerIdNotIn;
@property (nonatomic,assign) int workerIdEqual;
@property (nonatomic,copy) NSString* workerIdIn;
@property (nonatomic,copy) NSString* workerIdNotIn;
@property (nonatomic,assign) int batchIndexEqual;
@property (nonatomic,copy) NSString* batchIndexIn;
@property (nonatomic,copy) NSString* batchIndexNotIn;
@property (nonatomic,assign) int lastSchedulerIdEqual;
@property (nonatomic,copy) NSString* lastSchedulerIdIn;
@property (nonatomic,copy) NSString* lastSchedulerIdNotIn;
@property (nonatomic,assign) int lastWorkerIdEqual;
@property (nonatomic,copy) NSString* lastWorkerIdIn;
@property (nonatomic,copy) NSString* lastWorkerIdNotIn;
@property (nonatomic,assign) int dcEqual;
@property (nonatomic,copy) NSString* dcIn;
@property (nonatomic,copy) NSString* dcNotIn;
- (KalturaFieldType)getTypeOfEntryIdEqual;
- (KalturaFieldType)getTypeOfJobTypeEqual;
- (KalturaFieldType)getTypeOfJobTypeIn;
- (KalturaFieldType)getTypeOfJobTypeNotIn;
- (KalturaFieldType)getTypeOfJobSubTypeEqual;
- (KalturaFieldType)getTypeOfJobSubTypeIn;
- (KalturaFieldType)getTypeOfJobSubTypeNotIn;
- (KalturaFieldType)getTypeOfOnStressDivertToEqual;
- (KalturaFieldType)getTypeOfOnStressDivertToIn;
- (KalturaFieldType)getTypeOfOnStressDivertToNotIn;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfStatusNotIn;
- (KalturaFieldType)getTypeOfAbortEqual;
- (KalturaFieldType)getTypeOfCheckAgainTimeoutGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCheckAgainTimeoutLessThanOrEqual;
- (KalturaFieldType)getTypeOfProgressGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfProgressLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatesCountGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatesCountLessThanOrEqual;
- (KalturaFieldType)getTypeOfPriorityGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfPriorityLessThanOrEqual;
- (KalturaFieldType)getTypeOfPriorityEqual;
- (KalturaFieldType)getTypeOfPriorityIn;
- (KalturaFieldType)getTypeOfPriorityNotIn;
- (KalturaFieldType)getTypeOfTwinJobIdEqual;
- (KalturaFieldType)getTypeOfTwinJobIdIn;
- (KalturaFieldType)getTypeOfTwinJobIdNotIn;
- (KalturaFieldType)getTypeOfBulkJobIdEqual;
- (KalturaFieldType)getTypeOfBulkJobIdIn;
- (KalturaFieldType)getTypeOfBulkJobIdNotIn;
- (KalturaFieldType)getTypeOfParentJobIdEqual;
- (KalturaFieldType)getTypeOfParentJobIdIn;
- (KalturaFieldType)getTypeOfParentJobIdNotIn;
- (KalturaFieldType)getTypeOfRootJobIdEqual;
- (KalturaFieldType)getTypeOfRootJobIdIn;
- (KalturaFieldType)getTypeOfRootJobIdNotIn;
- (KalturaFieldType)getTypeOfQueueTimeGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfQueueTimeLessThanOrEqual;
- (KalturaFieldType)getTypeOfFinishTimeGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfFinishTimeLessThanOrEqual;
- (KalturaFieldType)getTypeOfErrTypeEqual;
- (KalturaFieldType)getTypeOfErrTypeIn;
- (KalturaFieldType)getTypeOfErrTypeNotIn;
- (KalturaFieldType)getTypeOfErrNumberEqual;
- (KalturaFieldType)getTypeOfErrNumberIn;
- (KalturaFieldType)getTypeOfErrNumberNotIn;
- (KalturaFieldType)getTypeOfFileSizeLessThan;
- (KalturaFieldType)getTypeOfFileSizeGreaterThan;
- (KalturaFieldType)getTypeOfLastWorkerRemoteEqual;
- (KalturaFieldType)getTypeOfSchedulerIdEqual;
- (KalturaFieldType)getTypeOfSchedulerIdIn;
- (KalturaFieldType)getTypeOfSchedulerIdNotIn;
- (KalturaFieldType)getTypeOfWorkerIdEqual;
- (KalturaFieldType)getTypeOfWorkerIdIn;
- (KalturaFieldType)getTypeOfWorkerIdNotIn;
- (KalturaFieldType)getTypeOfBatchIndexEqual;
- (KalturaFieldType)getTypeOfBatchIndexIn;
- (KalturaFieldType)getTypeOfBatchIndexNotIn;
- (KalturaFieldType)getTypeOfLastSchedulerIdEqual;
- (KalturaFieldType)getTypeOfLastSchedulerIdIn;
- (KalturaFieldType)getTypeOfLastSchedulerIdNotIn;
- (KalturaFieldType)getTypeOfLastWorkerIdEqual;
- (KalturaFieldType)getTypeOfLastWorkerIdIn;
- (KalturaFieldType)getTypeOfLastWorkerIdNotIn;
- (KalturaFieldType)getTypeOfDcEqual;
- (KalturaFieldType)getTypeOfDcIn;
- (KalturaFieldType)getTypeOfDcNotIn;
- (void)setJobSubTypeEqualFromString:(NSString*)aPropVal;
- (void)setOnStressDivertToEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
- (void)setAbortEqualFromString:(NSString*)aPropVal;
- (void)setCheckAgainTimeoutGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCheckAgainTimeoutLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setProgressGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setProgressLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatesCountGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatesCountLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setPriorityGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setPriorityLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setPriorityEqualFromString:(NSString*)aPropVal;
- (void)setTwinJobIdEqualFromString:(NSString*)aPropVal;
- (void)setBulkJobIdEqualFromString:(NSString*)aPropVal;
- (void)setParentJobIdEqualFromString:(NSString*)aPropVal;
- (void)setRootJobIdEqualFromString:(NSString*)aPropVal;
- (void)setQueueTimeGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setQueueTimeLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setFinishTimeGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setFinishTimeLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setErrTypeEqualFromString:(NSString*)aPropVal;
- (void)setErrNumberEqualFromString:(NSString*)aPropVal;
- (void)setFileSizeLessThanFromString:(NSString*)aPropVal;
- (void)setFileSizeGreaterThanFromString:(NSString*)aPropVal;
- (void)setLastWorkerRemoteEqualFromString:(NSString*)aPropVal;
- (void)setSchedulerIdEqualFromString:(NSString*)aPropVal;
- (void)setWorkerIdEqualFromString:(NSString*)aPropVal;
- (void)setBatchIndexEqualFromString:(NSString*)aPropVal;
- (void)setLastSchedulerIdEqualFromString:(NSString*)aPropVal;
- (void)setLastWorkerIdEqualFromString:(NSString*)aPropVal;
- (void)setDcEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaBatchJobFilter : KalturaBatchJobBaseFilter
@end

@interface KalturaBatchJobFilterExt : KalturaBatchJobFilter
@property (nonatomic,copy) NSString* jobTypeAndSubTypeIn;
- (KalturaFieldType)getTypeOfJobTypeAndSubTypeIn;
@end

@interface KalturaMailJobBaseFilter : KalturaBaseJobFilter
@end

@interface KalturaMailJobFilter : KalturaMailJobBaseFilter
@end

@interface KalturaNotificationBaseFilter : KalturaBaseJobFilter
@end

@interface KalturaNotificationFilter : KalturaNotificationBaseFilter
@end

@interface KalturaControlPanelCommandBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int createdByIdEqual;
@property (nonatomic,assign) int typeEqual;	// enum KalturaControlPanelCommandType
@property (nonatomic,copy) NSString* typeIn;
@property (nonatomic,assign) int targetTypeEqual;	// enum KalturaControlPanelCommandTargetType
@property (nonatomic,copy) NSString* targetTypeIn;
@property (nonatomic,assign) int statusEqual;	// enum KalturaControlPanelCommandStatus
@property (nonatomic,copy) NSString* statusIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedByIdEqual;
- (KalturaFieldType)getTypeOfTypeEqual;
- (KalturaFieldType)getTypeOfTypeIn;
- (KalturaFieldType)getTypeOfTargetTypeEqual;
- (KalturaFieldType)getTypeOfTargetTypeIn;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedByIdEqualFromString:(NSString*)aPropVal;
- (void)setTypeEqualFromString:(NSString*)aPropVal;
- (void)setTargetTypeEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaControlPanelCommandFilter : KalturaControlPanelCommandBaseFilter
@end

@interface KalturaAssetBaseFilter : KalturaFilter
@property (nonatomic,copy) NSString* idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* entryIdEqual;
@property (nonatomic,copy) NSString* entryIdIn;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,assign) int sizeGreaterThanOrEqual;
@property (nonatomic,assign) int sizeLessThanOrEqual;
@property (nonatomic,copy) NSString* tagsLike;
@property (nonatomic,copy) NSString* tagsMultiLikeOr;
@property (nonatomic,copy) NSString* tagsMultiLikeAnd;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int deletedAtGreaterThanOrEqual;
@property (nonatomic,assign) int deletedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfEntryIdEqual;
- (KalturaFieldType)getTypeOfEntryIdIn;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfSizeGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfSizeLessThanOrEqual;
- (KalturaFieldType)getTypeOfTagsLike;
- (KalturaFieldType)getTypeOfTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfDeletedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfDeletedAtLessThanOrEqual;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setSizeGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setSizeLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setDeletedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setDeletedAtLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaAssetFilter : KalturaAssetBaseFilter
@end

@interface KalturaFlavorAssetBaseFilter : KalturaAssetFilter
@property (nonatomic,assign) int statusEqual;	// enum KalturaFlavorAssetStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,copy) NSString* statusNotIn;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfStatusNotIn;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaFlavorAssetFilter : KalturaFlavorAssetBaseFilter
@end

@interface KalturaThumbAssetBaseFilter : KalturaAssetFilter
@property (nonatomic,assign) int statusEqual;	// enum KalturaThumbAssetStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,copy) NSString* statusNotIn;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfStatusNotIn;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaThumbAssetFilter : KalturaThumbAssetBaseFilter
@end

@interface KalturaAssetParamsBaseFilter : KalturaFilter
@property (nonatomic,copy) NSString* systemNameEqual;
@property (nonatomic,copy) NSString* systemNameIn;
@property (nonatomic,assign) int isSystemDefaultEqual;	// enum KalturaNullableBoolean
@property (nonatomic,copy) NSString* tagsEqual;
- (KalturaFieldType)getTypeOfSystemNameEqual;
- (KalturaFieldType)getTypeOfSystemNameIn;
- (KalturaFieldType)getTypeOfIsSystemDefaultEqual;
- (KalturaFieldType)getTypeOfTagsEqual;
- (void)setIsSystemDefaultEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaAssetParamsFilter : KalturaAssetParamsBaseFilter
@end

@interface KalturaAssetParamsOutputBaseFilter : KalturaAssetParamsFilter
@property (nonatomic,assign) int assetParamsIdEqual;
@property (nonatomic,copy) NSString* assetParamsVersionEqual;
@property (nonatomic,copy) NSString* assetIdEqual;
@property (nonatomic,copy) NSString* assetVersionEqual;
@property (nonatomic,copy) NSString* formatEqual;	// enum KalturaContainerFormat
- (KalturaFieldType)getTypeOfAssetParamsIdEqual;
- (KalturaFieldType)getTypeOfAssetParamsVersionEqual;
- (KalturaFieldType)getTypeOfAssetIdEqual;
- (KalturaFieldType)getTypeOfAssetVersionEqual;
- (KalturaFieldType)getTypeOfFormatEqual;
- (void)setAssetParamsIdEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaAssetParamsOutputFilter : KalturaAssetParamsOutputBaseFilter
@end

@interface KalturaFlavorParamsBaseFilter : KalturaAssetParamsFilter
@property (nonatomic,copy) NSString* formatEqual;	// enum KalturaContainerFormat
- (KalturaFieldType)getTypeOfFormatEqual;
@end

@interface KalturaFlavorParamsFilter : KalturaFlavorParamsBaseFilter
@end

@interface KalturaFlavorParamsOutputBaseFilter : KalturaFlavorParamsFilter
@property (nonatomic,assign) int flavorParamsIdEqual;
@property (nonatomic,copy) NSString* flavorParamsVersionEqual;
@property (nonatomic,copy) NSString* flavorAssetIdEqual;
@property (nonatomic,copy) NSString* flavorAssetVersionEqual;
- (KalturaFieldType)getTypeOfFlavorParamsIdEqual;
- (KalturaFieldType)getTypeOfFlavorParamsVersionEqual;
- (KalturaFieldType)getTypeOfFlavorAssetIdEqual;
- (KalturaFieldType)getTypeOfFlavorAssetVersionEqual;
- (void)setFlavorParamsIdEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaFlavorParamsOutputFilter : KalturaFlavorParamsOutputBaseFilter
@end

@interface KalturaMediaFlavorParamsOutputBaseFilter : KalturaFlavorParamsOutputFilter
@end

@interface KalturaMediaFlavorParamsOutputFilter : KalturaMediaFlavorParamsOutputBaseFilter
@end

@interface KalturaMediaFlavorParamsBaseFilter : KalturaFlavorParamsFilter
@end

@interface KalturaMediaFlavorParamsFilter : KalturaMediaFlavorParamsBaseFilter
@end

@interface KalturaThumbParamsBaseFilter : KalturaAssetParamsFilter
@property (nonatomic,copy) NSString* formatEqual;	// enum KalturaContainerFormat
- (KalturaFieldType)getTypeOfFormatEqual;
@end

@interface KalturaThumbParamsFilter : KalturaThumbParamsBaseFilter
@end

@interface KalturaThumbParamsOutputBaseFilter : KalturaThumbParamsFilter
@property (nonatomic,assign) int thumbParamsIdEqual;
@property (nonatomic,copy) NSString* thumbParamsVersionEqual;
@property (nonatomic,copy) NSString* thumbAssetIdEqual;
@property (nonatomic,copy) NSString* thumbAssetVersionEqual;
- (KalturaFieldType)getTypeOfThumbParamsIdEqual;
- (KalturaFieldType)getTypeOfThumbParamsVersionEqual;
- (KalturaFieldType)getTypeOfThumbAssetIdEqual;
- (KalturaFieldType)getTypeOfThumbAssetVersionEqual;
- (void)setThumbParamsIdEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaThumbParamsOutputFilter : KalturaThumbParamsOutputBaseFilter
@end

@interface KalturaConversionProfileAssetParamsBaseFilter : KalturaFilter
@property (nonatomic,assign) int conversionProfileIdEqual;
@property (nonatomic,copy) NSString* conversionProfileIdIn;
@property (nonatomic,assign) int assetParamsIdEqual;
@property (nonatomic,copy) NSString* assetParamsIdIn;
@property (nonatomic,assign) int readyBehaviorEqual;	// enum KalturaFlavorReadyBehaviorType
@property (nonatomic,copy) NSString* readyBehaviorIn;
@property (nonatomic,assign) int originEqual;	// enum KalturaAssetParamsOrigin
@property (nonatomic,copy) NSString* originIn;
@property (nonatomic,copy) NSString* systemNameEqual;
@property (nonatomic,copy) NSString* systemNameIn;
- (KalturaFieldType)getTypeOfConversionProfileIdEqual;
- (KalturaFieldType)getTypeOfConversionProfileIdIn;
- (KalturaFieldType)getTypeOfAssetParamsIdEqual;
- (KalturaFieldType)getTypeOfAssetParamsIdIn;
- (KalturaFieldType)getTypeOfReadyBehaviorEqual;
- (KalturaFieldType)getTypeOfReadyBehaviorIn;
- (KalturaFieldType)getTypeOfOriginEqual;
- (KalturaFieldType)getTypeOfOriginIn;
- (KalturaFieldType)getTypeOfSystemNameEqual;
- (KalturaFieldType)getTypeOfSystemNameIn;
- (void)setConversionProfileIdEqualFromString:(NSString*)aPropVal;
- (void)setAssetParamsIdEqualFromString:(NSString*)aPropVal;
- (void)setReadyBehaviorEqualFromString:(NSString*)aPropVal;
- (void)setOriginEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaConversionProfileBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* statusEqual;	// enum KalturaConversionProfileStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,copy) NSString* nameEqual;
@property (nonatomic,copy) NSString* systemNameEqual;
@property (nonatomic,copy) NSString* systemNameIn;
@property (nonatomic,copy) NSString* tagsMultiLikeOr;
@property (nonatomic,copy) NSString* tagsMultiLikeAnd;
@property (nonatomic,copy) NSString* defaultEntryIdEqual;
@property (nonatomic,copy) NSString* defaultEntryIdIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfNameEqual;
- (KalturaFieldType)getTypeOfSystemNameEqual;
- (KalturaFieldType)getTypeOfSystemNameIn;
- (KalturaFieldType)getTypeOfTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfDefaultEntryIdEqual;
- (KalturaFieldType)getTypeOfDefaultEntryIdIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaConversionProfileFilter : KalturaConversionProfileBaseFilter
@end

@interface KalturaConversionProfileAssetParamsFilter : KalturaConversionProfileAssetParamsBaseFilter
@property (nonatomic,retain) KalturaConversionProfileFilter* conversionProfileIdFilter;
@property (nonatomic,retain) KalturaAssetParamsFilter* assetParamsIdFilter;
- (KalturaFieldType)getTypeOfConversionProfileIdFilter;
- (NSString*)getObjectTypeOfConversionProfileIdFilter;
- (KalturaFieldType)getTypeOfAssetParamsIdFilter;
- (NSString*)getObjectTypeOfAssetParamsIdFilter;
@end

@interface KalturaMediaInfoBaseFilter : KalturaFilter
@property (nonatomic,copy) NSString* flavorAssetIdEqual;
- (KalturaFieldType)getTypeOfFlavorAssetIdEqual;
@end

@interface KalturaMediaInfoFilter : KalturaMediaInfoBaseFilter
@end

@interface KalturaBaseEntryBaseFilter : KalturaFilter
// This filter should be in use for retrieving only a specific entry (identified by its entryId).
// @var string
@property (nonatomic,copy) NSString* idEqual;
// This filter should be in use for retrieving few specific entries (string should include comma separated list of entryId strings).
// @var string
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* idNotIn;
// This filter should be in use for retrieving specific entries. It should include only one string to search for in entry names (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* nameLike;
// This filter should be in use for retrieving specific entries. It could include few (comma separated) strings for searching in entry names, while applying an OR logic to retrieve entries that contain at least one input string (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* nameMultiLikeOr;
// This filter should be in use for retrieving specific entries. It could include few (comma separated) strings for searching in entry names, while applying an AND logic to retrieve entries that contain all input strings (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* nameMultiLikeAnd;
// This filter should be in use for retrieving entries with a specific name.
// @var string
@property (nonatomic,copy) NSString* nameEqual;
// This filter should be in use for retrieving only entries which were uploaded by/assigned to users of a specific Kaltura Partner (identified by Partner ID).
// @var int
@property (nonatomic,assign) int partnerIdEqual;
// This filter should be in use for retrieving only entries within Kaltura network which were uploaded by/assigned to users of few Kaltura Partners  (string should include comma separated list of PartnerIDs)
// @var string
@property (nonatomic,copy) NSString* partnerIdIn;
// This filter parameter should be in use for retrieving only entries, uploaded by/assigned to a specific user (identified by user Id).
// @var string
@property (nonatomic,copy) NSString* userIdEqual;
// This filter should be in use for retrieving specific entries. It should include only one string to search for in entry tags (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* tagsLike;
// This filter should be in use for retrieving specific entries. It could include few (comma separated) strings for searching in entry tags, while applying an OR logic to retrieve entries that contain at least one input string (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* tagsMultiLikeOr;
// This filter should be in use for retrieving specific entries. It could include few (comma separated) strings for searching in entry tags, while applying an AND logic to retrieve entries that contain all input strings (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* tagsMultiLikeAnd;
// This filter should be in use for retrieving specific entries. It should include only one string to search for in entry tags set by an ADMIN user (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* adminTagsLike;
// This filter should be in use for retrieving specific entries. It could include few (comma separated) strings for searching in entry tags, set by an ADMIN user, while applying an OR logic to retrieve entries that contain at least one input string (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* adminTagsMultiLikeOr;
// This filter should be in use for retrieving specific entries. It could include few (comma separated) strings for searching in entry tags, set by an ADMIN user, while applying an AND logic to retrieve entries that contain all input strings (no wildcards, spaces are treated as part of the string).
// @var string
@property (nonatomic,copy) NSString* adminTagsMultiLikeAnd;
@property (nonatomic,copy) NSString* categoriesMatchAnd;
@property (nonatomic,copy) NSString* categoriesMatchOr;
@property (nonatomic,copy) NSString* categoriesIdsMatchAnd;
@property (nonatomic,copy) NSString* categoriesIdsMatchOr;
// This filter should be in use for retrieving only entries, at a specific {@link ?object=KalturaEntryStatus KalturaEntryStatus}.
// @var KalturaEntryStatus
@property (nonatomic,copy) NSString* statusEqual;	// enum KalturaEntryStatus
// This filter should be in use for retrieving only entries, not at a specific {@link ?object=KalturaEntryStatus KalturaEntryStatus}.
// @var KalturaEntryStatus
@property (nonatomic,copy) NSString* statusNotEqual;	// enum KalturaEntryStatus
// This filter should be in use for retrieving only entries, at few specific {@link ?object=KalturaEntryStatus KalturaEntryStatus} (comma separated).
// @dynamicType KalturaEntryStatus
@property (nonatomic,copy) NSString* statusIn;
// This filter should be in use for retrieving only entries, not at few specific {@link ?object=KalturaEntryStatus KalturaEntryStatus} (comma separated).
// @dynamicType KalturaEntryStatus
@property (nonatomic,copy) NSString* statusNotIn;
@property (nonatomic,assign) int moderationStatusEqual;	// enum KalturaEntryModerationStatus
@property (nonatomic,assign) int moderationStatusNotEqual;	// enum KalturaEntryModerationStatus
@property (nonatomic,copy) NSString* moderationStatusIn;
@property (nonatomic,copy) NSString* moderationStatusNotIn;
@property (nonatomic,copy) NSString* typeEqual;	// enum KalturaEntryType
// This filter should be in use for retrieving entries of few {@link ?object=KalturaEntryType KalturaEntryType} (string should include a comma separated list of {@link ?object=KalturaEntryType KalturaEntryType} enumerated parameters).
// @dynamicType KalturaEntryType
@property (nonatomic,copy) NSString* typeIn;
// This filter parameter should be in use for retrieving only entries which were created at Kaltura system after a specific time/date (standard timestamp format).
// @var int
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
// This filter parameter should be in use for retrieving only entries which were created at Kaltura system before a specific time/date (standard timestamp format).
// @var int
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int groupIdEqual;
// This filter should be in use for retrieving specific entries while search match the input string within all of the following metadata attributes: name, description, tags, adminTags.
// @var string
@property (nonatomic,copy) NSString* searchTextMatchAnd;
// This filter should be in use for retrieving specific entries while search match the input string within at least one of the following metadata attributes: name, description, tags, adminTags.
// @var string
@property (nonatomic,copy) NSString* searchTextMatchOr;
@property (nonatomic,assign) int accessControlIdEqual;
@property (nonatomic,copy) NSString* accessControlIdIn;
@property (nonatomic,assign) int startDateGreaterThanOrEqual;
@property (nonatomic,assign) int startDateLessThanOrEqual;
@property (nonatomic,assign) int startDateGreaterThanOrEqualOrNull;
@property (nonatomic,assign) int startDateLessThanOrEqualOrNull;
@property (nonatomic,assign) int endDateGreaterThanOrEqual;
@property (nonatomic,assign) int endDateLessThanOrEqual;
@property (nonatomic,assign) int endDateGreaterThanOrEqualOrNull;
@property (nonatomic,assign) int endDateLessThanOrEqualOrNull;
@property (nonatomic,copy) NSString* referenceIdEqual;
@property (nonatomic,copy) NSString* referenceIdIn;
@property (nonatomic,copy) NSString* replacingEntryIdEqual;
@property (nonatomic,copy) NSString* replacingEntryIdIn;
@property (nonatomic,copy) NSString* replacedEntryIdEqual;
@property (nonatomic,copy) NSString* replacedEntryIdIn;
@property (nonatomic,copy) NSString* replacementStatusEqual;	// enum KalturaEntryReplacementStatus
@property (nonatomic,copy) NSString* replacementStatusIn;
@property (nonatomic,assign) int partnerSortValueGreaterThanOrEqual;
@property (nonatomic,assign) int partnerSortValueLessThanOrEqual;
@property (nonatomic,copy) NSString* rootEntryIdEqual;
@property (nonatomic,copy) NSString* rootEntryIdIn;
@property (nonatomic,copy) NSString* tagsNameMultiLikeOr;
@property (nonatomic,copy) NSString* tagsAdminTagsMultiLikeOr;
@property (nonatomic,copy) NSString* tagsAdminTagsNameMultiLikeOr;
@property (nonatomic,copy) NSString* tagsNameMultiLikeAnd;
@property (nonatomic,copy) NSString* tagsAdminTagsMultiLikeAnd;
@property (nonatomic,copy) NSString* tagsAdminTagsNameMultiLikeAnd;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfIdNotIn;
- (KalturaFieldType)getTypeOfNameLike;
- (KalturaFieldType)getTypeOfNameMultiLikeOr;
- (KalturaFieldType)getTypeOfNameMultiLikeAnd;
- (KalturaFieldType)getTypeOfNameEqual;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfUserIdEqual;
- (KalturaFieldType)getTypeOfTagsLike;
- (KalturaFieldType)getTypeOfTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfAdminTagsLike;
- (KalturaFieldType)getTypeOfAdminTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfAdminTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfCategoriesMatchAnd;
- (KalturaFieldType)getTypeOfCategoriesMatchOr;
- (KalturaFieldType)getTypeOfCategoriesIdsMatchAnd;
- (KalturaFieldType)getTypeOfCategoriesIdsMatchOr;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusNotEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfStatusNotIn;
- (KalturaFieldType)getTypeOfModerationStatusEqual;
- (KalturaFieldType)getTypeOfModerationStatusNotEqual;
- (KalturaFieldType)getTypeOfModerationStatusIn;
- (KalturaFieldType)getTypeOfModerationStatusNotIn;
- (KalturaFieldType)getTypeOfTypeEqual;
- (KalturaFieldType)getTypeOfTypeIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfGroupIdEqual;
- (KalturaFieldType)getTypeOfSearchTextMatchAnd;
- (KalturaFieldType)getTypeOfSearchTextMatchOr;
- (KalturaFieldType)getTypeOfAccessControlIdEqual;
- (KalturaFieldType)getTypeOfAccessControlIdIn;
- (KalturaFieldType)getTypeOfStartDateGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfStartDateLessThanOrEqual;
- (KalturaFieldType)getTypeOfStartDateGreaterThanOrEqualOrNull;
- (KalturaFieldType)getTypeOfStartDateLessThanOrEqualOrNull;
- (KalturaFieldType)getTypeOfEndDateGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfEndDateLessThanOrEqual;
- (KalturaFieldType)getTypeOfEndDateGreaterThanOrEqualOrNull;
- (KalturaFieldType)getTypeOfEndDateLessThanOrEqualOrNull;
- (KalturaFieldType)getTypeOfReferenceIdEqual;
- (KalturaFieldType)getTypeOfReferenceIdIn;
- (KalturaFieldType)getTypeOfReplacingEntryIdEqual;
- (KalturaFieldType)getTypeOfReplacingEntryIdIn;
- (KalturaFieldType)getTypeOfReplacedEntryIdEqual;
- (KalturaFieldType)getTypeOfReplacedEntryIdIn;
- (KalturaFieldType)getTypeOfReplacementStatusEqual;
- (KalturaFieldType)getTypeOfReplacementStatusIn;
- (KalturaFieldType)getTypeOfPartnerSortValueGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfPartnerSortValueLessThanOrEqual;
- (KalturaFieldType)getTypeOfRootEntryIdEqual;
- (KalturaFieldType)getTypeOfRootEntryIdIn;
- (KalturaFieldType)getTypeOfTagsNameMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsAdminTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsAdminTagsNameMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsNameMultiLikeAnd;
- (KalturaFieldType)getTypeOfTagsAdminTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfTagsAdminTagsNameMultiLikeAnd;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setModerationStatusEqualFromString:(NSString*)aPropVal;
- (void)setModerationStatusNotEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setGroupIdEqualFromString:(NSString*)aPropVal;
- (void)setAccessControlIdEqualFromString:(NSString*)aPropVal;
- (void)setStartDateGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setStartDateLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setStartDateGreaterThanOrEqualOrNullFromString:(NSString*)aPropVal;
- (void)setStartDateLessThanOrEqualOrNullFromString:(NSString*)aPropVal;
- (void)setEndDateGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setEndDateLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setEndDateGreaterThanOrEqualOrNullFromString:(NSString*)aPropVal;
- (void)setEndDateLessThanOrEqualOrNullFromString:(NSString*)aPropVal;
- (void)setPartnerSortValueGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setPartnerSortValueLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaBaseEntryFilter : KalturaBaseEntryBaseFilter
@property (nonatomic,copy) NSString* freeText;
@property (nonatomic,assign) int isRoot;	// enum KalturaNullableBoolean
- (KalturaFieldType)getTypeOfFreeText;
- (KalturaFieldType)getTypeOfIsRoot;
- (void)setIsRootFromString:(NSString*)aPropVal;
@end

@interface KalturaDataEntryBaseFilter : KalturaBaseEntryFilter
@end

@interface KalturaDataEntryFilter : KalturaDataEntryBaseFilter
@end

@interface KalturaPlayableEntryBaseFilter : KalturaBaseEntryFilter
@property (nonatomic,assign) int durationLessThan;
@property (nonatomic,assign) int durationGreaterThan;
@property (nonatomic,assign) int durationLessThanOrEqual;
@property (nonatomic,assign) int durationGreaterThanOrEqual;
@property (nonatomic,assign) int msDurationLessThan;
@property (nonatomic,assign) int msDurationGreaterThan;
@property (nonatomic,assign) int msDurationLessThanOrEqual;
@property (nonatomic,assign) int msDurationGreaterThanOrEqual;
@property (nonatomic,copy) NSString* durationTypeMatchOr;
- (KalturaFieldType)getTypeOfDurationLessThan;
- (KalturaFieldType)getTypeOfDurationGreaterThan;
- (KalturaFieldType)getTypeOfDurationLessThanOrEqual;
- (KalturaFieldType)getTypeOfDurationGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfMsDurationLessThan;
- (KalturaFieldType)getTypeOfMsDurationGreaterThan;
- (KalturaFieldType)getTypeOfMsDurationLessThanOrEqual;
- (KalturaFieldType)getTypeOfMsDurationGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfDurationTypeMatchOr;
- (void)setDurationLessThanFromString:(NSString*)aPropVal;
- (void)setDurationGreaterThanFromString:(NSString*)aPropVal;
- (void)setDurationLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setDurationGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setMsDurationLessThanFromString:(NSString*)aPropVal;
- (void)setMsDurationGreaterThanFromString:(NSString*)aPropVal;
- (void)setMsDurationLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setMsDurationGreaterThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaPlayableEntryFilter : KalturaPlayableEntryBaseFilter
@end

@interface KalturaMediaEntryBaseFilter : KalturaPlayableEntryFilter
@property (nonatomic,assign) int mediaTypeEqual;	// enum KalturaMediaType
@property (nonatomic,copy) NSString* mediaTypeIn;
@property (nonatomic,assign) int mediaDateGreaterThanOrEqual;
@property (nonatomic,assign) int mediaDateLessThanOrEqual;
@property (nonatomic,copy) NSString* flavorParamsIdsMatchOr;
@property (nonatomic,copy) NSString* flavorParamsIdsMatchAnd;
- (KalturaFieldType)getTypeOfMediaTypeEqual;
- (KalturaFieldType)getTypeOfMediaTypeIn;
- (KalturaFieldType)getTypeOfMediaDateGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfMediaDateLessThanOrEqual;
- (KalturaFieldType)getTypeOfFlavorParamsIdsMatchOr;
- (KalturaFieldType)getTypeOfFlavorParamsIdsMatchAnd;
- (void)setMediaTypeEqualFromString:(NSString*)aPropVal;
- (void)setMediaDateGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setMediaDateLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaMediaEntryFilter : KalturaMediaEntryBaseFilter
@end

@interface KalturaLiveStreamEntryBaseFilter : KalturaMediaEntryFilter
@end

@interface KalturaLiveStreamEntryFilter : KalturaLiveStreamEntryBaseFilter
@end

@interface KalturaLiveStreamAdminEntryBaseFilter : KalturaLiveStreamEntryFilter
@end

@interface KalturaLiveStreamAdminEntryFilter : KalturaLiveStreamAdminEntryBaseFilter
@end

@interface KalturaMediaEntryFilterForPlaylist : KalturaMediaEntryFilter
@property (nonatomic,assign) int limit;
- (KalturaFieldType)getTypeOfLimit;
- (void)setLimitFromString:(NSString*)aPropVal;
@end

@interface KalturaMixEntryBaseFilter : KalturaPlayableEntryFilter
@end

@interface KalturaMixEntryFilter : KalturaMixEntryBaseFilter
@end

@interface KalturaPlaylistBaseFilter : KalturaBaseEntryFilter
@end

@interface KalturaPlaylistFilter : KalturaPlaylistBaseFilter
@end

@interface KalturaUserBaseFilter : KalturaFilter
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* screenNameLike;
@property (nonatomic,copy) NSString* screenNameStartsWith;
@property (nonatomic,copy) NSString* emailLike;
@property (nonatomic,copy) NSString* emailStartsWith;
@property (nonatomic,copy) NSString* tagsMultiLikeOr;
@property (nonatomic,copy) NSString* tagsMultiLikeAnd;
@property (nonatomic,assign) int statusEqual;	// enum KalturaUserStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) BOOL isAdminEqual;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfScreenNameLike;
- (KalturaFieldType)getTypeOfScreenNameStartsWith;
- (KalturaFieldType)getTypeOfEmailLike;
- (KalturaFieldType)getTypeOfEmailStartsWith;
- (KalturaFieldType)getTypeOfTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfIsAdminEqual;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setIsAdminEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaUserFilter : KalturaUserBaseFilter
@property (nonatomic,copy) NSString* idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) BOOL loginEnabledEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfLoginEnabledEqual;
- (void)setLoginEnabledEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaAdminUserBaseFilter : KalturaUserFilter
@end

@interface KalturaAdminUserFilter : KalturaAdminUserBaseFilter
@end

@interface KalturaCategoryBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int parentIdEqual;
@property (nonatomic,copy) NSString* parentIdIn;
@property (nonatomic,assign) int depthEqual;
@property (nonatomic,copy) NSString* fullNameEqual;
@property (nonatomic,copy) NSString* fullNameStartsWith;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfParentIdEqual;
- (KalturaFieldType)getTypeOfParentIdIn;
- (KalturaFieldType)getTypeOfDepthEqual;
- (KalturaFieldType)getTypeOfFullNameEqual;
- (KalturaFieldType)getTypeOfFullNameStartsWith;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setParentIdEqualFromString:(NSString*)aPropVal;
- (void)setDepthEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaCategoryFilter : KalturaCategoryBaseFilter
@end

@interface KalturaPartnerBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* nameLike;
@property (nonatomic,copy) NSString* nameMultiLikeOr;
@property (nonatomic,copy) NSString* nameMultiLikeAnd;
@property (nonatomic,copy) NSString* nameEqual;
@property (nonatomic,assign) int statusEqual;	// enum KalturaPartnerStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,assign) int partnerPackageEqual;
@property (nonatomic,assign) int partnerPackageGreaterThanOrEqual;
@property (nonatomic,assign) int partnerPackageLessThanOrEqual;
@property (nonatomic,copy) NSString* partnerNameDescriptionWebsiteAdminNameAdminEmailLike;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfNameLike;
- (KalturaFieldType)getTypeOfNameMultiLikeOr;
- (KalturaFieldType)getTypeOfNameMultiLikeAnd;
- (KalturaFieldType)getTypeOfNameEqual;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfPartnerPackageEqual;
- (KalturaFieldType)getTypeOfPartnerPackageGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfPartnerPackageLessThanOrEqual;
- (KalturaFieldType)getTypeOfPartnerNameDescriptionWebsiteAdminNameAdminEmailLike;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
- (void)setPartnerPackageEqualFromString:(NSString*)aPropVal;
- (void)setPartnerPackageGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setPartnerPackageLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaPartnerFilter : KalturaPartnerBaseFilter
@end

@interface KalturaReportBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,copy) NSString* systemNameEqual;
@property (nonatomic,copy) NSString* systemNameIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfSystemNameEqual;
- (KalturaFieldType)getTypeOfSystemNameIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaReportFilter : KalturaReportBaseFilter
@end

@interface KalturaUiConfBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* nameLike;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,assign) int objTypeEqual;	// enum KalturaUiConfObjType
@property (nonatomic,copy) NSString* objTypeIn;
@property (nonatomic,copy) NSString* tagsMultiLikeOr;
@property (nonatomic,copy) NSString* tagsMultiLikeAnd;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int creationModeEqual;	// enum KalturaUiConfCreationMode
@property (nonatomic,copy) NSString* creationModeIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfNameLike;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfObjTypeEqual;
- (KalturaFieldType)getTypeOfObjTypeIn;
- (KalturaFieldType)getTypeOfTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfCreationModeEqual;
- (KalturaFieldType)getTypeOfCreationModeIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setObjTypeEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreationModeEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaUiConfFilter : KalturaUiConfBaseFilter
@end

@interface KalturaUploadTokenBaseFilter : KalturaFilter
@property (nonatomic,copy) NSString* idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* userIdEqual;
@property (nonatomic,assign) int statusEqual;	// enum KalturaUploadTokenStatus
@property (nonatomic,copy) NSString* statusIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfUserIdEqual;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaUploadTokenFilter : KalturaUploadTokenBaseFilter
@end

@interface KalturaUserLoginDataBaseFilter : KalturaFilter
@property (nonatomic,copy) NSString* loginEmailEqual;
- (KalturaFieldType)getTypeOfLoginEmailEqual;
@end

@interface KalturaUserLoginDataFilter : KalturaUserLoginDataBaseFilter
@end

@interface KalturaWidgetBaseFilter : KalturaFilter
@property (nonatomic,copy) NSString* idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* sourceWidgetIdEqual;
@property (nonatomic,copy) NSString* rootWidgetIdEqual;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* entryIdEqual;
@property (nonatomic,assign) int uiConfIdEqual;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,copy) NSString* partnerDataLike;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfSourceWidgetIdEqual;
- (KalturaFieldType)getTypeOfRootWidgetIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfEntryIdEqual;
- (KalturaFieldType)getTypeOfUiConfIdEqual;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfPartnerDataLike;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setUiConfIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaWidgetFilter : KalturaWidgetBaseFilter
@end

@interface KalturaBaseSyndicationFeedBaseFilter : KalturaFilter
@end

@interface KalturaBaseSyndicationFeedFilter : KalturaBaseSyndicationFeedBaseFilter
@end

@interface KalturaGoogleVideoSyndicationFeedBaseFilter : KalturaBaseSyndicationFeedFilter
@end

@interface KalturaGoogleVideoSyndicationFeedFilter : KalturaGoogleVideoSyndicationFeedBaseFilter
@end

@interface KalturaITunesSyndicationFeedBaseFilter : KalturaBaseSyndicationFeedFilter
@end

@interface KalturaITunesSyndicationFeedFilter : KalturaITunesSyndicationFeedBaseFilter
@end

@interface KalturaTubeMogulSyndicationFeedBaseFilter : KalturaBaseSyndicationFeedFilter
@end

@interface KalturaTubeMogulSyndicationFeedFilter : KalturaTubeMogulSyndicationFeedBaseFilter
@end

@interface KalturaYahooSyndicationFeedBaseFilter : KalturaBaseSyndicationFeedFilter
@end

@interface KalturaYahooSyndicationFeedFilter : KalturaYahooSyndicationFeedBaseFilter
@end

@interface KalturaGenericSyndicationFeedBaseFilter : KalturaBaseSyndicationFeedFilter
@end

@interface KalturaGenericSyndicationFeedFilter : KalturaGenericSyndicationFeedBaseFilter
@end

@interface KalturaGenericXsltSyndicationFeedBaseFilter : KalturaGenericSyndicationFeedFilter
@end

@interface KalturaGenericXsltSyndicationFeedFilter : KalturaGenericXsltSyndicationFeedBaseFilter
@end

@interface KalturaPermissionItemBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* typeEqual;	// enum KalturaPermissionItemType
@property (nonatomic,copy) NSString* typeIn;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,copy) NSString* tagsMultiLikeOr;
@property (nonatomic,copy) NSString* tagsMultiLikeAnd;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfTypeEqual;
- (KalturaFieldType)getTypeOfTypeIn;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaPermissionItemFilter : KalturaPermissionItemBaseFilter
@end

@interface KalturaApiActionPermissionItemBaseFilter : KalturaPermissionItemFilter
@end

@interface KalturaApiActionPermissionItemFilter : KalturaApiActionPermissionItemBaseFilter
@end

@interface KalturaApiParameterPermissionItemBaseFilter : KalturaPermissionItemFilter
@end

@interface KalturaApiParameterPermissionItemFilter : KalturaApiParameterPermissionItemBaseFilter
@end

@interface KalturaPermissionBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int typeEqual;	// enum KalturaPermissionType
@property (nonatomic,copy) NSString* typeIn;
@property (nonatomic,copy) NSString* nameEqual;
@property (nonatomic,copy) NSString* nameIn;
@property (nonatomic,copy) NSString* friendlyNameLike;
@property (nonatomic,copy) NSString* descriptionLike;
@property (nonatomic,assign) int statusEqual;	// enum KalturaPermissionStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,copy) NSString* dependsOnPermissionNamesMultiLikeOr;
@property (nonatomic,copy) NSString* dependsOnPermissionNamesMultiLikeAnd;
@property (nonatomic,copy) NSString* tagsMultiLikeOr;
@property (nonatomic,copy) NSString* tagsMultiLikeAnd;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfTypeEqual;
- (KalturaFieldType)getTypeOfTypeIn;
- (KalturaFieldType)getTypeOfNameEqual;
- (KalturaFieldType)getTypeOfNameIn;
- (KalturaFieldType)getTypeOfFriendlyNameLike;
- (KalturaFieldType)getTypeOfDescriptionLike;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfDependsOnPermissionNamesMultiLikeOr;
- (KalturaFieldType)getTypeOfDependsOnPermissionNamesMultiLikeAnd;
- (KalturaFieldType)getTypeOfTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setTypeEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaPermissionFilter : KalturaPermissionBaseFilter
@end

@interface KalturaUserRoleBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,copy) NSString* nameEqual;
@property (nonatomic,copy) NSString* nameIn;
@property (nonatomic,copy) NSString* descriptionLike;
@property (nonatomic,assign) int statusEqual;	// enum KalturaUserRoleStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,copy) NSString* tagsMultiLikeOr;
@property (nonatomic,copy) NSString* tagsMultiLikeAnd;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfNameEqual;
- (KalturaFieldType)getTypeOfNameIn;
- (KalturaFieldType)getTypeOfDescriptionLike;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfTagsMultiLikeOr;
- (KalturaFieldType)getTypeOfTagsMultiLikeAnd;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaUserRoleFilter : KalturaUserRoleBaseFilter
@end

@interface KalturaStorageProfileBaseFilter : KalturaFilter
@property (nonatomic,assign) int idEqual;
@property (nonatomic,copy) NSString* idIn;
@property (nonatomic,assign) int createdAtGreaterThanOrEqual;
@property (nonatomic,assign) int createdAtLessThanOrEqual;
@property (nonatomic,assign) int updatedAtGreaterThanOrEqual;
@property (nonatomic,assign) int updatedAtLessThanOrEqual;
@property (nonatomic,assign) int partnerIdEqual;
@property (nonatomic,copy) NSString* partnerIdIn;
@property (nonatomic,copy) NSString* systemNameEqual;
@property (nonatomic,copy) NSString* systemNameIn;
@property (nonatomic,assign) int statusEqual;	// enum KalturaStorageProfileStatus
@property (nonatomic,copy) NSString* statusIn;
@property (nonatomic,assign) int protocolEqual;	// enum KalturaStorageProfileProtocol
@property (nonatomic,copy) NSString* protocolIn;
- (KalturaFieldType)getTypeOfIdEqual;
- (KalturaFieldType)getTypeOfIdIn;
- (KalturaFieldType)getTypeOfCreatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfCreatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtGreaterThanOrEqual;
- (KalturaFieldType)getTypeOfUpdatedAtLessThanOrEqual;
- (KalturaFieldType)getTypeOfPartnerIdEqual;
- (KalturaFieldType)getTypeOfPartnerIdIn;
- (KalturaFieldType)getTypeOfSystemNameEqual;
- (KalturaFieldType)getTypeOfSystemNameIn;
- (KalturaFieldType)getTypeOfStatusEqual;
- (KalturaFieldType)getTypeOfStatusIn;
- (KalturaFieldType)getTypeOfProtocolEqual;
- (KalturaFieldType)getTypeOfProtocolIn;
- (void)setIdEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setCreatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtGreaterThanOrEqualFromString:(NSString*)aPropVal;
- (void)setUpdatedAtLessThanOrEqualFromString:(NSString*)aPropVal;
- (void)setPartnerIdEqualFromString:(NSString*)aPropVal;
- (void)setStatusEqualFromString:(NSString*)aPropVal;
- (void)setProtocolEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaStorageProfileFilter : KalturaStorageProfileBaseFilter
@end

// The KalturaFilterPager object enables paging management to be applied upon service list actions.
@interface KalturaFilterPager : KalturaObjectBase
// The number of objects to retrieve. (Default is 30, maximum page size is 500).
@property (nonatomic,assign) int pageSize;
// The page number for which {pageSize} of objects should be retrieved (Default is 1).
@property (nonatomic,assign) int pageIndex;
- (KalturaFieldType)getTypeOfPageSize;
- (KalturaFieldType)getTypeOfPageIndex;
- (void)setPageSizeFromString:(NSString*)aPropVal;
- (void)setPageIndexFromString:(NSString*)aPropVal;
@end

@interface KalturaAccessControlProfileListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaAccessControlProfile elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

// DEPRECATED - use KalturaRule instead
@interface KalturaBaseRestriction : KalturaObjectBase
@end

// DEPRECATED - use KalturaRule instead
@interface KalturaCountryRestriction : KalturaBaseRestriction
// Country restriction type (Allow or deny)
@property (nonatomic,assign) int countryRestrictionType;	// enum KalturaCountryRestrictionType
// Comma separated list of country codes to allow to deny
@property (nonatomic,copy) NSString* countryList;
- (KalturaFieldType)getTypeOfCountryRestrictionType;
- (KalturaFieldType)getTypeOfCountryList;
- (void)setCountryRestrictionTypeFromString:(NSString*)aPropVal;
@end

// DEPRECATED
@interface KalturaDirectoryRestriction : KalturaBaseRestriction
// Kaltura directory restriction type
@property (nonatomic,assign) int directoryRestrictionType;	// enum KalturaDirectoryRestrictionType
- (KalturaFieldType)getTypeOfDirectoryRestrictionType;
- (void)setDirectoryRestrictionTypeFromString:(NSString*)aPropVal;
@end

// DEPRECATED - use KalturaRule instead
@interface KalturaIpAddressRestriction : KalturaBaseRestriction
// Ip address restriction type (Allow or deny)
@property (nonatomic,assign) int ipAddressRestrictionType;	// enum KalturaIpAddressRestrictionType
// Comma separated list of ip address to allow to deny
@property (nonatomic,copy) NSString* ipAddressList;
- (KalturaFieldType)getTypeOfIpAddressRestrictionType;
- (KalturaFieldType)getTypeOfIpAddressList;
- (void)setIpAddressRestrictionTypeFromString:(NSString*)aPropVal;
@end

// DEPRECATED - use KalturaRule instead
@interface KalturaSessionRestriction : KalturaBaseRestriction
@end

// DEPRECATED - use KalturaRule instead
@interface KalturaPreviewRestriction : KalturaSessionRestriction
// The preview restriction length
@property (nonatomic,assign) int previewLength;
- (KalturaFieldType)getTypeOfPreviewLength;
- (void)setPreviewLengthFromString:(NSString*)aPropVal;
@end

// DEPRECATED - use KalturaRule instead
@interface KalturaSiteRestriction : KalturaBaseRestriction
// The site restriction type (allow or deny)
@property (nonatomic,assign) int siteRestrictionType;	// enum KalturaSiteRestrictionType
// Comma separated list of sites (domains) to allow or deny
@property (nonatomic,copy) NSString* siteList;
- (KalturaFieldType)getTypeOfSiteRestrictionType;
- (KalturaFieldType)getTypeOfSiteList;
- (void)setSiteRestrictionTypeFromString:(NSString*)aPropVal;
@end

// DEPRECATED - use KalturaRule instead
@interface KalturaUserAgentRestriction : KalturaBaseRestriction
// User agent restriction type (Allow or deny)
@property (nonatomic,assign) int userAgentRestrictionType;	// enum KalturaUserAgentRestrictionType
// A comma seperated list of user agent regular expressions
@property (nonatomic,copy) NSString* userAgentRegexList;
- (KalturaFieldType)getTypeOfUserAgentRestrictionType;
- (KalturaFieldType)getTypeOfUserAgentRegexList;
- (void)setUserAgentRestrictionTypeFromString:(NSString*)aPropVal;
@end

// DEPRECATED - use KalturaAccessControlProfile instead
@interface KalturaAccessControl : KalturaObjectBase
// The id of the Access Control Profile
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int partnerId;
// The name of the Access Control Profile
@property (nonatomic,copy) NSString* name;
// System name of the Access Control Profile
@property (nonatomic,copy) NSString* systemName;
// The description of the Access Control Profile
@property (nonatomic,copy) NSString* description;
// Creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// True if this Conversion Profile is the default
@property (nonatomic,assign) int isDefault;	// enum KalturaNullableBoolean
// Array of Access Control Restrictions
@property (nonatomic,retain) NSMutableArray* restrictions;	// of KalturaBaseRestriction elements
// Indicates that the access control profile is new and should be handled using KalturaAccessControlProfile object and accessControlProfile service
@property (nonatomic,assign,readonly) BOOL containsUnsuportedRestrictions;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfSystemName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfIsDefault;
- (KalturaFieldType)getTypeOfRestrictions;
- (NSString*)getObjectTypeOfRestrictions;
- (KalturaFieldType)getTypeOfContainsUnsuportedRestrictions;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setIsDefaultFromString:(NSString*)aPropVal;
- (void)setContainsUnsuportedRestrictionsFromString:(NSString*)aPropVal;
@end

// DEPRECATED - use KalturaAccessControlProfileListResponse instead
@interface KalturaAccessControlListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaAccessControl elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaUser : KalturaObjectBase
@property (nonatomic,copy) NSString* id;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* screenName;
// DEPRECATED
@property (nonatomic,copy) NSString* fullName;
@property (nonatomic,copy) NSString* email;
@property (nonatomic,assign) int dateOfBirth;
@property (nonatomic,copy) NSString* country;
@property (nonatomic,copy) NSString* state;
@property (nonatomic,copy) NSString* city;
@property (nonatomic,copy) NSString* zip;
@property (nonatomic,copy) NSString* thumbnailUrl;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,copy) NSString* tags;
// Admin tags can be updated only by using an admin session
@property (nonatomic,copy) NSString* adminTags;
@property (nonatomic,assign) int gender;	// enum KalturaGender
@property (nonatomic,assign) int status;	// enum KalturaUserStatus
// Creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Last update date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
// Can be used to store various partner related data as a string
@property (nonatomic,copy) NSString* partnerData;
@property (nonatomic,assign) int indexedPartnerDataInt;
@property (nonatomic,copy) NSString* indexedPartnerDataString;
@property (nonatomic,assign,readonly) int storageSize;
@property (nonatomic,copy) NSString* password;	// insertonly
@property (nonatomic,copy) NSString* firstName;
@property (nonatomic,copy) NSString* lastName;
@property (nonatomic,assign) BOOL isAdmin;
@property (nonatomic,assign,readonly) int lastLoginTime;
@property (nonatomic,assign,readonly) int statusUpdatedAt;
@property (nonatomic,assign,readonly) int deletedAt;
@property (nonatomic,assign,readonly) BOOL loginEnabled;
@property (nonatomic,copy) NSString* roleIds;
@property (nonatomic,copy,readonly) NSString* roleNames;
@property (nonatomic,assign,readonly) BOOL isAccountOwner;
@property (nonatomic,copy) NSString* allowedPartnerIds;
@property (nonatomic,copy) NSString* allowedPartnerPackages;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfScreenName;
- (KalturaFieldType)getTypeOfFullName;
- (KalturaFieldType)getTypeOfEmail;
- (KalturaFieldType)getTypeOfDateOfBirth;
- (KalturaFieldType)getTypeOfCountry;
- (KalturaFieldType)getTypeOfState;
- (KalturaFieldType)getTypeOfCity;
- (KalturaFieldType)getTypeOfZip;
- (KalturaFieldType)getTypeOfThumbnailUrl;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfAdminTags;
- (KalturaFieldType)getTypeOfGender;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfPartnerData;
- (KalturaFieldType)getTypeOfIndexedPartnerDataInt;
- (KalturaFieldType)getTypeOfIndexedPartnerDataString;
- (KalturaFieldType)getTypeOfStorageSize;
- (KalturaFieldType)getTypeOfPassword;
- (KalturaFieldType)getTypeOfFirstName;
- (KalturaFieldType)getTypeOfLastName;
- (KalturaFieldType)getTypeOfIsAdmin;
- (KalturaFieldType)getTypeOfLastLoginTime;
- (KalturaFieldType)getTypeOfStatusUpdatedAt;
- (KalturaFieldType)getTypeOfDeletedAt;
- (KalturaFieldType)getTypeOfLoginEnabled;
- (KalturaFieldType)getTypeOfRoleIds;
- (KalturaFieldType)getTypeOfRoleNames;
- (KalturaFieldType)getTypeOfIsAccountOwner;
- (KalturaFieldType)getTypeOfAllowedPartnerIds;
- (KalturaFieldType)getTypeOfAllowedPartnerPackages;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setDateOfBirthFromString:(NSString*)aPropVal;
- (void)setGenderFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setIndexedPartnerDataIntFromString:(NSString*)aPropVal;
- (void)setStorageSizeFromString:(NSString*)aPropVal;
- (void)setIsAdminFromString:(NSString*)aPropVal;
- (void)setLastLoginTimeFromString:(NSString*)aPropVal;
- (void)setStatusUpdatedAtFromString:(NSString*)aPropVal;
- (void)setDeletedAtFromString:(NSString*)aPropVal;
- (void)setLoginEnabledFromString:(NSString*)aPropVal;
- (void)setIsAccountOwnerFromString:(NSString*)aPropVal;
@end

// DEPRECATED
@interface KalturaAdminUser : KalturaUser
@end

// Base class to all operation attributes types
@interface KalturaOperationAttributes : KalturaObjectBase
@end

// Clip operation attributes
@interface KalturaClipAttributes : KalturaOperationAttributes
// Offset in milliseconds
@property (nonatomic,assign) int offset;
// Duration in milliseconds
@property (nonatomic,assign) int duration;
- (KalturaFieldType)getTypeOfOffset;
- (KalturaFieldType)getTypeOfDuration;
- (void)setOffsetFromString:(NSString*)aPropVal;
- (void)setDurationFromString:(NSString*)aPropVal;
@end

@interface KalturaBaseEntry : KalturaObjectBase
// Auto generated 10 characters alphanumeric string
@property (nonatomic,copy,readonly) NSString* id;
// Entry name (Min 1 chars)
@property (nonatomic,copy) NSString* name;
// Entry description
@property (nonatomic,copy) NSString* description;
@property (nonatomic,assign,readonly) int partnerId;
// The ID of the user who is the owner of this entry
@property (nonatomic,copy) NSString* userId;
// Entry tags
@property (nonatomic,copy) NSString* tags;
// Entry admin tags can be updated only by administrators
@property (nonatomic,copy) NSString* adminTags;
@property (nonatomic,copy) NSString* categories;
@property (nonatomic,copy) NSString* categoriesIds;
@property (nonatomic,copy,readonly) NSString* status;	// enum KalturaEntryStatus
// Entry moderation status
@property (nonatomic,assign,readonly) int moderationStatus;	// enum KalturaEntryModerationStatus
// Number of moderation requests waiting for this entry
@property (nonatomic,assign,readonly) int moderationCount;
// The type of the entry, this is auto filled by the derived entry object
@property (nonatomic,copy) NSString* type;	// enum KalturaEntryType
// Entry creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Entry update date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
// Calculated rank
@property (nonatomic,assign,readonly) double rank;
// The total (sum) of all votes
@property (nonatomic,assign,readonly) int totalRank;
// Number of votes
@property (nonatomic,assign,readonly) int votes;
@property (nonatomic,assign) int groupId;
// Can be used to store various partner related data as a string
@property (nonatomic,copy) NSString* partnerData;
// Download URL for the entry
@property (nonatomic,copy,readonly) NSString* downloadUrl;
// Indexed search text for full text search
@property (nonatomic,copy,readonly) NSString* searchText;
// License type used for this entry
@property (nonatomic,assign) int licenseType;	// enum KalturaLicenseType
// Version of the entry data
@property (nonatomic,assign,readonly) int version;
// Thumbnail URL
@property (nonatomic,copy) NSString* thumbnailUrl;	// insertonly
// The Access Control ID assigned to this entry (null when not set, send -1 to remove)
@property (nonatomic,assign) int accessControlId;
// Entry scheduling start date (null when not set, send -1 to remove)
@property (nonatomic,assign) int startDate;
// Entry scheduling end date (null when not set, send -1 to remove)
@property (nonatomic,assign) int endDate;
// Entry external reference id
@property (nonatomic,copy) NSString* referenceId;
// ID of temporary entry that will replace this entry when it's approved and ready for replacement
@property (nonatomic,copy,readonly) NSString* replacingEntryId;
// ID of the entry that will be replaced when the replacement approved and this entry is ready
@property (nonatomic,copy,readonly) NSString* replacedEntryId;
// Status of the replacement readiness and approval
@property (nonatomic,copy,readonly) NSString* replacementStatus;	// enum KalturaEntryReplacementStatus
// Can be used to store various partner related data as a numeric value
@property (nonatomic,assign) int partnerSortValue;
// Override the default ingestion profile
@property (nonatomic,assign) int conversionProfileId;
// ID of source root entry, used for clipped, skipped and cropped entries that created from another entry
@property (nonatomic,copy,readonly) NSString* rootEntryId;
// clipping, skipping and cropping attributes that used to create this entry
@property (nonatomic,retain) NSMutableArray* operationAttributes;	// of KalturaOperationAttributes elements
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfUserId;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfAdminTags;
- (KalturaFieldType)getTypeOfCategories;
- (KalturaFieldType)getTypeOfCategoriesIds;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfModerationStatus;
- (KalturaFieldType)getTypeOfModerationCount;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfRank;
- (KalturaFieldType)getTypeOfTotalRank;
- (KalturaFieldType)getTypeOfVotes;
- (KalturaFieldType)getTypeOfGroupId;
- (KalturaFieldType)getTypeOfPartnerData;
- (KalturaFieldType)getTypeOfDownloadUrl;
- (KalturaFieldType)getTypeOfSearchText;
- (KalturaFieldType)getTypeOfLicenseType;
- (KalturaFieldType)getTypeOfVersion;
- (KalturaFieldType)getTypeOfThumbnailUrl;
- (KalturaFieldType)getTypeOfAccessControlId;
- (KalturaFieldType)getTypeOfStartDate;
- (KalturaFieldType)getTypeOfEndDate;
- (KalturaFieldType)getTypeOfReferenceId;
- (KalturaFieldType)getTypeOfReplacingEntryId;
- (KalturaFieldType)getTypeOfReplacedEntryId;
- (KalturaFieldType)getTypeOfReplacementStatus;
- (KalturaFieldType)getTypeOfPartnerSortValue;
- (KalturaFieldType)getTypeOfConversionProfileId;
- (KalturaFieldType)getTypeOfRootEntryId;
- (KalturaFieldType)getTypeOfOperationAttributes;
- (NSString*)getObjectTypeOfOperationAttributes;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setModerationStatusFromString:(NSString*)aPropVal;
- (void)setModerationCountFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setRankFromString:(NSString*)aPropVal;
- (void)setTotalRankFromString:(NSString*)aPropVal;
- (void)setVotesFromString:(NSString*)aPropVal;
- (void)setGroupIdFromString:(NSString*)aPropVal;
- (void)setLicenseTypeFromString:(NSString*)aPropVal;
- (void)setVersionFromString:(NSString*)aPropVal;
- (void)setAccessControlIdFromString:(NSString*)aPropVal;
- (void)setStartDateFromString:(NSString*)aPropVal;
- (void)setEndDateFromString:(NSString*)aPropVal;
- (void)setPartnerSortValueFromString:(NSString*)aPropVal;
- (void)setConversionProfileIdFromString:(NSString*)aPropVal;
@end

@interface KalturaDataEntry : KalturaBaseEntry
// The data of the entry
@property (nonatomic,copy) NSString* dataContent;
// indicator whether to return the object for get action with the dataContent field.
@property (nonatomic,assign) BOOL retrieveDataContentByGet;	// insertonly
- (KalturaFieldType)getTypeOfDataContent;
- (KalturaFieldType)getTypeOfRetrieveDataContentByGet;
- (void)setRetrieveDataContentByGetFromString:(NSString*)aPropVal;
@end

@interface KalturaPlayableEntry : KalturaBaseEntry
// Number of plays
@property (nonatomic,assign,readonly) int plays;
// Number of views
@property (nonatomic,assign,readonly) int views;
// The width in pixels
@property (nonatomic,assign,readonly) int width;
// The height in pixels
@property (nonatomic,assign,readonly) int height;
// The duration in seconds
@property (nonatomic,assign,readonly) int duration;
// The duration in miliseconds
@property (nonatomic,assign) int msDuration;
// The duration type (short for 0-4 mins, medium for 4-20 mins, long for 20+ mins)
@property (nonatomic,copy,readonly) NSString* durationType;	// enum KalturaDurationType
- (KalturaFieldType)getTypeOfPlays;
- (KalturaFieldType)getTypeOfViews;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (KalturaFieldType)getTypeOfDuration;
- (KalturaFieldType)getTypeOfMsDuration;
- (KalturaFieldType)getTypeOfDurationType;
- (void)setPlaysFromString:(NSString*)aPropVal;
- (void)setViewsFromString:(NSString*)aPropVal;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
- (void)setDurationFromString:(NSString*)aPropVal;
- (void)setMsDurationFromString:(NSString*)aPropVal;
@end

@interface KalturaMediaEntry : KalturaPlayableEntry
// The media type of the entry
@property (nonatomic,assign) int mediaType;	// enum KalturaMediaType, insertonly
// Override the default conversion quality
// DEPRECATED - use conversionProfileId instead
@property (nonatomic,copy) NSString* conversionQuality;	// insertonly
// The source type of the entry
@property (nonatomic,copy) NSString* sourceType;	// enum KalturaSourceType, insertonly
// The search provider type used to import this entry
@property (nonatomic,assign) int searchProviderType;	// enum KalturaSearchProviderType, insertonly
// The ID of the media in the importing site
@property (nonatomic,copy) NSString* searchProviderId;	// insertonly
// The user name used for credits
@property (nonatomic,copy) NSString* creditUserName;
// The URL for credits
@property (nonatomic,copy) NSString* creditUrl;
// The media date extracted from EXIF data (For images) as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int mediaDate;
// The URL used for playback. This is not the download URL.
@property (nonatomic,copy,readonly) NSString* dataUrl;
// Comma separated flavor params ids that exists for this media entry
@property (nonatomic,copy,readonly) NSString* flavorParamsIds;
- (KalturaFieldType)getTypeOfMediaType;
- (KalturaFieldType)getTypeOfConversionQuality;
- (KalturaFieldType)getTypeOfSourceType;
- (KalturaFieldType)getTypeOfSearchProviderType;
- (KalturaFieldType)getTypeOfSearchProviderId;
- (KalturaFieldType)getTypeOfCreditUserName;
- (KalturaFieldType)getTypeOfCreditUrl;
- (KalturaFieldType)getTypeOfMediaDate;
- (KalturaFieldType)getTypeOfDataUrl;
- (KalturaFieldType)getTypeOfFlavorParamsIds;
- (void)setMediaTypeFromString:(NSString*)aPropVal;
- (void)setSearchProviderTypeFromString:(NSString*)aPropVal;
- (void)setMediaDateFromString:(NSString*)aPropVal;
@end

@interface KalturaLiveStreamBitrate : KalturaObjectBase
@property (nonatomic,assign) int bitrate;
@property (nonatomic,assign) int width;
@property (nonatomic,assign) int height;
- (KalturaFieldType)getTypeOfBitrate;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (void)setBitrateFromString:(NSString*)aPropVal;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
@end

@interface KalturaLiveStreamEntry : KalturaMediaEntry
// The message to be presented when the stream is offline
@property (nonatomic,copy) NSString* offlineMessage;
// The stream id as provided by the provider
@property (nonatomic,copy,readonly) NSString* streamRemoteId;
// The backup stream id as provided by the provider
@property (nonatomic,copy,readonly) NSString* streamRemoteBackupId;
// Array of supported bitrates
@property (nonatomic,retain) NSMutableArray* bitrates;	// of KalturaLiveStreamBitrate elements
@property (nonatomic,copy) NSString* primaryBroadcastingUrl;
@property (nonatomic,copy) NSString* secondaryBroadcastingUrl;
@property (nonatomic,copy) NSString* streamName;
// The stream url
@property (nonatomic,copy) NSString* streamUrl;
- (KalturaFieldType)getTypeOfOfflineMessage;
- (KalturaFieldType)getTypeOfStreamRemoteId;
- (KalturaFieldType)getTypeOfStreamRemoteBackupId;
- (KalturaFieldType)getTypeOfBitrates;
- (NSString*)getObjectTypeOfBitrates;
- (KalturaFieldType)getTypeOfPrimaryBroadcastingUrl;
- (KalturaFieldType)getTypeOfSecondaryBroadcastingUrl;
- (KalturaFieldType)getTypeOfStreamName;
- (KalturaFieldType)getTypeOfStreamUrl;
@end

@interface KalturaLiveStreamAdminEntry : KalturaLiveStreamEntry
// The broadcast primary ip
@property (nonatomic,copy) NSString* encodingIP1;
// The broadcast secondary ip
@property (nonatomic,copy) NSString* encodingIP2;
// The broadcast password
@property (nonatomic,copy) NSString* streamPassword;
// The broadcast username
@property (nonatomic,copy,readonly) NSString* streamUsername;
- (KalturaFieldType)getTypeOfEncodingIP1;
- (KalturaFieldType)getTypeOfEncodingIP2;
- (KalturaFieldType)getTypeOfStreamPassword;
- (KalturaFieldType)getTypeOfStreamUsername;
@end

@interface KalturaMixEntry : KalturaPlayableEntry
// Indicates whether the user has submited a real thumbnail to the mix (Not the one that was generated automaticaly)
@property (nonatomic,assign,readonly) BOOL hasRealThumbnail;
// The editor type used to edit the metadata
@property (nonatomic,assign) int editorType;	// enum KalturaEditorType
// The xml data of the mix
@property (nonatomic,copy) NSString* dataContent;
- (KalturaFieldType)getTypeOfHasRealThumbnail;
- (KalturaFieldType)getTypeOfEditorType;
- (KalturaFieldType)getTypeOfDataContent;
- (void)setHasRealThumbnailFromString:(NSString*)aPropVal;
- (void)setEditorTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaPlaylist : KalturaBaseEntry
// Content of the playlist - 
// XML if the playlistType is dynamic 
// text if the playlistType is static 
// url if the playlistType is mRss
@property (nonatomic,copy) NSString* playlistContent;
@property (nonatomic,retain) NSMutableArray* filters;	// of KalturaMediaEntryFilterForPlaylist elements
@property (nonatomic,assign) int totalResults;
// Type of playlist
@property (nonatomic,assign) int playlistType;	// enum KalturaPlaylistType
// Number of plays
@property (nonatomic,assign,readonly) int plays;
// Number of views
@property (nonatomic,assign,readonly) int views;
// The duration in seconds
@property (nonatomic,assign,readonly) int duration;
- (KalturaFieldType)getTypeOfPlaylistContent;
- (KalturaFieldType)getTypeOfFilters;
- (NSString*)getObjectTypeOfFilters;
- (KalturaFieldType)getTypeOfTotalResults;
- (KalturaFieldType)getTypeOfPlaylistType;
- (KalturaFieldType)getTypeOfPlays;
- (KalturaFieldType)getTypeOfViews;
- (KalturaFieldType)getTypeOfDuration;
- (void)setTotalResultsFromString:(NSString*)aPropVal;
- (void)setPlaylistTypeFromString:(NSString*)aPropVal;
- (void)setPlaysFromString:(NSString*)aPropVal;
- (void)setViewsFromString:(NSString*)aPropVal;
- (void)setDurationFromString:(NSString*)aPropVal;
@end

// Used to ingest entry object, as single resource or list of resources accompanied by asset params ids.
@interface KalturaResource : KalturaObjectBase
@end

// Is a unified way to add content to Kaltura whether it's an uploaded file, webcam recording, imported URL or existing file sync.
@interface KalturaContentResource : KalturaResource
@end

// Used to ingest media that is already ingested to Kaltura system as a different flavor asset in the past, the new created flavor asset will be ready immediately using a file sync of link type that will point to the existing file sync of the existing flavor asset.
@interface KalturaAssetResource : KalturaContentResource
// ID of the source asset
@property (nonatomic,copy) NSString* assetId;
- (KalturaFieldType)getTypeOfAssetId;
@end

@interface KalturaDataCenterContentResource : KalturaContentResource
@end

// Used to ingest media file that is already accessible on the shared disc.
@interface KalturaServerFileResource : KalturaDataCenterContentResource
// Full path to the local file
@property (nonatomic,copy) NSString* localFilePath;
- (KalturaFieldType)getTypeOfLocalFilePath;
@end

// Used to ingest media that uploaded to the system and represented by token that returned from upload.upload action or uploadToken.add action.
@interface KalturaUploadedFileTokenResource : KalturaDataCenterContentResource
// Token that returned from upload.upload action or uploadToken.add action.
@property (nonatomic,copy) NSString* token;
- (KalturaFieldType)getTypeOfToken;
@end

// Used to ingest media that streamed to the system and represented by token that returned from media server such as FMS or red5.
@interface KalturaWebcamTokenResource : KalturaDataCenterContentResource
// Token that returned from media server such as FMS or red5.
@property (nonatomic,copy) NSString* token;
- (KalturaFieldType)getTypeOfToken;
@end

// Used to ingest media that is already ingested to Kaltura system as a different entry in the past, the new created flavor asset will be ready immediately using a file sync of link type that will point to the existing file sync of the existing entry.
@interface KalturaEntryResource : KalturaContentResource
// ID of the source entry
@property (nonatomic,copy) NSString* entryId;
// ID of the source flavor params, set to null to use the source flavor
@property (nonatomic,assign) int flavorParamsId;
- (KalturaFieldType)getTypeOfEntryId;
- (KalturaFieldType)getTypeOfFlavorParamsId;
- (void)setFlavorParamsIdFromString:(NSString*)aPropVal;
@end

// Used to ingest media that is already ingested to Kaltura system as a different file in the past, the new created flavor asset will be ready immediately using a file sync of link type that will point to the existing file sync.
@interface KalturaFileSyncResource : KalturaContentResource
// The object type of the file sync object
@property (nonatomic,assign) int fileSyncObjectType;
// The object sub-type of the file sync object
@property (nonatomic,assign) int objectSubType;
// The object id of the file sync object
@property (nonatomic,copy) NSString* objectId;
// The version of the file sync object
@property (nonatomic,copy) NSString* version;
- (KalturaFieldType)getTypeOfFileSyncObjectType;
- (KalturaFieldType)getTypeOfObjectSubType;
- (KalturaFieldType)getTypeOfObjectId;
- (KalturaFieldType)getTypeOfVersion;
- (void)setFileSyncObjectTypeFromString:(NSString*)aPropVal;
- (void)setObjectSubTypeFromString:(NSString*)aPropVal;
@end

// A resource that perform operation (transcoding, clipping, cropping) before the flavor is ready.
@interface KalturaOperationResource : KalturaContentResource
// Only KalturaEntryResource and KalturaAssetResource are supported
@property (nonatomic,retain) KalturaContentResource* resource;
@property (nonatomic,retain) NSMutableArray* operationAttributes;	// of KalturaOperationAttributes elements
// ID of alternative asset params to be used instead of the system default flavor params
@property (nonatomic,assign) int assetParamsId;
- (KalturaFieldType)getTypeOfResource;
- (NSString*)getObjectTypeOfResource;
- (KalturaFieldType)getTypeOfOperationAttributes;
- (NSString*)getObjectTypeOfOperationAttributes;
- (KalturaFieldType)getTypeOfAssetParamsId;
- (void)setAssetParamsIdFromString:(NSString*)aPropVal;
@end

// Used to ingest media that is available on remote server and accessible using the supplied URL, media file will be downloaded using import job in order to make the asset ready.
@interface KalturaUrlResource : KalturaContentResource
// Remote URL, FTP, HTTP or HTTPS
@property (nonatomic,copy) NSString* url;
- (KalturaFieldType)getTypeOfUrl;
@end

// Used to ingest media that is available on remote server and accessible using the supplied URL, the media file won't be downloaded but a file sync object of URL type will point to the media URL.
@interface KalturaRemoteStorageResource : KalturaUrlResource
// ID of storage profile to be associated with the created file sync, used for file serving URL composing.
@property (nonatomic,assign) int storageProfileId;
- (KalturaFieldType)getTypeOfStorageProfileId;
- (void)setStorageProfileIdFromString:(NSString*)aPropVal;
@end

// Used to ingest media that is available on remote SSH server and accessible using the supplied URL, media file will be downloaded using import job in order to make the asset ready.
@interface KalturaSshUrlResource : KalturaUrlResource
// SSH private key
@property (nonatomic,copy) NSString* privateKey;
// SSH public key
@property (nonatomic,copy) NSString* publicKey;
// Passphrase for SSH keys
@property (nonatomic,copy) NSString* keyPassphrase;
- (KalturaFieldType)getTypeOfPrivateKey;
- (KalturaFieldType)getTypeOfPublicKey;
- (KalturaFieldType)getTypeOfKeyPassphrase;
@end

// Used to ingest media that is available on remote server and accessible using the supplied URL, the media file won't be downloaded but a file sync object of URL type will point to the media URL.
@interface KalturaRemoteStorageResources : KalturaContentResource
// Array of remote stoage resources
@property (nonatomic,retain) NSMutableArray* resources;	// of KalturaRemoteStorageResource elements
- (KalturaFieldType)getTypeOfResources;
- (NSString*)getObjectTypeOfResources;
@end

@interface KalturaAssetParamsResourceContainer : KalturaResource
// The content resource to associate with asset params
@property (nonatomic,retain) KalturaContentResource* resource;
// The asset params to associate with the reaource
@property (nonatomic,assign) int assetParamsId;
- (KalturaFieldType)getTypeOfResource;
- (NSString*)getObjectTypeOfResource;
- (KalturaFieldType)getTypeOfAssetParamsId;
- (void)setAssetParamsIdFromString:(NSString*)aPropVal;
@end

@interface KalturaAssetsParamsResourceContainers : KalturaResource
// Array of resources associated with asset params ids
@property (nonatomic,retain) NSMutableArray* resources;	// of KalturaAssetParamsResourceContainer elements
- (KalturaFieldType)getTypeOfResources;
- (NSString*)getObjectTypeOfResources;
@end

@interface KalturaRemotePath : KalturaObjectBase
@property (nonatomic,assign,readonly) int storageProfileId;
@property (nonatomic,copy,readonly) NSString* uri;
- (KalturaFieldType)getTypeOfStorageProfileId;
- (KalturaFieldType)getTypeOfUri;
- (void)setStorageProfileIdFromString:(NSString*)aPropVal;
@end

@interface KalturaRemotePathListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaRemotePath elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaBaseEntryListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaBaseEntry elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaModerationFlag : KalturaObjectBase
// Moderation flag id
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int partnerId;
// The user id that added the moderation flag
@property (nonatomic,copy,readonly) NSString* userId;
// The type of the moderation flag (entry or user)
@property (nonatomic,assign,readonly) int moderationObjectType;	// enum KalturaModerationObjectType
// If moderation flag is set for entry, this is the flagged entry id
@property (nonatomic,copy) NSString* flaggedEntryId;
// If moderation flag is set for user, this is the flagged user id
@property (nonatomic,copy) NSString* flaggedUserId;
// The moderation flag status
@property (nonatomic,assign,readonly) int status;	// enum KalturaModerationFlagStatus
// The comment that was added to the flag
@property (nonatomic,copy) NSString* comments;
@property (nonatomic,assign) int flagType;	// enum KalturaModerationFlagType
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfUserId;
- (KalturaFieldType)getTypeOfModerationObjectType;
- (KalturaFieldType)getTypeOfFlaggedEntryId;
- (KalturaFieldType)getTypeOfFlaggedUserId;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfComments;
- (KalturaFieldType)getTypeOfFlagType;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setModerationObjectTypeFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setFlagTypeFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
@end

@interface KalturaModerationFlagListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaModerationFlag elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaAccessControlScope : KalturaObjectBase
// URL to be used to test domain conditions.
@property (nonatomic,copy) NSString* referrer;
// IP to be used to test geographic location conditions.
@property (nonatomic,copy) NSString* ip;
// Kaltura session to be used to test session and user conditions.
@property (nonatomic,copy) NSString* ks;
// Browser or client application to be used to test agent conditions.
@property (nonatomic,copy) NSString* userAgent;
// Unix timestamp (In seconds) to be used to test entry scheduling, keep null to use now.
@property (nonatomic,assign) int time;
// Indicates what contexts should be tested. No contexts means any context.
@property (nonatomic,retain) NSMutableArray* contexts;	// of KalturaAccessControlContextTypeHolder elements
- (KalturaFieldType)getTypeOfReferrer;
- (KalturaFieldType)getTypeOfIp;
- (KalturaFieldType)getTypeOfKs;
- (KalturaFieldType)getTypeOfUserAgent;
- (KalturaFieldType)getTypeOfTime;
- (KalturaFieldType)getTypeOfContexts;
- (NSString*)getObjectTypeOfContexts;
- (void)setTimeFromString:(NSString*)aPropVal;
@end

@interface KalturaEntryContextDataParams : KalturaAccessControlScope
@property (nonatomic,copy) NSString* flavorAssetId;
@property (nonatomic,copy) NSString* streamerType;
@property (nonatomic,copy) NSString* mediaProtocol;
- (KalturaFieldType)getTypeOfFlavorAssetId;
- (KalturaFieldType)getTypeOfStreamerType;
- (KalturaFieldType)getTypeOfMediaProtocol;
@end

// A string representation to return an array of strings
@interface KalturaString : KalturaObjectBase
@property (nonatomic,copy) NSString* value;
- (KalturaFieldType)getTypeOfValue;
@end

@interface KalturaEntryContextDataResult : KalturaObjectBase
// DEPRECATED
@property (nonatomic,assign) BOOL isSiteRestricted;
// DEPRECATED
@property (nonatomic,assign) BOOL isCountryRestricted;
// DEPRECATED
@property (nonatomic,assign) BOOL isSessionRestricted;
// DEPRECATED
@property (nonatomic,assign) BOOL isIpAddressRestricted;
// DEPRECATED
@property (nonatomic,assign) BOOL isUserAgentRestricted;
// DEPRECATED
@property (nonatomic,assign) int previewLength;
@property (nonatomic,assign) BOOL isScheduledNow;
@property (nonatomic,assign) BOOL isAdmin;
// http/rtmp/hdnetwork
@property (nonatomic,copy) NSString* streamerType;
// http/https, rtmp/rtmpe
@property (nonatomic,copy) NSString* mediaProtocol;
@property (nonatomic,copy) NSString* storageProfilesXML;
// Array of messages as received from the access control rules that invalidated
@property (nonatomic,retain) NSMutableArray* accessControlMessages;	// of KalturaString elements
// Array of actions as received from the access control rules that invalidated
@property (nonatomic,retain) NSMutableArray* accessControlActions;	// of KalturaAccessControlAction elements
- (KalturaFieldType)getTypeOfIsSiteRestricted;
- (KalturaFieldType)getTypeOfIsCountryRestricted;
- (KalturaFieldType)getTypeOfIsSessionRestricted;
- (KalturaFieldType)getTypeOfIsIpAddressRestricted;
- (KalturaFieldType)getTypeOfIsUserAgentRestricted;
- (KalturaFieldType)getTypeOfPreviewLength;
- (KalturaFieldType)getTypeOfIsScheduledNow;
- (KalturaFieldType)getTypeOfIsAdmin;
- (KalturaFieldType)getTypeOfStreamerType;
- (KalturaFieldType)getTypeOfMediaProtocol;
- (KalturaFieldType)getTypeOfStorageProfilesXML;
- (KalturaFieldType)getTypeOfAccessControlMessages;
- (NSString*)getObjectTypeOfAccessControlMessages;
- (KalturaFieldType)getTypeOfAccessControlActions;
- (NSString*)getObjectTypeOfAccessControlActions;
- (void)setIsSiteRestrictedFromString:(NSString*)aPropVal;
- (void)setIsCountryRestrictedFromString:(NSString*)aPropVal;
- (void)setIsSessionRestrictedFromString:(NSString*)aPropVal;
- (void)setIsIpAddressRestrictedFromString:(NSString*)aPropVal;
- (void)setIsUserAgentRestrictedFromString:(NSString*)aPropVal;
- (void)setPreviewLengthFromString:(NSString*)aPropVal;
- (void)setIsScheduledNowFromString:(NSString*)aPropVal;
- (void)setIsAdminFromString:(NSString*)aPropVal;
@end

@interface KalturaBulkUploadPluginData : KalturaObjectBase
@property (nonatomic,copy) NSString* field;
@property (nonatomic,copy) NSString* value;
- (KalturaFieldType)getTypeOfField;
- (KalturaFieldType)getTypeOfValue;
@end

@interface KalturaBulkUploadResult : KalturaObjectBase
// The id of the result
@property (nonatomic,assign,readonly) int id;
// The id of the parent job
@property (nonatomic,assign) int bulkUploadJobId;
// The index of the line in the CSV
@property (nonatomic,assign) int lineIndex;
@property (nonatomic,assign) int partnerId;
@property (nonatomic,assign) int action;	// enum KalturaBulkUploadAction
@property (nonatomic,copy) NSString* entryId;
@property (nonatomic,copy) NSString* objectId;
@property (nonatomic,copy) NSString* bulkUploadResultObjectType;	// enum KalturaBulkUploadResultObjectType
@property (nonatomic,assign) int entryStatus;
// The data as recieved in the csv
@property (nonatomic,copy) NSString* rowData;
@property (nonatomic,copy) NSString* title;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,copy) NSString* tags;
@property (nonatomic,copy) NSString* url;
@property (nonatomic,copy) NSString* contentType;
@property (nonatomic,assign) int conversionProfileId;
@property (nonatomic,assign) int accessControlProfileId;
@property (nonatomic,copy) NSString* category;
@property (nonatomic,assign) int scheduleStartDate;
@property (nonatomic,assign) int scheduleEndDate;
@property (nonatomic,copy) NSString* thumbnailUrl;
@property (nonatomic,assign) BOOL thumbnailSaved;
@property (nonatomic,copy) NSString* partnerData;
@property (nonatomic,copy) NSString* errorDescription;
@property (nonatomic,retain) NSMutableArray* pluginsData;	// of KalturaBulkUploadPluginData elements
@property (nonatomic,copy) NSString* sshPrivateKey;
@property (nonatomic,copy) NSString* sshPublicKey;
@property (nonatomic,copy) NSString* sshKeyPassphrase;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfBulkUploadJobId;
- (KalturaFieldType)getTypeOfLineIndex;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfAction;
- (KalturaFieldType)getTypeOfEntryId;
- (KalturaFieldType)getTypeOfObjectId;
- (KalturaFieldType)getTypeOfBulkUploadResultObjectType;
- (KalturaFieldType)getTypeOfEntryStatus;
- (KalturaFieldType)getTypeOfRowData;
- (KalturaFieldType)getTypeOfTitle;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfUrl;
- (KalturaFieldType)getTypeOfContentType;
- (KalturaFieldType)getTypeOfConversionProfileId;
- (KalturaFieldType)getTypeOfAccessControlProfileId;
- (KalturaFieldType)getTypeOfCategory;
- (KalturaFieldType)getTypeOfScheduleStartDate;
- (KalturaFieldType)getTypeOfScheduleEndDate;
- (KalturaFieldType)getTypeOfThumbnailUrl;
- (KalturaFieldType)getTypeOfThumbnailSaved;
- (KalturaFieldType)getTypeOfPartnerData;
- (KalturaFieldType)getTypeOfErrorDescription;
- (KalturaFieldType)getTypeOfPluginsData;
- (NSString*)getObjectTypeOfPluginsData;
- (KalturaFieldType)getTypeOfSshPrivateKey;
- (KalturaFieldType)getTypeOfSshPublicKey;
- (KalturaFieldType)getTypeOfSshKeyPassphrase;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setBulkUploadJobIdFromString:(NSString*)aPropVal;
- (void)setLineIndexFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setActionFromString:(NSString*)aPropVal;
- (void)setEntryStatusFromString:(NSString*)aPropVal;
- (void)setConversionProfileIdFromString:(NSString*)aPropVal;
- (void)setAccessControlProfileIdFromString:(NSString*)aPropVal;
- (void)setScheduleStartDateFromString:(NSString*)aPropVal;
- (void)setScheduleEndDateFromString:(NSString*)aPropVal;
- (void)setThumbnailSavedFromString:(NSString*)aPropVal;
@end

@interface KalturaBulkUpload : KalturaObjectBase
@property (nonatomic,assign) int id;
@property (nonatomic,copy) NSString* uploadedBy;
@property (nonatomic,copy) NSString* uploadedByUserId;
@property (nonatomic,assign) int uploadedOn;
@property (nonatomic,assign) int numOfEntries;
@property (nonatomic,assign) int status;	// enum KalturaBatchJobStatus
@property (nonatomic,copy) NSString* logFileUrl;
// DEPRECATED
@property (nonatomic,copy) NSString* csvFileUrl;
@property (nonatomic,copy) NSString* bulkFileUrl;
@property (nonatomic,copy) NSString* bulkUploadType;	// enum KalturaBulkUploadType
@property (nonatomic,retain) NSMutableArray* results;	// of KalturaBulkUploadResult elements
@property (nonatomic,copy) NSString* error;
@property (nonatomic,assign) int errorType;	// enum KalturaBatchJobErrorTypes
@property (nonatomic,assign) int errorNumber;
@property (nonatomic,copy) NSString* fileName;
@property (nonatomic,copy) NSString* description;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfUploadedBy;
- (KalturaFieldType)getTypeOfUploadedByUserId;
- (KalturaFieldType)getTypeOfUploadedOn;
- (KalturaFieldType)getTypeOfNumOfEntries;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfLogFileUrl;
- (KalturaFieldType)getTypeOfCsvFileUrl;
- (KalturaFieldType)getTypeOfBulkFileUrl;
- (KalturaFieldType)getTypeOfBulkUploadType;
- (KalturaFieldType)getTypeOfResults;
- (NSString*)getObjectTypeOfResults;
- (KalturaFieldType)getTypeOfError;
- (KalturaFieldType)getTypeOfErrorType;
- (KalturaFieldType)getTypeOfErrorNumber;
- (KalturaFieldType)getTypeOfFileName;
- (KalturaFieldType)getTypeOfDescription;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setUploadedOnFromString:(NSString*)aPropVal;
- (void)setNumOfEntriesFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setErrorTypeFromString:(NSString*)aPropVal;
- (void)setErrorNumberFromString:(NSString*)aPropVal;
@end

@interface KalturaBulkUploadListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaBulkUpload elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaCategory : KalturaObjectBase
// The id of the Category
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign) int parentId;
@property (nonatomic,assign,readonly) int depth;
@property (nonatomic,assign,readonly) int partnerId;
// The name of the Category. 
// The following characters are not allowed: '<', '>', ','
@property (nonatomic,copy) NSString* name;
// The full name of the Category
@property (nonatomic,copy,readonly) NSString* fullName;
// Number of entries in this Category (including child categories)
@property (nonatomic,assign,readonly) int entriesCount;
// Creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfParentId;
- (KalturaFieldType)getTypeOfDepth;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfFullName;
- (KalturaFieldType)getTypeOfEntriesCount;
- (KalturaFieldType)getTypeOfCreatedAt;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setParentIdFromString:(NSString*)aPropVal;
- (void)setDepthFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setEntriesCountFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
@end

@interface KalturaCategoryListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaCategory elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaConversionProfileAssetParams : KalturaObjectBase
// The id of the conversion profile
@property (nonatomic,assign,readonly) int conversionProfileId;
// The id of the asset params
@property (nonatomic,assign,readonly) int assetParamsId;
// The ingestion origin of the asset params
@property (nonatomic,assign) int readyBehavior;	// enum KalturaFlavorReadyBehaviorType
// The ingestion origin of the asset params
@property (nonatomic,assign) int origin;	// enum KalturaAssetParamsOrigin
// Asset params system name
@property (nonatomic,copy) NSString* systemName;
// Starts conversion even if the decision layer reduced the configuration to comply with the source
@property (nonatomic,assign) int forceNoneComplied;	// enum KalturaNullableBoolean
- (KalturaFieldType)getTypeOfConversionProfileId;
- (KalturaFieldType)getTypeOfAssetParamsId;
- (KalturaFieldType)getTypeOfReadyBehavior;
- (KalturaFieldType)getTypeOfOrigin;
- (KalturaFieldType)getTypeOfSystemName;
- (KalturaFieldType)getTypeOfForceNoneComplied;
- (void)setConversionProfileIdFromString:(NSString*)aPropVal;
- (void)setAssetParamsIdFromString:(NSString*)aPropVal;
- (void)setReadyBehaviorFromString:(NSString*)aPropVal;
- (void)setOriginFromString:(NSString*)aPropVal;
- (void)setForceNoneCompliedFromString:(NSString*)aPropVal;
@end

@interface KalturaConversionProfileAssetParamsListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaConversionProfileAssetParams elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaCropDimensions : KalturaObjectBase
// Crop left point
@property (nonatomic,assign) int left;
// Crop top point
@property (nonatomic,assign) int top;
// Crop width
@property (nonatomic,assign) int width;
// Crop height
@property (nonatomic,assign) int height;
- (KalturaFieldType)getTypeOfLeft;
- (KalturaFieldType)getTypeOfTop;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (void)setLeftFromString:(NSString*)aPropVal;
- (void)setTopFromString:(NSString*)aPropVal;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
@end

@interface KalturaConversionProfile : KalturaObjectBase
// The id of the Conversion Profile
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* status;	// enum KalturaConversionProfileStatus
// The name of the Conversion Profile
@property (nonatomic,copy) NSString* name;
// System name of the Conversion Profile
@property (nonatomic,copy) NSString* systemName;
// Comma separated tags
@property (nonatomic,copy) NSString* tags;
// The description of the Conversion Profile
@property (nonatomic,copy) NSString* description;
// ID of the default entry to be used for template data
@property (nonatomic,copy) NSString* defaultEntryId;
// Creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// List of included flavor ids (comma separated)
@property (nonatomic,copy) NSString* flavorParamsIds;
// Indicates that this conversion profile is system default
@property (nonatomic,assign) int isDefault;	// enum KalturaNullableBoolean
// Indicates that this conversion profile is partner default
@property (nonatomic,assign,readonly) BOOL isPartnerDefault;
// Cropping dimensions
// DEPRECATED
@property (nonatomic,retain) KalturaCropDimensions* cropDimensions;
// Clipping start position (in miliseconds)
// DEPRECATED
@property (nonatomic,assign) int clipStart;
// Clipping duration (in miliseconds)
// DEPRECATED
@property (nonatomic,assign) int clipDuration;
// XSL to transform ingestion MRSS XML
@property (nonatomic,copy) NSString* xslTransformation;
// ID of default storage profile to be used for linked net-storage file syncs
@property (nonatomic,assign) int storageProfileId;
// Media parser type to be used for extract media
@property (nonatomic,copy) NSString* mediaParserType;	// enum KalturaMediaParserType
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfSystemName;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfDefaultEntryId;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfFlavorParamsIds;
- (KalturaFieldType)getTypeOfIsDefault;
- (KalturaFieldType)getTypeOfIsPartnerDefault;
- (KalturaFieldType)getTypeOfCropDimensions;
- (NSString*)getObjectTypeOfCropDimensions;
- (KalturaFieldType)getTypeOfClipStart;
- (KalturaFieldType)getTypeOfClipDuration;
- (KalturaFieldType)getTypeOfXslTransformation;
- (KalturaFieldType)getTypeOfStorageProfileId;
- (KalturaFieldType)getTypeOfMediaParserType;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setIsDefaultFromString:(NSString*)aPropVal;
- (void)setIsPartnerDefaultFromString:(NSString*)aPropVal;
- (void)setClipStartFromString:(NSString*)aPropVal;
- (void)setClipDurationFromString:(NSString*)aPropVal;
- (void)setStorageProfileIdFromString:(NSString*)aPropVal;
@end

@interface KalturaConversionProfileListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaConversionProfile elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaDataListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaDataEntry elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaEmailIngestionProfile : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,copy) NSString* name;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,copy) NSString* emailAddress;
@property (nonatomic,copy) NSString* mailboxId;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,assign) int conversionProfile2Id;
@property (nonatomic,assign) int moderationStatus;	// enum KalturaEntryModerationStatus
@property (nonatomic,assign,readonly) int status;	// enum KalturaEmailIngestionProfileStatus
@property (nonatomic,copy,readonly) NSString* createdAt;
@property (nonatomic,copy) NSString* defaultCategory;
@property (nonatomic,copy) NSString* defaultUserId;
@property (nonatomic,copy) NSString* defaultTags;
@property (nonatomic,copy) NSString* defaultAdminTags;
@property (nonatomic,assign) int maxAttachmentSizeKbytes;
@property (nonatomic,assign) int maxAttachmentsPerMail;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfEmailAddress;
- (KalturaFieldType)getTypeOfMailboxId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfConversionProfile2Id;
- (KalturaFieldType)getTypeOfModerationStatus;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfDefaultCategory;
- (KalturaFieldType)getTypeOfDefaultUserId;
- (KalturaFieldType)getTypeOfDefaultTags;
- (KalturaFieldType)getTypeOfDefaultAdminTags;
- (KalturaFieldType)getTypeOfMaxAttachmentSizeKbytes;
- (KalturaFieldType)getTypeOfMaxAttachmentsPerMail;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setConversionProfile2IdFromString:(NSString*)aPropVal;
- (void)setModerationStatusFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setMaxAttachmentSizeKbytesFromString:(NSString*)aPropVal;
- (void)setMaxAttachmentsPerMailFromString:(NSString*)aPropVal;
@end

@interface KalturaAsset : KalturaObjectBase
// The ID of the Flavor Asset
@property (nonatomic,copy,readonly) NSString* id;
// The entry ID of the Flavor Asset
@property (nonatomic,copy,readonly) NSString* entryId;
@property (nonatomic,assign,readonly) int partnerId;
// The version of the Flavor Asset
@property (nonatomic,assign,readonly) int version;
// The size (in KBytes) of the Flavor Asset
@property (nonatomic,assign,readonly) int size;
// Tags used to identify the Flavor Asset in various scenarios
@property (nonatomic,copy) NSString* tags;
// The file extension
@property (nonatomic,copy) NSString* fileExt;	// insertonly
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,assign,readonly) int deletedAt;
// System description, error message, warnings and failure cause.
@property (nonatomic,copy,readonly) NSString* description;
// Partner private data
@property (nonatomic,copy) NSString* partnerData;
// Partner friendly description
@property (nonatomic,copy) NSString* partnerDescription;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfEntryId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfVersion;
- (KalturaFieldType)getTypeOfSize;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfFileExt;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfDeletedAt;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfPartnerData;
- (KalturaFieldType)getTypeOfPartnerDescription;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setVersionFromString:(NSString*)aPropVal;
- (void)setSizeFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setDeletedAtFromString:(NSString*)aPropVal;
@end

@interface KalturaFlavorAsset : KalturaAsset
// The Flavor Params used to create this Flavor Asset
@property (nonatomic,assign) int flavorParamsId;	// insertonly
// The width of the Flavor Asset
@property (nonatomic,assign,readonly) int width;
// The height of the Flavor Asset
@property (nonatomic,assign,readonly) int height;
// The overall bitrate (in KBits) of the Flavor Asset
@property (nonatomic,assign,readonly) int bitrate;
// The frame rate (in FPS) of the Flavor Asset
@property (nonatomic,assign,readonly) int frameRate;
// True if this Flavor Asset is the original source
@property (nonatomic,assign,readonly) BOOL isOriginal;
// True if this Flavor Asset is playable in KDP
@property (nonatomic,assign,readonly) BOOL isWeb;
// The container format
@property (nonatomic,copy,readonly) NSString* containerFormat;
// The video codec
@property (nonatomic,copy,readonly) NSString* videoCodecId;
// The status of the Flavor Asset
@property (nonatomic,assign,readonly) int status;	// enum KalturaFlavorAssetStatus
- (KalturaFieldType)getTypeOfFlavorParamsId;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (KalturaFieldType)getTypeOfBitrate;
- (KalturaFieldType)getTypeOfFrameRate;
- (KalturaFieldType)getTypeOfIsOriginal;
- (KalturaFieldType)getTypeOfIsWeb;
- (KalturaFieldType)getTypeOfContainerFormat;
- (KalturaFieldType)getTypeOfVideoCodecId;
- (KalturaFieldType)getTypeOfStatus;
- (void)setFlavorParamsIdFromString:(NSString*)aPropVal;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
- (void)setBitrateFromString:(NSString*)aPropVal;
- (void)setFrameRateFromString:(NSString*)aPropVal;
- (void)setIsOriginalFromString:(NSString*)aPropVal;
- (void)setIsWebFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
@end

@interface KalturaThumbAsset : KalturaAsset
// The Flavor Params used to create this Flavor Asset
@property (nonatomic,assign) int thumbParamsId;	// insertonly
// The width of the Flavor Asset
@property (nonatomic,assign,readonly) int width;
// The height of the Flavor Asset
@property (nonatomic,assign,readonly) int height;
// The status of the asset
@property (nonatomic,assign,readonly) int status;	// enum KalturaThumbAssetStatus
- (KalturaFieldType)getTypeOfThumbParamsId;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (KalturaFieldType)getTypeOfStatus;
- (void)setThumbParamsIdFromString:(NSString*)aPropVal;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
@end

@interface KalturaFlavorAssetListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaFlavorAsset elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaAssetParams : KalturaObjectBase
// The id of the Flavor Params
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int partnerId;
// The name of the Flavor Params
@property (nonatomic,copy) NSString* name;
// System name of the Flavor Params
@property (nonatomic,copy) NSString* systemName;
// The description of the Flavor Params
@property (nonatomic,copy) NSString* description;
// Creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// True if those Flavor Params are part of system defaults
@property (nonatomic,assign,readonly) int isSystemDefault;	// enum KalturaNullableBoolean
// The Flavor Params tags are used to identify the flavor for different usage (e.g. web, hd, mobile)
@property (nonatomic,copy) NSString* tags;
// Array of partner permisison names that required for using this asset params
@property (nonatomic,retain) NSMutableArray* requiredPermissions;	// of KalturaString elements
// Id of remote storage profile that used to get the source, zero indicates Kaltura data center
@property (nonatomic,assign) int sourceRemoteStorageProfileId;
// Comma seperated ids of remote storage profiles that the flavor distributed to, the distribution done by the conversion engine
@property (nonatomic,assign) int remoteStorageProfileIds;
// Media parser type to be used for post-conversion validation
@property (nonatomic,copy) NSString* mediaParserType;	// enum KalturaMediaParserType
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfSystemName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfIsSystemDefault;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfRequiredPermissions;
- (NSString*)getObjectTypeOfRequiredPermissions;
- (KalturaFieldType)getTypeOfSourceRemoteStorageProfileId;
- (KalturaFieldType)getTypeOfRemoteStorageProfileIds;
- (KalturaFieldType)getTypeOfMediaParserType;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setIsSystemDefaultFromString:(NSString*)aPropVal;
- (void)setSourceRemoteStorageProfileIdFromString:(NSString*)aPropVal;
- (void)setRemoteStorageProfileIdsFromString:(NSString*)aPropVal;
@end

@interface KalturaAssetParamsOutput : KalturaAssetParams
@property (nonatomic,assign) int assetParamsId;
@property (nonatomic,copy) NSString* assetParamsVersion;
@property (nonatomic,copy) NSString* assetId;
@property (nonatomic,copy) NSString* assetVersion;
@property (nonatomic,assign) int readyBehavior;
// The container format of the Flavor Params
@property (nonatomic,copy) NSString* format;	// enum KalturaContainerFormat
- (KalturaFieldType)getTypeOfAssetParamsId;
- (KalturaFieldType)getTypeOfAssetParamsVersion;
- (KalturaFieldType)getTypeOfAssetId;
- (KalturaFieldType)getTypeOfAssetVersion;
- (KalturaFieldType)getTypeOfReadyBehavior;
- (KalturaFieldType)getTypeOfFormat;
- (void)setAssetParamsIdFromString:(NSString*)aPropVal;
- (void)setReadyBehaviorFromString:(NSString*)aPropVal;
@end

@interface KalturaFlavorParams : KalturaAssetParams
// The video codec of the Flavor Params
@property (nonatomic,copy) NSString* videoCodec;	// enum KalturaVideoCodec
// The video bitrate (in KBits) of the Flavor Params
@property (nonatomic,assign) int videoBitrate;
// The audio codec of the Flavor Params
@property (nonatomic,copy) NSString* audioCodec;	// enum KalturaAudioCodec
// The audio bitrate (in KBits) of the Flavor Params
@property (nonatomic,assign) int audioBitrate;
// The number of audio channels for "downmixing"
@property (nonatomic,assign) int audioChannels;
// The audio sample rate of the Flavor Params
@property (nonatomic,assign) int audioSampleRate;
// The desired width of the Flavor Params
@property (nonatomic,assign) int width;
// The desired height of the Flavor Params
@property (nonatomic,assign) int height;
// The frame rate of the Flavor Params
@property (nonatomic,assign) int frameRate;
// The gop size of the Flavor Params
@property (nonatomic,assign) int gopSize;
// The list of conversion engines (comma separated)
@property (nonatomic,copy) NSString* conversionEngines;
// The list of conversion engines extra params (separated with "|")
@property (nonatomic,copy) NSString* conversionEnginesExtraParams;
@property (nonatomic,assign) BOOL twoPass;
@property (nonatomic,assign) int deinterlice;
@property (nonatomic,assign) int rotate;
@property (nonatomic,copy) NSString* operators;
@property (nonatomic,assign) int engineVersion;
// The container format of the Flavor Params
@property (nonatomic,copy) NSString* format;	// enum KalturaContainerFormat
@property (nonatomic,assign) int aspectRatioProcessingMode;
@property (nonatomic,assign) int forceFrameToMultiplication16;
@property (nonatomic,assign) int videoConstantBitrate;
@property (nonatomic,assign) int videoBitrateTolerance;
@property (nonatomic,assign) int clipOffset;
@property (nonatomic,assign) int clipDuration;
- (KalturaFieldType)getTypeOfVideoCodec;
- (KalturaFieldType)getTypeOfVideoBitrate;
- (KalturaFieldType)getTypeOfAudioCodec;
- (KalturaFieldType)getTypeOfAudioBitrate;
- (KalturaFieldType)getTypeOfAudioChannels;
- (KalturaFieldType)getTypeOfAudioSampleRate;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (KalturaFieldType)getTypeOfFrameRate;
- (KalturaFieldType)getTypeOfGopSize;
- (KalturaFieldType)getTypeOfConversionEngines;
- (KalturaFieldType)getTypeOfConversionEnginesExtraParams;
- (KalturaFieldType)getTypeOfTwoPass;
- (KalturaFieldType)getTypeOfDeinterlice;
- (KalturaFieldType)getTypeOfRotate;
- (KalturaFieldType)getTypeOfOperators;
- (KalturaFieldType)getTypeOfEngineVersion;
- (KalturaFieldType)getTypeOfFormat;
- (KalturaFieldType)getTypeOfAspectRatioProcessingMode;
- (KalturaFieldType)getTypeOfForceFrameToMultiplication16;
- (KalturaFieldType)getTypeOfVideoConstantBitrate;
- (KalturaFieldType)getTypeOfVideoBitrateTolerance;
- (KalturaFieldType)getTypeOfClipOffset;
- (KalturaFieldType)getTypeOfClipDuration;
- (void)setVideoBitrateFromString:(NSString*)aPropVal;
- (void)setAudioBitrateFromString:(NSString*)aPropVal;
- (void)setAudioChannelsFromString:(NSString*)aPropVal;
- (void)setAudioSampleRateFromString:(NSString*)aPropVal;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
- (void)setFrameRateFromString:(NSString*)aPropVal;
- (void)setGopSizeFromString:(NSString*)aPropVal;
- (void)setTwoPassFromString:(NSString*)aPropVal;
- (void)setDeinterliceFromString:(NSString*)aPropVal;
- (void)setRotateFromString:(NSString*)aPropVal;
- (void)setEngineVersionFromString:(NSString*)aPropVal;
- (void)setAspectRatioProcessingModeFromString:(NSString*)aPropVal;
- (void)setForceFrameToMultiplication16FromString:(NSString*)aPropVal;
- (void)setVideoConstantBitrateFromString:(NSString*)aPropVal;
- (void)setVideoBitrateToleranceFromString:(NSString*)aPropVal;
- (void)setClipOffsetFromString:(NSString*)aPropVal;
- (void)setClipDurationFromString:(NSString*)aPropVal;
@end

@interface KalturaFlavorParamsOutput : KalturaFlavorParams
@property (nonatomic,assign) int flavorParamsId;
@property (nonatomic,copy) NSString* commandLinesStr;
@property (nonatomic,copy) NSString* flavorParamsVersion;
@property (nonatomic,copy) NSString* flavorAssetId;
@property (nonatomic,copy) NSString* flavorAssetVersion;
@property (nonatomic,assign) int readyBehavior;
- (KalturaFieldType)getTypeOfFlavorParamsId;
- (KalturaFieldType)getTypeOfCommandLinesStr;
- (KalturaFieldType)getTypeOfFlavorParamsVersion;
- (KalturaFieldType)getTypeOfFlavorAssetId;
- (KalturaFieldType)getTypeOfFlavorAssetVersion;
- (KalturaFieldType)getTypeOfReadyBehavior;
- (void)setFlavorParamsIdFromString:(NSString*)aPropVal;
- (void)setReadyBehaviorFromString:(NSString*)aPropVal;
@end

@interface KalturaMediaFlavorParamsOutput : KalturaFlavorParamsOutput
@end

@interface KalturaMediaFlavorParams : KalturaFlavorParams
@end

@interface KalturaThumbParams : KalturaAssetParams
@property (nonatomic,assign) int cropType;	// enum KalturaThumbCropType
@property (nonatomic,assign) int quality;
@property (nonatomic,assign) int cropX;
@property (nonatomic,assign) int cropY;
@property (nonatomic,assign) int cropWidth;
@property (nonatomic,assign) int cropHeight;
@property (nonatomic,assign) double videoOffset;
@property (nonatomic,assign) int width;
@property (nonatomic,assign) int height;
@property (nonatomic,assign) double scaleWidth;
@property (nonatomic,assign) double scaleHeight;
// Hexadecimal value
@property (nonatomic,copy) NSString* backgroundColor;
// Id of the flavor params or the thumbnail params to be used as source for the thumbnail creation
@property (nonatomic,assign) int sourceParamsId;
// The container format of the Flavor Params
@property (nonatomic,copy) NSString* format;	// enum KalturaContainerFormat
// The image density (dpi) for example: 72 or 96
@property (nonatomic,assign) int density;
- (KalturaFieldType)getTypeOfCropType;
- (KalturaFieldType)getTypeOfQuality;
- (KalturaFieldType)getTypeOfCropX;
- (KalturaFieldType)getTypeOfCropY;
- (KalturaFieldType)getTypeOfCropWidth;
- (KalturaFieldType)getTypeOfCropHeight;
- (KalturaFieldType)getTypeOfVideoOffset;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (KalturaFieldType)getTypeOfScaleWidth;
- (KalturaFieldType)getTypeOfScaleHeight;
- (KalturaFieldType)getTypeOfBackgroundColor;
- (KalturaFieldType)getTypeOfSourceParamsId;
- (KalturaFieldType)getTypeOfFormat;
- (KalturaFieldType)getTypeOfDensity;
- (void)setCropTypeFromString:(NSString*)aPropVal;
- (void)setQualityFromString:(NSString*)aPropVal;
- (void)setCropXFromString:(NSString*)aPropVal;
- (void)setCropYFromString:(NSString*)aPropVal;
- (void)setCropWidthFromString:(NSString*)aPropVal;
- (void)setCropHeightFromString:(NSString*)aPropVal;
- (void)setVideoOffsetFromString:(NSString*)aPropVal;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
- (void)setScaleWidthFromString:(NSString*)aPropVal;
- (void)setScaleHeightFromString:(NSString*)aPropVal;
- (void)setSourceParamsIdFromString:(NSString*)aPropVal;
- (void)setDensityFromString:(NSString*)aPropVal;
@end

@interface KalturaThumbParamsOutput : KalturaThumbParams
@property (nonatomic,assign) int thumbParamsId;
@property (nonatomic,copy) NSString* thumbParamsVersion;
@property (nonatomic,copy) NSString* thumbAssetId;
@property (nonatomic,copy) NSString* thumbAssetVersion;
@property (nonatomic,assign) int rotate;
- (KalturaFieldType)getTypeOfThumbParamsId;
- (KalturaFieldType)getTypeOfThumbParamsVersion;
- (KalturaFieldType)getTypeOfThumbAssetId;
- (KalturaFieldType)getTypeOfThumbAssetVersion;
- (KalturaFieldType)getTypeOfRotate;
- (void)setThumbParamsIdFromString:(NSString*)aPropVal;
- (void)setRotateFromString:(NSString*)aPropVal;
@end

@interface KalturaFlavorAssetWithParams : KalturaObjectBase
// The Flavor Asset (Can be null when there are params without asset)
@property (nonatomic,retain) KalturaFlavorAsset* flavorAsset;
// The Flavor Params
@property (nonatomic,retain) KalturaFlavorParams* flavorParams;
// The entry id
@property (nonatomic,copy) NSString* entryId;
- (KalturaFieldType)getTypeOfFlavorAsset;
- (NSString*)getObjectTypeOfFlavorAsset;
- (KalturaFieldType)getTypeOfFlavorParams;
- (NSString*)getObjectTypeOfFlavorParams;
- (KalturaFieldType)getTypeOfEntryId;
@end

@interface KalturaFlavorParamsListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaFlavorParams elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaLiveStreamListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaLiveStreamEntry elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaMediaInfo : KalturaObjectBase
// The id of the media info
@property (nonatomic,assign,readonly) int id;
// The id of the related flavor asset
@property (nonatomic,copy) NSString* flavorAssetId;
// The file size
@property (nonatomic,assign) int fileSize;
// The container format
@property (nonatomic,copy) NSString* containerFormat;
// The container id
@property (nonatomic,copy) NSString* containerId;
// The container profile
@property (nonatomic,copy) NSString* containerProfile;
// The container duration
@property (nonatomic,assign) int containerDuration;
// The container bit rate
@property (nonatomic,assign) int containerBitRate;
// The video format
@property (nonatomic,copy) NSString* videoFormat;
// The video codec id
@property (nonatomic,copy) NSString* videoCodecId;
// The video duration
@property (nonatomic,assign) int videoDuration;
// The video bit rate
@property (nonatomic,assign) int videoBitRate;
// The video bit rate mode
@property (nonatomic,assign) int videoBitRateMode;	// enum KalturaBitRateMode
// The video width
@property (nonatomic,assign) int videoWidth;
// The video height
@property (nonatomic,assign) int videoHeight;
// The video frame rate
@property (nonatomic,assign) double videoFrameRate;
// The video display aspect ratio (dar)
@property (nonatomic,assign) double videoDar;
@property (nonatomic,assign) int videoRotation;
// The audio format
@property (nonatomic,copy) NSString* audioFormat;
// The audio codec id
@property (nonatomic,copy) NSString* audioCodecId;
// The audio duration
@property (nonatomic,assign) int audioDuration;
// The audio bit rate
@property (nonatomic,assign) int audioBitRate;
// The audio bit rate mode
@property (nonatomic,assign) int audioBitRateMode;	// enum KalturaBitRateMode
// The number of audio channels
@property (nonatomic,assign) int audioChannels;
// The audio sampling rate
@property (nonatomic,assign) int audioSamplingRate;
// The audio resolution
@property (nonatomic,assign) int audioResolution;
// The writing library
@property (nonatomic,copy) NSString* writingLib;
// The data as returned by the mediainfo command line
@property (nonatomic,copy) NSString* rawData;
@property (nonatomic,copy) NSString* multiStreamInfo;
@property (nonatomic,assign) int scanType;
@property (nonatomic,copy) NSString* multiStream;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfFlavorAssetId;
- (KalturaFieldType)getTypeOfFileSize;
- (KalturaFieldType)getTypeOfContainerFormat;
- (KalturaFieldType)getTypeOfContainerId;
- (KalturaFieldType)getTypeOfContainerProfile;
- (KalturaFieldType)getTypeOfContainerDuration;
- (KalturaFieldType)getTypeOfContainerBitRate;
- (KalturaFieldType)getTypeOfVideoFormat;
- (KalturaFieldType)getTypeOfVideoCodecId;
- (KalturaFieldType)getTypeOfVideoDuration;
- (KalturaFieldType)getTypeOfVideoBitRate;
- (KalturaFieldType)getTypeOfVideoBitRateMode;
- (KalturaFieldType)getTypeOfVideoWidth;
- (KalturaFieldType)getTypeOfVideoHeight;
- (KalturaFieldType)getTypeOfVideoFrameRate;
- (KalturaFieldType)getTypeOfVideoDar;
- (KalturaFieldType)getTypeOfVideoRotation;
- (KalturaFieldType)getTypeOfAudioFormat;
- (KalturaFieldType)getTypeOfAudioCodecId;
- (KalturaFieldType)getTypeOfAudioDuration;
- (KalturaFieldType)getTypeOfAudioBitRate;
- (KalturaFieldType)getTypeOfAudioBitRateMode;
- (KalturaFieldType)getTypeOfAudioChannels;
- (KalturaFieldType)getTypeOfAudioSamplingRate;
- (KalturaFieldType)getTypeOfAudioResolution;
- (KalturaFieldType)getTypeOfWritingLib;
- (KalturaFieldType)getTypeOfRawData;
- (KalturaFieldType)getTypeOfMultiStreamInfo;
- (KalturaFieldType)getTypeOfScanType;
- (KalturaFieldType)getTypeOfMultiStream;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setFileSizeFromString:(NSString*)aPropVal;
- (void)setContainerDurationFromString:(NSString*)aPropVal;
- (void)setContainerBitRateFromString:(NSString*)aPropVal;
- (void)setVideoDurationFromString:(NSString*)aPropVal;
- (void)setVideoBitRateFromString:(NSString*)aPropVal;
- (void)setVideoBitRateModeFromString:(NSString*)aPropVal;
- (void)setVideoWidthFromString:(NSString*)aPropVal;
- (void)setVideoHeightFromString:(NSString*)aPropVal;
- (void)setVideoFrameRateFromString:(NSString*)aPropVal;
- (void)setVideoDarFromString:(NSString*)aPropVal;
- (void)setVideoRotationFromString:(NSString*)aPropVal;
- (void)setAudioDurationFromString:(NSString*)aPropVal;
- (void)setAudioBitRateFromString:(NSString*)aPropVal;
- (void)setAudioBitRateModeFromString:(NSString*)aPropVal;
- (void)setAudioChannelsFromString:(NSString*)aPropVal;
- (void)setAudioSamplingRateFromString:(NSString*)aPropVal;
- (void)setAudioResolutionFromString:(NSString*)aPropVal;
- (void)setScanTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaMediaInfoListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaMediaInfo elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaSearch : KalturaObjectBase
@property (nonatomic,copy) NSString* keyWords;
@property (nonatomic,assign) int searchSource;	// enum KalturaSearchProviderType
@property (nonatomic,assign) int mediaType;	// enum KalturaMediaType
// Use this field to pass dynamic data for searching
// For example - if you set this field to "mymovies_$partner_id"
// The $partner_id will be automatically replcaed with your real partner Id
@property (nonatomic,copy) NSString* extraData;
@property (nonatomic,copy) NSString* authData;
- (KalturaFieldType)getTypeOfKeyWords;
- (KalturaFieldType)getTypeOfSearchSource;
- (KalturaFieldType)getTypeOfMediaType;
- (KalturaFieldType)getTypeOfExtraData;
- (KalturaFieldType)getTypeOfAuthData;
- (void)setSearchSourceFromString:(NSString*)aPropVal;
- (void)setMediaTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaSearchResult : KalturaSearch
@property (nonatomic,copy) NSString* id;
@property (nonatomic,copy) NSString* title;
@property (nonatomic,copy) NSString* thumbUrl;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,copy) NSString* tags;
@property (nonatomic,copy) NSString* url;
@property (nonatomic,copy) NSString* sourceLink;
@property (nonatomic,copy) NSString* credit;
@property (nonatomic,assign) int licenseType;	// enum KalturaLicenseType
@property (nonatomic,copy) NSString* flashPlaybackType;
@property (nonatomic,copy) NSString* fileExt;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfTitle;
- (KalturaFieldType)getTypeOfThumbUrl;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfUrl;
- (KalturaFieldType)getTypeOfSourceLink;
- (KalturaFieldType)getTypeOfCredit;
- (KalturaFieldType)getTypeOfLicenseType;
- (KalturaFieldType)getTypeOfFlashPlaybackType;
- (KalturaFieldType)getTypeOfFileExt;
- (void)setLicenseTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaConversionAttribute : KalturaObjectBase
// The id of the flavor params, set to null for source flavor
@property (nonatomic,assign) int flavorParamsId;
// Attribute name
@property (nonatomic,copy) NSString* name;
// Attribute value
@property (nonatomic,copy) NSString* value;
- (KalturaFieldType)getTypeOfFlavorParamsId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfValue;
- (void)setFlavorParamsIdFromString:(NSString*)aPropVal;
@end

@interface KalturaMediaListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaMediaEntry elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaMixListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaMixEntry elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

// Client notification object to hold the notification url and the data when sending client side notifications
@interface KalturaClientNotification : KalturaObjectBase
// The URL where the notification should be sent to
@property (nonatomic,copy) NSString* url;
// The serialized notification data to send
@property (nonatomic,copy) NSString* data;
- (KalturaFieldType)getTypeOfUrl;
- (KalturaFieldType)getTypeOfData;
@end

// A key value pair representation to return an array of key-value pairs (associative array)
@interface KalturaKeyValue : KalturaObjectBase
@property (nonatomic,copy) NSString* key;
@property (nonatomic,copy) NSString* value;
- (KalturaFieldType)getTypeOfKey;
- (KalturaFieldType)getTypeOfValue;
@end

@interface KalturaPartner : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,copy) NSString* name;
@property (nonatomic,copy) NSString* website;
@property (nonatomic,copy) NSString* notificationUrl;
@property (nonatomic,assign) int appearInSearch;
@property (nonatomic,assign,readonly) int createdAt;
// deprecated - lastName and firstName replaces this field
@property (nonatomic,copy) NSString* adminName;
@property (nonatomic,copy) NSString* adminEmail;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,assign) int commercialUse;	// enum KalturaCommercialUseType
@property (nonatomic,copy) NSString* landingPage;
@property (nonatomic,copy) NSString* userLandingPage;
@property (nonatomic,copy) NSString* contentCategories;
@property (nonatomic,assign) int type;	// enum KalturaPartnerType
@property (nonatomic,copy) NSString* phone;
@property (nonatomic,copy) NSString* describeYourself;
@property (nonatomic,assign) BOOL adultContent;
@property (nonatomic,copy) NSString* defConversionProfileType;
@property (nonatomic,assign) int notify;
@property (nonatomic,assign,readonly) int status;	// enum KalturaPartnerStatus
@property (nonatomic,assign) int allowQuickEdit;
@property (nonatomic,assign) int mergeEntryLists;
@property (nonatomic,copy) NSString* notificationsConfig;
@property (nonatomic,assign) int maxUploadSize;
@property (nonatomic,assign,readonly) int partnerPackage;
@property (nonatomic,copy,readonly) NSString* secret;
@property (nonatomic,copy,readonly) NSString* adminSecret;
@property (nonatomic,copy,readonly) NSString* cmsPassword;
@property (nonatomic,assign) int allowMultiNotification;
@property (nonatomic,assign,readonly) int adminLoginUsersQuota;
@property (nonatomic,copy) NSString* adminUserId;
// firstName and lastName replace the old (deprecated) adminName
@property (nonatomic,copy) NSString* firstName;
// lastName and firstName replace the old (deprecated) adminName
@property (nonatomic,copy) NSString* lastName;
// country code (2char) - this field is optional
@property (nonatomic,copy) NSString* country;
// state code (2char) - this field is optional
@property (nonatomic,copy) NSString* state;
@property (nonatomic,retain) NSMutableArray* additionalParams;	// of KalturaKeyValue elements, insertonly
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfWebsite;
- (KalturaFieldType)getTypeOfNotificationUrl;
- (KalturaFieldType)getTypeOfAppearInSearch;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfAdminName;
- (KalturaFieldType)getTypeOfAdminEmail;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfCommercialUse;
- (KalturaFieldType)getTypeOfLandingPage;
- (KalturaFieldType)getTypeOfUserLandingPage;
- (KalturaFieldType)getTypeOfContentCategories;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfPhone;
- (KalturaFieldType)getTypeOfDescribeYourself;
- (KalturaFieldType)getTypeOfAdultContent;
- (KalturaFieldType)getTypeOfDefConversionProfileType;
- (KalturaFieldType)getTypeOfNotify;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfAllowQuickEdit;
- (KalturaFieldType)getTypeOfMergeEntryLists;
- (KalturaFieldType)getTypeOfNotificationsConfig;
- (KalturaFieldType)getTypeOfMaxUploadSize;
- (KalturaFieldType)getTypeOfPartnerPackage;
- (KalturaFieldType)getTypeOfSecret;
- (KalturaFieldType)getTypeOfAdminSecret;
- (KalturaFieldType)getTypeOfCmsPassword;
- (KalturaFieldType)getTypeOfAllowMultiNotification;
- (KalturaFieldType)getTypeOfAdminLoginUsersQuota;
- (KalturaFieldType)getTypeOfAdminUserId;
- (KalturaFieldType)getTypeOfFirstName;
- (KalturaFieldType)getTypeOfLastName;
- (KalturaFieldType)getTypeOfCountry;
- (KalturaFieldType)getTypeOfState;
- (KalturaFieldType)getTypeOfAdditionalParams;
- (NSString*)getObjectTypeOfAdditionalParams;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setAppearInSearchFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setCommercialUseFromString:(NSString*)aPropVal;
- (void)setTypeFromString:(NSString*)aPropVal;
- (void)setAdultContentFromString:(NSString*)aPropVal;
- (void)setNotifyFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setAllowQuickEditFromString:(NSString*)aPropVal;
- (void)setMergeEntryListsFromString:(NSString*)aPropVal;
- (void)setMaxUploadSizeFromString:(NSString*)aPropVal;
- (void)setPartnerPackageFromString:(NSString*)aPropVal;
- (void)setAllowMultiNotificationFromString:(NSString*)aPropVal;
- (void)setAdminLoginUsersQuotaFromString:(NSString*)aPropVal;
@end

@interface KalturaPartnerUsage : KalturaObjectBase
// Partner total hosting in GB on the disk
@property (nonatomic,assign,readonly) double hostingGB;
// percent of usage out of partner's package. if usageGB is 5 and package is 10GB, this value will be 50
@property (nonatomic,assign,readonly) double Percent;
// package total BW - actually this is usage, which represents BW+storage
@property (nonatomic,assign,readonly) int packageBW;
// total usage in GB - including bandwidth and storage
@property (nonatomic,assign,readonly) int usageGB;
// date when partner reached the limit of his package (timestamp)
@property (nonatomic,assign,readonly) int reachedLimitDate;
// a semi-colon separated list of comma-separated key-values to represent a usage graph.
// keys could be 1-12 for a year view (1,1.2;2,1.1;3,0.9;...;12,1.4;)
// keys could be 1-[28,29,30,31] depending on the requested month, for a daily view in a given month (1,0.4;2,0.2;...;31,0.1;)
@property (nonatomic,copy,readonly) NSString* usageGraph;
- (KalturaFieldType)getTypeOfHostingGB;
- (KalturaFieldType)getTypeOfPercent;
- (KalturaFieldType)getTypeOfPackageBW;
- (KalturaFieldType)getTypeOfUsageGB;
- (KalturaFieldType)getTypeOfReachedLimitDate;
- (KalturaFieldType)getTypeOfUsageGraph;
- (void)setHostingGBFromString:(NSString*)aPropVal;
- (void)setPercentFromString:(NSString*)aPropVal;
- (void)setPackageBWFromString:(NSString*)aPropVal;
- (void)setUsageGBFromString:(NSString*)aPropVal;
- (void)setReachedLimitDateFromString:(NSString*)aPropVal;
@end

@interface KalturaPartnerListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaPartner elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaPermissionItem : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,copy,readonly) NSString* type;	// enum KalturaPermissionItemType
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* tags;
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
@end

@interface KalturaApiActionPermissionItem : KalturaPermissionItem
@property (nonatomic,copy) NSString* service;
@property (nonatomic,copy) NSString* action;
- (KalturaFieldType)getTypeOfService;
- (KalturaFieldType)getTypeOfAction;
@end

@interface KalturaApiParameterPermissionItem : KalturaPermissionItem
@property (nonatomic,copy) NSString* object;
@property (nonatomic,copy) NSString* parameter;
@property (nonatomic,copy) NSString* action;	// enum KalturaApiParameterPermissionItemAction
- (KalturaFieldType)getTypeOfObject;
- (KalturaFieldType)getTypeOfParameter;
- (KalturaFieldType)getTypeOfAction;
@end

@interface KalturaPermissionItemListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaPermissionItem elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaPermission : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int type;	// enum KalturaPermissionType
@property (nonatomic,copy) NSString* name;
@property (nonatomic,copy) NSString* friendlyName;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,assign) int status;	// enum KalturaPermissionStatus
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* dependsOnPermissionNames;
@property (nonatomic,copy) NSString* tags;
@property (nonatomic,copy) NSString* permissionItemsIds;
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,copy) NSString* partnerGroup;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfFriendlyName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfDependsOnPermissionNames;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfPermissionItemsIds;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfPartnerGroup;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setTypeFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
@end

@interface KalturaPermissionListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaPermission elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaPlaylistListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaPlaylist elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaReportInputFilter : KalturaObjectBase
@property (nonatomic,assign) int fromDate;
@property (nonatomic,assign) int toDate;
@property (nonatomic,copy) NSString* keywords;
@property (nonatomic,assign) BOOL searchInTags;
@property (nonatomic,assign) BOOL searchInAdminTags;
@property (nonatomic,copy) NSString* categories;
// time zone offset in minutes
@property (nonatomic,assign) int timeZoneOffset;
- (KalturaFieldType)getTypeOfFromDate;
- (KalturaFieldType)getTypeOfToDate;
- (KalturaFieldType)getTypeOfKeywords;
- (KalturaFieldType)getTypeOfSearchInTags;
- (KalturaFieldType)getTypeOfSearchInAdminTags;
- (KalturaFieldType)getTypeOfCategories;
- (KalturaFieldType)getTypeOfTimeZoneOffset;
- (void)setFromDateFromString:(NSString*)aPropVal;
- (void)setToDateFromString:(NSString*)aPropVal;
- (void)setSearchInTagsFromString:(NSString*)aPropVal;
- (void)setSearchInAdminTagsFromString:(NSString*)aPropVal;
- (void)setTimeZoneOffsetFromString:(NSString*)aPropVal;
@end

@interface KalturaReportGraph : KalturaObjectBase
@property (nonatomic,copy) NSString* id;
@property (nonatomic,copy) NSString* data;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfData;
@end

@interface KalturaReportTotal : KalturaObjectBase
@property (nonatomic,copy) NSString* header;
@property (nonatomic,copy) NSString* data;
- (KalturaFieldType)getTypeOfHeader;
- (KalturaFieldType)getTypeOfData;
@end

@interface KalturaReportTable : KalturaObjectBase
@property (nonatomic,copy,readonly) NSString* header;
@property (nonatomic,copy,readonly) NSString* data;
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfHeader;
- (KalturaFieldType)getTypeOfData;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaReportResponse : KalturaObjectBase
@property (nonatomic,copy) NSString* columns;
@property (nonatomic,retain) NSMutableArray* results;	// of KalturaString elements
- (KalturaFieldType)getTypeOfColumns;
- (KalturaFieldType)getTypeOfResults;
- (NSString*)getObjectTypeOfResults;
@end

@interface KalturaSearchResultResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaSearchResult elements
@property (nonatomic,assign,readonly) BOOL needMediaInfo;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfNeedMediaInfo;
- (void)setNeedMediaInfoFromString:(NSString*)aPropVal;
@end

@interface KalturaSearchAuthData : KalturaObjectBase
// The authentication data that further should be used for search
@property (nonatomic,copy) NSString* authData;
// Login URL when user need to sign-in and authorize the search
@property (nonatomic,copy) NSString* loginUrl;
// Information when there was an error
@property (nonatomic,copy) NSString* message;
- (KalturaFieldType)getTypeOfAuthData;
- (KalturaFieldType)getTypeOfLoginUrl;
- (KalturaFieldType)getTypeOfMessage;
@end

@interface KalturaStartWidgetSessionResponse : KalturaObjectBase
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy,readonly) NSString* ks;
@property (nonatomic,copy,readonly) NSString* userId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfKs;
- (KalturaFieldType)getTypeOfUserId;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
@end

// Will hold data from the Kaltura UI components to be passed on to the reports and analytics system
@interface KalturaStatsEvent : KalturaObjectBase
@property (nonatomic,copy) NSString* clientVer;
@property (nonatomic,assign) int eventType;	// enum KalturaStatsEventType
// the client's timestamp of this event
@property (nonatomic,assign) double eventTimestamp;
// a unique string generated by the client that will represent the client-side session: the primary component will pass it on to other components that sprout from it
@property (nonatomic,copy) NSString* sessionId;
@property (nonatomic,assign) int partnerId;
@property (nonatomic,copy) NSString* entryId;
// the UV cookie - creates in the operational system and should be passed on ofr every event
@property (nonatomic,copy) NSString* uniqueViewer;
@property (nonatomic,copy) NSString* widgetId;
@property (nonatomic,assign) int uiconfId;
// the partner's user id
@property (nonatomic,copy) NSString* userId;
// the timestamp along the video when the event happend
@property (nonatomic,assign) int currentPoint;
// the duration of the video in milliseconds - will make it much faster than quering the db for each entry
@property (nonatomic,assign) int duration;
// will be retrieved from the request of the user
@property (nonatomic,copy,readonly) NSString* userIp;
// the time in milliseconds the event took
@property (nonatomic,assign) int processDuration;
// the id of the GUI control - will be used in the future to better understand what the user clicked
@property (nonatomic,copy) NSString* controlId;
// true if the user ever used seek in this session
@property (nonatomic,assign) BOOL seek;
// timestamp of the new point on the timeline of the video after the user seeks
@property (nonatomic,assign) int newPoint;
// the referrer of the client
@property (nonatomic,copy) NSString* referrer;
// will indicate if the event is thrown for the first video in the session
@property (nonatomic,assign) BOOL isFirstInSession;
- (KalturaFieldType)getTypeOfClientVer;
- (KalturaFieldType)getTypeOfEventType;
- (KalturaFieldType)getTypeOfEventTimestamp;
- (KalturaFieldType)getTypeOfSessionId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfEntryId;
- (KalturaFieldType)getTypeOfUniqueViewer;
- (KalturaFieldType)getTypeOfWidgetId;
- (KalturaFieldType)getTypeOfUiconfId;
- (KalturaFieldType)getTypeOfUserId;
- (KalturaFieldType)getTypeOfCurrentPoint;
- (KalturaFieldType)getTypeOfDuration;
- (KalturaFieldType)getTypeOfUserIp;
- (KalturaFieldType)getTypeOfProcessDuration;
- (KalturaFieldType)getTypeOfControlId;
- (KalturaFieldType)getTypeOfSeek;
- (KalturaFieldType)getTypeOfNewPoint;
- (KalturaFieldType)getTypeOfReferrer;
- (KalturaFieldType)getTypeOfIsFirstInSession;
- (void)setEventTypeFromString:(NSString*)aPropVal;
- (void)setEventTimestampFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setUiconfIdFromString:(NSString*)aPropVal;
- (void)setCurrentPointFromString:(NSString*)aPropVal;
- (void)setDurationFromString:(NSString*)aPropVal;
- (void)setProcessDurationFromString:(NSString*)aPropVal;
- (void)setSeekFromString:(NSString*)aPropVal;
- (void)setNewPointFromString:(NSString*)aPropVal;
- (void)setIsFirstInSessionFromString:(NSString*)aPropVal;
@end

// Will hold data from the Kaltura UI components to be passed on to the reports and analytics system
@interface KalturaStatsKmcEvent : KalturaObjectBase
@property (nonatomic,copy) NSString* clientVer;
@property (nonatomic,copy) NSString* kmcEventActionPath;
@property (nonatomic,assign) int kmcEventType;	// enum KalturaStatsKmcEventType
// the client's timestamp of this event
@property (nonatomic,assign) double eventTimestamp;
// a unique string generated by the client that will represent the client-side session: the primary component will pass it on to other components that sprout from it
@property (nonatomic,copy) NSString* sessionId;
@property (nonatomic,assign) int partnerId;
@property (nonatomic,copy) NSString* entryId;
@property (nonatomic,copy) NSString* widgetId;
@property (nonatomic,assign) int uiconfId;
// the partner's user id
@property (nonatomic,copy) NSString* userId;
// will be retrieved from the request of the user
@property (nonatomic,copy,readonly) NSString* userIp;
- (KalturaFieldType)getTypeOfClientVer;
- (KalturaFieldType)getTypeOfKmcEventActionPath;
- (KalturaFieldType)getTypeOfKmcEventType;
- (KalturaFieldType)getTypeOfEventTimestamp;
- (KalturaFieldType)getTypeOfSessionId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfEntryId;
- (KalturaFieldType)getTypeOfWidgetId;
- (KalturaFieldType)getTypeOfUiconfId;
- (KalturaFieldType)getTypeOfUserId;
- (KalturaFieldType)getTypeOfUserIp;
- (void)setKmcEventTypeFromString:(NSString*)aPropVal;
- (void)setEventTimestampFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setUiconfIdFromString:(NSString*)aPropVal;
@end

@interface KalturaCEError : KalturaObjectBase
@property (nonatomic,copy,readonly) NSString* id;
@property (nonatomic,assign) int partnerId;
@property (nonatomic,copy) NSString* browser;
@property (nonatomic,copy) NSString* serverIp;
@property (nonatomic,copy) NSString* serverOs;
@property (nonatomic,copy) NSString* phpVersion;
@property (nonatomic,copy) NSString* ceAdminEmail;
@property (nonatomic,copy) NSString* type;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,copy) NSString* data;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfBrowser;
- (KalturaFieldType)getTypeOfServerIp;
- (KalturaFieldType)getTypeOfServerOs;
- (KalturaFieldType)getTypeOfPhpVersion;
- (KalturaFieldType)getTypeOfCeAdminEmail;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfData;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
@end

@interface KalturaStorageProfile : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* name;
@property (nonatomic,copy) NSString* systemName;
@property (nonatomic,copy) NSString* desciption;
@property (nonatomic,assign) int status;	// enum KalturaStorageProfileStatus
@property (nonatomic,assign) int protocol;	// enum KalturaStorageProfileProtocol
@property (nonatomic,copy) NSString* storageUrl;
@property (nonatomic,copy) NSString* storageBaseDir;
@property (nonatomic,copy) NSString* storageUsername;
@property (nonatomic,copy) NSString* storagePassword;
@property (nonatomic,assign) BOOL storageFtpPassiveMode;
@property (nonatomic,copy) NSString* deliveryHttpBaseUrl;
@property (nonatomic,copy) NSString* deliveryRmpBaseUrl;
@property (nonatomic,copy) NSString* deliveryIisBaseUrl;
@property (nonatomic,assign) int minFileSize;
@property (nonatomic,assign) int maxFileSize;
@property (nonatomic,copy) NSString* flavorParamsIds;
@property (nonatomic,assign) int maxConcurrentConnections;
@property (nonatomic,copy) NSString* pathManagerClass;
@property (nonatomic,retain) NSMutableArray* pathManagerParams;	// of KalturaKeyValue elements
@property (nonatomic,copy) NSString* urlManagerClass;
@property (nonatomic,retain) NSMutableArray* urlManagerParams;	// of KalturaKeyValue elements
// No need to create enum for temp field
@property (nonatomic,assign) int trigger;
// Delivery Priority
@property (nonatomic,assign) int deliveryPriority;
@property (nonatomic,assign) int deliveryStatus;	// enum KalturaStorageProfileDeliveryStatus
@property (nonatomic,copy) NSString* rtmpPrefix;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfSystemName;
- (KalturaFieldType)getTypeOfDesciption;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfProtocol;
- (KalturaFieldType)getTypeOfStorageUrl;
- (KalturaFieldType)getTypeOfStorageBaseDir;
- (KalturaFieldType)getTypeOfStorageUsername;
- (KalturaFieldType)getTypeOfStoragePassword;
- (KalturaFieldType)getTypeOfStorageFtpPassiveMode;
- (KalturaFieldType)getTypeOfDeliveryHttpBaseUrl;
- (KalturaFieldType)getTypeOfDeliveryRmpBaseUrl;
- (KalturaFieldType)getTypeOfDeliveryIisBaseUrl;
- (KalturaFieldType)getTypeOfMinFileSize;
- (KalturaFieldType)getTypeOfMaxFileSize;
- (KalturaFieldType)getTypeOfFlavorParamsIds;
- (KalturaFieldType)getTypeOfMaxConcurrentConnections;
- (KalturaFieldType)getTypeOfPathManagerClass;
- (KalturaFieldType)getTypeOfPathManagerParams;
- (NSString*)getObjectTypeOfPathManagerParams;
- (KalturaFieldType)getTypeOfUrlManagerClass;
- (KalturaFieldType)getTypeOfUrlManagerParams;
- (NSString*)getObjectTypeOfUrlManagerParams;
- (KalturaFieldType)getTypeOfTrigger;
- (KalturaFieldType)getTypeOfDeliveryPriority;
- (KalturaFieldType)getTypeOfDeliveryStatus;
- (KalturaFieldType)getTypeOfRtmpPrefix;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setProtocolFromString:(NSString*)aPropVal;
- (void)setStorageFtpPassiveModeFromString:(NSString*)aPropVal;
- (void)setMinFileSizeFromString:(NSString*)aPropVal;
- (void)setMaxFileSizeFromString:(NSString*)aPropVal;
- (void)setMaxConcurrentConnectionsFromString:(NSString*)aPropVal;
- (void)setTriggerFromString:(NSString*)aPropVal;
- (void)setDeliveryPriorityFromString:(NSString*)aPropVal;
- (void)setDeliveryStatusFromString:(NSString*)aPropVal;
@end

@interface KalturaStorageProfileListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaStorageProfile elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaBaseSyndicationFeed : KalturaObjectBase
@property (nonatomic,copy,readonly) NSString* id;
@property (nonatomic,copy,readonly) NSString* feedUrl;
@property (nonatomic,assign,readonly) int partnerId;
// link a playlist that will set what content the feed will include
// if empty, all content will be included in feed
@property (nonatomic,copy) NSString* playlistId;
// feed name
@property (nonatomic,copy) NSString* name;
// feed status
@property (nonatomic,assign,readonly) int status;	// enum KalturaSyndicationFeedStatus
// feed type
@property (nonatomic,assign) int type;	// enum KalturaSyndicationFeedType, insertonly
// Base URL for each video, on the partners site
// This is required by all syndication types.
@property (nonatomic,copy) NSString* landingPage;
// Creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// allow_embed tells google OR yahoo weather to allow embedding the video on google OR yahoo video results
// or just to provide a link to the landing page.
// it is applied on the video-player_loc property in the XML (google)
// and addes media-player tag (yahoo)
@property (nonatomic,assign) BOOL allowEmbed;
// Select a uiconf ID as player skin to include in the kwidget url
@property (nonatomic,assign) int playerUiconfId;
@property (nonatomic,assign) int flavorParamId;
@property (nonatomic,assign) BOOL transcodeExistingContent;
@property (nonatomic,assign) BOOL addToDefaultConversionProfile;
@property (nonatomic,copy) NSString* categories;
@property (nonatomic,assign) int storageId;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfFeedUrl;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfPlaylistId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfLandingPage;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfAllowEmbed;
- (KalturaFieldType)getTypeOfPlayerUiconfId;
- (KalturaFieldType)getTypeOfFlavorParamId;
- (KalturaFieldType)getTypeOfTranscodeExistingContent;
- (KalturaFieldType)getTypeOfAddToDefaultConversionProfile;
- (KalturaFieldType)getTypeOfCategories;
- (KalturaFieldType)getTypeOfStorageId;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setTypeFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setAllowEmbedFromString:(NSString*)aPropVal;
- (void)setPlayerUiconfIdFromString:(NSString*)aPropVal;
- (void)setFlavorParamIdFromString:(NSString*)aPropVal;
- (void)setTranscodeExistingContentFromString:(NSString*)aPropVal;
- (void)setAddToDefaultConversionProfileFromString:(NSString*)aPropVal;
- (void)setStorageIdFromString:(NSString*)aPropVal;
@end

@interface KalturaGenericSyndicationFeed : KalturaBaseSyndicationFeed
// feed description
@property (nonatomic,copy) NSString* feedDescription;
// feed landing page (i.e publisher website)
@property (nonatomic,copy) NSString* feedLandingPage;
- (KalturaFieldType)getTypeOfFeedDescription;
- (KalturaFieldType)getTypeOfFeedLandingPage;
@end

@interface KalturaGenericXsltSyndicationFeed : KalturaGenericSyndicationFeed
@property (nonatomic,copy) NSString* xslt;
// This parameter determines which custom metadata fields of type related-entry should be
// expanded to contain the kaltura MRSS feed of the related entry. Related-entry fields not
// included in this list will contain only the related entry id.
// This property contains a list xPaths in the Kaltura MRSS.
@property (nonatomic,retain) NSMutableArray* itemXpathsToExtend;	// of KalturaString elements
- (KalturaFieldType)getTypeOfXslt;
- (KalturaFieldType)getTypeOfItemXpathsToExtend;
- (NSString*)getObjectTypeOfItemXpathsToExtend;
@end

@interface KalturaGoogleVideoSyndicationFeed : KalturaBaseSyndicationFeed
@property (nonatomic,copy) NSString* adultContent;	// enum KalturaGoogleSyndicationFeedAdultValues
- (KalturaFieldType)getTypeOfAdultContent;
@end

@interface KalturaITunesSyndicationFeed : KalturaBaseSyndicationFeed
// feed description
@property (nonatomic,copy) NSString* feedDescription;
// feed language
@property (nonatomic,copy) NSString* language;
// feed landing page (i.e publisher website)
@property (nonatomic,copy) NSString* feedLandingPage;
// author/publisher name
@property (nonatomic,copy) NSString* ownerName;
// publisher email
@property (nonatomic,copy) NSString* ownerEmail;
// podcast thumbnail
@property (nonatomic,copy) NSString* feedImageUrl;
@property (nonatomic,copy,readonly) NSString* category;	// enum KalturaITunesSyndicationFeedCategories
@property (nonatomic,copy) NSString* adultContent;	// enum KalturaITunesSyndicationFeedAdultValues
@property (nonatomic,copy) NSString* feedAuthor;
- (KalturaFieldType)getTypeOfFeedDescription;
- (KalturaFieldType)getTypeOfLanguage;
- (KalturaFieldType)getTypeOfFeedLandingPage;
- (KalturaFieldType)getTypeOfOwnerName;
- (KalturaFieldType)getTypeOfOwnerEmail;
- (KalturaFieldType)getTypeOfFeedImageUrl;
- (KalturaFieldType)getTypeOfCategory;
- (KalturaFieldType)getTypeOfAdultContent;
- (KalturaFieldType)getTypeOfFeedAuthor;
@end

@interface KalturaTubeMogulSyndicationFeed : KalturaBaseSyndicationFeed
@property (nonatomic,copy,readonly) NSString* category;	// enum KalturaTubeMogulSyndicationFeedCategories
- (KalturaFieldType)getTypeOfCategory;
@end

@interface KalturaYahooSyndicationFeed : KalturaBaseSyndicationFeed
@property (nonatomic,copy,readonly) NSString* category;	// enum KalturaYahooSyndicationFeedCategories
@property (nonatomic,copy) NSString* adultContent;	// enum KalturaYahooSyndicationFeedAdultValues
// feed description
@property (nonatomic,copy) NSString* feedDescription;
// feed landing page (i.e publisher website)
@property (nonatomic,copy) NSString* feedLandingPage;
- (KalturaFieldType)getTypeOfCategory;
- (KalturaFieldType)getTypeOfAdultContent;
- (KalturaFieldType)getTypeOfFeedDescription;
- (KalturaFieldType)getTypeOfFeedLandingPage;
@end

@interface KalturaBaseSyndicationFeedListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaBaseSyndicationFeed elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaSyndicationFeedEntryCount : KalturaObjectBase
// the total count of entries that should appear in the feed without flavor filtering
@property (nonatomic,assign) int totalEntryCount;
// count of entries that will appear in the feed (including all relevant filters)
@property (nonatomic,assign) int actualEntryCount;
// count of entries that requires transcoding in order to be included in feed
@property (nonatomic,assign) int requireTranscodingCount;
- (KalturaFieldType)getTypeOfTotalEntryCount;
- (KalturaFieldType)getTypeOfActualEntryCount;
- (KalturaFieldType)getTypeOfRequireTranscodingCount;
- (void)setTotalEntryCountFromString:(NSString*)aPropVal;
- (void)setActualEntryCountFromString:(NSString*)aPropVal;
- (void)setRequireTranscodingCountFromString:(NSString*)aPropVal;
@end

@interface KalturaThumbAssetListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaThumbAsset elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaThumbParamsListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaThumbParams elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaUiConf : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
// Name of the uiConf, this is not a primary key
@property (nonatomic,copy) NSString* name;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,assign) int objType;	// enum KalturaUiConfObjType
@property (nonatomic,copy,readonly) NSString* objTypeAsString;
@property (nonatomic,assign) int width;
@property (nonatomic,assign) int height;
@property (nonatomic,copy) NSString* htmlParams;
@property (nonatomic,copy) NSString* swfUrl;
@property (nonatomic,copy,readonly) NSString* confFilePath;
@property (nonatomic,copy) NSString* confFile;
@property (nonatomic,copy) NSString* confFileFeatures;
@property (nonatomic,copy) NSString* confVars;
@property (nonatomic,assign) BOOL useCdn;
@property (nonatomic,copy) NSString* tags;
@property (nonatomic,copy) NSString* swfUrlVersion;
// Entry creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Entry creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
@property (nonatomic,assign) int creationMode;	// enum KalturaUiConfCreationMode
@property (nonatomic,copy) NSString* html5Url;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfObjType;
- (KalturaFieldType)getTypeOfObjTypeAsString;
- (KalturaFieldType)getTypeOfWidth;
- (KalturaFieldType)getTypeOfHeight;
- (KalturaFieldType)getTypeOfHtmlParams;
- (KalturaFieldType)getTypeOfSwfUrl;
- (KalturaFieldType)getTypeOfConfFilePath;
- (KalturaFieldType)getTypeOfConfFile;
- (KalturaFieldType)getTypeOfConfFileFeatures;
- (KalturaFieldType)getTypeOfConfVars;
- (KalturaFieldType)getTypeOfUseCdn;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfSwfUrlVersion;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfCreationMode;
- (KalturaFieldType)getTypeOfHtml5Url;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setObjTypeFromString:(NSString*)aPropVal;
- (void)setWidthFromString:(NSString*)aPropVal;
- (void)setHeightFromString:(NSString*)aPropVal;
- (void)setUseCdnFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
- (void)setCreationModeFromString:(NSString*)aPropVal;
@end

@interface KalturaUiConfListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaUiConf elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

// Info about uiconf type
@interface KalturaUiConfTypeInfo : KalturaObjectBase
// UiConf Type
@property (nonatomic,assign) int type;	// enum KalturaUiConfObjType
// Available versions
@property (nonatomic,retain) NSMutableArray* versions;	// of KalturaString elements
// The direcotry this type is saved at
@property (nonatomic,copy) NSString* directory;
// Filename for this UiConf type
@property (nonatomic,copy) NSString* filename;
- (KalturaFieldType)getTypeOfType;
- (KalturaFieldType)getTypeOfVersions;
- (NSString*)getObjectTypeOfVersions;
- (KalturaFieldType)getTypeOfDirectory;
- (KalturaFieldType)getTypeOfFilename;
- (void)setTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaUploadResponse : KalturaObjectBase
@property (nonatomic,copy) NSString* uploadTokenId;
@property (nonatomic,assign) int fileSize;
@property (nonatomic,assign) int errorCode;	// enum KalturaUploadErrorCode
@property (nonatomic,copy) NSString* errorDescription;
- (KalturaFieldType)getTypeOfUploadTokenId;
- (KalturaFieldType)getTypeOfFileSize;
- (KalturaFieldType)getTypeOfErrorCode;
- (KalturaFieldType)getTypeOfErrorDescription;
- (void)setFileSizeFromString:(NSString*)aPropVal;
- (void)setErrorCodeFromString:(NSString*)aPropVal;
@end

@interface KalturaUploadToken : KalturaObjectBase
// Upload token unique ID
@property (nonatomic,copy,readonly) NSString* id;
// Partner ID of the upload token
@property (nonatomic,assign,readonly) int partnerId;
// User id for the upload token
@property (nonatomic,copy,readonly) NSString* userId;
// Status of the upload token
@property (nonatomic,assign,readonly) int status;	// enum KalturaUploadTokenStatus
// Name of the file for the upload token, can be empty when the upload token is created and will be updated internally after the file is uploaded
@property (nonatomic,copy) NSString* fileName;	// insertonly
// File size in bytes, can be empty when the upload token is created and will be updated internally after the file is uploaded
@property (nonatomic,assign) double fileSize;	// insertonly
// Uploaded file size in bytes, can be used to identify how many bytes were uploaded before resuming
@property (nonatomic,assign,readonly) double uploadedFileSize;
// Creation date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int createdAt;
// Last update date as Unix timestamp (In seconds)
@property (nonatomic,assign,readonly) int updatedAt;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfUserId;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfFileName;
- (KalturaFieldType)getTypeOfFileSize;
- (KalturaFieldType)getTypeOfUploadedFileSize;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setFileSizeFromString:(NSString*)aPropVal;
- (void)setUploadedFileSizeFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
@end

@interface KalturaUploadTokenListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaUploadToken elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaUserRole : KalturaObjectBase
@property (nonatomic,assign,readonly) int id;
@property (nonatomic,copy) NSString* name;
@property (nonatomic,copy) NSString* description;
@property (nonatomic,assign) int status;	// enum KalturaUserRoleStatus
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* permissionNames;
@property (nonatomic,copy) NSString* tags;
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfName;
- (KalturaFieldType)getTypeOfDescription;
- (KalturaFieldType)getTypeOfStatus;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfPermissionNames;
- (KalturaFieldType)getTypeOfTags;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (void)setIdFromString:(NSString*)aPropVal;
- (void)setStatusFromString:(NSString*)aPropVal;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
@end

@interface KalturaUserRoleListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaUserRole elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaUserListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaUser elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

@interface KalturaWidget : KalturaObjectBase
@property (nonatomic,copy,readonly) NSString* id;
@property (nonatomic,copy) NSString* sourceWidgetId;
@property (nonatomic,copy,readonly) NSString* rootWidgetId;
@property (nonatomic,assign,readonly) int partnerId;
@property (nonatomic,copy) NSString* entryId;
@property (nonatomic,assign) int uiConfId;
@property (nonatomic,assign) int securityType;	// enum KalturaWidgetSecurityType
@property (nonatomic,assign) int securityPolicy;
@property (nonatomic,assign,readonly) int createdAt;
@property (nonatomic,assign,readonly) int updatedAt;
// Can be used to store various partner related data as a string
@property (nonatomic,copy) NSString* partnerData;
@property (nonatomic,copy,readonly) NSString* widgetHTML;
- (KalturaFieldType)getTypeOfId;
- (KalturaFieldType)getTypeOfSourceWidgetId;
- (KalturaFieldType)getTypeOfRootWidgetId;
- (KalturaFieldType)getTypeOfPartnerId;
- (KalturaFieldType)getTypeOfEntryId;
- (KalturaFieldType)getTypeOfUiConfId;
- (KalturaFieldType)getTypeOfSecurityType;
- (KalturaFieldType)getTypeOfSecurityPolicy;
- (KalturaFieldType)getTypeOfCreatedAt;
- (KalturaFieldType)getTypeOfUpdatedAt;
- (KalturaFieldType)getTypeOfPartnerData;
- (KalturaFieldType)getTypeOfWidgetHTML;
- (void)setPartnerIdFromString:(NSString*)aPropVal;
- (void)setUiConfIdFromString:(NSString*)aPropVal;
- (void)setSecurityTypeFromString:(NSString*)aPropVal;
- (void)setSecurityPolicyFromString:(NSString*)aPropVal;
- (void)setCreatedAtFromString:(NSString*)aPropVal;
- (void)setUpdatedAtFromString:(NSString*)aPropVal;
@end

@interface KalturaWidgetListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaWidget elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

///////////////////////// services /////////////////////////
// Manage access control profiles
@interface KalturaAccessControlProfileService : KalturaServiceBase
// Add new access control profile
- (KalturaAccessControlProfile*)addWithAccessControlProfile:(KalturaAccessControlProfile*)aAccessControlProfile;
// Get access control profile by id
- (KalturaAccessControlProfile*)getWithId:(int)aId;
// Update access control profile by id
- (KalturaAccessControlProfile*)updateWithId:(int)aId withAccessControlProfile:(KalturaAccessControlProfile*)aAccessControlProfile;
// Delete access control profile by id
- (void)deleteWithId:(int)aId;
// List access control profiles by filter and pager
- (KalturaAccessControlProfileListResponse*)listWithFilter:(KalturaAccessControlProfileFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaAccessControlProfileListResponse*)listWithFilter:(KalturaAccessControlProfileFilter*)aFilter;
- (KalturaAccessControlProfileListResponse*)list;
@end

// Add & Manage Access Controls
// DEPRECATED - use accessControlProfile service instead
@interface KalturaAccessControlService : KalturaServiceBase
// Add new Access Control Profile
- (KalturaAccessControl*)addWithAccessControl:(KalturaAccessControl*)aAccessControl;
// Get Access Control Profile by id
- (KalturaAccessControl*)getWithId:(int)aId;
// Update Access Control Profile by id
- (KalturaAccessControl*)updateWithId:(int)aId withAccessControl:(KalturaAccessControl*)aAccessControl;
// Delete Access Control Profile by id
- (void)deleteWithId:(int)aId;
// List Access Control Profiles by filter and pager
- (KalturaAccessControlListResponse*)listWithFilter:(KalturaAccessControlFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaAccessControlListResponse*)listWithFilter:(KalturaAccessControlFilter*)aFilter;
- (KalturaAccessControlListResponse*)list;
@end

// Manage details for the administrative user
@interface KalturaAdminUserService : KalturaServiceBase
// Update admin user password and email
// DEPRECATED
- (KalturaAdminUser*)updatePasswordWithEmail:(NSString*)aEmail withPassword:(NSString*)aPassword withNewEmail:(NSString*)aNewEmail withNewPassword:(NSString*)aNewPassword;
- (KalturaAdminUser*)updatePasswordWithEmail:(NSString*)aEmail withPassword:(NSString*)aPassword withNewEmail:(NSString*)aNewEmail;
- (KalturaAdminUser*)updatePasswordWithEmail:(NSString*)aEmail withPassword:(NSString*)aPassword;
// Reset admin user password and send it to the users email address
- (void)resetPasswordWithEmail:(NSString*)aEmail;
// Get an admin session using admin email and password (Used for login to the KMC application)
- (NSString*)loginWithEmail:(NSString*)aEmail withPassword:(NSString*)aPassword withPartnerId:(int)aPartnerId;
- (NSString*)loginWithEmail:(NSString*)aEmail withPassword:(NSString*)aPassword;
// Set initial users password
- (void)setInitialPasswordWithHashKey:(NSString*)aHashKey withNewPassword:(NSString*)aNewPassword;
@end

// Base Entry Service
@interface KalturaBaseEntryService : KalturaServiceBase
// Generic add entry, should be used when the uploaded entry type is not known
- (KalturaBaseEntry*)addWithEntry:(KalturaBaseEntry*)aEntry withType:(NSString*)aType;
- (KalturaBaseEntry*)addWithEntry:(KalturaBaseEntry*)aEntry;
// Generic add entry, should be used when the uploaded entry type is not known
- (KalturaBaseEntry*)addContentWithEntryId:(NSString*)aEntryId withResource:(KalturaResource*)aResource;
// Generic add entry using an uploaded file, should be used when the uploaded entry type is not known
- (KalturaBaseEntry*)addFromUploadedFileWithEntry:(KalturaBaseEntry*)aEntry withUploadTokenId:(NSString*)aUploadTokenId withType:(NSString*)aType;
- (KalturaBaseEntry*)addFromUploadedFileWithEntry:(KalturaBaseEntry*)aEntry withUploadTokenId:(NSString*)aUploadTokenId;
// Get base entry by ID.
- (KalturaBaseEntry*)getWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion;
- (KalturaBaseEntry*)getWithEntryId:(NSString*)aEntryId;
// Get remote storage existing paths for the asset
- (KalturaRemotePathListResponse*)getRemotePathsWithEntryId:(NSString*)aEntryId;
// Update base entry. Only the properties that were set will be updated.
- (KalturaBaseEntry*)updateWithEntryId:(NSString*)aEntryId withBaseEntry:(KalturaBaseEntry*)aBaseEntry;
// Update base entry. Only the properties that were set will be updated.
- (KalturaBaseEntry*)updateContentWithEntryId:(NSString*)aEntryId withResource:(KalturaResource*)aResource withConversionProfileId:(int)aConversionProfileId;
- (KalturaBaseEntry*)updateContentWithEntryId:(NSString*)aEntryId withResource:(KalturaResource*)aResource;
// Get base entry by comma separated entry ids.
- (NSMutableArray*)getByIdsWithEntryIds:(NSString*)aEntryIds;
// Delete an entry.
- (void)deleteWithEntryId:(NSString*)aEntryId;
// List base entries by filter with paging support.
- (KalturaBaseEntryListResponse*)listWithFilter:(KalturaBaseEntryFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaBaseEntryListResponse*)listWithFilter:(KalturaBaseEntryFilter*)aFilter;
- (KalturaBaseEntryListResponse*)list;
// List base entries by filter according to reference id
- (void)listByReferenceIdWithRefId:(NSString*)aRefId withPager:(KalturaFilterPager*)aPager;
- (void)listByReferenceIdWithRefId:(NSString*)aRefId;
// Count base entries by filter.
- (int)countWithFilter:(KalturaBaseEntryFilter*)aFilter;
- (int)count;
// Upload a file to Kaltura, that can be used to create an entry.
// DEPRECATED - use upload.upload or uploadToken.add instead
- (NSString*)uploadWithFileData:(NSString*)aFileData;
// Update entry thumbnail using a raw jpeg file
- (KalturaBaseEntry*)updateThumbnailJpegWithEntryId:(NSString*)aEntryId withFileData:(NSString*)aFileData;
// Update entry thumbnail using url
- (KalturaBaseEntry*)updateThumbnailFromUrlWithEntryId:(NSString*)aEntryId withUrl:(NSString*)aUrl;
// Update entry thumbnail from a different entry by a specified time offset (In seconds)
- (KalturaBaseEntry*)updateThumbnailFromSourceEntryWithEntryId:(NSString*)aEntryId withSourceEntryId:(NSString*)aSourceEntryId withTimeOffset:(int)aTimeOffset;
// Flag inappropriate entry for moderation
- (void)flagWithModerationFlag:(KalturaModerationFlag*)aModerationFlag;
// Reject the entry and mark the pending flags (if any) as moderated (this will make the entry non playable)
- (void)rejectWithEntryId:(NSString*)aEntryId;
// Approve the entry and mark the pending flags (if any) as moderated (this will make the entry playable)
- (void)approveWithEntryId:(NSString*)aEntryId;
// List all pending flags for the entry
- (KalturaModerationFlagListResponse*)listFlagsWithEntryId:(NSString*)aEntryId withPager:(KalturaFilterPager*)aPager;
- (KalturaModerationFlagListResponse*)listFlagsWithEntryId:(NSString*)aEntryId;
// Anonymously rank an entry, no validation is done on duplicate rankings
- (void)anonymousRankWithEntryId:(NSString*)aEntryId withRank:(int)aRank;
- (KalturaEntryContextDataResult*)getContextDataWithEntryId:(NSString*)aEntryId withContextDataParams:(KalturaEntryContextDataParams*)aContextDataParams;
// Action for manually exporting an entry
- (KalturaBaseEntry*)exportWithEntryId:(NSString*)aEntryId withStorageProfileId:(int)aStorageProfileId;
@end

// Bulk upload service is used to upload & manage bulk uploads using CSV files
@interface KalturaBulkUploadService : KalturaServiceBase
// Add new bulk upload batch job
// Conversion profile id can be specified in the API or in the CSV file, the one in the CSV file will be stronger.
// If no conversion profile was specified, partner's default will be used
- (KalturaBulkUpload*)addWithConversionProfileId:(int)aConversionProfileId withCsvFileData:(NSString*)aCsvFileData withBulkUploadType:(NSString*)aBulkUploadType withUploadedBy:(NSString*)aUploadedBy;
- (KalturaBulkUpload*)addWithConversionProfileId:(int)aConversionProfileId withCsvFileData:(NSString*)aCsvFileData withBulkUploadType:(NSString*)aBulkUploadType;
- (KalturaBulkUpload*)addWithConversionProfileId:(int)aConversionProfileId withCsvFileData:(NSString*)aCsvFileData;
// Get bulk upload batch job by id
- (KalturaBulkUpload*)getWithId:(int)aId;
// List bulk upload batch jobs
- (KalturaBulkUploadListResponse*)listWithPager:(KalturaFilterPager*)aPager;
- (KalturaBulkUploadListResponse*)list;
// serve action returan the original file.
- (NSString*)serveWithId:(int)aId;
// serveLog action returan the original file.
- (NSString*)serveLogWithId:(int)aId;
// Aborts the bulk upload and all its child jobs
- (KalturaBulkUpload*)abortWithId:(int)aId;
@end

// Add & Manage Categories
@interface KalturaCategoryService : KalturaServiceBase
// Add new Category
- (KalturaCategory*)addWithCategory:(KalturaCategory*)aCategory;
// Get Category by id
- (KalturaCategory*)getWithId:(int)aId;
// Update Category
- (KalturaCategory*)updateWithId:(int)aId withCategory:(KalturaCategory*)aCategory;
// Delete a Category
- (void)deleteWithId:(int)aId;
// List all categories
- (KalturaCategoryListResponse*)listWithFilter:(KalturaCategoryFilter*)aFilter;
- (KalturaCategoryListResponse*)list;
@end

// Manage the connection between Conversion Profiles and Asset Params
@interface KalturaConversionProfileAssetParamsService : KalturaServiceBase
// Lists asset parmas of conversion profile by ID
- (KalturaConversionProfileAssetParamsListResponse*)listWithFilter:(KalturaConversionProfileAssetParamsFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaConversionProfileAssetParamsListResponse*)listWithFilter:(KalturaConversionProfileAssetParamsFilter*)aFilter;
- (KalturaConversionProfileAssetParamsListResponse*)list;
// Update asset parmas of conversion profile by ID
- (KalturaConversionProfileAssetParams*)updateWithConversionProfileId:(int)aConversionProfileId withAssetParamsId:(int)aAssetParamsId withConversionProfileAssetParams:(KalturaConversionProfileAssetParams*)aConversionProfileAssetParams;
@end

// Add & Manage Conversion Profiles
@interface KalturaConversionProfileService : KalturaServiceBase
// Set Conversion Profile to be the partner default
- (KalturaConversionProfile*)setAsDefaultWithId:(int)aId;
// Get the partner's default conversion profile
- (KalturaConversionProfile*)getDefault;
// Add new Conversion Profile
- (KalturaConversionProfile*)addWithConversionProfile:(KalturaConversionProfile*)aConversionProfile;
// Get Conversion Profile by ID
- (KalturaConversionProfile*)getWithId:(int)aId;
// Update Conversion Profile by ID
- (KalturaConversionProfile*)updateWithId:(int)aId withConversionProfile:(KalturaConversionProfile*)aConversionProfile;
// Delete Conversion Profile by ID
- (void)deleteWithId:(int)aId;
// List Conversion Profiles by filter with paging support
- (KalturaConversionProfileListResponse*)listWithFilter:(KalturaConversionProfileFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaConversionProfileListResponse*)listWithFilter:(KalturaConversionProfileFilter*)aFilter;
- (KalturaConversionProfileListResponse*)list;
@end

// Data service lets you manage data content (textual content)
@interface KalturaDataService : KalturaServiceBase
// Adds a new data entry
- (KalturaDataEntry*)addWithDataEntry:(KalturaDataEntry*)aDataEntry;
// Get data entry by ID.
- (KalturaDataEntry*)getWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion;
- (KalturaDataEntry*)getWithEntryId:(NSString*)aEntryId;
// Update data entry. Only the properties that were set will be updated.
- (KalturaDataEntry*)updateWithEntryId:(NSString*)aEntryId withDocumentEntry:(KalturaDataEntry*)aDocumentEntry;
// Delete a data entry.
- (void)deleteWithEntryId:(NSString*)aEntryId;
// List data entries by filter with paging support.
- (KalturaDataListResponse*)listWithFilter:(KalturaDataEntryFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaDataListResponse*)listWithFilter:(KalturaDataEntryFilter*)aFilter;
- (KalturaDataListResponse*)list;
// serve action returan the file from dataContent field.
- (NSString*)serveWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion withForceProxy:(BOOL)aForceProxy;
- (NSString*)serveWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion;
- (NSString*)serveWithEntryId:(NSString*)aEntryId;
@end

// EmailIngestionProfile service lets you manage email ingestion profile records
@interface KalturaEmailIngestionProfileService : KalturaServiceBase
// EmailIngestionProfile Add action allows you to add a EmailIngestionProfile to Kaltura DB
- (KalturaEmailIngestionProfile*)addWithEmailIP:(KalturaEmailIngestionProfile*)aEmailIP;
// Retrieve a EmailIngestionProfile by email address
- (KalturaEmailIngestionProfile*)getByEmailAddressWithEmailAddress:(NSString*)aEmailAddress;
// Retrieve a EmailIngestionProfile by id
- (KalturaEmailIngestionProfile*)getWithId:(int)aId;
// Update an existing EmailIngestionProfile
- (KalturaEmailIngestionProfile*)updateWithId:(int)aId withEmailIP:(KalturaEmailIngestionProfile*)aEmailIP;
// Delete an existing EmailIngestionProfile
- (void)deleteWithId:(int)aId;
// add KalturaMediaEntry from email ingestion
- (KalturaMediaEntry*)addMediaEntryWithMediaEntry:(KalturaMediaEntry*)aMediaEntry withUploadTokenId:(NSString*)aUploadTokenId withEmailProfId:(int)aEmailProfId withFromAddress:(NSString*)aFromAddress withEmailMsgId:(NSString*)aEmailMsgId;
@end

// Retrieve information and invoke actions on Flavor Asset
@interface KalturaFlavorAssetService : KalturaServiceBase
// Add flavor asset
- (KalturaFlavorAsset*)addWithEntryId:(NSString*)aEntryId withFlavorAsset:(KalturaFlavorAsset*)aFlavorAsset;
// Update flavor asset
- (KalturaFlavorAsset*)updateWithId:(NSString*)aId withFlavorAsset:(KalturaFlavorAsset*)aFlavorAsset;
// Update content of flavor asset
- (KalturaFlavorAsset*)setContentWithId:(NSString*)aId withContentResource:(KalturaContentResource*)aContentResource;
// Get Flavor Asset by ID
- (KalturaFlavorAsset*)getWithId:(NSString*)aId;
// Get Flavor Assets for Entry
// DEPRECATED - Use thumbAsset.list instead
- (NSMutableArray*)getByEntryIdWithEntryId:(NSString*)aEntryId;
// List Flavor Assets by filter and pager
- (KalturaFlavorAssetListResponse*)listWithFilter:(KalturaAssetFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaFlavorAssetListResponse*)listWithFilter:(KalturaAssetFilter*)aFilter;
- (KalturaFlavorAssetListResponse*)list;
// Get web playable Flavor Assets for Entry
- (NSMutableArray*)getWebPlayableByEntryIdWithEntryId:(NSString*)aEntryId;
// Add and convert new Flavor Asset for Entry with specific Flavor Params
- (void)convertWithEntryId:(NSString*)aEntryId withFlavorParamsId:(int)aFlavorParamsId;
// Reconvert Flavor Asset by ID
- (void)reconvertWithId:(NSString*)aId;
// Delete Flavor Asset by ID
- (void)deleteWithId:(NSString*)aId;
// Get download URL for the asset
- (NSString*)getUrlWithId:(NSString*)aId withStorageId:(int)aStorageId;
- (NSString*)getUrlWithId:(NSString*)aId;
// Get remote storage existing paths for the asset
- (KalturaRemotePathListResponse*)getRemotePathsWithId:(NSString*)aId;
// Get download URL for the Flavor Asset
// DEPRECATED - use getUrl instead
- (NSString*)getDownloadUrlWithId:(NSString*)aId withUseCdn:(BOOL)aUseCdn;
- (NSString*)getDownloadUrlWithId:(NSString*)aId;
// Get Flavor Asset with the relevant Flavor Params (Flavor Params can exist without Flavor Asset & vice versa)
- (NSMutableArray*)getFlavorAssetsWithParamsWithEntryId:(NSString*)aEntryId;
// Action for manually exporting an asset
- (KalturaFlavorAsset*)exportWithAssetId:(NSString*)aAssetId withStorageProfileId:(int)aStorageProfileId;
@end

// Add & Manage Flavor Params
@interface KalturaFlavorParamsService : KalturaServiceBase
// Add new Flavor Params
- (KalturaFlavorParams*)addWithFlavorParams:(KalturaFlavorParams*)aFlavorParams;
// Get Flavor Params by ID
- (KalturaFlavorParams*)getWithId:(int)aId;
// Update Flavor Params by ID
- (KalturaFlavorParams*)updateWithId:(int)aId withFlavorParams:(KalturaFlavorParams*)aFlavorParams;
// Delete Flavor Params by ID
- (void)deleteWithId:(int)aId;
// List Flavor Params by filter with paging support (By default - all system default params will be listed too)
- (KalturaFlavorParamsListResponse*)listWithFilter:(KalturaFlavorParamsFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaFlavorParamsListResponse*)listWithFilter:(KalturaFlavorParamsFilter*)aFilter;
- (KalturaFlavorParamsListResponse*)list;
// Get Flavor Params by Conversion Profile ID
- (NSMutableArray*)getByConversionProfileIdWithConversionProfileId:(int)aConversionProfileId;
@end

// Live Stream service lets you manage live stream channels
@interface KalturaLiveStreamService : KalturaServiceBase
// Adds new live stream entry.
// The entry will be queued for provision.
- (KalturaLiveStreamAdminEntry*)addWithLiveStreamEntry:(KalturaLiveStreamAdminEntry*)aLiveStreamEntry withSourceType:(NSString*)aSourceType;
- (KalturaLiveStreamAdminEntry*)addWithLiveStreamEntry:(KalturaLiveStreamAdminEntry*)aLiveStreamEntry;
// Get live stream entry by ID.
- (KalturaLiveStreamEntry*)getWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion;
- (KalturaLiveStreamEntry*)getWithEntryId:(NSString*)aEntryId;
// Update live stream entry. Only the properties that were set will be updated.
- (KalturaLiveStreamAdminEntry*)updateWithEntryId:(NSString*)aEntryId withLiveStreamEntry:(KalturaLiveStreamAdminEntry*)aLiveStreamEntry;
// Delete a live stream entry.
- (void)deleteWithEntryId:(NSString*)aEntryId;
// List live stream entries by filter with paging support.
- (KalturaLiveStreamListResponse*)listWithFilter:(KalturaLiveStreamEntryFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaLiveStreamListResponse*)listWithFilter:(KalturaLiveStreamEntryFilter*)aFilter;
- (KalturaLiveStreamListResponse*)list;
// Update live stream entry thumbnail using a raw jpeg file
- (KalturaLiveStreamEntry*)updateOfflineThumbnailJpegWithEntryId:(NSString*)aEntryId withFileData:(NSString*)aFileData;
// Update entry thumbnail using url
- (KalturaLiveStreamEntry*)updateOfflineThumbnailFromUrlWithEntryId:(NSString*)aEntryId withUrl:(NSString*)aUrl;
@end

// Media Info service
@interface KalturaMediaInfoService : KalturaServiceBase
// List media info objects by filter and pager
- (KalturaMediaInfoListResponse*)listWithFilter:(KalturaMediaInfoFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaMediaInfoListResponse*)listWithFilter:(KalturaMediaInfoFilter*)aFilter;
- (KalturaMediaInfoListResponse*)list;
@end

// Media service lets you upload and manage media files (images / videos & audio)
@interface KalturaMediaService : KalturaServiceBase
// Add entry
- (KalturaMediaEntry*)addWithEntry:(KalturaMediaEntry*)aEntry;
// Add content to entry
- (KalturaMediaEntry*)addContentWithEntryId:(NSString*)aEntryId withResource:(KalturaResource*)aResource;
- (KalturaMediaEntry*)addContentWithEntryId:(NSString*)aEntryId;
// Adds new media entry by importing an HTTP or FTP URL.
// The entry will be queued for import and then for conversion.
// DEPRECATED - use media.add instead
- (KalturaMediaEntry*)addFromUrlWithMediaEntry:(KalturaMediaEntry*)aMediaEntry withUrl:(NSString*)aUrl;
// Adds new media entry by importing the media file from a search provider. 
// This action should be used with the search service result.
// DEPRECATED - use media.add instead
- (KalturaMediaEntry*)addFromSearchResultWithMediaEntry:(KalturaMediaEntry*)aMediaEntry withSearchResult:(KalturaSearchResult*)aSearchResult;
- (KalturaMediaEntry*)addFromSearchResultWithMediaEntry:(KalturaMediaEntry*)aMediaEntry;
- (KalturaMediaEntry*)addFromSearchResult;
// Add new entry after the specific media file was uploaded and the upload token id exists
// DEPRECATED - use media.add instead
- (KalturaMediaEntry*)addFromUploadedFileWithMediaEntry:(KalturaMediaEntry*)aMediaEntry withUploadTokenId:(NSString*)aUploadTokenId;
// Add new entry after the file was recored on the server and the token id exists
// DEPRECATED - use media.add instead
- (KalturaMediaEntry*)addFromRecordedWebcamWithMediaEntry:(KalturaMediaEntry*)aMediaEntry withWebcamTokenId:(NSString*)aWebcamTokenId;
// Copy entry into new entry
// DEPRECATED - use media.add instead
- (KalturaMediaEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId withMediaEntry:(KalturaMediaEntry*)aMediaEntry withSourceFlavorParamsId:(int)aSourceFlavorParamsId;
- (KalturaMediaEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId withMediaEntry:(KalturaMediaEntry*)aMediaEntry;
- (KalturaMediaEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId;
// Copy flavor asset into new entry
// DEPRECATED - use media.add instead
- (KalturaMediaEntry*)addFromFlavorAssetWithSourceFlavorAssetId:(NSString*)aSourceFlavorAssetId withMediaEntry:(KalturaMediaEntry*)aMediaEntry;
- (KalturaMediaEntry*)addFromFlavorAssetWithSourceFlavorAssetId:(NSString*)aSourceFlavorAssetId;
// Convert entry
- (int)convertWithEntryId:(NSString*)aEntryId withConversionProfileId:(int)aConversionProfileId withDynamicConversionAttributes:(NSArray*)aDynamicConversionAttributes;
- (int)convertWithEntryId:(NSString*)aEntryId withConversionProfileId:(int)aConversionProfileId;
- (int)convertWithEntryId:(NSString*)aEntryId;
// Get media entry by ID.
- (KalturaMediaEntry*)getWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion;
- (KalturaMediaEntry*)getWithEntryId:(NSString*)aEntryId;
// Update media entry. Only the properties that were set will be updated.
- (KalturaMediaEntry*)updateWithEntryId:(NSString*)aEntryId withMediaEntry:(KalturaMediaEntry*)aMediaEntry;
// Replace media content of the entry
- (KalturaMediaEntry*)updateContentWithEntryId:(NSString*)aEntryId withResource:(KalturaResource*)aResource withConversionProfileId:(int)aConversionProfileId;
- (KalturaMediaEntry*)updateContentWithEntryId:(NSString*)aEntryId withResource:(KalturaResource*)aResource;
// Delete a media entry.
- (void)deleteWithEntryId:(NSString*)aEntryId;
// Approves media replacement
- (KalturaMediaEntry*)approveReplaceWithEntryId:(NSString*)aEntryId;
// Cancels media replacement
- (KalturaMediaEntry*)cancelReplaceWithEntryId:(NSString*)aEntryId;
// List media entries by filter with paging support.
- (KalturaMediaListResponse*)listWithFilter:(KalturaMediaEntryFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaMediaListResponse*)listWithFilter:(KalturaMediaEntryFilter*)aFilter;
- (KalturaMediaListResponse*)list;
// Count media entries by filter.
- (int)countWithFilter:(KalturaMediaEntryFilter*)aFilter;
- (int)count;
// Upload a media file to Kaltura, then the file can be used to create a media entry.
// DEPRECATED - use upload.upload or uploadToken.add instead
- (NSString*)uploadWithFileData:(NSString*)aFileData;
// Update media entry thumbnail by a specified time offset (In seconds)
// If flavor params id not specified, source flavor will be used by default
// DEPRECATED
- (KalturaMediaEntry*)updateThumbnailWithEntryId:(NSString*)aEntryId withTimeOffset:(int)aTimeOffset withFlavorParamsId:(int)aFlavorParamsId;
- (KalturaMediaEntry*)updateThumbnailWithEntryId:(NSString*)aEntryId withTimeOffset:(int)aTimeOffset;
// Update media entry thumbnail from a different entry by a specified time offset (In seconds)
// If flavor params id not specified, source flavor will be used by default
// DEPRECATED
- (KalturaMediaEntry*)updateThumbnailFromSourceEntryWithEntryId:(NSString*)aEntryId withSourceEntryId:(NSString*)aSourceEntryId withTimeOffset:(int)aTimeOffset withFlavorParamsId:(int)aFlavorParamsId;
- (KalturaMediaEntry*)updateThumbnailFromSourceEntryWithEntryId:(NSString*)aEntryId withSourceEntryId:(NSString*)aSourceEntryId withTimeOffset:(int)aTimeOffset;
// Update media entry thumbnail using a raw jpeg file
// DEPRECATED
- (KalturaMediaEntry*)updateThumbnailJpegWithEntryId:(NSString*)aEntryId withFileData:(NSString*)aFileData;
// Update entry thumbnail using url
// DEPRECATED
- (KalturaBaseEntry*)updateThumbnailFromUrlWithEntryId:(NSString*)aEntryId withUrl:(NSString*)aUrl;
// Request a new conversion job, this can be used to convert the media entry to a different format
- (int)requestConversionWithEntryId:(NSString*)aEntryId withFileFormat:(NSString*)aFileFormat;
// Flag inappropriate media entry for moderation
- (void)flagWithModerationFlag:(KalturaModerationFlag*)aModerationFlag;
// Reject the media entry and mark the pending flags (if any) as moderated (this will make the entry non playable)
- (void)rejectWithEntryId:(NSString*)aEntryId;
// Approve the media entry and mark the pending flags (if any) as moderated (this will make the entry playable)
- (void)approveWithEntryId:(NSString*)aEntryId;
// List all pending flags for the media entry
- (KalturaModerationFlagListResponse*)listFlagsWithEntryId:(NSString*)aEntryId withPager:(KalturaFilterPager*)aPager;
- (KalturaModerationFlagListResponse*)listFlagsWithEntryId:(NSString*)aEntryId;
// Anonymously rank a media entry, no validation is done on duplicate rankings
- (void)anonymousRankWithEntryId:(NSString*)aEntryId withRank:(int)aRank;
@end

// A Mix is an XML unique format invented by Kaltura, it allows the user to create a mix of videos and images, in and out points, transitions, text overlays, soundtrack, effects and much more...
// Mixing service lets you create a new mix, manage its metadata and make basic manipulations.
@interface KalturaMixingService : KalturaServiceBase
// Adds a new mix.
// If the dataContent is null, a default timeline will be created.
- (KalturaMixEntry*)addWithMixEntry:(KalturaMixEntry*)aMixEntry;
// Get mix entry by id.
- (KalturaMixEntry*)getWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion;
- (KalturaMixEntry*)getWithEntryId:(NSString*)aEntryId;
// Update mix entry. Only the properties that were set will be updated.
- (KalturaMixEntry*)updateWithEntryId:(NSString*)aEntryId withMixEntry:(KalturaMixEntry*)aMixEntry;
// Delete a mix entry.
- (void)deleteWithEntryId:(NSString*)aEntryId;
// List entries by filter with paging support.
// Return parameter is an array of mix entries.
- (KalturaMixListResponse*)listWithFilter:(KalturaMixEntryFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaMixListResponse*)listWithFilter:(KalturaMixEntryFilter*)aFilter;
- (KalturaMixListResponse*)list;
// Count mix entries by filter.
- (int)countWithFilter:(KalturaMediaEntryFilter*)aFilter;
- (int)count;
// Clones an existing mix.
- (KalturaMixEntry*)cloneWithEntryId:(NSString*)aEntryId;
// Appends a media entry to a the end of the mix timeline, this will save the mix timeline as a new version.
- (KalturaMixEntry*)appendMediaEntryWithMixEntryId:(NSString*)aMixEntryId withMediaEntryId:(NSString*)aMediaEntryId;
// Request a new flattening job, flattening is used to convert a video mix to a video file.
- (int)requestFlatteningWithEntryId:(NSString*)aEntryId withFileFormat:(NSString*)aFileFormat withVersion:(int)aVersion;
- (int)requestFlatteningWithEntryId:(NSString*)aEntryId withFileFormat:(NSString*)aFileFormat;
// Get the mixes in which the media entry is included
- (NSMutableArray*)getMixesByMediaIdWithMediaEntryId:(NSString*)aMediaEntryId;
// Get all ready media entries that exist in the given mix id
- (NSMutableArray*)getReadyMediaEntriesWithMixId:(NSString*)aMixId withVersion:(int)aVersion;
- (NSMutableArray*)getReadyMediaEntriesWithMixId:(NSString*)aMixId;
// Anonymously rank a mix entry, no validation is done on duplicate rankings
- (void)anonymousRankWithEntryId:(NSString*)aEntryId withRank:(int)aRank;
@end

// Notification Service
@interface KalturaNotificationService : KalturaServiceBase
// Return the notifications for a specific entry id and type
- (KalturaClientNotification*)getClientNotificationWithEntryId:(NSString*)aEntryId withType:(int)aType;
@end

// partner service allows you to change/manage your partner personal details and settings as well
@interface KalturaPartnerService : KalturaServiceBase
// Register to Kaltura's partner program
- (KalturaPartner*)registerWithPartner:(KalturaPartner*)aPartner withCmsPassword:(NSString*)aCmsPassword;
- (KalturaPartner*)registerWithPartner:(KalturaPartner*)aPartner;
// Update details and settings of you existing partner
- (KalturaPartner*)updateWithPartner:(KalturaPartner*)aPartner withAllowEmpty:(BOOL)aAllowEmpty;
- (KalturaPartner*)updateWithPartner:(KalturaPartner*)aPartner;
// Retrieve partner secret and admin secret
- (KalturaPartner*)getSecretsWithPartnerId:(int)aPartnerId withAdminEmail:(NSString*)aAdminEmail withCmsPassword:(NSString*)aCmsPassword;
// Retrieve all info about partner
// This service gets no parameters, and is using the KS to know which partnerId info should be returned
- (KalturaPartner*)getInfo;
// Get usage statistics for a partner
// Calculation is done according to partner's package
// Additional data returned is a graph points of streaming usage in a timeframe
// The resolution can be "days" or "months"
- (KalturaPartnerUsage*)getUsageWithYear:(int)aYear withMonth:(int)aMonth withResolution:(NSString*)aResolution;
- (KalturaPartnerUsage*)getUsageWithYear:(int)aYear withMonth:(int)aMonth;
- (KalturaPartnerUsage*)getUsageWithYear:(int)aYear;
- (KalturaPartnerUsage*)getUsage;
// List partners by filter with paging support
// Current implementation will only list the sub partners of the partner initiating the api call (using the current KS)
- (KalturaPartnerListResponse*)listWithFilter:(KalturaPartnerFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaPartnerListResponse*)listWithFilter:(KalturaPartnerFilter*)aFilter;
- (KalturaPartnerListResponse*)list;
@end

// PermissionItem service lets you create and manage permission items
@interface KalturaPermissionItemService : KalturaServiceBase
// Allows you to add a new KalturaPermissionItem object
- (KalturaPermissionItem*)addWithPermissionItem:(KalturaPermissionItem*)aPermissionItem;
// Retrieve a KalturaPermissionItem object by ID
- (KalturaPermissionItem*)getWithPermissionItemId:(int)aPermissionItemId;
// Update an existing KalturaPermissionItem object
- (KalturaPermissionItem*)updateWithPermissionItemId:(int)aPermissionItemId withPermissionItem:(KalturaPermissionItem*)aPermissionItem;
// Mark the KalturaPermissionItem object as deleted
- (KalturaPermissionItem*)deleteWithPermissionItemId:(int)aPermissionItemId;
// List KalturaPermissionItem objects
- (KalturaPermissionItemListResponse*)listWithFilter:(KalturaPermissionItemFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaPermissionItemListResponse*)listWithFilter:(KalturaPermissionItemFilter*)aFilter;
- (KalturaPermissionItemListResponse*)list;
@end

// Permission service lets you create and manage user permissions
@interface KalturaPermissionService : KalturaServiceBase
// Allows you to add a new KalturaPermission object
- (KalturaPermission*)addWithPermission:(KalturaPermission*)aPermission;
// Retrieve a KalturaPermission object by ID
- (KalturaPermission*)getWithPermissionName:(NSString*)aPermissionName;
// Update an existing KalturaPermission object
- (KalturaPermission*)updateWithPermissionName:(NSString*)aPermissionName withPermission:(KalturaPermission*)aPermission;
// Mark the KalturaPermission object as deleted
- (KalturaPermission*)deleteWithPermissionName:(NSString*)aPermissionName;
// List KalturaPermission objects
- (KalturaPermissionListResponse*)listWithFilter:(KalturaPermissionFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaPermissionListResponse*)listWithFilter:(KalturaPermissionFilter*)aFilter;
- (KalturaPermissionListResponse*)list;
// Return a list of current sessions's allowed permission names
- (NSString*)getCurrentPermissions;
@end

// Playlist service lets you create,manage and play your playlists
// Playlists could be static (containing a fixed list of entries) or dynamic (baseed on a filter)
@interface KalturaPlaylistService : KalturaServiceBase
// Add new playlist
// Note that all entries used in a playlist will become public and may appear in KalturaNetwork
- (KalturaPlaylist*)addWithPlaylist:(KalturaPlaylist*)aPlaylist withUpdateStats:(BOOL)aUpdateStats;
- (KalturaPlaylist*)addWithPlaylist:(KalturaPlaylist*)aPlaylist;
// Retrieve a playlist
- (KalturaPlaylist*)getWithId:(NSString*)aId withVersion:(int)aVersion;
- (KalturaPlaylist*)getWithId:(NSString*)aId;
// Update existing playlist
// Note - you cannot change playlist type. updated playlist must be of the same type.
- (KalturaPlaylist*)updateWithId:(NSString*)aId withPlaylist:(KalturaPlaylist*)aPlaylist withUpdateStats:(BOOL)aUpdateStats;
- (KalturaPlaylist*)updateWithId:(NSString*)aId withPlaylist:(KalturaPlaylist*)aPlaylist;
// Delete existing playlist
- (void)deleteWithId:(NSString*)aId;
// Clone an existing playlist
- (KalturaPlaylist*)cloneWithId:(NSString*)aId withNewPlaylist:(KalturaPlaylist*)aNewPlaylist;
- (KalturaPlaylist*)cloneWithId:(NSString*)aId;
// List available playlists
- (KalturaPlaylistListResponse*)listWithFilter:(KalturaPlaylistFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaPlaylistListResponse*)listWithFilter:(KalturaPlaylistFilter*)aFilter;
- (KalturaPlaylistListResponse*)list;
// Retrieve playlist for playing purpose
- (NSMutableArray*)executeWithId:(NSString*)aId withDetailed:(NSString*)aDetailed;
- (NSMutableArray*)executeWithId:(NSString*)aId;
// Retrieve playlist for playing purpose, based on content
- (NSMutableArray*)executeFromContentWithPlaylistType:(int)aPlaylistType withPlaylistContent:(NSString*)aPlaylistContent withDetailed:(NSString*)aDetailed;
- (NSMutableArray*)executeFromContentWithPlaylistType:(int)aPlaylistType withPlaylistContent:(NSString*)aPlaylistContent;
// Revrieve playlist for playing purpose, based on media entry filters
- (NSMutableArray*)executeFromFiltersWithFilters:(NSArray*)aFilters withTotalResults:(int)aTotalResults withDetailed:(NSString*)aDetailed;
- (NSMutableArray*)executeFromFiltersWithFilters:(NSArray*)aFilters withTotalResults:(int)aTotalResults;
// Retrieve playlist statistics
- (KalturaPlaylist*)getStatsFromContentWithPlaylistType:(int)aPlaylistType withPlaylistContent:(NSString*)aPlaylistContent;
@end

// api for getting reports data by the report type and some inputFilter
@interface KalturaReportService : KalturaServiceBase
// report getGraphs action allows to get a graph data for a specific report.
- (NSMutableArray*)getGraphsWithReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withDimension:(NSString*)aDimension withObjectIds:(NSString*)aObjectIds;
- (NSMutableArray*)getGraphsWithReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withDimension:(NSString*)aDimension;
- (NSMutableArray*)getGraphsWithReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter;
// report getTotal action allows to get a graph data for a specific report.
- (KalturaReportTotal*)getTotalWithReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withObjectIds:(NSString*)aObjectIds;
- (KalturaReportTotal*)getTotalWithReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter;
// report getTable action allows to get a graph data for a specific report.
- (KalturaReportTable*)getTableWithReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withPager:(KalturaFilterPager*)aPager withOrder:(NSString*)aOrder withObjectIds:(NSString*)aObjectIds;
- (KalturaReportTable*)getTableWithReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withPager:(KalturaFilterPager*)aPager withOrder:(NSString*)aOrder;
- (KalturaReportTable*)getTableWithReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withPager:(KalturaFilterPager*)aPager;
// will create a Csv file for the given report and return the URL to access it
- (NSString*)getUrlForReportAsCsvWithReportTitle:(NSString*)aReportTitle withReportText:(NSString*)aReportText withHeaders:(NSString*)aHeaders withReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withDimension:(NSString*)aDimension withPager:(KalturaFilterPager*)aPager withOrder:(NSString*)aOrder withObjectIds:(NSString*)aObjectIds;
- (NSString*)getUrlForReportAsCsvWithReportTitle:(NSString*)aReportTitle withReportText:(NSString*)aReportText withHeaders:(NSString*)aHeaders withReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withDimension:(NSString*)aDimension withPager:(KalturaFilterPager*)aPager withOrder:(NSString*)aOrder;
- (NSString*)getUrlForReportAsCsvWithReportTitle:(NSString*)aReportTitle withReportText:(NSString*)aReportText withHeaders:(NSString*)aHeaders withReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withDimension:(NSString*)aDimension withPager:(KalturaFilterPager*)aPager;
- (NSString*)getUrlForReportAsCsvWithReportTitle:(NSString*)aReportTitle withReportText:(NSString*)aReportText withHeaders:(NSString*)aHeaders withReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter withDimension:(NSString*)aDimension;
- (NSString*)getUrlForReportAsCsvWithReportTitle:(NSString*)aReportTitle withReportText:(NSString*)aReportText withHeaders:(NSString*)aHeaders withReportType:(int)aReportType withReportInputFilter:(KalturaReportInputFilter*)aReportInputFilter;
- (KalturaReportResponse*)executeWithId:(int)aId withParams:(NSArray*)aParams;
- (KalturaReportResponse*)executeWithId:(int)aId;
- (NSString*)getCsvWithId:(int)aId withParams:(NSArray*)aParams;
- (NSString*)getCsvWithId:(int)aId;
// Returns report CSV file executed by string params with the following convention: param1=value1;param2=value2
- (NSString*)getCsvFromStringParamsWithId:(int)aId withParams:(NSString*)aParams;
- (NSString*)getCsvFromStringParamsWithId:(int)aId;
@end

// Expose the schema definitions for syndication MRSS, bulk upload XML and other schema types.
@interface KalturaSchemaService : KalturaServiceBase
// Serves the requested XSD according to the type and name.
- (NSString*)serveWithType:(NSString*)aType;
@end

// Search service allows you to search for media in various media providers
// This service is being used mostly by the CW component
@interface KalturaSearchService : KalturaServiceBase
// Search for media in one of the supported media providers
- (KalturaSearchResultResponse*)searchWithSearch:(KalturaSearch*)aSearch withPager:(KalturaFilterPager*)aPager;
- (KalturaSearchResultResponse*)searchWithSearch:(KalturaSearch*)aSearch;
// Retrieve extra information about media found in search action
// Some providers return only part of the fields needed to create entry from, use this action to get the rest of the fields.
- (KalturaSearchResult*)getMediaInfoWithSearchResult:(KalturaSearchResult*)aSearchResult;
// Search for media given a specific URL
// Kaltura supports a searchURL action on some of the media providers.
// This action will return a KalturaSearchResult object based on a given URL (assuming the media provider is supported)
- (KalturaSearchResult*)searchUrlWithMediaType:(int)aMediaType withUrl:(NSString*)aUrl;
- (KalturaSearchAuthData*)externalLoginWithSearchSource:(int)aSearchSource withUserName:(NSString*)aUserName withPassword:(NSString*)aPassword;
@end

// Session service
@interface KalturaSessionService : KalturaServiceBase
// Start a session with Kaltura's server.
// The result KS is the session key that you should pass to all services that requires a ticket.
- (NSString*)startWithSecret:(NSString*)aSecret withUserId:(NSString*)aUserId withType:(int)aType withPartnerId:(int)aPartnerId withExpiry:(int)aExpiry withPrivileges:(NSString*)aPrivileges;
- (NSString*)startWithSecret:(NSString*)aSecret withUserId:(NSString*)aUserId withType:(int)aType withPartnerId:(int)aPartnerId withExpiry:(int)aExpiry;
- (NSString*)startWithSecret:(NSString*)aSecret withUserId:(NSString*)aUserId withType:(int)aType withPartnerId:(int)aPartnerId;
- (NSString*)startWithSecret:(NSString*)aSecret withUserId:(NSString*)aUserId withType:(int)aType;
- (NSString*)startWithSecret:(NSString*)aSecret withUserId:(NSString*)aUserId;
- (NSString*)startWithSecret:(NSString*)aSecret;
// End a session with the Kaltura server, making the current KS invalid.
- (void)end;
// Start an impersonated session with Kaltura's server.
// The result KS is the session key that you should pass to all services that requires a ticket.
- (NSString*)impersonateWithSecret:(NSString*)aSecret withImpersonatedPartnerId:(int)aImpersonatedPartnerId withUserId:(NSString*)aUserId withType:(int)aType withPartnerId:(int)aPartnerId withExpiry:(int)aExpiry withPrivileges:(NSString*)aPrivileges;
- (NSString*)impersonateWithSecret:(NSString*)aSecret withImpersonatedPartnerId:(int)aImpersonatedPartnerId withUserId:(NSString*)aUserId withType:(int)aType withPartnerId:(int)aPartnerId withExpiry:(int)aExpiry;
- (NSString*)impersonateWithSecret:(NSString*)aSecret withImpersonatedPartnerId:(int)aImpersonatedPartnerId withUserId:(NSString*)aUserId withType:(int)aType withPartnerId:(int)aPartnerId;
- (NSString*)impersonateWithSecret:(NSString*)aSecret withImpersonatedPartnerId:(int)aImpersonatedPartnerId withUserId:(NSString*)aUserId withType:(int)aType;
- (NSString*)impersonateWithSecret:(NSString*)aSecret withImpersonatedPartnerId:(int)aImpersonatedPartnerId withUserId:(NSString*)aUserId;
- (NSString*)impersonateWithSecret:(NSString*)aSecret withImpersonatedPartnerId:(int)aImpersonatedPartnerId;
// Start a session for Kaltura's flash widgets
- (KalturaStartWidgetSessionResponse*)startWidgetSessionWithWidgetId:(NSString*)aWidgetId withExpiry:(int)aExpiry;
- (KalturaStartWidgetSessionResponse*)startWidgetSessionWithWidgetId:(NSString*)aWidgetId;
@end

// Stats Service
@interface KalturaStatsService : KalturaServiceBase
// Will write to the event log a single line representing the event
// KalturaStatsEvent $event
- (void)collectWithEvent:(KalturaStatsEvent*)aEvent;
// Will collect the kmcEvent sent form the KMC client
- (void)kmcCollectWithKmcEvent:(KalturaStatsKmcEvent*)aKmcEvent;
- (KalturaCEError*)reportKceErrorWithKalturaCEError:(KalturaCEError*)aKalturaCEError;
@end

// Storage Profiles service
@interface KalturaStorageProfileService : KalturaServiceBase
// Adds a storage profile to the Kaltura DB.
- (KalturaStorageProfile*)addWithStorageProfile:(KalturaStorageProfile*)aStorageProfile;
- (void)updateStatusWithStorageId:(int)aStorageId withStatus:(int)aStatus;
// Get storage profile by id
- (KalturaStorageProfile*)getWithStorageProfileId:(int)aStorageProfileId;
// Update storage profile by id
- (KalturaStorageProfile*)updateWithStorageProfileId:(int)aStorageProfileId withStorageProfile:(KalturaStorageProfile*)aStorageProfile;
- (KalturaStorageProfileListResponse*)listWithFilter:(KalturaStorageProfileFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaStorageProfileListResponse*)listWithFilter:(KalturaStorageProfileFilter*)aFilter;
- (KalturaStorageProfileListResponse*)list;
@end

// Add & Manage Syndication Feeds
@interface KalturaSyndicationFeedService : KalturaServiceBase
// Add new Syndication Feed
- (KalturaBaseSyndicationFeed*)addWithSyndicationFeed:(KalturaBaseSyndicationFeed*)aSyndicationFeed;
// Get Syndication Feed by ID
- (KalturaBaseSyndicationFeed*)getWithId:(NSString*)aId;
// Update Syndication Feed by ID
- (KalturaBaseSyndicationFeed*)updateWithId:(NSString*)aId withSyndicationFeed:(KalturaBaseSyndicationFeed*)aSyndicationFeed;
// Delete Syndication Feed by ID
- (void)deleteWithId:(NSString*)aId;
// List Syndication Feeds by filter with paging support
- (KalturaBaseSyndicationFeedListResponse*)listWithFilter:(KalturaBaseSyndicationFeedFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaBaseSyndicationFeedListResponse*)listWithFilter:(KalturaBaseSyndicationFeedFilter*)aFilter;
- (KalturaBaseSyndicationFeedListResponse*)list;
// get entry count for a syndication feed
- (KalturaSyndicationFeedEntryCount*)getEntryCountWithFeedId:(NSString*)aFeedId;
// request conversion for all entries that doesnt have the required flavor param
// returns a comma-separated ids of conversion jobs
// @action requestConversion
// @param string $feedId
// @return string
- (NSString*)requestConversionWithFeedId:(NSString*)aFeedId;
@end

// System service is used for internal system helpers & to retrieve system level information
@interface KalturaSystemService : KalturaServiceBase
- (BOOL)ping;
@end

// Retrieve information and invoke actions on Thumb Asset
@interface KalturaThumbAssetService : KalturaServiceBase
// Add thumbnail asset
- (KalturaThumbAsset*)addWithEntryId:(NSString*)aEntryId withThumbAsset:(KalturaThumbAsset*)aThumbAsset;
// Update content of thumbnail asset
- (KalturaThumbAsset*)setContentWithId:(NSString*)aId withContentResource:(KalturaContentResource*)aContentResource;
// Update thumbnail asset
- (KalturaThumbAsset*)updateWithId:(NSString*)aId withThumbAsset:(KalturaThumbAsset*)aThumbAsset;
// Serves thumbnail by entry id and thumnail params id
- (NSString*)serveByEntryIdWithEntryId:(NSString*)aEntryId withThumbParamId:(int)aThumbParamId;
- (NSString*)serveByEntryIdWithEntryId:(NSString*)aEntryId;
// Serves thumbnail by its id
- (NSString*)serveWithThumbAssetId:(NSString*)aThumbAssetId;
// Tags the thumbnail as DEFAULT_THUMB and removes that tag from all other thumbnail assets of the entry.
// Create a new file sync link on the entry thumbnail that points to the thumbnail asset file sync.
- (void)setAsDefaultWithThumbAssetId:(NSString*)aThumbAssetId;
- (KalturaThumbAsset*)generateByEntryIdWithEntryId:(NSString*)aEntryId withDestThumbParamsId:(int)aDestThumbParamsId;
- (KalturaThumbAsset*)generateWithEntryId:(NSString*)aEntryId withThumbParams:(KalturaThumbParams*)aThumbParams withSourceAssetId:(NSString*)aSourceAssetId;
- (KalturaThumbAsset*)generateWithEntryId:(NSString*)aEntryId withThumbParams:(KalturaThumbParams*)aThumbParams;
- (KalturaThumbAsset*)regenerateWithThumbAssetId:(NSString*)aThumbAssetId;
- (KalturaThumbAsset*)getWithThumbAssetId:(NSString*)aThumbAssetId;
// DEPRECATED - Use thumbAsset.list instead
- (NSMutableArray*)getByEntryIdWithEntryId:(NSString*)aEntryId;
// List Thumbnail Assets by filter and pager
- (KalturaThumbAssetListResponse*)listWithFilter:(KalturaAssetFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaThumbAssetListResponse*)listWithFilter:(KalturaAssetFilter*)aFilter;
- (KalturaThumbAssetListResponse*)list;
// DEPRECATED - use thumbAsset.add and thumbAsset.setContent instead
- (KalturaThumbAsset*)addFromUrlWithEntryId:(NSString*)aEntryId withUrl:(NSString*)aUrl;
- (KalturaThumbAsset*)addFromImageWithEntryId:(NSString*)aEntryId withFileData:(NSString*)aFileData;
- (void)deleteWithThumbAssetId:(NSString*)aThumbAssetId;
// Get download URL for the asset
- (NSString*)getUrlWithId:(NSString*)aId withStorageId:(int)aStorageId;
- (NSString*)getUrlWithId:(NSString*)aId;
// Get remote storage existing paths for the asset
- (KalturaRemotePathListResponse*)getRemotePathsWithId:(NSString*)aId;
@end

// Add & Manage Thumb Params
@interface KalturaThumbParamsService : KalturaServiceBase
// Add new Thumb Params
- (KalturaThumbParams*)addWithThumbParams:(KalturaThumbParams*)aThumbParams;
// Get Thumb Params by ID
- (KalturaThumbParams*)getWithId:(int)aId;
// Update Thumb Params by ID
- (KalturaThumbParams*)updateWithId:(int)aId withThumbParams:(KalturaThumbParams*)aThumbParams;
// Delete Thumb Params by ID
- (void)deleteWithId:(int)aId;
// List Thumb Params by filter with paging support (By default - all system default params will be listed too)
- (KalturaThumbParamsListResponse*)listWithFilter:(KalturaThumbParamsFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaThumbParamsListResponse*)listWithFilter:(KalturaThumbParamsFilter*)aFilter;
- (KalturaThumbParamsListResponse*)list;
// Get Thumb Params by Conversion Profile ID
- (NSMutableArray*)getByConversionProfileIdWithConversionProfileId:(int)aConversionProfileId;
@end

// UiConf service lets you create and manage your UIConfs for the various flash components
// This service is used by the KMC-ApplicationStudio
@interface KalturaUiConfService : KalturaServiceBase
// UIConf Add action allows you to add a UIConf to Kaltura DB
- (KalturaUiConf*)addWithUiConf:(KalturaUiConf*)aUiConf;
// Update an existing UIConf
- (KalturaUiConf*)updateWithId:(int)aId withUiConf:(KalturaUiConf*)aUiConf;
// Retrieve a UIConf by id
- (KalturaUiConf*)getWithId:(int)aId;
// Delete an existing UIConf
- (void)deleteWithId:(int)aId;
// Clone an existing UIConf
- (KalturaUiConf*)cloneWithId:(int)aId;
// retrieve a list of available template UIConfs
- (KalturaUiConfListResponse*)listTemplatesWithFilter:(KalturaUiConfFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaUiConfListResponse*)listTemplatesWithFilter:(KalturaUiConfFilter*)aFilter;
- (KalturaUiConfListResponse*)listTemplates;
// Retrieve a list of available UIConfs
- (KalturaUiConfListResponse*)listWithFilter:(KalturaUiConfFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaUiConfListResponse*)listWithFilter:(KalturaUiConfFilter*)aFilter;
- (KalturaUiConfListResponse*)list;
// Retrieve a list of all available versions by object type
- (NSMutableArray*)getAvailableTypes;
@end

@interface KalturaUploadService : KalturaServiceBase
- (NSString*)uploadWithFileData:(NSString*)aFileData;
- (KalturaUploadResponse*)getUploadedFileTokenByFileNameWithFileName:(NSString*)aFileName;
@end

@interface KalturaUploadTokenService : KalturaServiceBase
// Adds new upload token to upload a file
- (KalturaUploadToken*)addWithUploadToken:(KalturaUploadToken*)aUploadToken;
- (KalturaUploadToken*)add;
// Get upload token by id
- (KalturaUploadToken*)getWithUploadTokenId:(NSString*)aUploadTokenId;
// Upload a file using the upload token id, returns an error on failure (an exception will be thrown when using one of the Kaltura clients)
- (KalturaUploadToken*)uploadWithUploadTokenId:(NSString*)aUploadTokenId withFileData:(NSString*)aFileData withResume:(BOOL)aResume withFinalChunk:(BOOL)aFinalChunk withResumeAt:(double)aResumeAt;
- (KalturaUploadToken*)uploadWithUploadTokenId:(NSString*)aUploadTokenId withFileData:(NSString*)aFileData withResume:(BOOL)aResume withFinalChunk:(BOOL)aFinalChunk;
- (KalturaUploadToken*)uploadWithUploadTokenId:(NSString*)aUploadTokenId withFileData:(NSString*)aFileData withResume:(BOOL)aResume;
- (KalturaUploadToken*)uploadWithUploadTokenId:(NSString*)aUploadTokenId withFileData:(NSString*)aFileData;
// Deletes the upload token by upload token id
- (void)deleteWithUploadTokenId:(NSString*)aUploadTokenId;
// List upload token by filter with pager support. 
// When using a user session the service will be restricted to users objects only.
- (KalturaUploadTokenListResponse*)listWithFilter:(KalturaUploadTokenFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaUploadTokenListResponse*)listWithFilter:(KalturaUploadTokenFilter*)aFilter;
- (KalturaUploadTokenListResponse*)list;
@end

// UserRole service lets you create and manage user roles
@interface KalturaUserRoleService : KalturaServiceBase
// Allows you to add a new KalturaUserRole object
- (KalturaUserRole*)addWithUserRole:(KalturaUserRole*)aUserRole;
// Retrieve a KalturaUserRole object by ID
- (KalturaUserRole*)getWithUserRoleId:(int)aUserRoleId;
// Update an existing KalturaUserRole object
- (KalturaUserRole*)updateWithUserRoleId:(int)aUserRoleId withUserRole:(KalturaUserRole*)aUserRole;
// Mark the KalturaUserRole object as deleted
- (KalturaUserRole*)deleteWithUserRoleId:(int)aUserRoleId;
// List user roles
- (KalturaUserRoleListResponse*)listWithFilter:(KalturaUserRoleFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaUserRoleListResponse*)listWithFilter:(KalturaUserRoleFilter*)aFilter;
- (KalturaUserRoleListResponse*)list;
// Clone role
- (KalturaUserRole*)cloneWithUserRoleId:(int)aUserRoleId;
@end

// Manage partner users on Kaltura's side
// The userId in kaltura is the unique Id in the partner's system, and the [partnerId,Id] couple are unique key in kaltura's DB
@interface KalturaUserService : KalturaServiceBase
// Adds a user to the Kaltura DB.
// Input param $id is the unique identifier in the partner's system
- (KalturaUser*)addWithUser:(KalturaUser*)aUser;
// Update existing user, it is possible to update the user id too
- (KalturaUser*)updateWithUserId:(NSString*)aUserId withUser:(KalturaUser*)aUser;
// Get user by user ID
- (KalturaUser*)getWithUserId:(NSString*)aUserId;
// Get user by user's login ID and partner ID
- (KalturaUser*)getByLoginIdWithLoginId:(NSString*)aLoginId;
// Mark the user as deleted
- (KalturaUser*)deleteWithUserId:(NSString*)aUserId;
// List users (When not set in the filter, blocked and deleted users will be returned too)
- (KalturaUserListResponse*)listWithFilter:(KalturaUserFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaUserListResponse*)listWithFilter:(KalturaUserFilter*)aFilter;
- (KalturaUserListResponse*)list;
// Notify about user ban
- (void)notifyBanWithUserId:(NSString*)aUserId;
// Get a session using user id and password
- (NSString*)loginWithPartnerId:(int)aPartnerId withUserId:(NSString*)aUserId withPassword:(NSString*)aPassword withExpiry:(int)aExpiry withPrivileges:(NSString*)aPrivileges;
- (NSString*)loginWithPartnerId:(int)aPartnerId withUserId:(NSString*)aUserId withPassword:(NSString*)aPassword withExpiry:(int)aExpiry;
- (NSString*)loginWithPartnerId:(int)aPartnerId withUserId:(NSString*)aUserId withPassword:(NSString*)aPassword;
// Get a session using user's kaltura id and password
- (NSString*)loginByLoginIdWithLoginId:(NSString*)aLoginId withPassword:(NSString*)aPassword withPartnerId:(int)aPartnerId withExpiry:(int)aExpiry withPrivileges:(NSString*)aPrivileges;
- (NSString*)loginByLoginIdWithLoginId:(NSString*)aLoginId withPassword:(NSString*)aPassword withPartnerId:(int)aPartnerId withExpiry:(int)aExpiry;
- (NSString*)loginByLoginIdWithLoginId:(NSString*)aLoginId withPassword:(NSString*)aPassword withPartnerId:(int)aPartnerId;
- (NSString*)loginByLoginIdWithLoginId:(NSString*)aLoginId withPassword:(NSString*)aPassword;
// Update user password and email
- (void)updateLoginDataWithOldLoginId:(NSString*)aOldLoginId withPassword:(NSString*)aPassword withNewLoginId:(NSString*)aNewLoginId withNewPassword:(NSString*)aNewPassword withNewFirstName:(NSString*)aNewFirstName withNewLastName:(NSString*)aNewLastName;
- (void)updateLoginDataWithOldLoginId:(NSString*)aOldLoginId withPassword:(NSString*)aPassword withNewLoginId:(NSString*)aNewLoginId withNewPassword:(NSString*)aNewPassword withNewFirstName:(NSString*)aNewFirstName;
- (void)updateLoginDataWithOldLoginId:(NSString*)aOldLoginId withPassword:(NSString*)aPassword withNewLoginId:(NSString*)aNewLoginId withNewPassword:(NSString*)aNewPassword;
- (void)updateLoginDataWithOldLoginId:(NSString*)aOldLoginId withPassword:(NSString*)aPassword withNewLoginId:(NSString*)aNewLoginId;
- (void)updateLoginDataWithOldLoginId:(NSString*)aOldLoginId withPassword:(NSString*)aPassword;
// Reset admin user password and send it to the users email address
- (void)resetPasswordWithEmail:(NSString*)aEmail;
// Set initial users password
- (void)setInitialPasswordWithHashKey:(NSString*)aHashKey withNewPassword:(NSString*)aNewPassword;
// Enable the user to login with a loginId (email) and password.
- (KalturaUser*)enableLoginWithUserId:(NSString*)aUserId withLoginId:(NSString*)aLoginId withPassword:(NSString*)aPassword;
- (KalturaUser*)enableLoginWithUserId:(NSString*)aUserId withLoginId:(NSString*)aLoginId;
// Disallow user to login with an id/password.
// Passing either a loginId or a userId is allowed.
- (KalturaUser*)disableLoginWithUserId:(NSString*)aUserId withLoginId:(NSString*)aLoginId;
- (KalturaUser*)disableLoginWithUserId:(NSString*)aUserId;
- (KalturaUser*)disableLogin;
@end

// widget service for full widget management
@interface KalturaWidgetService : KalturaServiceBase
// Add new widget, can be attached to entry or kshow
// SourceWidget is ignored.
- (KalturaWidget*)addWithWidget:(KalturaWidget*)aWidget;
// Update exisiting widget
- (KalturaWidget*)updateWithId:(NSString*)aId withWidget:(KalturaWidget*)aWidget;
// Get widget by id
- (KalturaWidget*)getWithId:(NSString*)aId;
// Add widget based on existing widget.
// Must provide valid sourceWidgetId
- (KalturaWidget*)cloneWithWidget:(KalturaWidget*)aWidget;
// Retrieve a list of available widget depends on the filter given
- (KalturaWidgetListResponse*)listWithFilter:(KalturaWidgetFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaWidgetListResponse*)listWithFilter:(KalturaWidgetFilter*)aFilter;
- (KalturaWidgetListResponse*)list;
@end

// Internal Service is used for actions that are used internally in Kaltura applications and might be changed in the future without any notice.
@interface KalturaXInternalService : KalturaServiceBase
// Creates new download job for multiple entry ids (comma separated), an email will be sent when the job is done
// This sevice support the following entries: 
// - MediaEntry
// - Video will be converted using the flavor params id
// - Audio will be downloaded as MP3
// - Image will be downloaded as Jpeg
// - MixEntry will be flattend using the flavor params id
// - Other entry types are not supported
// Returns the admin email that the email message will be sent to
- (NSString*)xAddBulkDownloadWithEntryIds:(NSString*)aEntryIds withFlavorParamsId:(NSString*)aFlavorParamsId;
- (NSString*)xAddBulkDownloadWithEntryIds:(NSString*)aEntryIds;
@end

@interface KalturaClient : KalturaClientBase
{
	KalturaAccessControlProfileService* _accessControlProfile;
	KalturaAccessControlService* _accessControl;
	KalturaAdminUserService* _adminUser;
	KalturaBaseEntryService* _baseEntry;
	KalturaBulkUploadService* _bulkUpload;
	KalturaCategoryService* _category;
	KalturaConversionProfileAssetParamsService* _conversionProfileAssetParams;
	KalturaConversionProfileService* _conversionProfile;
	KalturaDataService* _data;
	KalturaEmailIngestionProfileService* _EmailIngestionProfile;
	KalturaFlavorAssetService* _flavorAsset;
	KalturaFlavorParamsService* _flavorParams;
	KalturaLiveStreamService* _liveStream;
	KalturaMediaInfoService* _mediaInfo;
	KalturaMediaService* _media;
	KalturaMixingService* _mixing;
	KalturaNotificationService* _notification;
	KalturaPartnerService* _partner;
	KalturaPermissionItemService* _permissionItem;
	KalturaPermissionService* _permission;
	KalturaPlaylistService* _playlist;
	KalturaReportService* _report;
	KalturaSchemaService* _schema;
	KalturaSearchService* _search;
	KalturaSessionService* _session;
	KalturaStatsService* _stats;
	KalturaStorageProfileService* _storageProfile;
	KalturaSyndicationFeedService* _syndicationFeed;
	KalturaSystemService* _system;
	KalturaThumbAssetService* _thumbAsset;
	KalturaThumbParamsService* _thumbParams;
	KalturaUiConfService* _uiConf;
	KalturaUploadService* _upload;
	KalturaUploadTokenService* _uploadToken;
	KalturaUserRoleService* _userRole;
	KalturaUserService* _user;
	KalturaWidgetService* _widget;
	KalturaXInternalService* _xInternal;
}

@property (nonatomic, readonly) KalturaAccessControlProfileService* accessControlProfile;
@property (nonatomic, readonly) KalturaAccessControlService* accessControl;
@property (nonatomic, readonly) KalturaAdminUserService* adminUser;
@property (nonatomic, readonly) KalturaBaseEntryService* baseEntry;
@property (nonatomic, readonly) KalturaBulkUploadService* bulkUpload;
@property (nonatomic, readonly) KalturaCategoryService* category;
@property (nonatomic, readonly) KalturaConversionProfileAssetParamsService* conversionProfileAssetParams;
@property (nonatomic, readonly) KalturaConversionProfileService* conversionProfile;
@property (nonatomic, readonly) KalturaDataService* data;
@property (nonatomic, readonly) KalturaEmailIngestionProfileService* EmailIngestionProfile;
@property (nonatomic, readonly) KalturaFlavorAssetService* flavorAsset;
@property (nonatomic, readonly) KalturaFlavorParamsService* flavorParams;
@property (nonatomic, readonly) KalturaLiveStreamService* liveStream;
@property (nonatomic, readonly) KalturaMediaInfoService* mediaInfo;
@property (nonatomic, readonly) KalturaMediaService* media;
@property (nonatomic, readonly) KalturaMixingService* mixing;
@property (nonatomic, readonly) KalturaNotificationService* notification;
@property (nonatomic, readonly) KalturaPartnerService* partner;
@property (nonatomic, readonly) KalturaPermissionItemService* permissionItem;
@property (nonatomic, readonly) KalturaPermissionService* permission;
@property (nonatomic, readonly) KalturaPlaylistService* playlist;
@property (nonatomic, readonly) KalturaReportService* report;
@property (nonatomic, readonly) KalturaSchemaService* schema;
@property (nonatomic, readonly) KalturaSearchService* search;
@property (nonatomic, readonly) KalturaSessionService* session;
@property (nonatomic, readonly) KalturaStatsService* stats;
@property (nonatomic, readonly) KalturaStorageProfileService* storageProfile;
@property (nonatomic, readonly) KalturaSyndicationFeedService* syndicationFeed;
@property (nonatomic, readonly) KalturaSystemService* system;
@property (nonatomic, readonly) KalturaThumbAssetService* thumbAsset;
@property (nonatomic, readonly) KalturaThumbParamsService* thumbParams;
@property (nonatomic, readonly) KalturaUiConfService* uiConf;
@property (nonatomic, readonly) KalturaUploadService* upload;
@property (nonatomic, readonly) KalturaUploadTokenService* uploadToken;
@property (nonatomic, readonly) KalturaUserRoleService* userRole;
@property (nonatomic, readonly) KalturaUserService* user;
@property (nonatomic, readonly) KalturaWidgetService* widget;
@property (nonatomic, readonly) KalturaXInternalService* xInternal;
@end

