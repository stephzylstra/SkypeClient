//
//  Statistics.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 3/09/11.
//  Copyright 2011 Stephanie Zylstra. All rights reserved.
//

// Handles statistics processing

#import "Global.h"
#import "Session.h"
#import "SkypeClientAppDelegate.h"


@interface Statistics : NSObject

@property (retain) NSMutableDictionary *conversationSessions;
@property (copy) NSString *loggedIn;

// will find actual convo based on conversation parameter and convert that into a list of sessions
- (NSArray *) sessionsForContact:(NSString *)contact: (NSString *)loggedInAccountName;

// find contact you chat to most
- (NSString *)mostFrequentChats:(NSString *) loggedInAccountName;

// average number of lines per conversation overall (not per contact)
- (NSInteger) averageNumberOfLines:(NSString *) loggedInAccountName;

// percentage that you have started conversations with each contact
- (NSDictionary *) percentageOfChatsStarted: (NSString *) loggedInAccountName; 

// average response time overall
- (NSInteger) averageResponseTime:(NSString *) loggedInAccountName;

// average number of questions overall
- (NSInteger) averageNumberOfQuestions:(NSString *) loggedInAccountName;

// average length of each conversation (in lines) with the specific contact
- (NSInteger) averageLinesForContact:(NSString *)contact whenLoggedInAs:(NSString *)loggedInAccountName;

// time of last conversation with this particular contact
- (NSDate *) lastMessageTimeForContact:(NSString *)contact whenLoggedInAs:(NSString *)loggedInAccountName;

// average response time with a particular contact - with you/them times
- (NSArray *) averageResponseTimeForContact:(NSString *)contact whenLoggedInAs:(NSString *)loggedInAccountName;

// helper method for returning human-readable times
- (NSString *) stringFromTime:(double)time;

@end
