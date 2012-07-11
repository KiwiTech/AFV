//
//  GenericXMLParser.m
//  PlayNetwork
//
//  Created by Kaveh G. on 8/13/10.
//  Copyright 2010 Teleca. All rights reserved.
//

#import "GenericXMLParser.h"


@implementation GenericXMLParser

@synthesize elementIgnorArray;
@synthesize elementAsPropertyArray;

- (id) initWithURL:(NSURL*) URL ignoring:(NSArray*)ignorList treatAsProperty:(NSArray*) treatAsPropertyList
{
	if (self = [super init]) {
		
		parser = [[NSXMLParser alloc] initWithContentsOfURL:URL];
		[parser setDelegate:self];
				
		self.elementIgnorArray = ignorList;
		self.elementAsPropertyArray = treatAsPropertyList;
		
		currentElementHierarchy = @"";
		
		return self;
	}
	
	return nil;
	
}

- (id) initWithData:(NSData*) data ignoring:(NSArray*)ignorList treatAsProperty:(NSArray*) treatAsPropertyList
{
	if (self = [super init]) {
		
		parser = [[NSXMLParser alloc] initWithData:data];
		[parser setDelegate:self];
				
		self.elementIgnorArray = ignorList;
		self.elementAsPropertyArray = treatAsPropertyList;
		
		currentElementHierarchy = @"";
		
		return self;
	}
	
	return nil;
	
}


#ifdef DEBUG
- (void) printTreeStructure:(NSDictionary*) root
{
	if(!root)
		return;
	
	NSString* attribs = @"";
	NSArray* children = nil;
	
	for(NSString* key in [root allKeys])
	{
		id item = [root objectForKey:key];
		if([item isKindOfClass:[NSString class]])
			attribs =[attribs stringByAppendingFormat:@"%@ = %@   ", key, item];
		else
			children = item;
		
	}
	
	NSLog(@"%@",attribs);
	
	if (children) {
		for(NSDictionary* child in children)
			[self printTreeStructure:child];
		
	}
	
}
#endif


- (NSDictionary*) parse
{
	[parser parse];
	
	NSError* error = [parser parserError];
	if (error) {
		NSLog(@"%@",[error description]);
	}

#ifdef DEBUG
	[self printTreeStructure:rootDictionary];
#endif
	
		return rootDictionary;
}

- (BOOL) array:(NSArray*) array containsElementHierarchy:(NSString*) elementHierarchy
{

	for(NSString* string in array)
	{
		NSRange range = [elementHierarchy rangeOfString:string];
		if(range.length > 0 && range.location == 0)
			return YES;
	}
	
	return NO;
	
}

- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName attributes:(NSDictionary *)attributeDict
{	
	currentElementHierarchy = [currentElementHierarchy stringByAppendingFormat:@"/%@",elementName];
	
	if(!elementIgnorArray || (elementIgnorArray && ![self array:elementIgnorArray containsElementHierarchy:currentElementHierarchy]) )
	{
		
		if (!rootDictionary) {
			rootDictionary = [[NSMutableDictionary dictionaryWithDictionary:attributeDict] retain];
			currentDictionary = rootDictionary;
			dictionaryStack = [[NSMutableArray alloc] init];
			[dictionaryStack insertObject:rootDictionary atIndex:0];
		}
		else {
			
			if((!attributeDict || [attributeDict count] == 0) && elementAsPropertyArray && [elementAsPropertyArray containsObject:currentElementHierarchy])
			{
				currentElementAsProperty = elementName;
				
			}
			else
			{
				
				NSMutableArray* children = [currentDictionary objectForKey:CHILDREN_KEY];
				if(!children)
				{
					children = [NSMutableArray array];
					[currentDictionary setObject:children forKey:CHILDREN_KEY];
				}
				
				currentDictionary = [NSMutableDictionary dictionaryWithDictionary:attributeDict];
				[children addObject:currentDictionary];
				[dictionaryStack insertObject:currentDictionary atIndex:0];
			}
		}
		
		if(!currentElementAsProperty)
			[currentDictionary setObject:elementName forKey:ELEMENT_KEY];
	}
}

- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName
{
	
	if((!elementIgnorArray || (elementIgnorArray && ![self array:elementIgnorArray containsElementHierarchy:currentElementHierarchy])) && !currentElementAsProperty)
	{
		[dictionaryStack removeObjectAtIndex:0];
		if([dictionaryStack count] > 0)
			currentDictionary = [dictionaryStack objectAtIndex:0];
	}
	
	currentElementHierarchy = [currentElementHierarchy stringByDeletingLastPathComponent];
	currentElementAsProperty = nil;
	
	
}
- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string
{
	if(![string rangeOfString:@"\n"].location == 0)
	{
		if(!elementIgnorArray || (elementIgnorArray && ![self array:elementIgnorArray containsElementHierarchy:currentElementHierarchy]) )
		{
			if(currentElementAsProperty)
			{
				NSString* currentVal = nil;
				if(currentVal = [currentDictionary valueForKey:currentElementAsProperty])
					[currentDictionary setObject:[currentVal stringByAppendingString:string] forKey:currentElementAsProperty];
				else
					[currentDictionary setObject:string forKey:currentElementAsProperty];
			}
			else
			{
				NSString* currentVal = nil;
				if(currentVal = [currentDictionary valueForKey:TEXT_KEY])
					[currentDictionary setObject:[currentVal stringByAppendingString:string] forKey:TEXT_KEY];
				else
					[currentDictionary setObject:string forKey:TEXT_KEY];
				
			}
		}
	}
	
}


- (void)dealloc {
	
	
	[dictionaryStack release];
	[rootDictionary release];
	[parser release];
	
	[elementIgnorArray release];
	[elementAsPropertyArray release];
    [super dealloc];
}


@end
