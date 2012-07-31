//
//  RegistrationViewController.m
//  AFV
//
//  Created by kiwitech on 17/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "RegistrationViewController.h"
#import "AFVAppDelegate.h"

#define allTrim( object ) [object stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet] ]


@interface RegistrationViewController ()

@end

@implementation RegistrationViewController
@synthesize m_scrollView;
@synthesize m_tableView;
@synthesize m_datePicker;
@synthesize m_pickerView;
@synthesize m_sBirthDate;
@synthesize isCompleted;
@synthesize m_delegate;
@synthesize m_txtGender;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)showAlertMessage:(NSString*)sMessage {
    
    UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"" message:sMessage delegate:nil cancelButtonTitle:@"OK" otherButtonTitles: nil];
    [alert show];
    [alert release];

}

- (void)viewDidLoad
{
    [super viewDidLoad];
        
     [AFVAppDelegate insertAdInController:self atOffset:369];
    
    m_datePicker.maximumDate = [NSDate date];
    isRemembered = NO;
        
    NSDateFormatter* dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"MM/dd/yyyy"];
    
    self.m_sBirthDate = [dateFormatter stringFromDate:[NSDate date]];
    [dateFormatter release];
    
    m_scrollView.contentSize = CGSizeMake(320.0, 750.0);
    m_tableView.backgroundColor =[UIColor whiteColor];
    
    [m_tableView.layer setCornerRadius:2.0];
    //Set the border color
    [m_tableView.layer setBorderColor:[[UIColor darkGrayColor] CGColor]];
    [m_tableView.layer setBorderWidth:1.0];
    
    if(m_userData) {
       [m_userData release];
        m_userData = nil;
    }
                  
    m_userData = [[UserDataHolder alloc] init];
}

- (void)viewWillDisappear:(BOOL)animated {

    [super viewWillDisappear:animated];
    
    for(NSInteger i=1;i<=12;i++) {
        
        UITextField* txtField = (UITextField*)[m_scrollView viewWithTag:i];
        txtField.text = @"";
    }
    
    NSDateFormatter* dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"MM/dd/yyyy"];
    
    self.m_sBirthDate = [dateFormatter stringFromDate:[NSDate date]];
    [dateFormatter release];
    
    m_txtGender.text = @"Select a value";
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)dealloc {
    
    [m_txtGender release];
    [m_pickerView release];
    [m_datePicker release];
    [m_tableView release];
    [m_userData release];
    [m_scrollView release];
    [m_sBirthDate release];
    [super dealloc];
}


#pragma mark --
#pragma mark <UIControlCallBacks>

- (void)hidePickerView {
    [UIView beginAnimations:@"pickerStopped" context:nil]; 
    [UIView setAnimationDuration:0.4];
    [UIView setAnimationDelegate:self];
    [UIView setAnimationDidStopSelector:@selector(animationStop:finished:context:)];
    
    CGRect frame = m_pickerView.frame;
    frame.origin.y = 367;
    m_pickerView.frame = frame;
    
    [UIView commitAnimations];
}

- (IBAction)doneButtonPressed:(id)sender {
    
    NSDateFormatter* dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"MM/dd/yyyy"];
    
    NSDate* dt = [dateFormatter dateFromString:self.m_sBirthDate];
	m_userData.sBirthDate = [NSString stringWithFormat:@"%.0f", [dt timeIntervalSince1970]];
    [dateFormatter release];

    
    UITextField* textField = (UITextField*)[m_scrollView viewWithTag:5];
    textField.text = m_sBirthDate;
    [self hidePickerView];
}

- (IBAction)cancelButtonPressed:(id)sender {
   
    [self hidePickerView];
}

- (IBAction)submitButtonPressed:(id)sender {
    
    if(m_tableView.hidden == NO) {
        [self hideTableView];
    }
    
    for(NSInteger i=1;i<=12;i++) {

        UITextField* txtField = (UITextField*)[m_scrollView viewWithTag:i];
        if([txtField isEditing]) {
            [txtField resignFirstResponder];
        }
    }
    
    [m_scrollView setContentOffset:CGPointMake(0.0, 0.0) animated:NO];
    
   self.isCompleted = [self checkForRequiredField];
    
    if(isCompleted) {
       
        NSString *sPath = [kLIBRARY_DIRECTORY stringByAppendingPathComponent:@"user_data.xml"];

        if(isRemembered) {
            [NSKeyedArchiver archiveRootObject:m_userData toFile:sPath];
        }
        else {
            	
            NSFileManager *fileManager = [NSFileManager defaultManager];
            if([fileManager fileExistsAtPath:sPath]) {
                   [fileManager removeItemAtPath:sPath error:nil];
            }
        }
    
        [m_delegate registrationCompleted:m_userData];
    }
}

- (IBAction)genderButtonPressed:(id)sender {
    
    [m_scrollView setContentOffset:CGPointMake(0.0, 380) animated:YES];
    for(NSInteger i=1;i<=12;i++) {
        
        UITextField* txtField = (UITextField*)[m_scrollView viewWithTag:i];
        [txtField resignFirstResponder];
    }
    
    if(m_tableView.hidden == YES) {
        m_tableView.hidden = NO;
        
        [UIView beginAnimations:@"" context:nil]; 
        [UIView setAnimationDuration:0.4];
        
        CGRect frame = m_tableView.frame;
        frame.size.height = 75;
        m_tableView.frame = frame;
        
        [UIView commitAnimations];
    }
    else {
        [self hideTableView];
    }
}

- (IBAction)rememberMeButtonPressed:(id)sender {
 
    if(m_tableView.hidden == NO) {
        [self hideTableView];
    }
    
    UIButton* btn = (UIButton*)sender;
    isRemembered = !isRemembered;
    
    if(isRemembered) {
        [btn setImage:[UIImage imageNamed:@"checkRememberMe.png"] forState:UIControlStateNormal];
    }
    else {
         [btn setImage:[UIImage imageNamed:@"uncheckRememberMe.png"] forState:UIControlStateNormal];
    }
}

- (BOOL) validateEmail: (NSString *) candidate {
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}"; 
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex]; 
    
    return [emailTest evaluateWithObject:candidate];
}

- (void)animationStop:(NSString *)animationID finished:(BOOL)finished context:(void *)context 
{
    if([animationID isEqualToString:@"pickerStopped"]) {
        m_pickerView.hidden = YES;
    }
    else {
        m_tableView.hidden = YES;
    }
}

- (void)hideTableView {
    
    [UIView beginAnimations:@"" context:nil]; 
    [UIView setAnimationDuration:0.4];
    [UIView setAnimationDelegate:self];
    [UIView setAnimationDidStopSelector:@selector(animationStop:finished:context:)];
    
    CGRect frame = m_tableView.frame;
    frame.size.height = 0;
    m_tableView.frame = frame;
    
    [UIView commitAnimations];
}

- (BOOL)checkForRequiredField {
            
    UITextField* txtField = (UITextField*)[m_scrollView viewWithTag:1]; 
        
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter first name"];            
        return NO;
    }
    
    txtField = (UITextField*)[m_scrollView viewWithTag:2]; 
    
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter last name"];            
        return NO;
    }
    
   txtField = (UITextField*)[m_scrollView viewWithTag:3]; 
    
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter email"];            
        return NO;
    }
    
    txtField = (UITextField*)[m_scrollView viewWithTag:3]; 
    
    if(![self validateEmail:txtField.text]) {
        [self showAlertMessage:@"Invalid Email Address"];            
        return NO;
    }
  
    txtField = (UITextField*)[m_scrollView viewWithTag:4]; 
    
    if(![m_userData.sEmail isEqualToString:txtField.text]) {
        [self showAlertMessage:@"Please enter correct confirm email"];            
        return NO;
    }
  
    txtField = (UITextField*)[m_scrollView viewWithTag:5]; 
    
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter birthdate"];            
        return NO;
    }
    
    txtField = (UITextField*)[m_scrollView viewWithTag:6]; 
    
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter address"];            
        return NO;
    }
    
    txtField = (UITextField*)[m_scrollView viewWithTag:7]; 
    
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter city"];            
        return NO;
    }
   
    txtField = (UITextField*)[m_scrollView viewWithTag:8]; 
    
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter state"];            
        return NO;
    }
   
    txtField = (UITextField*)[m_scrollView viewWithTag:9]; 
    
   if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter zip postal"];            
        return NO;
    }
    txtField = (UITextField*)[m_scrollView viewWithTag:10]; 
    
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter country"];            
        return NO;
    }
    txtField = (UITextField*)[m_scrollView viewWithTag:11]; 
    
    if([allTrim(txtField.text) length] == 0) {
        [self showAlertMessage:@"Please enter phone"];            
        return NO;
    }
    
//    txtField = (UITextField*)[m_scrollView viewWithTag:12]; 
//    
//    if([allTrim(txtField.text) length] == 0) {
//        [self showAlertMessage:@"Please enter phone 2"];            
//        return NO;
//    }
    
    if([m_userData.sGender length] == 0) {
        
        [self showAlertMessage:@"Please select gender"];            
        return NO;
    }

    return YES;
}

- (void)setUserData:(UITextField*)textField {
    
    if(textField.tag == 1)
	{
		m_userData.sFirstName = textField.text;
	}
	if(textField.tag == 2)
	{
		m_userData.sLastName = textField.text;
	}
	if(textField.tag == 3)
	{
		m_userData.sEmail = textField.text;
	}
	if(textField.tag == 5)
	{
		m_userData.sBirthDate = textField.text;
	}
	if(textField.tag == 6)
	{
		m_userData.sAddress = textField.text;
	}
	if(textField.tag == 7)
	{
		m_userData.sCity = textField.text;
	}
	if(textField.tag == 8)
	{
		m_userData.sState = textField.text;
	}
	if(textField.tag == 9)
	{
		m_userData.sZip = textField.text;
	}
    if(textField.tag == 10)
	{
		m_userData.sCountry = textField.text;
	}
    if(textField.tag == 11)
	{
		m_userData.sPhone1 = textField.text;
	}
    if(textField.tag == 12)
	{
		m_userData.sPhone2 = textField.text;
	}
}

#pragma mark --
#pragma mark <UITextFieldDelegate> Methods

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{	
    if(m_tableView.hidden == NO) {
        m_tableView.hidden = YES;
    }
    
    m_pickerView.hidden = YES;
    if(textField.tag == 4)
	{
		[m_scrollView setContentOffset:CGPointMake(0.0, 60) animated:YES];
	}
	else if(textField.tag == 5)
	{
        for(NSInteger i=1;i<=12;i++) {
            
            UITextField* txtField = (UITextField*)[m_scrollView viewWithTag:i];
            if([txtField isEditing]) {
                [txtField resignFirstResponder];
            }
        }
        
        m_pickerView.hidden = NO;

        [UIView beginAnimations:@"" context:nil]; 
        [UIView setAnimationDuration:0.4];
        
        CGRect frame = m_pickerView.frame;
        frame.origin.y = 107;
        frame.size.height = 260;
        m_pickerView.frame = frame;
        
        [UIView commitAnimations];
		[m_scrollView setContentOffset:CGPointMake(0.0, 170) animated:YES];
        
        return NO;
	}
	else if(textField.tag == 6)
	{
		[m_scrollView setContentOffset:CGPointMake(0.0, 200) animated:YES];
	}
	else if(textField.tag == 7)
	{
		[m_scrollView setContentOffset:CGPointMake(0.0, 220) animated:YES];
	}
	else if(textField.tag == 8)
	{
		[m_scrollView setContentOffset:CGPointMake(0.0, 240) animated:YES];
	}
	else if(textField.tag == 9)
	{
		[m_scrollView setContentOffset:CGPointMake(0.0, 260) animated:YES];
	}
	else if(textField.tag == 10)
	{
		[m_scrollView setContentOffset:CGPointMake(0.0, 300) animated:YES];
	}
    else if(textField.tag == 11)
	{
		[m_scrollView setContentOffset:CGPointMake(0.0, 340) animated:YES];
	}
    else if(textField.tag == 12)
	{
		[m_scrollView setContentOffset:CGPointMake(0.0, 380) animated:YES];
	}
    
	return YES;
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField  {
    
    [self setUserData:textField];
    return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    
    [textField resignFirstResponder];
    
//    if(textField.tag == 1){
//        [(UITextField*)[m_scrollView viewWithTag:2] becomeFirstResponder];
//    }
//    else if(textField.tag == 2){
//        [(UITextField*)[m_scrollView viewWithTag:3] becomeFirstResponder];
//    }
//    else if(textField.tag == 3){
//        [(UITextField*)[m_scrollView viewWithTag:4] becomeFirstResponder];
//    }
//    else if(textField.tag == 4){
//        [(UITextField*)[m_scrollView viewWithTag:5] becomeFirstResponder];
//    }
//    else if(textField.tag == 5){
//        [(UITextField*)[m_scrollView viewWithTag:6] becomeFirstResponder];
//    }
//    else if(textField.tag == 6){
//        [(UITextField*)[m_scrollView viewWithTag:7] becomeFirstResponder];
//    }
//    else if(textField.tag == 7){
//        [(UITextField*)[m_scrollView viewWithTag:8] becomeFirstResponder];
//    }
//    else if(textField.tag == 8){
//        [(UITextField*)[m_scrollView viewWithTag:9] becomeFirstResponder];
//    }
//    else if(textField.tag == 9){
//        [(UITextField*)[m_scrollView viewWithTag:10] becomeFirstResponder];
//    }
//    else if(textField.tag == 10){
//        [(UITextField*)[m_scrollView viewWithTag:11] becomeFirstResponder];
//    }
//    else if(textField.tag == 11){
//        [(UITextField*)[m_scrollView viewWithTag:12] becomeFirstResponder];
//    }
    
    return YES;
}

#pragma mark --
#pragma mark Table view data source and delegate

- (NSInteger)numberOfSectionsInTableView:(UITableView*)tableView {
    
    return 1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    return 0.0;    
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    
    return 3;
}

-(UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    
    NSString *QuoteCellIdentifier = [NSString stringWithFormat:@"CellIdentifier%d-%d", indexPath.section, indexPath.row];
    
    UITableViewCell *cell = (UITableViewCell*)[tableView dequeueReusableCellWithIdentifier:QuoteCellIdentifier];
    
    if (!cell) {
        
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:QuoteCellIdentifier];
        
        cell.textLabel.font = [UIFont boldSystemFontOfSize:14.0];
        cell.textLabel.textColor = [UIColor blackColor];
     
        cell.backgroundColor = [UIColor whiteColor];
        switch (indexPath.row) {
            case 0:
                cell.textLabel.text = @"Male";
                break;
            case 1:
                cell.textLabel.text = @"Female";
                break; 
            case 2:
                cell.textLabel.text = @"N/A";
                break; 
            default:
                break;
        }
    }
    
    return cell;
}


-(void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    
    UITableViewCell* cell = (UITableViewCell*)[tableView cellForRowAtIndexPath:indexPath];
    m_userData.sGender = cell.textLabel.text;
     m_txtGender.text = cell.textLabel.text;
    
    [self hideTableView];
}


#pragma mark --
#pragma mark <UIDatePicker Delegate>

- (IBAction)dateValueChanged:(id)sender
{
    NSDateFormatter* dateFormatter = [[NSDateFormatter alloc] init];
     [dateFormatter setDateFormat:@"MM/dd/yyyy"];
    
	self.m_sBirthDate = [dateFormatter stringFromDate:[m_datePicker date]];
    [dateFormatter release];
}


@end
