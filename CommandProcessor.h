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
- (BOOL) isLoginCheck:(NSString *) line;
- (BOOL) isContactListChange:(NSString *) line;
- (BOOL) isFileTransfer:(NSString *)line;
- (NSString *) getFileSender:(NSString *)line;
- (NSString *) getFilename:(NSString *)line;

@end
