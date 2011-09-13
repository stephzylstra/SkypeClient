//
//  FileProcessor.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 31/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



@interface FileProcessor : NSObject


@property (copy) NSString *rootPath;
@property (copy) NSString *defaultImagePath;


- (void) writeToConversation:(NSString *)conversation withLoggedInAccount:(NSString *)loggedInAccount conversationLine: (NSArray *) conversationLine;
- (NSArray *) getConversation: (NSString *) conversation: (NSString *) loggedInAccount;
- (NSImage *) getAvatar: (NSString *) contact;
- (BOOL) hasAvatar: (NSString *) contact;
- (NSString *) filePath: (NSString *)conversation: (NSString *)loggedInAccount;
- (NSString *) imagePath: (NSString *)loggedInAccount;
- (void) testing123;



@end
