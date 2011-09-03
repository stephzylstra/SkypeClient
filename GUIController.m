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
#import "FileProcessor.h"

@implementation GUIController

- (void) dataUpdated {
    //convoRecorded.string = [[Global _settings] convo];
}

- (int)numberOfRowsInTableView:(NSTableView *)tableView {
    
    if ([[tableView identifier] isEqualToString:@"contactsPane"]) {
        return (int)[[[Global _settings] onlineContacts] count];

    }
    return (int)[[(NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]] objectAtIndex:0] count];
}



- (NSView *)tableView:(NSTableView *)tableView
   viewForTableColumn:(NSTableColumn *)tableColumn
                  row:(NSInteger)row {
    
    
    NSTableCellView *result;
        
    if ([[tableView identifier] isEqualToString:@"contactsPane"]) {
        result = [tableView makeViewWithIdentifier:@"contacts" owner:self];
        result.textField.stringValue = [[[Global _settings] onlineContacts] objectAtIndex:row];        
        [result.imageView setImage:[[[Global _settings] fileProcessor] getAvatar:result.textField.stringValue]];
    } else {
        
        NSArray *correctConversation = (NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]];
        
        
        if ([[tableColumn identifier] isEqualToString:@"sender"]) {
            result = [tableView makeViewWithIdentifier:@"sender" owner:self];
            result.textField.stringValue = [[correctConversation objectAtIndex:0] objectAtIndex:row];
        } else {
            result = [tableView makeViewWithIdentifier:@"conversation" owner:self];
            result.textField.stringValue = [[correctConversation objectAtIndex:1] objectAtIndex:row];
        }
        //[result.textField sizeToFit];
    }
    return result;
}

- (id)init {
    self = [super init];
    if(self) {
        [[Global _settings] addListener:self];
        skypeAppDelegate = (SkypeClientAppDelegate *) [[NSApplication sharedApplication] delegate];
    }
    return self;
}

- (void)dealloc {
    [[Global _settings] removeListener:self];
    [super dealloc];
}

- (IBAction)sendChatMessage:(id)sender {
    
    
    if ([[text stringValue] isEqualToString:@""]) {
        return;
    }
    
    NSString *entered = [[[[[NSString alloc] init] stringByAppendingString:@"hs\n"] stringByAppendingString:[text stringValue]] stringByAppendingString:@"\n"];
    
    // send the message
    NSData  *sending = [entered dataUsingEncoding:NSASCIIStringEncoding
                             allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
    
    [text setStringValue:@""];
    
    //[[[Global _settings] commandProcessor] getContacts];
    
}


@end
