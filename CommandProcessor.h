//
//  CommandProcessor.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 17/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



@interface CommandProcessor : NSObject

- (NSString *) getConversationSender:(NSString *) line;
- (NSString *) getConversationName:(NSString *) line;
- (BOOL) isConversation:(NSString *)line;
- (BOOL) isAccountCommand:(NSString *)line;
- (NSArray *) splitLineAtSeparator:(NSString *) line;
- (NSString *) getConversationMessage:(NSString *) line;
- (void) getContacts;

@end
