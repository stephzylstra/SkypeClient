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

@property (nonatomic,retain) NSMutableArray *listeners;
@property (nonatomic,retain) NSPipe *readPipe;
@property (nonatomic,retain) NSPipe *writePipe;
@property (nonatomic,copy) NSString *convo;
@property (nonatomic, retain) NSMutableArray *convoLine;
@property (nonatomic, retain) NSMutableArray *convoSpeakers;
@property (nonatomic, retain) NSMutableArray *onlineContacts;
@property (nonatomic, retain) CommandProcessor *commandProcessor;
@property (nonatomic) NSInteger sentCount;
@property (nonatomic, retain) NSMutableDictionary *conversationText;
@property (nonatomic, copy) NSString *currentConversation;

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