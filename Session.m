//
//  Session.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 3/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Session.h"

@implementation Session

@synthesize sessionDate;

- (id)init {
    self = [super init];
    if (self) {
        // Initialization code here.
        session = [[NSMutableArray alloc] init];
    }
    
    return self;
}

- (void) addConversationLine:(NSArray *)conversationLine {
    [session addObject:conversationLine];
}


- (void) removeConversationLineAtIndex:(NSInteger)index {
    [session removeObjectAtIndex:index];
}


- (NSString *) getSenderAtLine:(NSInteger)line {
    return [[session objectAtIndex:line] objectAtIndex:1];
}


- (NSString *) getMessageAtLine:(NSInteger)line {
    return [[session objectAtIndex:line] objectAtIndex:2];
}

@end
