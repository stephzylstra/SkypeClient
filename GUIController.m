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
#import "ConversationTableCell.h"

@implementation GUIController
@synthesize generalStats, popoverController;

- (void) dataUpdated {
    //convoRecorded.string = [[Global _settings] convo];
}

- (int)numberOfRowsInTableView:(NSTableView *)tableView {
    
    if ([[tableView identifier] isEqualToString:@"contactsPane"]) {
        return (int)[[[Global _settings] onlineContacts] count];

    } else if ([[tableView identifier] isEqualToString:@"generalStatistics"]) {
        return 8; // double spacing
    }
    return (int)[[(NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]] objectAtIndex:0] count];
}



- (NSView *)tableView:(NSTableView *)tableView
   viewForTableColumn:(NSTableColumn *)tableColumn
                  row:(NSInteger)row {
    
    
        
    if ([[tableView identifier] isEqualToString:@"contactsPane"]) {
        NSTableCellView *result;

        result = [tableView makeViewWithIdentifier:@"contacts" owner:self];
        result.textField.stringValue = [[[Global _settings] onlineContacts] objectAtIndex:row];        
        [result.imageView setImage:[[[Global _settings] fileProcessor] getAvatar:result.textField.stringValue]];
        
        return result;
        
        
    } else if ([[tableView identifier] isEqualToString:@"generalStatistics"]) {
        
        NSTableCellView *result;
        
        if ([[tableColumn identifier] isEqualToString:@"statDescription"]) {
            result = [tableView makeViewWithIdentifier:@"statDescription" owner:self];
            
            switch (row) {
                case 0:
                    result.textField.stringValue = @"Contact you talk to most:";
                    break;
                    
                case 2:
                    result.textField.stringValue = @"Average # lines per conversation:";
                    break;
                    
                case 4:
                    result.textField.stringValue = @"Average response time (seconds):";
                    break;
                    
                case 6:
                    result.textField.stringValue = @"Average # questions per conversation:";
                    break;
                
                default:
                    result.textField.stringValue = @"";
                    break;
            }
            
        } else {
            result = [tableView makeViewWithIdentifier:@"statData" owner:self];
            
            
            switch (row) {
                case 0:
                    result.textField.stringValue = [[[Global _settings] statistics] mostFrequentChats:@"sz.ienv3500"];

                    break;
                    
                case 2:
                    result.textField.stringValue = [NSString stringWithFormat:@"%ld", [[[Global _settings] statistics] averageNumberOfLines:@"sz.ienv3500"] ];

                    break;
                    
                case 4:
                    result.textField.stringValue = [NSString stringWithFormat:@"%ld", [[[Global _settings] statistics] averageResponseTime:@"sz.ienv3500"]];
                    break;
                    
                case 6:
                    result.textField.stringValue = [NSString stringWithFormat:@"%ld", [[[Global _settings] statistics] averageNumberOfQuestions:@"sz.ienv3500"]];
                    break;
                    
                default:
                    result.textField.stringValue = @"";
            }
        }
        
        return result;
        
    } else {
        
        NSArray *correctConversation = (NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]];
        

        
        if ([[tableColumn identifier] isEqualToString:@"sender"]) {
            
            NSTableCellView *result;
            
            result = [tableView makeViewWithIdentifier:@"sender" owner:self];
            result.textField.stringValue = [[correctConversation objectAtIndex:0] objectAtIndex:row];
            [result.imageView setImage:[[[Global _settings] fileProcessor] getAvatar:result.textField.stringValue]];
            
            //result.multilineText.stringValue = [[correctConversation objectAtIndex:0] objectAtIndex:row];
            
            return result;
                        
        } else {
            
            ConversationTableCell *result;
            
            result = [tableView makeViewWithIdentifier:@"conversation" owner:self];
            
            
            if ([[[correctConversation objectAtIndex:1] objectAtIndex:row] hasPrefix:@"FILE- "]) {
                NSArray *fileObjects = [[[[correctConversation objectAtIndex:1] objectAtIndex:row] stringByReplacingOccurrencesOfString:@"FILE- " withString:@""] componentsSeparatedByString:@": "];
                result.filename.stringValue = [fileObjects objectAtIndex:0];
                
                
                NSString *filePath = [[@"~/Library/Application Support/SkypeClient/Files/" stringByExpandingTildeInPath] stringByAppendingPathComponent:[fileObjects objectAtIndex:0]];
                
                
                if ([[filePath pathExtension] isCaseInsensitiveLike:@"jpg"] || [[filePath pathExtension] isCaseInsensitiveLike:@"png"] || [[filePath pathExtension] isCaseInsensitiveLike:@"gif"]) {                    
                    [result.imageButton setImage:[[NSImage alloc] initWithContentsOfFile:filePath]];
                    [result.imageButton setAlternateImage:[[NSImage alloc] initWithContentsOfFile:filePath]];

                    
                } else {
                    [result.imageButton setImage:[[[NSFileWrapper alloc] initWithPath:filePath] icon]];
                    [result.imageButton setAlternateImage:[[[NSFileWrapper alloc] initWithPath:filePath] icon]];
                }
                
            } else {
            
            result.multilineText.stringValue = [[correctConversation objectAtIndex:1] objectAtIndex:row]; 
            [result.imageButton setEnabled:NO];
            
            }
            
            return result;

            
        }
        //[result.textField sizeToFit];
    }
    return nil;
    //return result;
}

- (id)init {
    self = [super init];
    if(self) {
        [[Global _settings] addListener:self];
        skypeAppDelegate = (SkypeClientAppDelegate *) [[NSApplication sharedApplication] delegate];
        viewController = [[[ContentViewController alloc] initWithNibName:@"ContentViewController" bundle:nil] autorelease];
        self.popoverController = [[[INPopoverController alloc] initWithContentViewController:viewController] autorelease];
        self.popoverController.closesWhenPopoverResignsKey = NO;
        self.popoverController.color = [NSColor colorWithCalibratedWhite:1.0 alpha:0.8];
        self.popoverController.borderColor = [NSColor blackColor];
        self.popoverController.borderWidth = 2.0;
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


- (IBAction)loadPopover:(id)sender {
    
    NSLog(@"Processing popover");
    
    if (self.popoverController.popoverIsVisible) {
        [self.popoverController closePopover:nil];
    } else {
        viewController.imageView.image = ((NSButton *)sender).image;
        NSRect buttonBounds = [sender bounds];
        [self.popoverController showPopoverAtPoint:NSMakePoint(NSMidX(buttonBounds), NSMidY(buttonBounds)) inView:sender preferredArrowDirection:INPopoverArrowDirectionUp anchorsToPositionView:YES];
    }
    
}
@end
