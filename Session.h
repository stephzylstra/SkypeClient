//
//  Session.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 3/09/11.
//  Copyright 2011 Stephanie Zylstra. All rights reserved.
//



// Session class stores conversation details, grouped by conversation
// name. Each session consists of conversation messages that appear to be
// a single conversation session.

@interface Session : NSObject {
    
    NSMutableArray *session;
    
}

@property (retain) NSDate *sessionDate;

- (void) addConversationLine:(NSArray *)conversationLine;
- (void) removeConversationLineAtIndex:(NSInteger)index;
- (NSString *) getSenderAtLine:(NSInteger)line;
- (NSString *) getMessageAtLine:(NSInteger)line;
- (NSDate *) getDateAtLine:(NSInteger)line;
- (NSInteger) numberOfLines;

@end
