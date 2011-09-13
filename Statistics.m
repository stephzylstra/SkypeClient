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
#import "SkypeClientAppDelegate.h"

#define ONE_DAY 86400
#define FOUR_HOURS 14400

@implementation Statistics

@synthesize conversationSessions, loggedIn;

- (id)init {
    self = [super init];
    if (self) {
        // Initialization code here.
        self.conversationSessions = [[NSMutableDictionary alloc] init];
        self.loggedIn = ((SkypeClientAppDelegate *)[[NSApplication sharedApplication] delegate]).loggedInUsername.stringValue;
        
    }
    
    return self;
}


- (NSArray *) sessionsForContact:(NSString *)contact: (NSString *)loggedInAccountName {
    
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
    
    // add the array of sessions to the conversations dictionary
    if ([sessions count] > 0) {
        [[self conversationSessions] setObject:sessions forKey:contact];
    }
    
    return sessions;
}


- (NSString *) mostFrequentChats:(NSString *) loggedInAccountName {
    // returns skypename of contact with the most sessions
    
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/Users/stephaniezylstra/Library/Application Support/SkypeClient/sz.ienv3500" error:NULL];
    
    NSString *contact = nil;
    NSInteger chatCount = 0;
    
    // make sure we are comparing all contacts
    for (int i = 0; i < [files count]; i++) {
        
        if ([[files objectAtIndex:i] characterAtIndex:0] == '.') {
            continue;
        }
        
        if ([[self conversationSessions] objectForKey:[files objectAtIndex:i]] == nil) {
            // current contact has not already had sessions calculated
            NSArray *contactSessions = [self sessionsForContact:[files objectAtIndex:i] :loggedInAccountName];
            
            if (contactSessions == nil) {
                // current contact has no valid history stored
                continue;
            }
        }
        
        if ([[[self conversationSessions] objectForKey:[files objectAtIndex:i]] count] > chatCount) {
            chatCount = [[[self conversationSessions] objectForKey:[files objectAtIndex:i]] count];
            contact = [files objectAtIndex:i];
        }
    }
        
    return contact;
}


- (NSInteger) averageNumberOfLines:(NSString *) loggedInAccountName {
    
    // average number of lines per session (not per contact)
    
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/Users/stephaniezylstra/Library/Application Support/SkypeClient/sz.ienv3500" error:NULL];
    
    NSInteger totalLines = 0;
    NSInteger numSessions = 0;
    
    // make sure we are comparing all contacts
    for (int i = 0; i < [files count]; i++) {
        
        if ([[files objectAtIndex:i] characterAtIndex:0] == '.') {
            continue;
        }
        
        if ([[self conversationSessions] objectForKey:[files objectAtIndex:i]] == nil) {
            // current contact has not already had sessions calculated
            NSArray *contactSessions = [self sessionsForContact:[files objectAtIndex:i] :loggedInAccountName];
            
            if (contactSessions == nil) {
                // current contact has no valid history stored
                continue;
            }
        }
        
        
        for (int j = 0; j < [[[self conversationSessions] objectForKey:[files objectAtIndex:i]] count]; j++) {
            
            
            totalLines += [[[[self conversationSessions] objectForKey:[files objectAtIndex:i]] objectAtIndex:j] numberOfLines];
            numSessions++;
        }
        
    }
    
    return totalLines / numSessions;
    
}

- (NSDictionary *) percentageOfChatsStarted: (NSString *) loggedInAccountName {
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/Users/stephaniezylstra/Library/Application Support/SkypeClient/sz.ienv3500" error:NULL];
    
    NSMutableDictionary *percentages = [[NSMutableDictionary alloc] init];
    
    // make sure we are comparing all contacts
    for (int i = 0; i < [files count]; i++) {
        
        if ([[files objectAtIndex:i] characterAtIndex:0] == '.') {
            // hidden file (.DS_Store)
            continue;
        }
        
        NSInteger started = 0, sessions = 0, percentage;
        
        if ([[self conversationSessions] objectForKey:[files objectAtIndex:i]] == nil) {
            // current contact has not already had sessions calculated
            NSArray *contactSessions = [self sessionsForContact:[files objectAtIndex:i] :loggedInAccountName];
            
            if (contactSessions == nil) {
                // current contact has no valid history stored
                continue;
            }
        }
        
        
        for (int j = 0; j < [[[self conversationSessions] objectForKey:[files objectAtIndex:i]] count]; j++) {
            if ([[[[[self conversationSessions] objectForKey:[files objectAtIndex:i]] objectAtIndex:j] getSenderAtLine:0] isEqualToString:loggedInAccountName]) {
                started++;
            }
            sessions++;
        }
        
        percentage = ((double) started / (double) sessions) * 100;
        
        NSLog(@"You have started %ld%% of conversations with %@", percentage, [files objectAtIndex:i]);
        
        [percentages setValue:[NSNumber numberWithDouble:percentage] forKey:[files objectAtIndex:i]];
    }
    
    if ([percentages count] == 0) {
        return nil;
    }
    
    return percentages;
    
}

- (NSInteger) averageNumberOfQuestions:(NSString *) loggedInAccountName {
    // average number of lines per session that has a question mark
    
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/Users/stephaniezylstra/Library/Application Support/SkypeClient/sz.ienv3500" error:NULL];
    
    NSInteger questions = 0;
    NSInteger numSessions = 0;
    
    // make sure we are comparing all contacts
    for (int i = 0; i < [files count]; i++) {
        
        if ([[files objectAtIndex:i] characterAtIndex:0] == '.') {
            // hidden file (.DS_Store)
            continue;
        }
        
        if ([[self conversationSessions] objectForKey:[files objectAtIndex:i]] == nil) {
            // current contact has not already had sessions calculated
            NSArray *contactSessions = [self sessionsForContact:[files objectAtIndex:i] :loggedInAccountName];
            
            if (contactSessions == nil) {
                // current contact has no valid history stored
                continue;
            }
        }
        
        
        for (int j = 0; j < [[[self conversationSessions] objectForKey:[files objectAtIndex:i]] count]; j++) {
            
            numSessions++;
            
            for (int k = 0; k < [[[[self conversationSessions] objectForKey:[files objectAtIndex:i]] objectAtIndex:j] numberOfLines]; k++) {
                
                NSRange range = [[[[[self conversationSessions] objectForKey:[files objectAtIndex:i]] objectAtIndex:j] getMessageAtLine:k] rangeOfString:@"?"];
                
                if (range.location != NSNotFound) {
                    questions++;
                }
            }
        }
        
    }
    
    return questions / numSessions;
}



- (NSInteger) averageResponseTime:(NSString *) loggedInAccountName {
    // average time taken for you to reply to a message
    // should maybe consider comparing with response times from contacts
    
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/Users/stephaniezylstra/Library/Application Support/SkypeClient/sz.ienv3500" error:NULL];
    
    NSInteger totalResponseTime = 0;
    NSInteger numLines = 0;
    
    // make sure we are comparing all contacts
    for (int i = 0; i < [files count]; i++) {
        
        // iterate through contacts
        
        if ([[files objectAtIndex:i] characterAtIndex:0] == '.') {
            // hidden file (.DS_Store)
            continue;
        }
        
        if ([[self conversationSessions] objectForKey:[files objectAtIndex:i]] == nil) {
            // current contact has not already had sessions calculated
            NSArray *contactSessions = [self sessionsForContact:[files objectAtIndex:i] :loggedInAccountName];
            
            if (contactSessions == nil) {
                // current contact has no valid history stored
                continue;
            }
        }
        
        
        for (int j = 0; j < [[[self conversationSessions] objectForKey:[files objectAtIndex:i]] count]; j++) {
            
            // iterate through each contact's conversation sessions
                        
            for (int k = 1; k < [[[[self conversationSessions] objectForKey:[files objectAtIndex:i]] objectAtIndex:j] numberOfLines]; k++) {
                
                // iterate through each line of a conversation session
                                
                NSDate *currentLineDate = [[[[self conversationSessions] objectForKey:[files objectAtIndex:i]] objectAtIndex:j] getDateAtLine:k];
                NSDate *previousLineDate = [[[[self conversationSessions] objectForKey:[files objectAtIndex:i]] objectAtIndex:j] getDateAtLine:k-1];
                
                totalResponseTime += fabs([currentLineDate timeIntervalSinceDate:previousLineDate]);
                
                numLines++;
            }
        }
    }
    return ((double) totalResponseTime / (double) numLines);
}


- (NSInteger) averageLinesForContact:(NSString *)contact whenLoggedInAs:(NSString *)loggedInAccountName {
    // the average number of lines per conversation session with this contact
    
    NSInteger totalLines = 0;
    NSInteger numSessions = 0;
    
    if ([[self conversationSessions] objectForKey:contact] == nil) {
        // contact has not already had sessions generated
        
        NSArray *contactSessions = [self sessionsForContact:contact :loggedInAccountName];
        
        if (contactSessions != nil) {
            for (int i = 0; i < [[[self conversationSessions] objectForKey:contact] count]; i++) {
                totalLines += [[[[self conversationSessions] objectForKey:contact] objectAtIndex:i] numberOfLines];
                numSessions++;
            }
            
        }
    }
    return totalLines / numSessions;
}

@end
