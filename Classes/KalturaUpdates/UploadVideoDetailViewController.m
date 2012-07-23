//
//  UploadVideoDetailViewController.m
//  AFV
//
//  Created by Kaveh on 2/10/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "UploadVideoDetailViewController.h"
#import <MediaPlayer/MediaPlayer.h>
#import "GenericXMLParser.h"
#import "UploadConfirmationViewController.h"
#import <QuartzCore/QuartzCore.h>
#import "KalturaMetadataClientPlugin.h"

@implementation UploadVideoDetailViewController

@synthesize imageView;
@synthesize titleTextField;
@synthesize descriptionTextField;
@synthesize descriptionTextView;
@synthesize playButton;
@synthesize uploadProgressOverlayView;
@synthesize progressView;
@synthesize uploadButton;

@synthesize videoThumbnail;
@synthesize videoFileURL;
@synthesize userData;

//@synthesize cancelButton;
//@synthesize postRequest;


#pragma mark -
#pragma mark helper methods

- (void)exitEditMode
{
	[UIView beginAnimations:nil context:nil];
	[UIView setAnimationDuration:0.25];
	
	imageView.transform = CGAffineTransformIdentity;
	playButton.transform = CGAffineTransformIdentity;
	
	imageView.alpha = 1.0;
	playButton.alpha = 1.0;
	
	[UIView commitAnimations];
	
	
	
	[UIView beginAnimations:nil context:nil];
	[UIView setAnimationDuration:0.3];
	
	titleTextField.transform = CGAffineTransformIdentity;
	descriptionTextField.transform = CGAffineTransformIdentity;
	descriptionTextView.transform = CGAffineTransformIdentity;
	
	[UIView commitAnimations];
	
}


- (void)enterEditMode
{
	[UIView beginAnimations:nil context:nil];
	[UIView setAnimationDuration:0.25];
	
	imageView.transform = CGAffineTransformMakeScale(0.01, 0.01);
	playButton.transform = CGAffineTransformMakeScale(0.01, 0.01);
	
	imageView.alpha = 0.0;
	playButton.alpha = 0.0;
	
	[UIView commitAnimations];
	
	
	[UIView beginAnimations:nil context:nil];
	[UIView setAnimationDuration:0.3];
	
	titleTextField.transform = CGAffineTransformMakeTranslation(0.0, -180.0);
	descriptionTextField.transform = CGAffineTransformMakeTranslation(0.0, -180.0);
	descriptionTextView.transform = CGAffineTransformMakeTranslation(0.0, -180.0);
	
	[UIView commitAnimations];
	
}

#pragma mark -
#pragma mark View loading

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
	
	isTitleEmpty = YES;
	isDescriptionEmpty = YES;
	
	// Position the textview
	CGRect descriptionTextFieldFrame = descriptionTextField.frame;
	descriptionTextFieldFrame.size.height += 65;
	descriptionTextField.frame = descriptionTextFieldFrame;
	
	CGRect descriptionTextViewFrame = descriptionTextFieldFrame;
	descriptionTextViewFrame.origin.x += 1;
	descriptionTextViewFrame.origin.y += 3;
	descriptionTextViewFrame.size.width -= 2;
	descriptionTextViewFrame.size.height -= 4;
	descriptionTextView.frame = descriptionTextViewFrame;

	// user rounded corners
	descriptionTextView.layer.cornerRadius = 8.0;
	
	// Set video thumbnail
	imageView.image = videoThumbnail;

}



#pragma mark -
#pragma mark UI Actions

-(IBAction)playAction:(id)sender
{
	if(videoFileURL)
	{
		MPMoviePlayerViewController* moviePlayer = [[MPMoviePlayerViewController alloc] initWithContentURL:videoFileURL];
		[self presentMoviePlayerViewControllerAnimated:moviePlayer];
		[moviePlayer release];
	
	}
}

-(IBAction)uploadAction:(id)sender
{
	
	if ([titleTextField isFirstResponder])
	{
		[titleTextField resignFirstResponder];
		[self exitEditMode];
	}
	
	if ([descriptionTextView isFirstResponder])
	{
		[descriptionTextView resignFirstResponder];
		[self exitEditMode];
	}
	
	if(!isTitleEmpty && [titleTextField.text length] <= 80 && !isDescriptionEmpty && [descriptionTextView.text length] <= 255)
	{
		
		
		// disable the upload button
		uploadButton.enabled = NO;
		
		// put up the upload progress overlay
		uploadProgressOverlayView.hidden = NO;
		
		// start the upload process
        NSDictionary *contentDict = [NSDictionary dictionaryWithObjects:[NSArray arrayWithObjects:@"", titleTextField.text, descriptionTextView.text, @"", [self.videoFileURL path], nil] forKeys:[NSArray arrayWithObjects:@"category", @"title", @"description", @"tags", @"path", nil]];
        
		[self performSelector:@selector(uploadProcess:) withObject:contentDict afterDelay:0.2];
	}
	else { // handle input errors
		
		NSString* errorMessage = nil;

		if (isTitleEmpty) {
			errorMessage = @"Please provide a short title for your video.";
		}
		else if (isDescriptionEmpty) {
			errorMessage = @"Please provide a short description for your video.";
		}
		else if ([titleTextField.text length] > 80) {
			errorMessage = [NSString stringWithFormat:@"The title you provided is %u characters long. The video title must be at most 80 characters long.",[titleTextField.text length]];
		}		
		else if ([descriptionTextView.text length] > 255) {
			errorMessage = [NSString stringWithFormat:@"The description you provided is %u characters long. The video description must be at most 255 characters long.",[descriptionTextView.text length]];
		}
		
		
		UIAlertView *alert = [[UIAlertView alloc]
							  initWithTitle:@"Upload Error"
							  message:errorMessage
							  delegate:nil
							  cancelButtonTitle:@"OK"
							  otherButtonTitles:nil];
		
		[alert show];
		[alert release];		
		
	}
	
	
	
}


#pragma mark -
#pragma mark HTTPPostRequestDelegate methods

- (void)endUploading {
    
   if (token) {
        
        [token release];
        
    }
    uploadButton.enabled = YES;
    uploadProgressOverlayView.hidden = YES;
    KalturaClient *client = [Client instance].client;
    
    client.delegate = nil;
    client.uploadProgressDelegate = nil;
    
}

-(IBAction)cancelAction:(id)sender
{
    [[Client instance].client cancelRequest];
    
    [self endUploading];
    
    // empty out the text fields to get arround text size limit checks
    titleTextField.text = @"";
	descriptionTextView.text = @"";
	
    [self.navigationController popToRootViewControllerAnimated:NO];
	[self dismissModalViewControllerAnimated:YES];
}



- (void)request:(ASIHTTPRequest *)request didSendBytes:(long long)bytes {
    
    uploadedSize += bytes;
    
    progressView.progress = (float)(uploadedSize * 300 / fileSize) / 300.0;
    
}

- (void)requestFinished:(KalturaClientBase*)aClient withResult:(id)result {
    
    NSLog(@"requestFinished");
       
    //[self endUploading];

    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Upload Video" message:@"Thank You! Your video has been uploaded successfully." delegate:self
                                          cancelButtonTitle:@"OK"
                                          otherButtonTitles:nil];
    
    [alert show];
    [alert release];

}

- (void)requestFailed:(KalturaClientBase*)aClient {
    
    NSLog(@"requestFailed");
    [self endUploading];
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Upload Error" message:@"The video failed to upload. Please try again." delegate:nil
                          										  cancelButtonTitle:@"OK"
                          										  otherButtonTitles:nil];
                          					
    [alert show];
    [alert release];
        
}

#define ADMIN_SECRET (@"2fbce27a889eed321a3c5b951d85bc73")
#define PARTNER_ID (989031)
#define USER_ID    @"ANONYMOUS"
//([[NSUserDefaults standardUserDefaults] objectForKey:@"userEmail"])


- (void)uploadProcess:(NSDictionary *)data {
    
    //KalturaClient *client = [Client instance].client;
    
    KalturaClientConfiguration* config = [[KalturaClientConfiguration alloc] init];
    KalturaNSLogger* logger = [[KalturaNSLogger alloc] init];
    config.logger = logger;
    config.serviceUrl = DEFAULT_SERVICE_URL;
    [logger release];           // retained on config
    
    KalturaClient *client = [[KalturaClient alloc] initWithConfig:config];
    [config release];           // retained on the client
    
    KalturaUserService *service = [[KalturaUserService alloc] init];
    service.client = client;

    client.delegate = nil;
    
    client.ks = [KalturaClient generateSessionWithSecret:ADMIN_SECRET withUserId:USER_ID withType:[KalturaSessionType ADMIN] withPartnerId:PARTNER_ID withExpiry:86400 withPrivileges:@""];
    
    token = [[KalturaUploadToken alloc] init];
    token.fileName = @"video.m4v";
    token = [client.uploadToken addWithUploadToken:token];
    
    // return: object, params: object
    KalturaMediaEntry* entry = [[[KalturaMediaEntry alloc] init] autorelease];
    entry.name = [data objectForKey:@"title"];
    entry.mediaType = [KalturaMediaType VIDEO];
    entry.categories = [data objectForKey:@"category"];
    entry.description = [data objectForKey:@"description"];
    entry.tags = [data objectForKey:@"tags"];
    
    entry = [client.media addWithEntry:entry];
    
    // return: object, params: string, object
    KalturaUploadedFileTokenResource* resource = [[[KalturaUploadedFileTokenResource alloc] init] autorelease];
    resource.token = token.id;
    entry = [client.media addContentWithEntryId:entry.id withResource:resource];
   
    //Custom Data Upload
    KalturaMetadataClientPlugin *newClinet = [[KalturaMetadataClientPlugin alloc] init];
    KalturaMetadataFilter *filter = [[KalturaMetadataFilter alloc] init];
    filter.objectIdEqual = entry.id;
    filter.metadataObjectTypeEqual = [KalturaMetadataObjectType ENTRY];
    newClinet.client = client;
    KalturaMetadataListResponse *list = [newClinet.metadata listWithFilter:filter];
    NSMutableArray * thisArray = [list objects];
    KalturaMetadata *xnl = [thisArray objectAtIndex:0];
    NSString *newString = [NSString stringWithFormat:@"<metadata>"
    "<WorkflowStatus>For Review</WorkflowStatus>"
    "<UGCFirstName>%@</UGCFirstName>"
    "<UGCLastName>%@</UGCLastName>"
    "<UGCEmail>%@</UGCEmail>"
    "<UGCAdress>%@</UGCAdress>"
    "<UGCCity>%@</UGCCity>"
    "<UGCState>%@</UGCState>"
    "<UGCZipPostal>%@</UGCZipPostal>"
    "<UGCCountry>%@</UGCCountry>"
    "<UGCPhone>%@</UGCPhone>"
    "<UGCPhone2>%@</UGCPhone2>"
    "<UGCBirthDate>%@</UGCBirthDate>"
    "<UGCGender>%@</UGCGender>"
    "<WebID>%@</WebID>"
    "<SubmissionType>iPhone</SubmissionType>"
                           "</metadata>", userData.sFirstName, userData.sLastName, userData.sEmail, userData.sAddress, userData.sCity, userData.sState, userData.sZip, userData.sCountry, userData.sPhone1, ([userData.sPhone2 length] > 0) ? userData.sPhone2 : @"", userData.sBirthDate, userData.sGender, entry.id];

    [newClinet.metadata updateWithId:xnl.id withXmlData:newString];
    
    
    client.delegate = self;
    client.uploadProgressDelegate = self;
      
    NSDictionary *fileAttributes = [[NSFileManager defaultManager] attributesOfItemAtPath:[data objectForKey:@"path"] error:nil];
    
    NSNumber *fileSizeNumber = [fileAttributes objectForKey:NSFileSize];
    fileSize = [fileSizeNumber longLongValue];
    uploadedSize = 0;
    token = [client.uploadToken uploadWithUploadTokenId:token.id withFileData:[data objectForKey:@"path"]];
  
 
    
    
}


#pragma UIAlertView Delegate Methods

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex{
    
    switch (buttonIndex) {
        case 0:
            [self cancelAction:nil];
            break;
       }
}



#pragma mark -
#pragma mark UITextFieldDelegate methods

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
	
	if(textField == titleTextField)
	{
		if(isTitleEmpty)
			textField.text = @"";
	}
	
	textField.textColor = [UIColor blackColor];
	
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{

	if(textField == titleTextField)
	{
		isTitleEmpty = [textField.text isEqualToString:@""];
		
		if(isTitleEmpty)
		{
			textField.text = @"Title:";
			textField.textColor = [UIColor lightGrayColor];
		}
		else {
			textField.textColor = [UIColor blackColor];
		}
	}
	
}


- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
	
	if([textField resignFirstResponder])
	{
		[self exitEditMode];
		return YES;
	}
	
	return NO;
	
}


- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{
	
	[self enterEditMode];
	return YES;
	
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
	
	if (textField == titleTextField && [titleTextField.text length] > 80) {

		NSString* errorMessage = [NSString stringWithFormat:@"The title you provided is %u characters long. The video title must be at most 80 characters long.",[titleTextField.text length]];
		
		UIAlertView *alert = [[UIAlertView alloc]
							  initWithTitle:@"Upload Error"
							  message:errorMessage
							  delegate:nil
							  cancelButtonTitle:@"OK"
							  otherButtonTitles:nil];
		
		[alert show];
		[alert release];
		
		return NO;
	}
	
	return YES;
}	

#pragma mark -
#pragma mark UITextViewDelegate methods


- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text {
	
	// Not the best solution
    if([text isEqualToString:@"\n"]) {
		
        if([textView resignFirstResponder])
			[self exitEditMode];
	
		return NO;
    }
	
    return YES;
}

- (BOOL)textViewShouldBeginEditing:(UITextView *)textView
{
	
	[self enterEditMode];
	return YES;
	
}

- (BOOL)textViewShouldEndEditing:(UITextView *)textView
{
	
	if ([descriptionTextView.text length] > 255) {
		
		NSString* errorMessage = [NSString stringWithFormat:@"The description you provided is %u characters long. The video description must be at most 255 characters long.",[descriptionTextView.text length]];
	
		UIAlertView *alert = [[UIAlertView alloc]
							  initWithTitle:@"Upload Error"
							  message:errorMessage
							  delegate:nil
							  cancelButtonTitle:@"OK"
							  otherButtonTitles:nil];
		
		[alert show];
		[alert release];
		
		return NO;
	}
	
	return YES;
	
}

- (void)textViewDidBeginEditing:(UITextView *)textView
{
	
	if(isDescriptionEmpty)
		textView.text = @"";
	
	textView.textColor = [UIColor blackColor];
	
}

- (void)textViewDidEndEditing:(UITextView *)textView
{
	isDescriptionEmpty = [textView.text isEqualToString:@""];

	if(isDescriptionEmpty)
	{
		textView.text = @"Description:";
		textView.textColor = [UIColor lightGrayColor];
	}
	else {
		textView.textColor = [UIColor blackColor];
	}
	
	
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

	self.imageView = nil;
	self.titleTextField = nil;
	self.descriptionTextField = nil;
	self.descriptionTextView = nil;
	self.playButton = nil;
	self.uploadProgressOverlayView = nil;
	self.progressView = nil;
	self.uploadButton = nil;
}


- (void)dealloc {
	
	[imageView release];
	[titleTextField release];
	[descriptionTextField release];
	[descriptionTextView release];
	[playButton release];
	[uploadProgressOverlayView release];
	[progressView release];
	[uploadButton release];
	
	[videoThumbnail release];
	[videoFileURL release];
    [userData release];
	
    [super dealloc];
}


@end
