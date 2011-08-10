//
//  Controller.m
//  IDontKnowWhatImDoing
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "GUIController.h"
#import "SkypeClientAppDelegate.h"
#import "Global.h"

@implementation GUIController

//@synthesize currentConvo;

- (void)dataUpdated {
    NSLog(@"NEW DATA: %@",[[Global _settings] convo]);
    convoRecorded.string = [[Global _settings] convo];
}

- (id)init {
    self = [super init];
    if(self) {
        [[Global _settings] addListener:self];
    }
    return self;
}

- (void)dealloc {
    [[Global _settings] removeListener:self];
    [super dealloc];
}

- (IBAction)sendChatMessage:(id)sender {
    
    // add the text to the display box
    /*if (currentConvo == nil) {
        currentConvo = @"";
    }*/
    
    /*NSData *received = [[Singleton readHandle] availableData];
    if (received) {
        NSString *test2;
        test2 = [[NSString alloc] initWithData:received encoding:NSUTF8StringEncoding];
        //NSLog(@"read data: %@:)\n", test2);
        currentConvo = [[currentConvo stringByAppendingString:test2] copy];
    }*/
    
    // send the message
    NSString *entered =  [[text stringValue] stringByAppendingString:@"\n"];
    NSData *sending;
    
    sending = [entered dataUsingEncoding:NSASCIIStringEncoding
                    allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
    
    if ([entered length] >= 4) {
        if ([entered isEqualToString:@"testing13\n"]) {
            entered = @"*********\n";
        }
    } else {
        entered = @"\n";
    }
    
    
    [[Global _settings] setConvo:[[[Global _settings] convo] stringByAppendingString:entered]];
    
    NSLog(@"Singleton is: %@",[[Global _settings] convo]);


    
    //[[Global convoRecorded] setString:[Global currentConvo]];
    //[convoRecorded insertText:currentConvo];
    NSLog(@"DING");
    
    // reset the text field
    [text setStringValue:@""];
    
}


@end
