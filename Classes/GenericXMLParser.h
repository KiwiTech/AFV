//
//  GenericXMLParser.h
//  PlayNetwork
//
//  Created by Kaveh G. on 8/13/10.
//  Copyright 2010 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>

#define CHILDREN_KEY  @"_children_"
#define TEXT_KEY  @"_text_"
#define ELEMENT_KEY  @"_Element_"


@interface GenericXMLParser : NSObject<NSXMLParserDelegate> {

	NSXMLParser* parser;
	
	NSArray* elementIgnorArray;
	NSArray* elementAsPropertyArray;
	NSString* currentElementAsProperty; 
	
	NSMutableDictionary* rootDictionary;
	NSMutableDictionary* currentDictionary;
	NSMutableArray* dictionaryStack;
	NSString* currentElementHierarchy;
}

@property(nonatomic, retain) NSArray* elementIgnorArray;
@property(nonatomic, retain) NSArray* elementAsPropertyArray;


- (id) initWithURL:(NSURL*) URL ignoring:(NSArray*)ignorList treatAsProperty:(NSArray*) treatAsPropertyList;
- (id) initWithData:(NSData*) data ignoring:(NSArray*)ignorList treatAsProperty:(NSArray*) treatAsPropertyList;
- (NSDictionary*) parse;

@end
