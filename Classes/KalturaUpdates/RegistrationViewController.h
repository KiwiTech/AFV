//
//  RegistrationViewController.h
//  AFV
//
//  Created by kiwitech on 17/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UserDataHolder.h"
#import <QuartzCore/QuartzCore.h>

@interface RegistrationViewController : UIViewController <UITextFieldDelegate, UITableViewDataSource, UITableViewDelegate> {
    UserDataHolder*     m_userData;
    
    BOOL    isRemembered;
    BOOL isCompleted;
    
}

@property (nonatomic, retain) IBOutlet UIScrollView*        m_scrollView;
@property (nonatomic, retain) IBOutlet UITableView*         m_tableView;
@property (nonatomic, retain) IBOutlet  UIDatePicker*       m_datePicker;
@property (nonatomic, retain) IBOutlet UIView*   m_pickerView;
@property (nonatomic, retain)     NSString*       m_sBirthDate;
@property (nonatomic, assign) BOOL isCompleted;

- (IBAction)submitButtonPressed:(id)sender;
- (IBAction)genderButtonPressed:(id)sender;
- (IBAction)rememberMeButtonPressed:(id)sender;
- (IBAction)doneButtonPressed:(id)sender;
- (IBAction)cancelButtonPressed:(id)sender;
- (IBAction)dateValueChanged:(id)sender;

@end
