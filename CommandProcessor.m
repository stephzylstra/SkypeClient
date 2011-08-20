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
    return [line hasPrefix:@"CHAT."];
}

- (BOOL) isAccountCommand:(NSString *)line {
    return [line hasPrefix:@"ACCOUNT."];
}


- (NSString *) getConversationSender:(NSString *) line {
    NSString *sender = [line stringByReplacingOccurrencesOfString:@"CHAT." withString:@""];
    //sender = [[sender componentsSeparatedByString:@": "] objectAtIndex:0];
    sender = [[[[Global _settings] commandProcessor] splitLineAtSeparator:sender] objectAtIndex:0];
    //NSLog(@"sender is %@\n", sender);
    return sender;
}

- (NSArray *) splitLineAtSeparator:(NSString *) line {
    NSArray *components = [line componentsSeparatedByString:@": "];
    return components;
}

- (NSString *) getConversationMessage:(NSString *) line {
    NSString *message = [line stringByReplacingOccurrencesOfString:@"CHAT." withString:@""];
    //sender = [[sender componentsSeparatedByString:@": "] objectAtIndex:0];
    message = [[[[Global _settings] commandProcessor] splitLineAtSeparator:message] objectAtIndex:1];
    //NSLog(@"message is %@\n", message);
    
    
    message = [message stringByReplacingOccurrencesOfString:@"&apos;" withString:@"'"];
    message = [message stringByReplacingOccurrencesOfString:@"&quot;" withString:@"\""];
    
    return message;
}


- (void) getContacts {
    
    NSLog(@"getting contacts");
    
    NSApplication *appDelegate = [[NSApplication sharedApplication] delegate]; // will need to cast each time
        
    NSData *sending = [@"lg\n4\n" dataUsingEncoding:NSASCIIStringEncoding
                    allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
    
    NSString *rawData = [[NSString alloc] initWithData:[[[Global _settings] readHandle] availableData] encoding:NSUTF8StringEncoding];
    
    NSArray *contacts = [rawData componentsSeparatedByString:@"\n"];
    for (int i = 0; i < [contacts count]; i++) {
        if ([[contacts objectAtIndex:i] hasPrefix:@"SKYPE.Contact"]) {
            
            NSString *user = [[[contacts objectAtIndex:i] stringByReplacingOccurrencesOfString:@"SKYPE.Contact:" withString:@""] stringByReplacingOccurrencesOfString:@"\n" withString:@""];
            
            [[Global _settings] addOnlineContacts:user];
        }
    }
    
    [((SkypeClientAppDelegate *)appDelegate)._convoTableView reloadData];
    
}


@end
