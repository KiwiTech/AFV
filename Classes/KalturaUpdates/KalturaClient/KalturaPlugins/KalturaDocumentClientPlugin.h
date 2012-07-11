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
@interface KalturaDocumentEntryOrderBy : NSObject
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

@interface KalturaDocumentFlavorParamsOrderBy : NSObject
@end

@interface KalturaDocumentFlavorParamsOutputOrderBy : NSObject
@end

@interface KalturaDocumentType : NSObject
+ (int)DOCUMENT;
+ (int)SWF;
+ (int)PDF;
@end

@interface KalturaPdfFlavorParamsOrderBy : NSObject
@end

@interface KalturaPdfFlavorParamsOutputOrderBy : NSObject
@end

@interface KalturaSwfFlavorParamsOrderBy : NSObject
@end

@interface KalturaSwfFlavorParamsOutputOrderBy : NSObject
@end

///////////////////////// classes /////////////////////////
@interface KalturaDocumentFlavorParamsOutputBaseFilter : KalturaFlavorParamsOutputFilter
@end

@interface KalturaDocumentFlavorParamsOutputFilter : KalturaDocumentFlavorParamsOutputBaseFilter
@end

@interface KalturaPdfFlavorParamsOutputBaseFilter : KalturaFlavorParamsOutputFilter
@end

@interface KalturaPdfFlavorParamsOutputFilter : KalturaPdfFlavorParamsOutputBaseFilter
@end

@interface KalturaSwfFlavorParamsOutputBaseFilter : KalturaFlavorParamsOutputFilter
@end

@interface KalturaSwfFlavorParamsOutputFilter : KalturaSwfFlavorParamsOutputBaseFilter
@end

@interface KalturaDocumentFlavorParamsBaseFilter : KalturaFlavorParamsFilter
@end

@interface KalturaDocumentFlavorParamsFilter : KalturaDocumentFlavorParamsBaseFilter
@end

@interface KalturaPdfFlavorParamsBaseFilter : KalturaFlavorParamsFilter
@end

@interface KalturaPdfFlavorParamsFilter : KalturaPdfFlavorParamsBaseFilter
@end

@interface KalturaSwfFlavorParamsBaseFilter : KalturaFlavorParamsFilter
@end

@interface KalturaSwfFlavorParamsFilter : KalturaSwfFlavorParamsBaseFilter
@end

@interface KalturaDocumentEntryBaseFilter : KalturaBaseEntryFilter
@property (nonatomic,assign) int documentTypeEqual;	// enum KalturaDocumentType
@property (nonatomic,copy) NSString* documentTypeIn;
@property (nonatomic,copy) NSString* assetParamsIdsMatchOr;
@property (nonatomic,copy) NSString* assetParamsIdsMatchAnd;
- (KalturaFieldType)getTypeOfDocumentTypeEqual;
- (KalturaFieldType)getTypeOfDocumentTypeIn;
- (KalturaFieldType)getTypeOfAssetParamsIdsMatchOr;
- (KalturaFieldType)getTypeOfAssetParamsIdsMatchAnd;
- (void)setDocumentTypeEqualFromString:(NSString*)aPropVal;
@end

@interface KalturaDocumentEntryFilter : KalturaDocumentEntryBaseFilter
@end

@interface KalturaDocumentEntry : KalturaBaseEntry
// The type of the document
@property (nonatomic,assign) int documentType;	// enum KalturaDocumentType, insertonly
// Comma separated asset params ids that exists for this media entry
@property (nonatomic,copy,readonly) NSString* assetParamsIds;
- (KalturaFieldType)getTypeOfDocumentType;
- (KalturaFieldType)getTypeOfAssetParamsIds;
- (void)setDocumentTypeFromString:(NSString*)aPropVal;
@end

@interface KalturaDocumentFlavorParamsOutput : KalturaFlavorParamsOutput
@end

@interface KalturaPdfFlavorParamsOutput : KalturaFlavorParamsOutput
@property (nonatomic,assign) BOOL readonly;
- (KalturaFieldType)getTypeOfReadonly;
- (void)setReadonlyFromString:(NSString*)aPropVal;
@end

@interface KalturaSwfFlavorParamsOutput : KalturaFlavorParamsOutput
@property (nonatomic,assign) int flashVersion;
@property (nonatomic,assign) BOOL poly2Bitmap;
- (KalturaFieldType)getTypeOfFlashVersion;
- (KalturaFieldType)getTypeOfPoly2Bitmap;
- (void)setFlashVersionFromString:(NSString*)aPropVal;
- (void)setPoly2BitmapFromString:(NSString*)aPropVal;
@end

@interface KalturaDocumentFlavorParams : KalturaFlavorParams
@end

@interface KalturaPdfFlavorParams : KalturaFlavorParams
@property (nonatomic,assign) BOOL readonly;
- (KalturaFieldType)getTypeOfReadonly;
- (void)setReadonlyFromString:(NSString*)aPropVal;
@end

@interface KalturaSwfFlavorParams : KalturaFlavorParams
@property (nonatomic,assign) int flashVersion;
@property (nonatomic,assign) BOOL poly2Bitmap;
- (KalturaFieldType)getTypeOfFlashVersion;
- (KalturaFieldType)getTypeOfPoly2Bitmap;
- (void)setFlashVersionFromString:(NSString*)aPropVal;
- (void)setPoly2BitmapFromString:(NSString*)aPropVal;
@end

@interface KalturaDocumentListResponse : KalturaObjectBase
@property (nonatomic,retain,readonly) NSMutableArray* objects;	// of KalturaDocumentEntry elements
@property (nonatomic,assign,readonly) int totalCount;
- (KalturaFieldType)getTypeOfObjects;
- (NSString*)getObjectTypeOfObjects;
- (KalturaFieldType)getTypeOfTotalCount;
- (void)setTotalCountFromString:(NSString*)aPropVal;
@end

///////////////////////// services /////////////////////////
// Document service lets you upload and manage document files
@interface KalturaDocumentsService : KalturaServiceBase
// Add new document entry after the specific document file was uploaded and the upload token id exists
- (KalturaDocumentEntry*)addFromUploadedFileWithDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry withUploadTokenId:(NSString*)aUploadTokenId;
// Copy entry into new entry
- (KalturaDocumentEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId withDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry withSourceFlavorParamsId:(int)aSourceFlavorParamsId;
- (KalturaDocumentEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId withDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry;
- (KalturaDocumentEntry*)addFromEntryWithSourceEntryId:(NSString*)aSourceEntryId;
// Copy flavor asset into new entry
- (KalturaDocumentEntry*)addFromFlavorAssetWithSourceFlavorAssetId:(NSString*)aSourceFlavorAssetId withDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry;
- (KalturaDocumentEntry*)addFromFlavorAssetWithSourceFlavorAssetId:(NSString*)aSourceFlavorAssetId;
// Convert entry
- (int)convertWithEntryId:(NSString*)aEntryId withConversionProfileId:(int)aConversionProfileId withDynamicConversionAttributes:(NSArray*)aDynamicConversionAttributes;
- (int)convertWithEntryId:(NSString*)aEntryId withConversionProfileId:(int)aConversionProfileId;
- (int)convertWithEntryId:(NSString*)aEntryId;
// Get document entry by ID.
- (KalturaDocumentEntry*)getWithEntryId:(NSString*)aEntryId withVersion:(int)aVersion;
- (KalturaDocumentEntry*)getWithEntryId:(NSString*)aEntryId;
// Update document entry. Only the properties that were set will be updated.
- (KalturaDocumentEntry*)updateWithEntryId:(NSString*)aEntryId withDocumentEntry:(KalturaDocumentEntry*)aDocumentEntry;
// Delete a document entry.
- (void)deleteWithEntryId:(NSString*)aEntryId;
// List document entries by filter with paging support.
- (KalturaDocumentListResponse*)listWithFilter:(KalturaDocumentEntryFilter*)aFilter withPager:(KalturaFilterPager*)aPager;
- (KalturaDocumentListResponse*)listWithFilter:(KalturaDocumentEntryFilter*)aFilter;
- (KalturaDocumentListResponse*)list;
// Upload a document file to Kaltura, then the file can be used to create a document entry.
// DEPRECATED - use upload.upload or uploadToken.add instead
- (NSString*)uploadWithFileData:(NSString*)aFileData;
// This will queue a batch job for converting the document file to swf
// Returns the URL where the new swf will be available
- (NSString*)convertPptToSwfWithEntryId:(NSString*)aEntryId;
// Serves the file content
- (NSString*)serveWithEntryId:(NSString*)aEntryId withFlavorAssetId:(NSString*)aFlavorAssetId withForceProxy:(BOOL)aForceProxy;
- (NSString*)serveWithEntryId:(NSString*)aEntryId withFlavorAssetId:(NSString*)aFlavorAssetId;
- (NSString*)serveWithEntryId:(NSString*)aEntryId;
// Serves the file content
- (NSString*)serveByFlavorParamsIdWithEntryId:(NSString*)aEntryId withFlavorParamsId:(NSString*)aFlavorParamsId withForceProxy:(BOOL)aForceProxy;
- (NSString*)serveByFlavorParamsIdWithEntryId:(NSString*)aEntryId withFlavorParamsId:(NSString*)aFlavorParamsId;
- (NSString*)serveByFlavorParamsIdWithEntryId:(NSString*)aEntryId;
@end

@interface KalturaDocumentClientPlugin : KalturaClientPlugin
{
	KalturaDocumentsService* _documents;
}

@property (nonatomic, assign) KalturaClientBase* client;
@property (nonatomic, readonly) KalturaDocumentsService* documents;
@end

