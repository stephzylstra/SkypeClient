//
//  SkypeClientAppDelegate.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 StephanieZylstra. All rights reserved.
//

// Application Delegate

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

@interface SkypeClientAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
    NSTableView *_convoTableView;
    NSTextField *loggedInUsername;
    NSImageCell *loggedInImage;
    NSPanel *progressPanel;
    NSProgressIndicator *progress;
    NSTask *runtime;
    NSTask *processor;
    //NSTableView *_tableview;
    IBOutlet NSWindow *loginWindow;
    NSTextField *username;
    NSSecureTextField *password;
    NSLock *lock;
    NSTableView *statsGeneral;
    WebView *convStarter;
    NSTextField *individualAverageLines;
    NSTextField *individualResponseTimeYou;
    NSTextField *individualResponseTimeThem;
    IBOutlet NSWindow *statsWindow;
    NSComboBox *selectContact;
    NSTextField *individualLastConversation;
    NSButton *loginButton;
}

// for individual statistics
@property (assign) IBOutlet NSComboBox *selectContact;
@property (assign) IBOutlet NSTextField *individualLastConversation;
@property (assign) IBOutlet WebView *convStarter;
@property (assign) IBOutlet NSTextField *individualAverageLines;
@property (assign) IBOutlet NSTextField *individualResponseTimeYou;
@property (assign) IBOutlet NSTextField *individualResponseTimeThem;

// table views
@property (assign) IBOutlet NSTableView *statsGeneral;
@property (retain) IBOutlet NSTableView *_convoTableView;
@property (retain) IBOutlet NSTableView *_tableview;

// logging in
@property (assign) IBOutlet NSButton *loginButton;
@property (assign) IBOutlet NSTextField *username;
@property (assign) IBOutlet NSSecureTextField *password;

// main window
@property (assign) IBOutlet NSWindow *window;

// current user
@property (assign) IBOutlet NSTextField *loggedInUsername;
@property (assign) IBOutlet NSImageCell *loggedInImage;

// progress indicator
@property (assign) IBOutlet NSPanel *progressPanel;
@property (assign) IBOutlet NSProgressIndicator *progress;


- (IBAction)test:(id)sender;
- (void)stdoutDataAvailable:(NSNotification *)notification;
- (void)bgThreadIsDone:(id)obj;
- (void) initialiseAfterLogin;
- (IBAction) doLogin:(id)sender;
- (void)bgThreadIsDone:(id)obj;
- (void)bgThread:(NSConnection *)connection;
- (void) processStdoutData:(NSNotification *) notification;
- (IBAction)doSearch:(id)sender;
- (void)processSearch:(NSString *)searchTerm;
- (void)sendFileTransfer:(NSString *)filename;
- (void) updateContactsAfterLogin:(NSTimer *)timer;


@end
