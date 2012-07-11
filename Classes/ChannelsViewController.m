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


@interface ChannelsViewController()

-(void)asyncDataReady;

@end
	
	
@implementation ChannelsViewController

@synthesize channels;

#pragma mark -
#pragma mark View lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];

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
		
		NSURL* url = [NSURL URLWithString:@"http://cdn.abc.go.com/ugv/filters?showKey=SH000168930000"];
		GenericXMLParser* parser = [[GenericXMLParser alloc] initWithURL:url ignoring:nil treatAsProperty:nil];
		
		@try {
			self.channels = [[[[parser parse] objectForKey:CHILDREN_KEY] objectAtIndex:0] objectForKey:CHILDREN_KEY];

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

