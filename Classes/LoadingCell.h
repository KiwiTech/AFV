//
//  LoadingCell.h
//  AFV
//
//  Created by Kaveh G. on 2/7/11.
//  Copyright 2011 Teleca. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface LoadingCell : UITableViewCell {

	UIActivityIndicatorView* activityIndicator;
	UILabel* loadingLabel;
}

@property(nonatomic, retain) IBOutlet UIActivityIndicatorView* activityIndicator;
@property(nonatomic, retain) IBOutlet UILabel* loadingLabel;

- (void)resizeContent;

@end
