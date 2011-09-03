//
//  Statistics.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 3/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Statistics.h"
#import "Global.h"
#import "Session.h"

#define ONE_DAY 86400
#define FOUR_HOURS 14400

@implementation Statistics

- (id)init {
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}


- (NSArray *) sessionsForContact:(NSString *)contact: (NSString *)loggedInAccountName {
    /*if (![[NSFileManager defaultManager] fileExistsAtPath:@"test"]) {
        NSLog(@"No history with contact %@ when logged in as %@", contact, loggedInAccountName);
        return nil;
    }*/
    
    NSArray *conversation = [[[Global _settings] fileProcessor] getConversation:contact :loggedInAccountName];
    
    if (conversation == nil) {
        NSLog(@"No history with contact %@ when logged in as %@", contact, loggedInAccountName);
        return nil;
    }
    
    NSMutableArray *sessions = [[NSMutableArray alloc] init];
    
    NSDate *lastChecked = [NSDate distantPast];
    NSDateFormatter *df = [[NSDateFormatter alloc] init];
    [df setDateFormat:@"dd-MM-yyyy HH:mm"];
    
    Session *currentSession = nil;
    
    for (int i = 0; i < [[conversation objectAtIndex:0] count]; i++) {
        
        NSString *dateField = [[conversation objectAtIndex:0] objectAtIndex:i];
        NSString *senderField = [[conversation objectAtIndex:1] objectAtIndex:i];
        NSString *messageField = [[conversation objectAtIndex:2] objectAtIndex:i];
        
        NSDate *currentDate = [df dateFromString:dateField];
        
                
        if (fabs([lastChecked timeIntervalSinceDate:currentDate]) > FOUR_HOURS) {
            
            NSLog(@"Starting new session");
            
            // if a previous session existed, it's complete, so store it
            if (currentSession != nil) {
                [sessions addObject:currentSession];
                currentSession = nil;
            }
            
            // start a new session
            currentSession = [[Session alloc] init];
            [currentSession setSessionDate:currentDate];
        }
        
        // add the conversation line we're looking at to our current session
        [currentSession addConversationLine:[[NSArray alloc] initWithObjects:dateField, senderField, messageField, nil]];
        
        // update the last checked date
        lastChecked = currentDate;
    }
    
    // add the last session found
    if (currentSession != nil) {
        [sessions addObject:currentSession];
        currentSession = nil;
    }
    
    NSLog(@"There are %lu sessions", [sessions count]);
    
    return sessions;
}


- (NSArray *) mostFrequentChats:(NSString *) loggedInAccountName {
    return nil;
}


- (NSInteger) averageNumberOfLines:(NSString *) loggedInAccountName {
    return 0;
}

- (NSDictionary *) percentageOfChatsStarted: (NSString *) loggedInAccountName {
    return nil;
}

- (NSInteger) averageResponseTime:(NSString *) loggedInAccountName {
    return 0;
}

- (NSInteger) averageNumberOfQuestions:(NSString *) loggedInAccountName {
    
    return 0;
}

@end
