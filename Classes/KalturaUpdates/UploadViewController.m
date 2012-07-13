//
//  UploadViewController.m
//  AFV
//
//  Created by Kaveh G. on 2/3/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "UploadViewController.h"
#import <MobileCoreServices/MobileCoreServices.h>
#import "LoginViewController.h"
#import "AFVAppDelegate.h"
#import <MediaPlayer/MediaPlayer.h>

@interface UploadViewController(private)

- (void) presentImagePickerWithType:(UIImagePickerControllerSourceType)type;

@end

@implementation UploadViewController(private)

- (void) presentImagePickerWithType:(UIImagePickerControllerSourceType)type
{
    
	UIImagePickerController *pickerController = [[UIImagePickerController alloc] init];
    pickerController.sourceType = type;
    pickerController.mediaTypes = [[NSArray alloc] initWithObjects: (NSString*)kUTTypeMovie, nil];
    pickerController.allowsEditing = YES;
    pickerController.videoQuality = UIImagePickerControllerQualityTypeMedium;
	pickerController.delegate = self;
	pickerController.videoMaximumDuration = 1200; // 20 minutes
	
	if([((AFVAppDelegate*)[UIApplication sharedApplication].delegate).internetReachability currentReachabilityStatus] == ReachableViaWWAN)
	{
		pickerController.videoQuality = UIImagePickerControllerQualityTypeLow;
		pickerController.videoMaximumDuration = 600; // 10 minutes

	}
	
    [self presentModalViewController: pickerController animated: YES];
	[pickerController release];
	
}


@end

@implementation UploadViewController

@synthesize loginButton;
@synthesize webLinkButton;
@synthesize shootVideoButton;
@synthesize uploadExistingVideoButton;
@synthesize loginView;
@synthesize videoOptionsView;


#pragma mark -
#pragma mark ABCRegistrationViewDelegate methods

- (void)updateView
{
    if ([[NSUserDefaults standardUserDefaults] objectForKey:@"userPassword"]) {
        if ([[Client instance] login])
        {
            //[[NSUserDefaults standardUserDefaults] removeObjectForKey:@"userEmail"];
            [[NSUserDefaults standardUserDefaults] removeObjectForKey:@"userPassword"];
            [[NSUserDefaults standardUserDefaults] synchronize];

            loginView.hidden = YES;
            videoOptionsView.center = self.view.center;
            
            // detect camera availability
            shootVideoButton.enabled =	[UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]&&
            [[UIImagePickerController availableMediaTypesForSourceType:UIImagePickerControllerSourceTypeCamera] containsObject:(NSString*) kUTTypeMovie];
            
            // detect video album availability
            uploadExistingVideoButton.enabled = [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeSavedPhotosAlbum] &&
            [[UIImagePickerController availableMediaTypesForSourceType:UIImagePickerControllerSourceTypeSavedPhotosAlbum] containsObject:(NSString*) kUTTypeMovie];
        }
    }	
}


#pragma mark -
#pragma mark View loading

- (void)viewDidLoad {
    [super viewDidLoad];

	shouldPresentVideoDetailView = NO;
	
}

- (void)viewWillAppear:(BOOL)animated
{
	[super viewWillAppear:animated];
	
	[self updateView];	
}


- (void)viewDidAppear:(BOOL)animated
{
	[super viewDidAppear:animated];

	// present the video detail view if we need to
	if (shouldPresentVideoDetailView) {
		
		shouldPresentVideoDetailView = NO;
		
		// Present the view
		if (uploadVideoDetailViewController) {
			[self.navigationController presentModalViewController:uploadVideoDetailViewController animated:YES];
			[uploadVideoDetailViewController release];
		}
		
	}
	
}


#pragma mark -
#pragma mark UI Actions

-(IBAction)loginButtonAction:(id)sender
{
	LoginViewController* loginViewController = [[LoginViewController alloc] initWithNibName:@"LoginViewController" bundle:nil];
	[self presentModalViewController:loginViewController animated:YES];
	[loginViewController release];
	
}
-(IBAction)webLinkButtonAction:(id)sender
{
    NSArray *topLevelObjects = [[NSBundle mainBundle] loadNibNamed:@"KalturaRegistrationView" owner:nil options:nil];
	if (topLevelObjects && topLevelObjects.count > 0 && [[topLevelObjects objectAtIndex:0] isKindOfClass:[KalturaRegistrationView class]]) {
        
        KalturaRegistrationView* kalturaRegistrationView = [topLevelObjects objectAtIndex:0];
		
		UIWindow* window = [UIApplication sharedApplication].keyWindow;
		if (!window) {
			window = [[UIApplication sharedApplication].windows objectAtIndex:0];
		}
		
		[window addSubview:kalturaRegistrationView];
  
    }
		
}
-(IBAction)shootVideoButtonAction:(id)sender
{
	[self presentImagePickerWithType:UIImagePickerControllerSourceTypeCamera];
}
-(IBAction)uploadExistingVideoButtonAction:(id)sender
{
	[self presentImagePickerWithType:UIImagePickerControllerSourceTypeSavedPhotosAlbum];
	
}

#pragma mark -
#pragma mark UIImagePickerControllerDelegate methods

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
	
	NSURL* fileURL = [info objectForKey:UIImagePickerControllerMediaURL];
	NSString* filePath = [fileURL path];
	
	NSFileManager* fileManager = [[NSFileManager alloc] init];
	NSError* error = nil;
	NSDictionary* fileInfo = [fileManager attributesOfItemAtPath:filePath error:&error];
	[fileManager release];
	
	unsigned long long maxFileSize = ([((AFVAppDelegate*)[UIApplication sharedApplication].delegate).internetReachability currentReachabilityStatus] == ReachableViaWWAN)?15:300;
	maxFileSize *= 1024*1024; // in bytes

	if([[fileInfo objectForKey:@"NSFileSize"] unsignedLongLongValue] > maxFileSize)
	{
		UIAlertView *alert = [[UIAlertView alloc]
							  initWithTitle:@"File Size Error"
							  message:@"The selected video file is too large. Please select a smaller clip." 
							  delegate:nil
							  cancelButtonTitle:@"OK"
							  otherButtonTitles:nil];
		
		[alert performSelectorOnMainThread:@selector(show) withObject:nil waitUntilDone:NO];
		[alert release];		
		
	}
	else {

		shouldPresentVideoDetailView = YES;
		
		uploadVideoDetailViewController = [[UploadVideoDetailViewController alloc] initWithNibName:@"UploadVideoDetailViewController" bundle:nil];		

		// Set video file URL
		uploadVideoDetailViewController.videoFileURL = fileURL;
		
		// Generate and set the thumbnail
		MPMoviePlayerController* moviePlayer = [[MPMoviePlayerController alloc] initWithContentURL:fileURL];
		uploadVideoDetailViewController.videoThumbnail = [moviePlayer thumbnailImageAtTime:0 timeOption:MPMovieTimeOptionNearestKeyFrame];
		[moviePlayer pause];
		moviePlayer.initialPlaybackTime = -1;
		[moviePlayer release];
		

		// Save the movie to the camera roll if we shoot a new video
		if(![info objectForKey:UIImagePickerControllerReferenceURL])
			UISaveVideoAtPathToSavedPhotosAlbum(filePath, nil, nil, NULL);

	}
		
	[picker dismissModalViewControllerAnimated:YES];

}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
	[self dismissModalViewControllerAnimated: YES];

}




#pragma mark -
#pragma mark View cleanup

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc. that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];

	self.loginButton = nil;
	self.webLinkButton = nil;
	self.shootVideoButton = nil;
	self.uploadExistingVideoButton = nil;
	self.loginView = nil;
	self.videoOptionsView = nil;
}


- (void)dealloc {
    [super dealloc];
	
	[loginButton release];
	[webLinkButton release];
	[shootVideoButton release];
	[uploadExistingVideoButton release];
	[loginView release];
	[videoOptionsView release];

}


@end
