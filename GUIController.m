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

- (void) dataUpdated {
    convoRecorded.string = [[Global _settings] convo];
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

    } else {
        
        NSArray *correctRow = (NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]];
        
        
        if ([[tableColumn identifier] isEqualToString:@"sender"]) {
            result = [tableView makeViewWithIdentifier:@"sender" owner:self];
            result.textField.stringValue = [[correctRow objectAtIndex:0] objectAtIndex:row];
        } else {
            result = [tableView makeViewWithIdentifier:@"conversation" owner:self];
            NSLog(@"conversation message at row %ld is %@", row, [[correctRow objectAtIndex:1] objectAtIndex:row]);
            result.textField.stringValue = [[correctRow objectAtIndex:1] objectAtIndex:row];
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
        NSLog(@"empty chat message");
        return;
    }
    
    NSString *entered;
    
    // if user is logged in, the message is an actual chat message
    if ([[Global _settings] sentCount] < 5) {
        if ([[Global _settings] sentCount] == 3) { // logged in, now get contacts
            [[[Global _settings] commandProcessor] getContacts];
        }
        [[Global _settings] setSentCount:[[Global _settings] sentCount] + 1];
        entered = [[text stringValue] stringByAppendingString:@"\n"];
    } else {
        // if already logged in, we don't care about the number of lines
        entered = [[[[[NSString alloc] init] stringByAppendingString:@"hs\n"] stringByAppendingString:[text stringValue]] stringByAppendingString:@"\n"];
    }
        
    // send the message
    NSData *sending;
    
    sending = [entered dataUsingEncoding:NSASCIIStringEncoding
                    allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
    
    /*if ([entered length] >= 3) {
        if ([entered isEqualToString:@"testing13\n"]) {
            entered = @"*********\n";
        }
    } else {
        entered = @"";
    }*/
    
    
    
    //NSLog(@"Sent count is: %ld", [[Global _settings] sentCount]);
    
    /*if ([entered length] == 0) {
        [[Global _settings] addConvoLine:entered];
        [[Global _settings] addConvoSpeakers:entered];
        [((SkypeClientAppDelegate *)skypeAppDelegate)._tableview reloadData];
    }*/


    
    //NSLog(@"Singleton is: %@",[[Global _settings] convo]);
    //[[Global convoRecorded] setString:[Global currentConvo]];
    //[convoRecorded insertText:currentConvo];
    //NSLog(@"DING");
    
    // reset the text field
    [text setStringValue:@""];
    
}


@end
