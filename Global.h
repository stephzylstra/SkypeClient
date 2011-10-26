//
//  Global.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 Stephanie Zylstra. All rights reserved.
//

// Singleton class for objects which are required over the whole application.

#import <Foundation/Foundation.h>
#import "GUIController.h"
#import "CommandProcessor.h"
#import "Statistics.h"
#import "FileProcessor.h"
#import "SearchEngine.h"


@interface Global : NSObject {
    NSFileHandle *_readHandle;
    NSFileHandle *_writeHandle;
    CommandProcessor *_commandProcessor;
    FileProcessor *fp;
    Statistics *_statistics;
    SearchEngine *_se;
}

+(Global *)_settings;

@property (retain) NSPipe *readPipe;
@property (retain) NSPipe *writePipe;
@property (retain) NSMutableArray *onlineContacts;
@property (retain) CommandProcessor *commandProcessor;
@property (retain) FileProcessor *fileProcessor;
@property (retain) Statistics *statistics;
@property (retain) SearchEngine *searchEngine;
@property NSInteger sentCount;
@property (retain) NSMutableDictionary *conversationText;
@property (copy) NSString *currentConversation;
@property BOOL isLoggedIn;
@property (retain) NSString *loggedInAs;
@property NSInteger selectedContact;
@property (retain) NSMutableDictionary *contactsAvatars;


// get a reference of the read end of the pipe to the backend process
- (NSFileHandle *)readHandle;

// get a reference to the write end of the pipe to the backend process
- (NSFileHandle *)writeHandle;

// add another contact to the list of online contacts
- (void) addOnlineContacts:(id)object;

// remove a contact from the list of online contacts
- (void) removeOnlineContacts:(id)object;

// add a conversation line
- (void) addConversation:(NSString *)key:(id)conversation;

// remove a conversation line
- (void) removeConversation:(NSString *)key;

@end