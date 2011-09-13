//
//  Session.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 3/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



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
