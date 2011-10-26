//
//  CommandProcessor.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 17/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



@interface CommandProcessor : NSObject

// get sender of conversation line
- (NSString *) getConversationSender:(NSString *) line;

// get name to store the conversation under (usually the other person - not you)
- (NSString *) getConversationName:(NSString *) line;

// check whether the selected line is part of a conversation
- (BOOL) isConversation:(NSString *)line;

// check whether the selected line is an account command
- (BOOL) isAccountCommand:(NSString *)line;

// split line into components for later processing
- (NSArray *) splitLineAtSeparator:(NSString *) line;

// get text of conversation line
- (NSString *) getConversationMessage:(NSString *) line;

// force reload of contacts table after getting most recent list
- (void) getContacts;
- (void) populateContacts:(NSString *)text;

// check whether the line is a login check
- (BOOL) isLoginCheck:(NSString *) line;

// check whether the line is a notification the login attempt was unsuccessful
- (BOOL) isInvalidLogin:(NSString *) line;

// check whether the line shows a change in a contact's online status
- (BOOL) isContactListChange:(NSString *) line;

// check whether the line is an indication of a file transfer
- (BOOL) isFileTransfer: (NSString *)line;

// determines whethere the text is a list of online contacts
- (BOOL) isContactList: (NSString *)text;

// get sender for a file transfer
- (NSString *) getFileSender:(NSString *)line;

// get filename for a file transfer
- (NSString *) getFilename:(NSString *)line;

// get conversation for a file transfer
- (NSString *) getFileConversation:(NSString *)line;

// get first range containing emoticon syntax
- (void) getEmoticonRangeFromLine:(NSString *)line usingRange:(NSRangePointer)range;

// determine whether a call needs to be made to the Skype servers to fetch an avatar
- (BOOL) isAvatarCheck:(NSString *) str;

// store the boolean value of whether the contact has a non-default avatar
- (void) contactHasAvatar:(NSString *) text;

// add support for emoticons to the line
- (NSString *) addEmoticonSupportToLine:(NSString*)line;

@end
