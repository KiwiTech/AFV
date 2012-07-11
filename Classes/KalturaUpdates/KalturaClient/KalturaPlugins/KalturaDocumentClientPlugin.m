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
#import "KalturaDocumentClientPlugin.h"

///////////////////////// enums /////////////////////////
@implementation KalturaDocumentEntryOrderBy
+ (NSString*)NAME_ASC
{
    return @"+name";
}
+ (NSString*)NAME_DESC
{
    return @"-name";
}
+ (NSString*)MODERATION_COUNT_ASC
{
    return @"+moderationCount";
}
+ (NSString*)MODERATION_COUNT_DESC
{
    return @"-moderationCount";
}
+ (NSString*)CREATED_AT_ASC
{
    return @"+createdAt";
}
+ (NSString*)CREATED_AT_DESC
{
    return @"-createdAt";
}
+ (NSString*)UPDATED_AT_ASC
{
    return @"+updatedAt";
}
+ (NSString*)UPDATED_AT_DESC
{
    return @"-updatedAt";
}
+ (NSString*)RANK_ASC
{
    return @"+rank";
}
+ (NSString*)RANK_DESC
{
    return @"-rank";
}
+ (NSString*)START_DATE_ASC
{
    return @"+startDate";
}
+ (NSString*)START_DATE_DESC
{
    return @"-startDate";
}
+ (NSString*)END_DATE_ASC
{
    return @"+endDate";
}
+ (NSString*)END_DATE_DESC
{
    return @"-endDate";
}
+ (NSString*)PARTNER_SORT_VALUE_ASC
{
    return @"+partnerSortValue";
}
+ (NSString*)PARTNER_SORT_VALUE_DESC
{
    return @"-partnerSortValue";
}
@end

@implementation KalturaDocumentFlavorParamsOrderBy
@end

@implementation KalturaDocumentFlavorParamsOutputOrderBy
@end

@implementation KalturaDocumentType
+ (int)DOCUMENT
{
    return 11;
}
+ (int)SWF
{
    return 12;
}
+ (int)PDF
{
    return 13;
}
@end

@implementation KalturaPdfFlavorParamsOrderBy
@end

@implementation KalturaPdfFlavorParamsOutputOrderBy
@end

@implementation KalturaSwfFlavorParamsOrderBy
@end

@implementation KalturaSwfFlavorParamsOutputOrderBy
@end

///////////////////////// classes /////////////////////////
@implementation KalturaDocumentFlavorParamsOutputBaseFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentFlavorParamsOutputBaseFilter"];
}

@end

@implementation KalturaDocumentFlavorParamsOutputFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentFlavorParamsOutputFilter"];
}

@end

@implementation KalturaPdfFlavorParamsOutputBaseFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaPdfFlavorParamsOutputBaseFilter"];
}

@end

@implementation KalturaPdfFlavorParamsOutputFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaPdfFlavorParamsOutputFilter"];
}

@end

@implementation KalturaSwfFlavorParamsOutputBaseFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaSwfFlavorParamsOutputBaseFilter"];
}

@end

@implementation KalturaSwfFlavorParamsOutputFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaSwfFlavorParamsOutputFilter"];
}

@end

@implementation KalturaDocumentFlavorParamsBaseFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentFlavorParamsBaseFilter"];
}

@end

@implementation KalturaDocumentFlavorParamsFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentFlavorParamsFilter"];
}

@end

@implementation KalturaPdfFlavorParamsBaseFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaPdfFlavorParamsBaseFilter"];
}

@end

@implementation KalturaPdfFlavorParamsFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaPdfFlavorParamsFilter"];
}

@end

@implementation KalturaSwfFlavorParamsBaseFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaSwfFlavorParamsBaseFilter"];
}

@end

@implementation KalturaSwfFlavorParamsFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaSwfFlavorParamsFilter"];
}

@end

@implementation KalturaDocumentEntryBaseFilter
@synthesize documentTypeEqual = _documentTypeEqual;
@synthesize documentTypeIn = _documentTypeIn;
@synthesize assetParamsIdsMatchOr = _assetParamsIdsMatchOr;
@synthesize assetParamsIdsMatchAnd = _assetParamsIdsMatchAnd;

- (id)init
{
    self = [super init];
    if (self == nil)
        return nil;
    self->_documentTypeEqual = KALTURA_UNDEF_INT;
    return self;
}

- (KalturaFieldType)getTypeOfDocumentTypeEqual
{
    return KFT_Int;
}

- (KalturaFieldType)getTypeOfDocumentTypeIn
{
    return KFT_String;
}

- (KalturaFieldType)getTypeOfAssetParamsIdsMatchOr
{
    return KFT_String;
}

- (KalturaFieldType)getTypeOfAssetParamsIdsMatchAnd
{
    return KFT_String;
}

- (void)setDocumentTypeEqualFromString:(NSString*)aPropVal
{
    self.documentTypeEqual = [KalturaSimpleTypeParser parseInt:aPropVal];
}

- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentEntryBaseFilter"];
    [aParams addIfDefinedKey:@"documentTypeEqual" withInt:self.documentTypeEqual];
    [aParams addIfDefinedKey:@"documentTypeIn" withString:self.documentTypeIn];
    [aParams addIfDefinedKey:@"assetParamsIdsMatchOr" withString:self.assetParamsIdsMatchOr];
    [aParams addIfDefinedKey:@"assetParamsIdsMatchAnd" withString:self.assetParamsIdsMatchAnd];
}

- (void)dealloc
{
    [self->_documentTypeIn release];
    [self->_assetParamsIdsMatchOr release];
    [self->_assetParamsIdsMatchAnd release];
    [super dealloc];
}

@end

@implementation KalturaDocumentEntryFilter
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentEntryFilter"];
}

@end

@interface KalturaDocumentEntry()
@property (nonatomic,copy) NSString* assetParamsIds;
@end

@implementation KalturaDocumentEntry
@synthesize documentType = _documentType;
@synthesize assetParamsIds = _assetParamsIds;

- (id)init
{
    self = [super init];
    if (self == nil)
        return nil;
    self->_documentType = KALTURA_UNDEF_INT;
    return self;
}

- (KalturaFieldType)getTypeOfDocumentType
{
    return KFT_Int;
}

- (KalturaFieldType)getTypeOfAssetParamsIds
{
    return KFT_String;
}

- (void)setDocumentTypeFromString:(NSString*)aPropVal
{
    self.documentType = [KalturaSimpleTypeParser parseInt:aPropVal];
}

- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentEntry"];
    [aParams addIfDefinedKey:@"documentType" withInt:self.documentType];
}

- (void)dealloc
{
    [self->_assetParamsIds release];
    [super dealloc];
}

@end

@implementation KalturaDocumentFlavorParamsOutput
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentFlavorParamsOutput"];
}

@end

@implementation KalturaPdfFlavorParamsOutput
@synthesize readonly = _readonly;

- (id)init
{
    self = [super init];
    if (self == nil)
        return nil;
    self->_readonly = KALTURA_UNDEF_BOOL;
    return self;
}

- (KalturaFieldType)getTypeOfReadonly
{
    return KFT_Bool;
}

- (void)setReadonlyFromString:(NSString*)aPropVal
{
    self.readonly = [KalturaSimpleTypeParser parseBool:aPropVal];
}

- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaPdfFlavorParamsOutput"];
    [aParams addIfDefinedKey:@"readonly" withBool:self.readonly];
}

@end

@implementation KalturaSwfFlavorParamsOutput
@synthesize flashVersion = _flashVersion;
@synthesize poly2Bitmap = _poly2Bitmap;

- (id)init
{
    self = [super init];
    if (self == nil)
        return nil;
    self->_flashVersion = KALTURA_UNDEF_INT;
    self->_poly2Bitmap = KALTURA_UNDEF_BOOL;
    return self;
}

- (KalturaFieldType)getTypeOfFlashVersion
{
    return KFT_Int;
}

- (KalturaFieldType)getTypeOfPoly2Bitmap
{
    return KFT_Bool;
}

- (void)setFlashVersionFromString:(NSString*)aPropVal
{
    self.flashVersion = [KalturaSimpleTypeParser parseInt:aPropVal];
}

- (void)setPoly2BitmapFromString:(NSString*)aPropVal
{
    self.poly2Bitmap = [KalturaSimpleTypeParser parseBool:aPropVal];
}

- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaSwfFlavorParamsOutput"];
    [aParams addIfDefinedKey:@"flashVersion" withInt:self.flashVersion];
    [aParams addIfDefinedKey:@"poly2Bitmap" withBool:self.poly2Bitmap];
}

@end

@implementation KalturaDocumentFlavorParams
- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentFlavorParams"];
}

@end

@implementation KalturaPdfFlavorParams
@synthesize readonly = _readonly;

- (id)init
{
    self = [super init];
    if (self == nil)
        return nil;
    self->_readonly = KALTURA_UNDEF_BOOL;
    return self;
}

- (KalturaFieldType)getTypeOfReadonly
{
    return KFT_Bool;
}

- (void)setReadonlyFromString:(NSString*)aPropVal
{
    self.readonly = [KalturaSimpleTypeParser parseBool:aPropVal];
}

- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaPdfFlavorParams"];
    [aParams addIfDefinedKey:@"readonly" withBool:self.readonly];
}

@end

@implementation KalturaSwfFlavorParams
@synthesize flashVersion = _flashVersion;
@synthesize poly2Bitmap = _poly2Bitmap;

- (id)init
{
    self = [super init];
    if (self == nil)
        return nil;
    self->_flashVersion = KALTURA_UNDEF_INT;
    self->_poly2Bitmap = KALTURA_UNDEF_BOOL;
    return self;
}

- (KalturaFieldType)getTypeOfFlashVersion
{
    return KFT_Int;
}

- (KalturaFieldType)getTypeOfPoly2Bitmap
{
    return KFT_Bool;
}

- (void)setFlashVersionFromString:(NSString*)aPropVal
{
    self.flashVersion = [KalturaSimpleTypeParser parseInt:aPropVal];
}

- (void)setPoly2BitmapFromString:(NSString*)aPropVal
{
    self.poly2Bitmap = [KalturaSimpleTypeParser parseBool:aPropVal];
}

- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaSwfFlavorParams"];
    [aParams addIfDefinedKey:@"flashVersion" withInt:self.flashVersion];
    [aParams addIfDefinedKey:@"poly2Bitmap" withBool:self.poly2Bitmap];
}

@end

@interface KalturaDocumentListResponse()
@property (nonatomic,retain) NSMutableArray* objects;
@property (nonatomic,assign) int totalCount;
@end

@implementation KalturaDocumentListResponse
@synthesize objects = _objects;
@synthesize totalCount = _totalCount;

- (id)init
{
    self = [super init];
    if (self == nil)
        return nil;
    self->_totalCount = KALTURA_UNDEF_INT;
    return self;
}

- (KalturaFieldType)getTypeOfObjects
{
    return KFT_Array;
}

- (NSString*)getObjectTypeOfObjects
{
    return @"KalturaDocumentEntry";
}

- (KalturaFieldType)getTypeOfTotalCount
{
    return KFT_Int;
}

- (void)setTotalCountFromString:(NSString*)aPropVal
{
    self.totalCount = [KalturaSimpleTypeParser parseInt:aPropVal];
}

- (void)toParams:(KalturaParams*)aParams isSuper:(BOOL)aIsSuper
{
    [super toParams:aParams isSuper:YES];
    if (!aIsSuper)
        [aParams putKey:@"objectType" withString:@"KalturaDocumentListResponse"];
}

- (void)dealloc
{
    [self->_objects release];
    [super dealloc];
}

@end

///////////////////////// services /////////////////////////
@implementation KalturaDocumentsService
- (KalturaDocumentEntry*)addFromUploadedFileWithDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry withUploadTokenId:(NSString*)aUploadTokenId
{
    [self.client.params addIfDefinedKey:@"documentEntry" withObject:aDocumentEntry];
    [self.client.params addIfDefinedKey:@"uploadTokenId" withString:aUploadTokenId];
    return [self.client queueObjectService:@"document_documents" withAction:@"addFromUploadedFile" withExpectedType:@"KalturaDocumentEntry"];
}

- (KalturaDocumentEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId withDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry withSourceFlavorParamsId:(int)aSourceFlavorParamsId
{
    [self.client.params addIfDefinedKey:@"sourceEntryId" withString:aSourceEntryId];
    [self.client.params addIfDefinedKey:@"documentEntry" withObject:aDocumentEntry];
    [self.client.params addIfDefinedKey:@"sourceFlavorParamsId" withInt:aSourceFlavorParamsId];
    return [self.client queueObjectService:@"document_documents" withAction:@"addFromEntry" withExpectedType:@"KalturaDocumentEntry"];
}

- (KalturaDocumentEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId withDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry
{
    return [self addFromEntryWithSourceEntryId:aSourceEntryId withDocumentEntry:aDocumentEntry withSourceFlavorParamsId:KALTURA_UNDEF_INT];
}

- (KalturaDocumentEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId
{
    return [self addFromEntryWithSourceEntryId:aSourceEntryId withDocumentEntry:nil];
}

- (KalturaDocumentEntry*)addFromFlavorAssetWithSourceFlavorAssetId:(NSString*)aSourceFlavorAssetId withDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry
{
    [self.client.params addIfDefinedKey:@"sourceFlavorAssetId" withString:aSourceFlavorAssetId];
    [self.client.params addIfDefinedKey:@"documentEntry" withObject:aDocumentEntry];
    return [self.client queueObjectService:@"document_documents" withAction:@"addFromFlavorAsset" withExpectedType:@"KalturaDocumentEntry"];
}

- (KalturaDocumentEntry*)addFromFlavorAssetWithSourceFlavorAssetId:(NSString*)aSourceFlavorAssetId
{
    return [self addFromFlavorAssetWithSourceFlavorAssetId:aSourceFlavorAssetId withDocumentEntry:nil];
}

- (int)convertWithEntryId:(NSString*)aEntryId withConversionProfileId:(int)aConversionProfileId withDynamicConversionAttributes:(NSArray*)aDynamicConversionAttributes
{
    [self.client.params addIfDefinedKey:@"entryId" withString:aEntryId];
    [self.client.params addIfDefinedKey:@"conversionProfileId" withInt:aConversionProfileId];
    [self.client.params addIfDefinedKey:@"dynamicConversionAttributes" withArray:aDynamicConversionAttributes];
    return [self.client queueIntService:@"document_documents" withAction:@"convert"];
}

- (int)convertWithEntryId:(NSString*)aEntryId withConversionProfileId:(int)aConversionProfileId
{
    return [self convertWithEntryId:aEntryId withConversionProfileId:aConversionProfileId withDynamicConversionAttributes:nil];
}

- (int)convertWithEntryId:(NSString*)aEntryId
{
    return [self convertWithEntryId:aEntryId withConversionProfileId:KALTURA_UNDEF_INT];
}

- (KalturaDocumentEntry*)getWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion
{
    [self.client.params addIfDefinedKey:@"entryId" withString:aEntryId];
    [self.client.params addIfDefinedKey:@"version" withInt:aVersion];
    return [self.client queueObjectService:@"document_documents" withAction:@"get" withExpectedType:@"KalturaDocumentEntry"];
}

- (KalturaDocumentEntry*)getWithEntryId:(NSString*)aEntryId
{
    return [self getWithEntryId:aEntryId withVersion:KALTURA_UNDEF_INT];
}

- (KalturaDocumentEntry*)updateWithEntryId:(NSString*)aEntryId withDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry
{
    [self.client.params addIfDefinedKey:@"entryId" withString:aEntryId];
    [self.client.params addIfDefinedKey:@"documentEntry" withObject:aDocumentEntry];
    return [self.client queueObjectService:@"document_documents" withAction:@"update" withExpectedType:@"KalturaDocumentEntry"];
}

- (void)deleteWithEntryId:(NSString*)aEntryId
{
    [self.client.params addIfDefinedKey:@"entryId" withString:aEntryId];
    [self.client queueVoidService:@"document_documents" withAction:@"delete"];
}

- (KalturaDocumentListResponse*)listWithFilter:(KalturaDocumentEntryFilter*)aFilter withPager:(KalturaFilterPager*)aPager
{
    [self.client.params addIfDefinedKey:@"filter" withObject:aFilter];
    [self.client.params addIfDefinedKey:@"pager" withObject:aPager];
    return [self.client queueObjectService:@"document_documents" withAction:@"list" withExpectedType:@"KalturaDocumentListResponse"];
}

- (KalturaDocumentListResponse*)listWithFilter:(KalturaDocumentEntryFilter*)aFilter
{
    return [self listWithFilter:aFilter withPager:nil];
}

- (KalturaDocumentListResponse*)list
{
    return [self listWithFilter:nil];
}

- (NSString*)uploadWithFileData:(NSString*)aFileData
{
    [self.client.params addIfDefinedKey:@"fileData" withFileName:aFileData];
    return [self.client queueStringService:@"document_documents" withAction:@"upload"];
}

- (NSString*)convertPptToSwfWithEntryId:(NSString*)aEntryId
{
    [self.client.params addIfDefinedKey:@"entryId" withString:aEntryId];
    return [self.client queueStringService:@"document_documents" withAction:@"convertPptToSwf"];
}

- (NSString*)serveWithEntryId:(NSString*)aEntryId withFlavorAssetId:(NSString*)aFlavorAssetId withForceProxy:(BOOL)aForceProxy
{
    [self.client.params addIfDefinedKey:@"entryId" withString:aEntryId];
    [self.client.params addIfDefinedKey:@"flavorAssetId" withString:aFlavorAssetId];
    [self.client.params addIfDefinedKey:@"forceProxy" withBool:aForceProxy];
    return [self.client queueServeService:@"document_documents" withAction:@"serve"];
}

- (NSString*)serveWithEntryId:(NSString*)aEntryId withFlavorAssetId:(NSString*)aFlavorAssetId
{
    return [self serveWithEntryId:aEntryId withFlavorAssetId:aFlavorAssetId withForceProxy:KALTURA_UNDEF_BOOL];
}

- (NSString*)serveWithEntryId:(NSString*)aEntryId
{
    return [self serveWithEntryId:aEntryId withFlavorAssetId:nil];
}

- (NSString*)serveByFlavorParamsIdWithEntryId:(NSString*)aEntryId withFlavorParamsId:(NSString*)aFlavorParamsId withForceProxy:(BOOL)aForceProxy
{
    [self.client.params addIfDefinedKey:@"entryId" withString:aEntryId];
    [self.client.params addIfDefinedKey:@"flavorParamsId" withString:aFlavorParamsId];
    [self.client.params addIfDefinedKey:@"forceProxy" withBool:aForceProxy];
    return [self.client queueServeService:@"document_documents" withAction:@"serveByFlavorParamsId"];
}

- (NSString*)serveByFlavorParamsIdWithEntryId:(NSString*)aEntryId withFlavorParamsId:(NSString*)aFlavorParamsId
{
    return [self serveByFlavorParamsIdWithEntryId:aEntryId withFlavorParamsId:aFlavorParamsId withForceProxy:KALTURA_UNDEF_BOOL];
}

- (NSString*)serveByFlavorParamsIdWithEntryId:(NSString*)aEntryId
{
    return [self serveByFlavorParamsIdWithEntryId:aEntryId withFlavorParamsId:nil];
}

@end

@implementation KalturaDocumentClientPlugin
@synthesize client = _client;

- (id)initWithClient:(KalturaClient*)aClient
{
    self = [super init];
    if (self == nil)
        return nil;
    self.client = aClient;
    return self;
}

- (KalturaDocumentsService*)documents
{
    if (self->_documents == nil)
    	self->_documents = [[KalturaDocumentsService alloc] initWithClient:self.client];
    return self->_documents;
}

- (void)dealloc
{
    [self->_documents release];
	[super dealloc];
}

@end

