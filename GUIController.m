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

- (id)init {
    self = [super init];
    if(self) {
        [[Global _settings] addListener:self];
        viewController = [[ContentViewController alloc] initWithNibName:@"ContentViewController" bundle:nil];
        self.popoverController = [[INPopoverController alloc] initWithContentViewController:viewController];
        self.popoverController.closesWhenPopoverResignsKey = YES;
        self.popoverController.color = [NSColor colorWithCalibratedWhite:1.0 alpha:0.8];
        self.popoverController.borderColor = [NSColor blackColor];
        self.popoverController.borderWidth = 1.0;
    }
    return self;
}

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
            
            
            if ([[Global _settings] loggedInAs] != NULL && [[Global _settings] loggedInAs] != nil) {
                switch (row) {
                    case 0:
                        result.textField.stringValue = [[[Global _settings] statistics] mostFrequentChats:[[Global _settings] loggedInAs]];
                        break;
                        
                    case 2:
                        result.textField.stringValue = [NSString stringWithFormat:@"%ld", [[[Global _settings] statistics] averageNumberOfLines:[[Global _settings] loggedInAs]]];
                        break;
                        
                    case 4:
                        result.textField.stringValue = [NSString stringWithFormat:@"%ld", [[[Global _settings] statistics] averageResponseTime:[[Global _settings] loggedInAs]]];
                        break;
                        
                    case 6:
                        result.textField.stringValue = [NSString stringWithFormat:@"%ld", [[[Global _settings] statistics] averageNumberOfQuestions:[[Global _settings] loggedInAs]]];
                        break;
                        
                    default:
                        result.textField.stringValue = @"";
                }

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
            
            NSMutableAttributedString * test = [[NSMutableAttributedString alloc] init];
            
            NSRange range;
            NSString *textLine = [NSString stringWithString:[[correctConversation objectAtIndex:1] objectAtIndex:row]];
            
            [[[Global _settings] commandProcessor] getEmoticonRangeFromLine:textLine usingRange:&range];
                        
            while (range.location != NSNotFound) {
                NSRange start = [[textLine substringWithRange:range] rangeOfString:@"\""];
                                
                [test appendAttributedString:[[NSAttributedString alloc] initWithString:[textLine substringToIndex:range.location]]];
                
                NSRange end = [[[textLine substringWithRange:range] substringFromIndex:start.location + 1]
 rangeOfString:@"\""];
                                
                NSRange emoticonNameRange = NSMakeRange(start.location + 1, end.location);

                NSString *emoticonName = [[textLine substringWithRange:range] substringWithRange:emoticonNameRange];
                NSString *filePath = [[NSString stringWithFormat:@"~/Library/Application Support/SkypeClient/emoticons/%@_20.png", emoticonName] stringByExpandingTildeInPath];
                
                NSTextAttachment *ta = [[NSTextAttachment alloc] init];
                NSTextAttachmentCell *tac = [[NSTextAttachmentCell alloc] init];
                [tac setImage:[[NSImage alloc] initWithContentsOfFile:filePath]];
                [ta setAttachmentCell:tac];
                NSAttributedString *imgStr = [NSAttributedString attributedStringWithAttachment:ta];
                [test appendAttributedString:imgStr];
                
                textLine = [textLine stringByReplacingCharactersInRange:NSMakeRange(0, range.location + range.length) withString:@""];
                [[[Global _settings] commandProcessor] getEmoticonRangeFromLine:textLine usingRange:&range];                
            }
            
            [test appendAttributedString:[[NSAttributedString alloc] initWithString:textLine]];
            
            if ([[[correctConversation objectAtIndex:1] objectAtIndex:row] hasPrefix:@"FILE- "]) {
                
                NSArray *fileObjects = [[[[correctConversation objectAtIndex:1] objectAtIndex:row] stringByReplacingOccurrencesOfString:@"FILE- " withString:@""] componentsSeparatedByString:@": "];
                result.filename.stringValue = [fileObjects objectAtIndex:0];
                
                NSString *filePath;
                
                if ([[[correctConversation objectAtIndex:0] objectAtIndex:row] isEqualToString:[[Global _settings] loggedInAs]]) {
                    NSLog(@"equal");
                    filePath = [fileObjects objectAtIndex:0];
                    filePath = [filePath stringByReplacingOccurrencesOfString:@"\n" withString:@""];
                } else {
                    filePath = [[@"~/Library/Application Support/SkypeClient/Files/" stringByExpandingTildeInPath] stringByAppendingPathComponent:[[fileObjects objectAtIndex:0] stringByReplacingOccurrencesOfString:@"\n" withString:@""]];

                }
                
                NSLog(@"%@", filePath);
                
                
                if ([[filePath pathExtension] isCaseInsensitiveLike:@"jpg"] || [[filePath pathExtension] isCaseInsensitiveLike:@"png"] || [[filePath pathExtension] isCaseInsensitiveLike:@"gif"]) {                    
                    [result.imageButton setImage:[[NSImage alloc] initWithContentsOfFile:filePath]];
                    [result.imageButton setAlternateImage:[[NSImage alloc] initWithContentsOfFile:filePath]];

                    
                } else {
                    [result.imageButton setImage:[[[NSFileWrapper alloc] initWithPath:filePath] icon]];
                    [result.imageButton setAlternateImage:[[[NSFileWrapper alloc] initWithPath:filePath] icon]];
                }
                
                [result setMode:FILE_MODE];
                
            } else {
            
            //result.multilineText.stringValue = [[correctConversation objectAtIndex:1] objectAtIndex:row]; 
                
            [result.multilineText setAttributedStringValue:test];
            [result.imageButton setEnabled:NO];
                
            [result setMode:TEXT_MODE];
            
            }
            
            return result;

            
        }
        //[result.textField sizeToFit];
    }
    return nil;
    //return result;
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


- (BOOL)   tableView:(NSTableView *)pTableView 
writeRowsWithIndexes:(NSIndexSet *)pIndexSetOfRows 
        toPasteboard:(NSPasteboard*)pboard {
    return YES;
}


- (NSDragOperation)tableView:(NSTableView*)pTableView 
                validateDrop:(id )info 
                 proposedRow:(NSInteger)row 
       proposedDropOperation:(NSTableViewDropOperation)op {
       return NSDragOperationEvery;
}

- (BOOL)tableView:(NSTableView *)pTableView 
       acceptDrop:(id )info
              row:(NSInteger)pRow 
    dropOperation:(NSTableViewDropOperation)operation {
        
    NSPasteboard *pasteboard = [info draggingPasteboard];    
    NSArray *filenames = [pasteboard propertyListForType:NSFilenamesPboardType];  
    
    for (NSString *filename in filenames) {
        
        [NSThread detachNewThreadSelector:@selector(sendFileTransfer:) toTarget:[[NSApplication sharedApplication] delegate] withObject:filename];

    }
    
    //NSArray *filenames = 
    
    return YES;
}


- (IBAction)loadPopover:(id)sender {
        
    if (self.popoverController.popoverIsVisible) {
        [self.popoverController closePopover:nil];
    } else {
        viewController.imageView.image = ((NSButton *)sender).image;
        NSRect buttonBounds = [sender bounds];
        [self.popoverController showPopoverAtPoint:NSMakePoint(NSMidX(buttonBounds), NSMidY(buttonBounds)) inView:sender preferredArrowDirection:INPopoverArrowDirectionUp anchorsToPositionView:YES];
    }
    
}
@end
