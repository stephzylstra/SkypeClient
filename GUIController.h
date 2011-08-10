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
}

- (IBAction)sendChatMessage:(id)sender;



//@property (assign) NSString *currentConvo;

@end
