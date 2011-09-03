//
//  Singleton.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GUIController.h"
#import "CommandProcessor.h"
#import "Statistics.h"
#import "FileProcessor.h"


@interface Global : NSObject {
    NSFileHandle *_readHandle;
    NSFileHandle *_writeHandle;
    CommandProcessor *_commandProcessor;
    FileProcessor *fp;
    Statistics *_statistics;
}

+(Global *)_settings;

@property (retain) NSMutableArray *listeners;
@property (retain) NSPipe *readPipe;
@property (retain) NSPipe *writePipe;
@property (retain) NSMutableArray *onlineContacts;
@property (retain) CommandProcessor *commandProcessor;
@property (retain) FileProcessor *fileProcessor;
@property (retain) Statistics *statistics;
@property NSInteger sentCount;
@property (retain) NSMutableDictionary *conversationText;
@property (copy) NSString *currentConversation;
@property BOOL isLoggedIn;

- (NSFileHandle *)readHandle;
- (NSFileHandle *)writeHandle;

- (void) addListener:(id)object;
- (void) removeListener:(id)object;
- (void) messageListeners;
- (void) addOnlineContacts:(id)object;
- (void) removeOnlineContacts:(id)object;
- (void) addConversation:(NSString *)key:(id)conversation;
- (void) removeConversation:(NSString *)key;

@end