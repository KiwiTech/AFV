//
//  VideoDetailViewController.m
//  AFV
//
//  Created by Kaveh G. on 2/1/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "VideoDetailViewController.h"
#import "MoviePlayerViewController.h"
#import "FavoritesDB.h"
#import "FacebookManager.h"
#import "AFVAppDelegate.h"

@implementation VideoDetailViewController

@synthesize titleLabel;
@synthesize descriptonLabel;
@synthesize thumbnailImageView;
@synthesize playButton;
@synthesize facebookButton;
@synthesize favoriteButton;

@synthesize videoItem;
@synthesize webView;



#pragma mark -
#pragma mark View loading

- (void)viewDidLoad {
    [super viewDidLoad];

    for (id view in [webView subviews]) {
        if ([view isKindOfClass:[UIScrollView class]]) {
            [(UIScrollView*)view setBounces:FALSE];
        }
    }
    
	self.navigationItem.title = @"Video Details";
	self.titleLabel.text = videoItem.title;
	self.descriptonLabel.text = videoItem.description;

	self.thumbnailImageView.contentMode = UIViewContentModeScaleToFill;
	self.thumbnailImageView.loadingIndicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleWhiteLarge;
	[self.thumbnailImageView loadCachedImageWithImageUrl:videoItem.thumbnailUrl usingMaxImageSize:default_image_size];
    
    NSString *html = [NSString stringWithFormat:embedHTML, videoItem.videoUrl, webView.frame.size.width, webView.frame.size.height];
    [webView loadHTMLString:html baseURL:nil];
    
    [AFVAppDelegate insertAdInController:self atOffset:369];
	
}

- (void)viewWillAppear:(BOOL)animated
{
	[super viewWillAppear:animated];
	
	// Set favorites button state
	favoriteButton.selected = [FavoritesDB isFavorite:videoItem];
	
}
	
	

#pragma mark -
#pragma mark UI Actions


-(IBAction)playButtonAction:(id)sender
{
	MoviePlayerViewController* moviePlayer = [[MoviePlayerViewController alloc] initWithContentURL:[NSURL URLWithString:videoItem.videoUrl]];
	[self presentMoviePlayerViewControllerAnimated:moviePlayer];
	[moviePlayer release];
	
}

-(IBAction)facebookButtonAction:(id)sender
{
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
		[FavoritesDB addFavorite:videoItem];
		
	}else {
		[FavoritesDB removeFavorite:videoItem];
	}
	
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
	self.descriptonLabel = nil;
	self.thumbnailImageView = nil;
	self.playButton = nil;
	self.facebookButton = nil;
	self.favoriteButton = nil;
	
}


- (void)dealloc {
    [super dealloc];
	
	[titleLabel release];
	[descriptonLabel release];
	[thumbnailImageView release];
	[playButton release];
	[facebookButton release];
	[favoriteButton release];
	[webView release];
	[videoItem release];
}


@end
