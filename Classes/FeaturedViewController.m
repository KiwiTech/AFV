//
//  FeaturedViewController.m
//  AFV
//
//  Created by Kaveh G. on 2/1/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "FeaturedViewController.h"
#import "VideoItem.h"
#import "GenericXMLParser.h"
#import "CachedImageView.h"
#import "MoviePlayerViewController.h"
#import "FavoritesDB.h"
#import "FacebookManager.h"
#import <QuartzCore/QuartzCore.h>

#define featured_item_count		20

@interface FeaturedViewController()

- (VideoItem*)currentVideoItem;
- (void)updateViewForCurrentSelection;
- (void)loadPage;
-(void)asyncDataReady;


@end



@implementation FeaturedViewController

@synthesize titleLabel;
@synthesize scrollView;
@synthesize leftButton;
@synthesize rightButton;
@synthesize playButton;
@synthesize facebookButton;
@synthesize favoriteButton;
@synthesize reloadButton;
@synthesize loadingView;

@synthesize items;


#pragma mark -
#pragma mark Helper methods

- (VideoItem*)currentVideoItem
{
	if(currentPageIndex >= 0 && currentPageIndex < items.count)
		return (VideoItem*)[items objectAtIndex:currentPageIndex];
	else
		return nil;
	
}

- (void)updateViewForCurrentSelection
{
	
	VideoItem* currentVideoItem = [self currentVideoItem];
	
	if (currentVideoItem) {
		titleLabel.text = currentVideoItem.title;
		
		favoriteButton.selected = [FavoritesDB isFavorite:currentVideoItem];
	}
}

- (void)loadPage
{
	
	if (items.count == 0) {
		
		// hide all subviews
		for(UIView* subview in [self.view subviews])
			subview.hidden = YES;
		
		// Add loading View
		if (loadingView) {
			
			[self.view addSubview:loadingView];
			loadingView.hidden = NO;
			
			// Get the data
			[NSThread detachNewThreadSelector:@selector(asynchDataDownloadThread) toTarget:self withObject:nil];
			
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
	if(items && items.count > 0)
	{
		
		// Populate the scrollview
		int count = 0;
		for(VideoItem* videoItem in items)
		{
			CachedImageView* imageView = [[CachedImageView alloc] initWithFrame:self.scrollView.frame activityInidcatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
			CGRect frame = imageView.frame;
			frame.origin.y = 0;
			frame.origin.x = frame.size.width * count++;
			imageView.frame = frame;
			imageView.contentMode = UIViewContentModeScaleToFill;
			[imageView loadCachedImageWithImageUrl:videoItem.thumbnailUrl usingMaxImageSize:default_image_size];
			[scrollView addSubview:imageView];
			[imageView release];
			
		}
		
		self.scrollView.contentSize = CGSizeMake(items.count * scrollView.frame.size.width, 10);
		currentPageIndex = 0;
		
		// hide the reload button
		reloadButton.hidden = YES;
		
		// unhide all subviews
		for(UIView* subview in [self.view subviews])
			subview.hidden = NO;
		
		// go to selected page
		scrollView.contentOffset = CGPointMake(currentPageIndex * 320, 0);
				
		[self updateViewForCurrentSelection];

	}
	else {
		
		// show the reload button
		reloadButton.hidden = NO;

		
		UIAlertView *alert = [[UIAlertView alloc]
							  initWithTitle:@"Connection Error"
							  message:@"Data was not received from the server. Please try again later." 
							  delegate:nil
							  cancelButtonTitle:@"OK"
							  otherButtonTitles:nil];
		
		[alert performSelectorOnMainThread:@selector(show) withObject:nil waitUntilDone:NO];
		[alert release];		
		
	}

	
	[self.loadingView removeFromSuperview];
		
}


-(void)asynchDataDownloadThread
{
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	@synchronized(self)
	{
		GenericXMLParser* parser = nil;
		
		@try {
			
			// Get the channels
			NSURL* url = [NSURL URLWithString:@"http://cdn.abc.go.com/ugv/filters?showKey=SH000168930000"];
			parser = [[GenericXMLParser alloc] initWithURL:url ignoring:nil treatAsProperty:nil];
			NSArray* channels = [[[[parser parse] objectForKey:CHILDREN_KEY] objectAtIndex:0] objectForKey:CHILDREN_KEY];
			[parser release];
			parser = nil;
			
			// Get the Featured channel
			for(NSDictionary* channel in channels)
			{
				if([[channel valueForKey:TEXT_KEY] isEqualToString:@"Fan Favorites"])
				{
					url = [NSURL URLWithString:[NSString stringWithFormat:@"http://cdn.abc.go.com/ugv/mdf?ugvVideoId=336124&fv=%@&start=0&limit=%d&ff=m3u8", [channel valueForKey:@"id"], featured_item_count]];
					
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

					
					parser = [[GenericXMLParser alloc] initWithURL:url ignoring:ignoreList treatAsProperty:treatAsAttributeList];
					NSArray* videoItems = [[[[parser parse] objectForKey:CHILDREN_KEY] objectAtIndex:0] objectForKey:CHILDREN_KEY];
					
					self.items = [NSMutableArray arrayWithCapacity:videoItems.count];
					
					// generate the data objects
					for(NSDictionary* videoDic in videoItems)
					{
						VideoItem* item = [[VideoItem alloc] init];
						
						item.ABCSiteURL = [videoDic valueForKey:@"link"];
						
						NSDictionary* mediaContent = [[videoDic objectForKey:CHILDREN_KEY] objectAtIndex:0];
						if([[mediaContent valueForKey:@"warning"] isEqualToString:@"TRANSCODE_FAILURE"])
							continue;
						
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
					}
					
					
					break;
				}
				
			}
			
			// Done downlaoding, update the UI
			[self performSelectorOnMainThread:@selector(asyncDataReady) withObject:nil waitUntilDone:NO];
			
		}
		@catch (NSException * e) {
			
			UIAlertView *alert = [[UIAlertView alloc]
								  initWithTitle:@"Connection Error"
								  message:@"A server connection could not be established. Please try again later." 
								  delegate:nil
								  cancelButtonTitle:@"OK"
								  otherButtonTitles:nil];
			
			[alert performSelectorOnMainThread:@selector(show) withObject:nil waitUntilDone:NO];
			[alert release];		
			
		}
		@finally {
			
			if(parser)
				[parser release];
		}
		
		
	}
	
	[pool release];
	
}




#pragma mark -
#pragma mark View loading

- (void)viewDidLoad {
    [super viewDidLoad];
	
	// add rounded corners to loading view
	loadingView.layer.cornerRadius = 8.0;
	
	[self loadPage];	
}

- (void)viewWillAppear:(BOOL)animated
{
	[super viewWillAppear:animated];
	
	[self updateViewForCurrentSelection];
}


#pragma mark -
#pragma mark UIScrollViewDelegate methods

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollview
{
	currentPageIndex = scrollView.contentOffset.x / scrollView.frame.size.width;
	
	if(currentPageIndex < 0)
		currentPageIndex = 0;
	
	if(currentPageIndex > items.count-1)
		currentPageIndex = items.count-1;
	
	rightButton.enabled = YES;	
	leftButton.enabled = YES;
	
	if(currentPageIndex == 0)
		leftButton.enabled = NO;
	else if(currentPageIndex == items.count-1)
		rightButton.enabled = NO;
	
	[self updateViewForCurrentSelection];

}

#pragma mark -
#pragma mark UI Actions

-(IBAction)leftButtonAction:(id)sender
{
	currentPageIndex--;
	
	if(currentPageIndex < 0)
		currentPageIndex = 0;
	
	
	[UIView beginAnimations:nil context:nil];
	[UIView setAnimationDuration:0.3];
	[UIView setAnimationBeginsFromCurrentState:YES];
	
	scrollView.contentOffset = CGPointMake(currentPageIndex * 320, 0);
	
	[UIView commitAnimations];
	
	
	rightButton.enabled = YES;	
	if(currentPageIndex == 0)
		leftButton.enabled = NO;
	
	[self updateViewForCurrentSelection];

}

-(IBAction)rightButtonAction:(id)sender
{
	
	currentPageIndex++;
	
	if(currentPageIndex > items.count -1)
		currentPageIndex = items.count -1;
	

	[UIView beginAnimations:nil context:nil];
	[UIView setAnimationDuration:0.3];
	[UIView setAnimationBeginsFromCurrentState:YES];
	
	scrollView.contentOffset = CGPointMake(currentPageIndex * 320, 0);
	
	[UIView commitAnimations];


	leftButton.enabled = YES;	
	if(currentPageIndex == items.count -1)
		rightButton.enabled = NO;
	
	[self updateViewForCurrentSelection];

}

-(IBAction)playButtonAction:(id)sender
{
	VideoItem* videoItem = [self currentVideoItem];
	
	if(videoItem)
	{
		MoviePlayerViewController* moviePlayer = [[MoviePlayerViewController alloc] initWithContentURL:[NSURL URLWithString:videoItem.videoUrl]];
		[self presentMoviePlayerViewControllerAnimated:moviePlayer];
		[moviePlayer release];
	}
	
}


-(IBAction)facebookButtonAction:(id)sender
{
	
	VideoItem* videoItem = [self currentVideoItem];
	
	if(videoItem)
	{
		
		NSArray* actionLinks = [NSArray arrayWithObjects:[NSDictionary dictionaryWithObjectsAndKeys:
															   @"Watch this video",@"name",videoItem.ABCSiteURL,@"link", nil], nil];
		
		SBJSON *jsonWriter = [SBJSON new];
		NSString *actionLinksStr = [jsonWriter stringWithObject:actionLinks];
		[jsonWriter release];
		
		NSMutableDictionary* params = [NSMutableDictionary dictionaryWithObjectsAndKeys:
									   @"What's on your mind?",  @"user_message_prompt",
									   actionLinksStr, @"actions",
									   [NSString stringWithFormat:@"<b>%@</b>", videoItem.title], @"name",
									   videoItem.ABCSiteURL, @"link",
									   [NSString stringWithFormat:@"%@", videoItem.description], @"description",
									   videoItem.thumbnailUrl, @"picture",
									   nil];
		
		[[FacebookManager sharedInstance] updateFacebookFeedWithParams:params];
		
	}
	
}

-(IBAction)favoritesButtonAction:(id)sender
{
	favoriteButton.selected = !favoriteButton.selected;
	
	if(favoriteButton.selected)
	{
		[FavoritesDB addFavorite:[self currentVideoItem]];
		
	}else {
		[FavoritesDB removeFavorite:[self currentVideoItem]];
	}

	
}

-(IBAction)reloadButtonAction:(id)sender
{
	
	reloadButton.hidden = YES;
	[self loadPage];
	
}

#pragma mark -
#pragma mark Controller Memory Management

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
}

- (void)viewDidUnload {
    [super viewDidUnload];

	self.titleLabel = nil;
	self.scrollView = nil;
	self.leftButton = nil;
	self.rightButton = nil;
	self.playButton = nil;
	self.facebookButton = nil;
	self.favoriteButton = nil;
	self.reloadButton = nil;
	self.loadingView = nil;
}


- (void)dealloc {
    [super dealloc];
	
	[titleLabel release];
	[scrollView release];
	[leftButton release];
	[rightButton release];
	[playButton release];
	[facebookButton release];
	[favoriteButton release];
	[reloadButton release];
	[loadingView release];
	
	[items release];
}


@end
