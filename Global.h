//
//  Singleton.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CommandProcessor.h"


@interface Global : NSObject {
    NSFileHandle *_readHandle;
    NSFileHandle *_writeHandle;
    CommandProcessor *_commandProcessor;
}

+(Global *)_settings;

@property (retain) NSMutableArray *listeners;
@property (retain) NSPipe *readPipe;
@property (retain) NSPipe *writePipe;
@property (copy) NSString *convo;
@property (retain) NSMutableArray *convoLine;
@property (retain) NSMutableArray *convoSpeakers;
@property (retain) NSMutableArray *onlineContacts;
@property (retain) CommandProcessor *commandProcessor;
@property NSInteger sentCount;
@property (retain) NSMutableDictionary *conversationText;
@property (copy) NSString *currentConversation;
@property BOOL isLoggedIn;

- (NSFileHandle *)readHandle;
- (NSFileHandle *)writeHandle;

- (void) addListener:(id)object;
- (void) removeListener:(id)object;
- (void) messageListeners;
- (void) addConvoLine:(id)object;
- (void) removeConvoLine:(id) objects;
- (void) addConvoSpeakers:(id)object;
- (void) removeConvoSpeakers:(id)object;
- (void) addOnlineContacts:(id)object;
- (void) removeOnlineContacts:(id)object;
- (void) addConversation:(NSString *)key:(id)conversation;
- (void) removeConversation:(NSString *)key;

@end

/*
+ (void)setup;
+ (NSFileHandle *) writeHandle;
+ (NSFileHandle *) readHandle;
+ (NSPipe *) readPipe;
+ (NSPipe *) writePipe;
+ (NSMutableString *) currentConvo;
+ (void) setCurrentConvo:(NSString *)newVal;
+ (IBOutlet NSTextView *) convoRecorded;

+ (void)addListener:(id)object;
+ (void)removeListener:(id)object;


+ (NSMutableArray *)listeners;
+ (void)setListeners:(NSMutableArray *)newVar;

+ (void) flush;

@end

static NSMutableString *current = nil;
static NSTextView *convoRecorded = nil;*/