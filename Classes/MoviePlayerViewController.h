//
//  MoviePlayerViewController.h
//  AFV
//
//  Created by Kaveh on 2/12/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

@interface MoviePlayerViewController : MPMoviePlayerViewController {

	UIView* loadingView;
}

@property(nonatomic, retain) IBOutlet UIView* loadingView;

- (IBAction)doneActioin:(id)sender;

@end
