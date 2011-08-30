//
//  IDontKnowWhatImDoingAppDelegate.h
//  IDontKnowWhatImDoing
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface SkypeClientAppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window;
    NSTableView *_convoTableView;
    NSTask *runtime;
    NSTask *processor;
    //NSTableView *_tableview;
    IBOutlet NSWindow *loginWindow;
    NSTextField *username;
    NSSecureTextField *password;
}
@property (assign) IBOutlet NSTextField *username;
@property (assign) IBOutlet NSSecureTextField *password;



@property (retain) IBOutlet NSTableView *_tableview;
@property (assign) IBOutlet NSWindow *window;
@property (retain) IBOutlet NSTableView *_convoTableView;

- (void)stdoutDataAvailable:(NSNotification *)notification;

- (void) initialiseAfterLogin;

- (IBAction)doLogin:(id)sender;


@end
