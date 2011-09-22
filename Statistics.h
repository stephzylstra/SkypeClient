//
//  Statistics.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 3/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



@interface Statistics : NSObject

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


@property (retain) NSMutableDictionary *conversationSessions;
@property (copy) NSString *loggedIn;

@end
