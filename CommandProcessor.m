//
//  CommandProcessor.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 17/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "CommandProcessor.h"
#import "Global.h"
#import "SkypeClientAppDelegate.h"

@implementation CommandProcessor

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


- (BOOL) isConversation:(NSString *)line {
    return [line hasPrefix:@"CHAT: "];
}

- (BOOL) isAccountCommand:(NSString *)line {
    return [line hasPrefix:@"ACCOUNT."];
}

- (BOOL) isLoginCheck:(NSString *) line {
    return [line hasPrefix:@"SKYPE.LOGGEDIN"];
}

- (BOOL) isInvalidLogin:(NSString *) line {
    return [line hasPrefix:@"SKYPE.LOGGEDOUT"];
}

- (BOOL) isContactListChange:(NSString *) line {
    return [line hasPrefix:@"SKYPE.CONTACTLIST"];
}

- (BOOL) isFileTransfer:(NSString *)line {
    return [line hasPrefix:@"FILE: "];
}

- (BOOL) isContactList: (NSString *)text {
    return [text hasPrefix:@"SKYPE.ONLINECONTACTS"];
}

- (NSString *) getFileConversation:(NSString *)line {
        return [[[[[Global _settings] commandProcessor] splitLineAtSeparator:line] objectAtIndex:1] stringByReplacingOccurrencesOfString:@"\n" withString:@""];
}

- (NSString *) getFileSender:(NSString *)line {
    return [[[[[Global _settings] commandProcessor] splitLineAtSeparator:line] objectAtIndex:0] stringByReplacingOccurrencesOfString:@"\n" withString:@""];
}

- (NSString *) getFilename:(NSString *)line {
    return [[[[[Global _settings] commandProcessor] splitLineAtSeparator:line] objectAtIndex:2] stringByReplacingOccurrencesOfString:@"\n" withString:@""];
}


- (NSString *) getConversationSender:(NSString *) line {
    NSString *sender = [line stringByReplacingOccurrencesOfString:@"CHAT: " withString:@""];
    //sender = [[sender componentsSeparatedByString:@": "] objectAtIndex:0];
    sender = [[[[Global _settings] commandProcessor] splitLineAtSeparator:sender] objectAtIndex:0];
    return sender;
}

- (NSString *) getConversationName:(NSString *) line {
    NSString *name = [line stringByReplacingOccurrencesOfString:@"CHAT: " withString:@""];
    //sender = [[sender componentsSeparatedByString:@": "] objectAtIndex:0];
    name = [[[[Global _settings] commandProcessor] splitLineAtSeparator:name] objectAtIndex:1];
    return name;
}

- (NSArray *) splitLineAtSeparator:(NSString *) line {
    NSArray *components = [line componentsSeparatedByString:@": "];
    return components;
}

- (NSString *) getConversationMessage:(NSString *) line {
    NSString *message = [line stringByReplacingOccurrencesOfString:@"CHAT: " withString:@""];
    message = [[[[Global _settings] commandProcessor] splitLineAtSeparator:message] objectAtIndex:2];
    message = [message stringByReplacingOccurrencesOfString:@"&apos;" withString:@"'"];
    message = [message stringByReplacingOccurrencesOfString:@"&quot;" withString:@"\""];
    if ([[self getConversationSender:line] isEqualToString:[[Global _settings] loggedInAs]]) {
        message = [[[Global _settings] commandProcessor] addEmoticonSupportToLine:message];        
    }
    return message;
}


- (void) populateContacts:(NSString *)text {
    
    NSArray *contacts = [text componentsSeparatedByString:@"\n"];
    [[[Global _settings] onlineContacts] removeAllObjects];
    
    for (int i = 0; i < [contacts count]; i++) {
        if ([[contacts objectAtIndex:i] hasPrefix:@"SKYPE.Contact"]) {
            
            NSString *user = [[[contacts objectAtIndex:i] stringByReplacingOccurrencesOfString:@"SKYPE.Contact:" withString:@""] stringByReplacingOccurrencesOfString:@"\n" withString:@""];
            
            [[Global _settings] addOnlineContacts:user];
        }
    }
    
    
    NSApplication *appDelegate = [[NSApplication sharedApplication] delegate]; // will need to cast each time

    [((SkypeClientAppDelegate *)appDelegate)._convoTableView reloadData];
    
    if ([[[Global _settings] onlineContacts] containsObject:[[Global _settings] currentConversation]]) {
        NSInteger index = [[[Global _settings] onlineContacts] indexOfObject:[[Global _settings] currentConversation]];
        [((SkypeClientAppDelegate *)appDelegate)._convoTableView selectRowIndexes:[NSIndexSet indexSetWithIndex:index] byExtendingSelection:NO];
    }

}

- (BOOL) isAvatarCheck:(NSString *) str {
    return [str hasPrefix:@"SKYPE.AVATAR"];
}

- (void) contactHasAvatar:(NSString *) text {
    
    NSString *trimmed = [[text stringByReplacingOccurrencesOfString:@"SKYPE.AVATAR:" withString:@""] stringByReplacingOccurrencesOfString:@"\n" withString:@""];
    NSArray *components = [trimmed componentsSeparatedByString:@":"];
    
    NSNumber *boolValue = [NSNumber numberWithBool:[[components objectAtIndex:1] boolValue]];
    
    [[[Global _settings] contactsAvatars] setObject:boolValue forKey:[components objectAtIndex:0]];
    
}

- (void) getContacts {
        
    NSData *sending = [@"lg\n" dataUsingEncoding:NSASCIIStringEncoding
                    allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
}

- (void) getEmoticonRangeFromLine:(NSString *)line usingRange:(NSRangePointer)range {
        
    NSRange startRange = [line rangeOfString:@"<ss"];
    NSRange endRange = [line rangeOfString:@"</ss>"];
    
    if (startRange.location != NSNotFound && endRange.location != NSNotFound) {
        NSRange newRange = NSUnionRange(startRange, endRange);
        range->location = newRange.location;
        range->length = newRange.length;
    } else {
        range->location = NSNotFound;
        range->length = 0;
    }
}

- (NSString *) addEmoticonSupportToLine:(NSString*)line {
    
    NSLog(@"%@", line);
    
    NSArray *emoticons = [NSArray arrayWithObjects:@":)", @":-)", @":(", @":-(", @":D", @":O", @":P", @":-P", @";)", @";-)", @";(", @";-(", nil];
    NSArray *names = [NSArray arrayWithObjects:@"smile", @"smile", @"sadsmile", @"sadsmile", @"bigsmile", @"surprised", @"tongueout", @"tongueout", @"wink", @"wink", @"crying", @"crying", nil];
    for (int i = 0; i < [emoticons count]; i++) {
        NSString *replacement = [NSString stringWithFormat:@"<ss type=\"%@\">%@</ss>", [names objectAtIndex:i], [emoticons objectAtIndex:i]];
        line = [line stringByReplacingOccurrencesOfString:[emoticons objectAtIndex:i] withString:replacement];
    }
    return line;
}


@end
