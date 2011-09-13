//
//  Statistics.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 3/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



@interface Statistics : NSObject

- (NSArray *) sessionsForContact:(NSString *)contact: (NSString *)loggedInAccountName; // will find actual convo based on conversation parameter and convert that into a list of sessions


- (NSString *) mostFrequentChats:(NSString *) loggedInAccountName;
- (NSInteger) averageNumberOfLines:(NSString *) loggedInAccountName;
- (NSDictionary *) percentageOfChatsStarted: (NSString *) loggedInAccountName;
- (NSInteger) averageResponseTime:(NSString *) loggedInAccountName;
- (NSInteger) averageNumberOfQuestions:(NSString *) loggedInAccountName;
- (NSInteger) averageLinesForContact:(NSString *)contact whenLoggedInAs:(NSString *)loggedInAccountName;
@property (retain) NSMutableDictionary *conversationSessions;
@property (copy) NSString *loggedIn;

@end
