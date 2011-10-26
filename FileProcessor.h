//
//  FileProcessor.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 31/08/11.
//  Copyright 2011 Stephanie Zylstra. All rights reserved.
//


// Handles operations that require reading/writing from the filesystem


@interface FileProcessor : NSObject


@property (copy) NSString *rootPath;
@property (copy) NSString *defaultImagePath;

// writes to logfile for the given conversation
- (void) writeToConversation:(NSString *) conversation
         withLoggedInAccount:(NSString *) loggedInAccount
            conversationLine: (NSArray *) conversationLine;

// reads logfile for given conversation
- (NSArray *) getConversation:(NSString *) conversation:(NSString *)loggedInAccount;

// fetches avatar for given contact from filesystem
- (NSImage *) getAvatar: (NSString *) contact;

// begins process of copying avatar from skype server to local filesystem
- (void) startAvatarCheck: (NSString *) contact;

// finds appropriate logfile for a conversation
- (NSString *) filePath: (NSString *)conversation: (NSString *)loggedInAccount;

// finds appropriate avatar file path for a given contact
- (NSString *) imagePath: (NSString *)loggedInAccount;


@end
