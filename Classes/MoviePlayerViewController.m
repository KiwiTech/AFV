    //
//  MoviePlayerViewController.m
//  AFV
//
//  Created by Kaveh on 2/12/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "MoviePlayerViewController.h"


@implementation MoviePlayerViewController

@synthesize loadingView;

#pragma mark -
#pragma mark Loading

- (id)initWithContentURL:(NSURL *)contentURL
{
	if(self = [super initWithContentURL:contentURL])
	{
		
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(moviePlayerContentPreloadDidFinish:) name:MPMediaPlaybackIsPreparedToPlayDidChangeNotification object:self.moviePlayer];
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(moviePlayerPlaybackDidFinishNotification:) name:MPMoviePlayerPlaybackDidFinishNotification object:self.moviePlayer];

		return self;
	}
	
	return nil;
	
}


- (void)viewDidLoad {
    [super viewDidLoad];
	
	[[NSBundle mainBundle] loadNibNamed:@"MoviePlayerViewControllerLoadingView" owner:self options:nil];
	loadingView.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin;
	[self.view addSubview:loadingView];
	
}

#pragma mark -
#pragma mark UI Actions

- (IBAction)doneActioin:(id)sender
{
	[self.parentViewController dismissMoviePlayerViewControllerAnimated];
	
}

#pragma mark -
#pragma mark Notifications

-(void)moviePlayerContentPreloadDidFinish:(NSNotification*)notification
{
	[loadingView removeFromSuperview];
	self.loadingView = nil;
}

-(void)moviePlayerPlaybackDidFinishNotification:(NSNotification*)notification
{
	if(notification.object == self.moviePlayer)
	{
		NSNumber* reason = [notification.userInfo objectForKey:MPMoviePlayerPlaybackDidFinishReasonUserInfoKey];
		
		if ([reason intValue] == MPMovieFinishReasonPlaybackError) {
			
			UIAlertView *alert = [[UIAlertView alloc]
								  initWithTitle:@"Video Playback Error"
								  message:@"This video is either no longer available or cannot be accessed at this time."
								  delegate:nil
								  cancelButtonTitle:@"OK"
								  otherButtonTitles:nil];
			
			[alert show];
			[alert release];		
			
			[self performSelector:@selector(doneActioin:) withObject:nil afterDelay:0.5];
		}
		
	}
	
}

#pragma mark -
#pragma mark Cleanup

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc. that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
	
	self.loadingView = nil;
	
}


- (void)dealloc {
	
	[[NSNotificationCenter defaultCenter] removeObserver:self name:MPMediaPlaybackIsPreparedToPlayDidChangeNotification object:nil];
	[[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerPlaybackDidFinishNotification object:nil];
	[loadingView release];
	
    [super dealloc];
}


@end
