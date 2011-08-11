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
    NSTask *runtime;
    NSTask *processor;
    NSTableView *_tableview;
}

- (void)stdoutDataAvailable:(NSNotification *)notification;

@property (assign) IBOutlet NSTableView *_tableview;
@property (assign) IBOutlet NSWindow *window;

@end
