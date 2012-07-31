//
//  FavoritesViewController.m
//  AFV
//
//  Created by Kaveh G. on 1/26/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import "FavoritesViewController.h"
#import "FavoritesDB.h"
#import "LoadingCell.h"
#import "VideoItem.h"
#import "VideoDetailViewController.h"
#import "MoviePlayerViewController.h"
#import "FavoritesDB.h"
#import "AFVAppDelegate.h"

@implementation FavoritesViewController

@synthesize items;
@synthesize tableView;

#pragma mark -
#pragma mark Helper methods

- (NSArray*)getFavorites
{
	NSArray* favorites = [[FavoritesDB sharedInstance].favorites allValues];
	
	return [favorites sortedArrayUsingDescriptors:[NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"favoriteTimeStamp" ascending:NO]]];
	
}

#pragma mark -
#pragma mark View lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];

	self.items = [self getFavorites];
    
	[AFVAppDelegate insertAdInController:self atOffset:369];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
	
    [tableView deselectRowAtIndexPath:[tableView indexPathForSelectedRow] animated:YES];

	self.items = [self getFavorites];
	[self.tableView reloadData];
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
		return items.count;
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
			LoadingCell *cell = (LoadingCell*)[self.tableView dequeueReusableCellWithIdentifier:loadingCellIdentifier];
			if (cell == nil) {
				
				NSArray * nib = [[NSBundle mainBundle] loadNibNamed:@"LoadingCell" owner:nil options:nil];
				for (id oneObject in nib) {
					if ([oneObject isKindOfClass:[LoadingCell class]]) {
						cell = (LoadingCell*)oneObject;
					}
				}
				
			}
			
			cell.loadingLabel.text = @"No Favorites";
			[cell.loadingLabel sizeToFit];
			cell.loadingLabel.center = cell.contentView.center;
			[cell.activityIndicator stopAnimating];
			
			return cell;
		}
		
		UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:emptyCellIdentifier];
		if (cell == nil) {
			
			cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:emptyCellIdentifier] autorelease];
		}
		
		cell.selectionStyle = UITableViewCellSelectionStyleNone;
		return cell;
		
		
	}
	else
	{
		VideoItemCell *cell = (VideoItemCell*)[self.tableView dequeueReusableCellWithIdentifier:videoItemCellIdentifier];
		if (cell == nil) {
			
			NSArray * nib = [[NSBundle mainBundle] loadNibNamed:@"VideoItemCell" owner:nil options:nil];
			for (id oneObject in nib) {
				if ([oneObject isKindOfClass:[VideoItemCell class]]) {
					cell = (VideoItemCell*)oneObject;
					//cell.cachedWebView.delegate = cell;
					cell.delegate = self;
				}
			}
			
            cell.selectionStyle = UITableViewCellSelectionStyleNone;
		}
		
		
		VideoItem* item = [self.items objectAtIndex:indexPath.row];
		cell.titleLabel.text = item.title;
		cell.descriptionLabel.text = item.description;
        NSString *html = [NSString stringWithFormat:embedHTML, item.videoUrl, cell.webView.frame.size.width, cell.frame.size.height];
        [cell.webView loadHTMLString:html baseURL:nil];
        

        
	//	[cell.cachedWebView reset];
	//	cell.cachedWebView.fadeInOnUpdate = NO;
	//	[cell.cachedImageView loadCachedImageWithImageUrl:item.thumbnailUrl usingMaxImageSize:CGSizeMake(96, 72)];
		
		return cell;
		
	}
}



- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    
    if (editingStyle == UITableViewCellEditingStyleDelete) {

		[FavoritesDB removeFavorite:(VideoItem*)[self.items objectAtIndex:indexPath.row]];
		 self.items = [self getFavorites];
		
		if(items.count > 0)
			[self.tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationFade];
		else {
			[self.tableView reloadData];
		}

		
    }   
}



#pragma mark -
#pragma mark Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
//	if(items.count > 0)
//	{
//		VideoItem* item = [self.items objectAtIndex:indexPath.row];
//		MoviePlayerViewController* moviePlayer = [[MoviePlayerViewController alloc] initWithContentURL:[NSURL URLWithString:item.videoUrl]];
//		[self presentMoviePlayerViewControllerAnimated:moviePlayer];
//		[moviePlayer release];
//	}
	
}

// Enabled swipe delete, don't remove
- (void)tableView:(UITableView*)tableView willBeginEditingRowAtIndexPath:(NSIndexPath *)indexPath
{}

- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
	return (items.count > 0) ? UITableViewCellEditingStyleDelete : UITableViewCellEditingStyleNone;
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
    
    self.items = nil;
}

- (void)viewDidUnload {
    // Relinquish ownership of anything that can be recreated in viewDidLoad or on demand.
    // For example: self.myOutlet = nil;
}


- (void)dealloc {
	
	[items release];

    [super dealloc];
}


@end

