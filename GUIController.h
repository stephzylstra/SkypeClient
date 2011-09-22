//
//  Controller.h
//  IDontKnowWhatImDoing
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ContentViewController.h"
#import "INPopoverController.h"
#import "SkypeClientAppDelegate.h"


@interface GUIController : NSObject {
    IBOutlet id button;
    IBOutlet NSTextField *text;
    IBOutlet NSScrollView *conversation;
    IBOutlet NSTextView *convoRecorded;
    //NSString *currentConvo;
    NSMutableArray *convoData;
    NSTableView *generalStats;
    ContentViewController *viewController;
}

@property (assign) IBOutlet NSTableView *generalStats;
@property (nonatomic, retain) INPopoverController *popoverController;


- (IBAction)loadPopover:(id)sender;
- (IBAction)sendChatMessage:(id)sender;
- (void)dataUpdated;



//@property (readwrite, copy) NSMutableArray *convoData;

//@property (assign) NSString *currentConvo;

@end
