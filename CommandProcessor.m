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

- (BOOL) isContactListChange:(NSString *) line {
    return [line hasPrefix:@"SKYPE.CONTACTLIST"];
}

- (BOOL) isFileTransfer:(NSString *)line {
    return [line hasPrefix:@"FILE: "];
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
    return message;
}


- (void) getContacts {
        
    NSApplication *appDelegate = [[NSApplication sharedApplication] delegate]; // will need to cast each time
    NSData *sending = [@"lg\n4\n" dataUsingEncoding:NSASCIIStringEncoding
                    allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
    
    NSString *rawData = [[NSString alloc] initWithData:[[[Global _settings] readHandle] availableData] encoding:NSUTF8StringEncoding];
        
    NSArray *contacts = [rawData componentsSeparatedByString:@"\n"];
    
    [[[Global _settings] onlineContacts] removeAllObjects];

    for (int i = 0; i < [contacts count]; i++) {
        if ([[contacts objectAtIndex:i] hasPrefix:@"SKYPE.Contact"]) {
            
            NSString *user = [[[contacts objectAtIndex:i] stringByReplacingOccurrencesOfString:@"SKYPE.Contact:" withString:@""] stringByReplacingOccurrencesOfString:@"\n" withString:@""];
            
            [[Global _settings] addOnlineContacts:user];
        }
    }
    
    [((SkypeClientAppDelegate *)appDelegate)._convoTableView reloadData];
    
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


@end
