//
//  Controller.h
//  IDontKnowWhatImDoing
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GUIController : NSObject {
    IBOutlet id button;
    IBOutlet NSTextField *text;
    IBOutlet NSScrollView *conversation;
    IBOutlet NSTextView *convoRecorded;
    //NSString *currentConvo;
    NSMutableArray *convoData;
    NSApplication *skypeAppDelegate;
    NSTableView *generalStats;
}

- (IBAction)sendChatMessage:(id)sender;
- (void)dataUpdated;
@property (assign) IBOutlet NSTableView *generalStats;



//@property (readwrite, copy) NSMutableArray *convoData;

//@property (assign) NSString *currentConvo;

@end
