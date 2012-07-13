//
//  ChannelsViewController.m
//  AFV
//
//  Created by Kaveh G. on 1/26/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "ChannelsViewController.h"
#import "GenericXMLParser.h"
#import "LoadingCell.h"
#import "ChannelViewController.h"
#import "SBJSON.h"

@interface ChannelsViewController()

-(void)asyncDataReady;

@end
	
	
@implementation ChannelsViewController

@synthesize channels;

#pragma mark -
#pragma mark View lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];

    self.channels = [[NSMutableArray alloc] init];
    
	if(channels.count == 0)
	{
		// Load the data
		loadingData = YES;
		[NSThread detachNewThreadSelector:@selector(asynchDataDownloadThread) toTarget:self withObject:nil];
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
	if (self.channels.count == 0)
	{
		UIAlertView *alert = [[UIAlertView alloc]
							  initWithTitle:@"Connection Error"
							  message:@"Could not retrieve the channel list. Please try again later." 
							  delegate:nil
							  cancelButtonTitle:@"OK"
							  otherButtonTitles:nil];
		
		[alert show];
		[alert release];		
	}
	
	[self.tableView reloadData];
	
}


-(void)asynchDataDownloadThread
{
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	@synchronized(self)
	{		
		@try {
			
            NSMutableArray* videoFeedArray = [[NSMutableArray alloc] init];
            
            NSString* searchString = @"http://gdata.youtube.com/feeds/api/users/afvofficial/playlists?alt=json&orderby=published&start-index=1&max-results=50&v=2";
            
            NSString* escapedUrlString =[searchString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
            
			NSURL *feedURL = [[NSURL alloc] initWithString:escapedUrlString];
            
             NSError *error;
            NSString *responseString = [NSString stringWithContentsOfURL:feedURL encoding:NSStringEncodingConversionAllowLossy error:nil];

            SBJSON *json = [[SBJSON new] autorelease];
            NSDictionary *dataDictionary = [json objectWithString:responseString error:&error];
            [videoFeedArray addObjectsFromArray:[[dataDictionary objectForKey:@"feed"] objectForKey:@"entry"]];
            
            for(NSInteger i=0;i<[videoFeedArray count];i++) {
               
                NSDictionary *videoDict = [videoFeedArray objectAtIndex:i];
                NSMutableDictionary* dict = [[NSMutableDictionary alloc] init];
                
                [dict setValue:[[videoDict objectForKey:@"title"] objectForKey:@"$t"] forKey:TEXT_KEY];
                [dict setValue:[[videoDict objectForKey:@"yt$playlistId"] objectForKey:@"$t"] forKey:@"id"];
                
                [channels addObject:dict];
                [dict release];
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
#pragma mark Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    // Return the number of sections.
    return 1;
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {

    if(channels.count == 0)
	   return 3;
	else
		return channels.count;

}


// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

	static NSString *EmptyCellIdentifier = @"EmptyCellIdentifier";
    static NSString *loadingCellIdentifier = @"LoadingCellIdentifier";
    static NSString *channelCellIdentifier = @"ChannelCellIdentifier";
	
	if(channels.count == 0)
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
		
		UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:EmptyCellIdentifier];
		if (cell == nil) {

			cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:EmptyCellIdentifier] autorelease];
		}
		
		cell.selectionStyle = UITableViewCellSelectionStyleNone;

		return cell;

		
	}
	else
	{
		
		UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:channelCellIdentifier];
		if (cell == nil) {
			
			cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:channelCellIdentifier] autorelease];
			cell.textLabel.textColor = [UIColor whiteColor];
			cell.textLabel.font = [UIFont fontWithName:cell.textLabel.font.fontName size:17];
            cell.selectionStyle = UITableViewCellSelectionStyleGray;
		}
		
		
		cell.textLabel.text = [[self.channels objectAtIndex:indexPath.row] valueForKey:TEXT_KEY];
		
		
		return cell;
		
		
	}
    
}




#pragma mark -
#pragma mark Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {

	if(channels.count == 0)
	{
		LoadingCell* cell = (LoadingCell*)[tableView cellForRowAtIndexPath:indexPath];
		if([cell isKindOfClass:[LoadingCell class]])
		{
			if(!loadingData)
			{
				loadingData = YES;
				
				cell.loadingLabel.text = @"Loading...";
				[cell.activityIndicator startAnimating];
				cell.selectionStyle = UITableViewCellSelectionStyleNone;
				[cell resizeContent];

				// Load more data
				[NSThread detachNewThreadSelector:@selector(asynchDataDownloadThread) toTarget:self withObject:nil];
			}
			
			[tableView deselectRowAtIndexPath:indexPath animated:YES];
		}
		
	}
	else
		
	{
		ChannelViewController* channelViewController = [[ChannelViewController alloc] initWithNibName:@"ChannelViewController" bundle:nil];
		channelViewController.channelID = [[channels objectAtIndex:indexPath.row] valueForKey:@"id"];
		channelViewController.videoCount = [[[channels objectAtIndex:indexPath.row] valueForKey:@"count"] intValue]; 
		channelViewController.navigationItem.title = [[self.channels objectAtIndex:indexPath.row] valueForKey:TEXT_KEY];
		[self.navigationController pushViewController:channelViewController animated:YES];
		[channelViewController release];
	}

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
	
	[channels release];
	
    [super dealloc];
}


@end

