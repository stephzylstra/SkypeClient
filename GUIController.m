//
//  Controller.m
//  IDontKnowWhatImDoing
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "GUIController.h"
#import "SkypeClientAppDelegate.h"
#import "Singleton.h"

@implementation GUIController

//@synthesize currentConvo;

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
    [[Singleton writeHandle] writeData:sending];
    
    if ([entered length] >= 4) {
        if ([entered isEqualToString:@"testing13\n"]) {
            entered = @"*********\n";
        }
    } else {
        entered = @"\n";
    }
    
    
    [Singleton setCurrentConvo:[[[Singleton currentConvo] stringByAppendingString:entered] copy]];
    
    NSLog(@"Singleton is: %@", [Singleton currentConvo]);


    
    [convoRecorded setString:[Singleton currentConvo]];
    //[convoRecorded insertText:currentConvo];
    
    
    // reset the text field
    [text setStringValue:@""];
    
}


@end
