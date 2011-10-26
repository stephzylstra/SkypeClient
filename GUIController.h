//
//  Controller.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 Stephanie Zylstra. All rights reserved.
//

// Tableview Delegate class

#import <Foundation/Foundation.h>
#import "ContentViewController.h"
#import "INPopoverController.h"
#import "SkypeClientAppDelegate.h"


@interface GUIController : NSObject {
    IBOutlet id button;
    IBOutlet NSTextField *text;
    IBOutlet NSScrollView *conversation;
    IBOutlet NSTextView *convoRecorded;
    NSMutableArray *convoData;
    NSTableView *generalStats;
    ContentViewController *viewController;
}

@property (assign) IBOutlet NSTableView *generalStats;
@property (nonatomic, retain) INPopoverController *popoverController;

// load popover view for inline display of images
- (IBAction)loadPopover:(id)sender;

// send a chat message to the currently selected conversation
- (IBAction)sendChatMessage:(id)sender;

// find number of rows to display in a table - Table delegate method
- (int)numberOfRowsInTableView:(NSTableView *)tableView;

// get content for given cell - Table delegate method
- (NSView *)tableView:(NSTableView *)tableView
   viewForTableColumn:(NSTableColumn *)tableColumn
                  row:(NSInteger)row;

@end
