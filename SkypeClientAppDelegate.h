//
//  IDontKnowWhatImDoingAppDelegate.h
//  IDontKnowWhatImDoing
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>



@interface SkypeClientAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
    NSTableView *_convoTableView;
    NSTextField *loggedInUsername;
    NSImageCell *loggedInImage;
    NSTask *runtime;
    NSTask *processor;
    //NSTableView *_tableview;
    IBOutlet NSWindow *loginWindow;
    NSTextField *username;
    NSSecureTextField *password;
    NSLock *lock;
    NSTableView *statsGeneral;
    WebView *convStarter;
    IBOutlet NSWindow *statsWindow;
}

@property (assign) IBOutlet NSTableView *statsGeneral;
@property (assign) IBOutlet WebView *convStarter;

@property (assign) IBOutlet NSTextField *username;
@property (assign) IBOutlet NSSecureTextField *password;
@property (retain) IBOutlet NSTableView *_tableview;
@property (assign) IBOutlet NSWindow *window;
@property (retain) IBOutlet NSTableView *_convoTableView;

@property (assign) IBOutlet NSTextField *loggedInUsername;
@property (assign) IBOutlet NSImageCell *loggedInImage;

- (IBAction)test:(id)sender;
- (void)stdoutDataAvailable:(NSNotification *)notification;
- (void)bgThreadIsDone:(id)obj;
- (void) initialiseAfterLogin;
- (IBAction) doLogin:(id)sender;
- (void)bgThreadIsDone:(id)obj;
- (void)bgThread:(NSConnection *)connection;
- (void) processStdoutData:(NSNotification *) notification;

@end
