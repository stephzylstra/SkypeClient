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




- (void)dataUpdated {
    //NSLog(@"NEW DATA: %@",[[Global _settings] convo]);
    convoRecorded.string = [[Global _settings] convo];
}

- (int)numberOfRowsInTableView:(NSTableView *)tableView {
    //return [self.convoData count];
    [tableView reloadData];
    return [[[Global _settings] convoLine] count];
}

/*- (id)tableView:(NSTableView *)tableView objectValueForTableColumn:(NSTableColumn *)tableColumn row:(int)row {
    NSLog(@"obj val");
    NSLog(@"%@", [self.convoData objectAtIndex:row]);
    return [self.convoData objectAtIndex:row];
    
}*/




- (NSView *)tableView:(NSTableView *)tableView
   viewForTableColumn:(NSTableColumn *)tableColumn
                  row:(NSInteger)row {

    NSTableCellView *result = [tableView makeViewWithIdentifier:@"test" owner:self];
    NSLog(@"%@", result);
    result.textField.stringValue = [[[Global _settings] convoLine] objectAtIndex:row];
    return result;
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
    
    // send the message
    NSString *entered =  [[text stringValue] stringByAppendingString:@"\n"];
    NSData *sending;
    
    sending = [entered dataUsingEncoding:NSASCIIStringEncoding
                    allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
    
    if ([entered length] >= 3) {
        if ([entered isEqualToString:@"testing13\n"]) {
            entered = @"*********\n";
        }
    } else {
        entered = @"\n";
    }
    
    
    [[Global _settings] setConvo:[[[Global _settings] convo] stringByAppendingString:entered]];
    
    //NSLog(@"Singleton is: %@",[[Global _settings] convo]);


    
    //[[Global convoRecorded] setString:[Global currentConvo]];
    //[convoRecorded insertText:currentConvo];
    //NSLog(@"DING");
    
    // reset the text field
    
    
    
    [text setStringValue:@""];
    
}


@end
