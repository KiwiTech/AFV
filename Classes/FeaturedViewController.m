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
#import "AFVAppDelegate.h"

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
	
    items = [[NSMutableArray alloc] init];
    
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
            UIWebView* webView = [[UIWebView alloc] initWithFrame:self.scrollView.frame];

            for (id view in [webView subviews]) {
               if ([view isKindOfClass:[UIScrollView class]]) {
                    [(UIScrollView*)view setBounces:FALSE];
                    }
            }
            
            CGRect frame = webView.frame;
			frame.origin.y = 0;
			frame.origin.x = frame.size.width * count++;
			webView.frame = frame;
			webView.contentMode = UIViewContentModeScaleToFill;

            NSString *html = [NSString stringWithFormat:embedHTML, videoItem.videoUrl, frame.size.width, frame.size.height];
            [webView loadHTMLString:html baseURL:nil];

			[scrollView addSubview:webView];
			[webView release];
			
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
		@try {
			
            NSMutableArray* videoFeedArray = [[NSMutableArray alloc] init];
            
//          NSString* searchString = @"https://gdata.youtube.com/feeds/api/videos?q=afvofficial&feature=results_main&orderby=published&start-index=1&max-results=40&v=1";
                

            NSString* searchString = @"http://gdata.youtube.com/feeds/api/users/afvofficial/uploads?orderby=published&start-index=1&max-results=20&alt=json&v=2";
            
            NSString* escapedUrlString =[searchString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];

			NSURL *feedURL = [[NSURL alloc] initWithString:escapedUrlString];
            
            NSString *responseString = [NSString stringWithContentsOfURL:feedURL encoding:NSStringEncodingConversionAllowLossy error:nil];
                              
            NSError *error;
            SBJSON *json = [[SBJSON new] autorelease];
            NSDictionary *dataDictionary = [json objectWithString:responseString error:&error];
            [videoFeedArray addObjectsFromArray:[[dataDictionary objectForKey:@"feed"] objectForKey:@"entry"]];

			for(NSInteger i=0;i<[videoFeedArray count];i++) {
               
                NSDictionary *videoDict = [videoFeedArray objectAtIndex:i];
                
                if([[[[videoDict objectForKey:@"app$control"] objectForKey:@"yt$state"] objectForKey:@"name"] isEqualToString:@"restricted"]) {
                    continue;
                }
                
                VideoItem* videoItem = [[VideoItem alloc] init];
                videoItem.title = [[[videoDict objectForKey:@"media$group"] objectForKey:@"media$title"] objectForKey:@"$t"];
                
                videoItem.videoUrl = [[[videoDict objectForKey:@"link"] objectAtIndex:0] objectForKey:@"href"];
                NSString *tagString = [[[videoDict objectForKey:@"media$group"] objectForKey:@"media$description"] objectForKey:@"$t"];
                tagString = [tagString stringByReplacingOccurrencesOfString:@"\n\n" withString:@" "];
                videoItem.description = [tagString stringByReplacingOccurrencesOfString:@"\n" withString:@" "];
           
                [items addObject:videoItem];
                [videoItem release];
            }

            [videoFeedArray release];
						
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
	}
	
	[pool release];
	
}




#pragma mark -
#pragma mark View loading

- (void)viewDidLoad {
    [super viewDidLoad];
	
	// add rounded corners to loading view
	loadingView.layer.cornerRadius = 8.0;
	
    [AFVAppDelegate insertAdInController:self atOffset:369];
    
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
															   @"Watch this video",@"name",videoItem.videoUrl,@"link", nil], nil];
		
		SBJSON *jsonWriter = [SBJSON new];
		NSString *actionLinksStr = [jsonWriter stringWithObject:actionLinks];
		[jsonWriter release];
		
		NSMutableDictionary* params = [NSMutableDictionary dictionaryWithObjectsAndKeys:
									   @"What's on your mind?",  @"user_message_prompt",
									   actionLinksStr, @"actions",
									   [NSString stringWithFormat:@"<b>%@</b>", videoItem.title], @"name",
									   videoItem.videoUrl, @"link",
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
