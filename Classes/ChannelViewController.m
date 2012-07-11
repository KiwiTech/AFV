//
//  ChannelViewController.m
//  AFV
//
//  Created by Kaveh G. on 2/8/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "ChannelViewController.h"
#import "GenericXMLParser.h"
#import "LoadingCell.h"
#import "MoviePlayerViewController.h"
#import "VideoItem.h"
#import "VideoDetailViewController.h"

#define load_increments		15


@interface ChannelViewController()

-(void)asyncDataReady;

@end


@implementation ChannelViewController

@synthesize items;
@synthesize channelID;
@synthesize videoCount;

#pragma mark -
#pragma mark View lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];

	
	if(items.count == 0)
	{
		if(self.channelID)
		{
			// Load the data
			loadingData = YES;
			[NSThread detachNewThreadSelector:@selector(asynchDataDownloadThread) toTarget:self withObject:nil];
		}
		else {
			
			UIAlertView *alert = [[UIAlertView alloc]
								  initWithTitle:@"Connection Error"
								  message:@"The selected channel could not be found. Please try again later." 
								  delegate:nil
								  cancelButtonTitle:@"OK"
								  otherButtonTitles:nil];
			
			[alert show];
			[alert release];		
			
		}
	}
	else {
		[self asyncDataReady];
	}

}


#pragma mark -
#pragma mark Data loading and parsing


-(void)asyncDataReady
{
	loadingData = NO;

	// No content available.
	if (self.items.count == 0)
	{
		// if we are part of a visible chain
		if ([self parentViewController])
		{
		
			UIAlertView *alert = [[UIAlertView alloc]
								  initWithTitle:@"Connection Error"
								  message:@"Content for this channel could not be retrieved at this time. Please try again later." 
								  delegate:nil
								  cancelButtonTitle:@"OK"
								  otherButtonTitles:nil];
			
			[alert show];
			[alert release];		
		}
	}
	
	[self.tableView reloadData];
}


-(void)asynchDataDownloadThread
{
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	@synchronized(self)
	{
		
		NSURL* url = [NSURL URLWithString:[NSString stringWithFormat:@"http://cdn.abc.go.com/ugv/mdf?ugvVideoId=336124&fv=%@&start=%d&limit=%d&ff=m3u8", channelID, self.items.count + errorStartOffset,load_increments]];
		
		NSArray* ignoreList = [NSArray arrayWithObjects:
							   @"/rss/channel/title",
							   @"/rss/channel/description",
							   @"/rss/channel/lastBuildDate",
							   @"/rss/channel/link",
							   @"/rss/channel/item/title",
							   @"/rss/channel/item/guid",
							   @"/rss/channel/item/media:content/media:rating",
							   @"/rss/channel/item/media:content/dcterms:valid",
							   nil];
		
		NSArray* treatAsAttributeList = [NSArray arrayWithObjects:
										 @"/rss/channel/item/link",
										 nil];
		
		GenericXMLParser* parser = [[GenericXMLParser alloc] initWithURL:url ignoring:ignoreList treatAsProperty:treatAsAttributeList];
		
		@try {

			NSArray* videoItems = [[[[parser parse] objectForKey:CHILDREN_KEY] objectAtIndex:0] objectForKey:CHILDREN_KEY];
			
			// Couldn't load more items
			if (self.items.count > 0 && videoItems.count == 0)
			{
				// if we are part of a visible chain
				if ([self parentViewController])
				{
					
					UIAlertView *alert = [[UIAlertView alloc]
										  initWithTitle:@"Connection Error"
										  message:@"Additional content for this channel could not be retrieved at this time. Please try again later." 
										  delegate:nil
										  cancelButtonTitle:@"OK"
										  otherButtonTitles:nil];
					
					[alert performSelectorOnMainThread:@selector(show) withObject:nil waitUntilDone:NO];
					[alert release];		
				}
			}
			
			
			if(!items)
				self.items = [NSMutableArray arrayWithCapacity:videoItems.count];
			
			// generate the data objects
			for(NSDictionary* videoDic in videoItems)
			{
				VideoItem* item = [[VideoItem alloc] init];
				
				item.ABCSiteURL = [videoDic valueForKey:@"link"];

				NSDictionary* mediaContent = [[videoDic objectForKey:CHILDREN_KEY] objectAtIndex:0];
				if([[mediaContent valueForKey:@"warning"] isEqualToString:@"TRANSCODE_FAILURE"])
				{
					videoCount--;
					errorStartOffset++;
					continue;
				}

				item.videoUrl = [[mediaContent valueForKey:@"url"] stringByReplacingOccurrencesOfString:@"&amp;" withString:@"&"];
				
				for(NSDictionary* dic in [mediaContent objectForKey:CHILDREN_KEY])
				{
					if([[dic valueForKey:ELEMENT_KEY] isEqualToString:@"media:title"])
						item.title = [dic valueForKey:TEXT_KEY];
					
					else if([[dic valueForKey:ELEMENT_KEY] isEqualToString:@"media:description"])
						item.description = [dic valueForKey:TEXT_KEY];
					
					else if([[dic valueForKey:ELEMENT_KEY] isEqualToString:@"media:thumbnail"])
						item.thumbnailUrl= [[dic valueForKey:@"url"] stringByReplacingOccurrencesOfString:@"&amp;" withString:@"&"];
				}
				
				[items addObject:item];
				[item release];
			}
			
		}
		@catch (NSException * e) {
			
			// if we are part of a visible chain
			if ([self parentViewController])
			{
				
				UIAlertView *alert = [[UIAlertView alloc]
									  initWithTitle:@"Connection Error"
									  message:@"A server connection could not be established. Please try again later." 
									  delegate:nil
									  cancelButtonTitle:@"OK"
									  otherButtonTitles:nil];
				
				[alert performSelectorOnMainThread:@selector(show) withObject:nil waitUntilDone:NO];
				[alert release];
			}
			
		}
		@finally {
			
			[self performSelectorOnMainThread:@selector(asyncDataReady) withObject:nil waitUntilDone:NO];
			[parser release];
		}
		
		
	}
	
	[pool release];
	
}


#pragma mark -
#pragma mark Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    // Return the number of sections.
    return 1;
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {

    if(items.count == 0)
		return 3;
	else
		return (items.count < videoCount)?items.count+1:items.count;
}


// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
	static NSString *emptyCellIdentifier = @"EmptyCellIdentifier";
    static NSString *loadingCellIdentifier = @"LoadingCellIdentifier";
    static NSString *videoItemCellIdentifier = @"VideoItemCellIdentifier";
	
	if(items.count == 0)
	{
		if(indexPath.row == 2)
		{
			LoadingCell *cell = (LoadingCell*)[tableView dequeueReusableCellWithIdentifier:loadingCellIdentifier];
			if (cell == nil) {
				
				NSArray * nib = [[NSBundle mainBundle] loadNibNamed:@"LoadingCell" owner:nil options:nil];
				for (id oneObject in nib) {
					if ([oneObject isKindOfClass:[LoadingCell class]]) {
						cell = (LoadingCell*)oneObject;
					}
				}
				
			}
			
			if(loadingData)
			{
				cell.loadingLabel.text = @"Loading...";
				[cell.activityIndicator startAnimating];
				cell.selectionStyle = UITableViewCellSelectionStyleNone;

			}
			else {
				
				cell.loadingLabel.text = @"Reload Content";
				[cell.activityIndicator stopAnimating];
				cell.selectionStyle = UITableViewCellSelectionStyleBlue;
			}
			
			[cell resizeContent];
			
			return cell;
		}
		
		UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:emptyCellIdentifier];
		if (cell == nil) {
			
			cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:emptyCellIdentifier] autorelease];
		}
		
		cell.selectionStyle = UITableViewCellSelectionStyleNone;
		return cell;
		
		
	}
	else
	{
		if(items.count > 0 && indexPath.row == items.count)
		{
			LoadingCell *cell = (LoadingCell*)[tableView dequeueReusableCellWithIdentifier:loadingCellIdentifier];
			if (cell == nil) {
				
				NSArray * nib = [[NSBundle mainBundle] loadNibNamed:@"LoadingCell" owner:nil options:nil];
				for (id oneObject in nib) {
					if ([oneObject isKindOfClass:[LoadingCell class]]) {
						cell = (LoadingCell*)oneObject;
					}
				}
				
			}
			
			if(!loadingData)
			{
				cell.loadingLabel.text = @"Load More...";
				[cell.activityIndicator stopAnimating];
			}
			else {
				
				cell.loadingLabel.text = @"Loading...";
				[cell.activityIndicator startAnimating];
				
			}

			cell.selectionStyle = UITableViewCellSelectionStyleBlue;
			[cell resizeContent];

			return cell;
			
		}
		else
		{
			VideoItemCell *cell = (VideoItemCell*)[tableView dequeueReusableCellWithIdentifier:videoItemCellIdentifier];
			if (cell == nil) {
				
				NSArray * nib = [[NSBundle mainBundle] loadNibNamed:@"VideoItemCell" owner:nil options:nil];
				for (id oneObject in nib) {
					if ([oneObject isKindOfClass:[VideoItemCell class]]) {
						cell = (VideoItemCell*)oneObject;
						cell.cachedImageView.delegate = cell;
						cell.delegate = self;
					}
				}
				
			}
			
			
			VideoItem* item = [self.items objectAtIndex:indexPath.row];
			cell.titleLabel.text = item.title;
			cell.descriptionLabel.text = item.description;
			[cell.cachedImageView reset];
			cell.cachedImageView.fadeInOnUpdate = NO;
			[cell.cachedImageView loadCachedImageWithImageUrl:item.thumbnailUrl usingMaxImageSize:CGSizeMake(96, 72)];
			
			
			
			return cell;
		}
		
	}
}




#pragma mark -
#pragma mark Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {

	if(items.count == 0)
	{
		LoadingCell* cell = (LoadingCell*)[tableView cellForRowAtIndexPath:indexPath];
		if([cell isKindOfClass:[LoadingCell class]])
		{
			if(!loadingData)
			{
				loadingData = YES;
				
				cell.loadingLabel.text = @"Loading...";
				[cell.activityIndicator startAnimating];
				[cell performSelector:@selector(setSelectionStyle:) withObject:UITableViewCellSelectionStyleNone afterDelay:0.5];
				[cell resizeContent];

				// Load more data
				[NSThread detachNewThreadSelector:@selector(asynchDataDownloadThread) toTarget:self withObject:nil];
			}
			
			[tableView deselectRowAtIndexPath:indexPath animated:YES];
		}
		
	}
	else
	{
		LoadingCell* cell = (LoadingCell*)[tableView cellForRowAtIndexPath:indexPath];
		if([cell isKindOfClass:[LoadingCell class]])
		{
			if(!loadingData)
			{
				loadingData = YES;
				
				cell.loadingLabel.text = @"Loading...";
				[cell.activityIndicator startAnimating];
				[cell resizeContent];
								
				// Load more data
				[NSThread detachNewThreadSelector:@selector(asynchDataDownloadThread) toTarget:self withObject:nil];
			}
			
			[tableView deselectRowAtIndexPath:indexPath animated:YES];

		}
		else
		{
			VideoItem* item = [self.items objectAtIndex:indexPath.row];
			MoviePlayerViewController* moviePlayer = [[MoviePlayerViewController alloc] initWithContentURL:[NSURL URLWithString:item.videoUrl]];
			[self presentMoviePlayerViewControllerAnimated:moviePlayer];
			[moviePlayer release];
		}
	}
	
}

#pragma mark -
#pragma mark VideoItemCellDelegate methods


- (void)accessoryButtonActionWithEvent:(UIEvent*)event
{
	UITouch *touch = [[event allTouches] anyObject];
	CGPoint touchPosition = [touch locationInView:self.tableView];

	NSIndexPath *indexPath = [self.tableView indexPathForRowAtPoint:touchPosition];
	VideoItem* videoItem = [self.items objectAtIndex:indexPath.row];

	VideoDetailViewController* videoDetailViewController = [[VideoDetailViewController alloc] initWithNibName:@"VideoDetailViewController" bundle:nil];
	videoDetailViewController.videoItem = videoItem;
	[self.navigationController pushViewController:videoDetailViewController animated:YES];
	[videoDetailViewController release];
	
}



#pragma mark -
#pragma mark Memory management

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];

}

- (void)viewDidUnload {
    // Relinquish ownership of anything that can be recreated in viewDidLoad or on demand.
    // For example: self.myOutlet = nil;
}


- (void)dealloc {
	
	[items release];
	[channelID release];
	
    [super dealloc];
}


@end

