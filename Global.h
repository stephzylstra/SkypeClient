//
//  Singleton.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Global : NSObject {
    NSFileHandle *_readHandle;
    NSFileHandle *_writeHandle;
}

+(Global *)_settings;

@property (nonatomic,retain) NSMutableArray *listeners;
@property (nonatomic,retain) NSPipe *readPipe;
@property (nonatomic,retain) NSPipe *writePipe;
@property (nonatomic,copy) NSString *convo;
@property (nonatomic, retain) NSMutableArray *convoLine;

- (NSFileHandle *)readHandle;
- (NSFileHandle *)writeHandle;

- (void)addListener:(id)object;
- (void)removeListener:(id)object;
- (void)messageListeners;
- (void) addConvoLine:(id)object;
- (void) removeConvoLine:(id) objects;


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