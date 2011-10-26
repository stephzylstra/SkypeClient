//
//  Global.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 Stephanie Zylstra. All rights reserved.
//

#import "Global.h"

@implementation Global

static Global* _settings = nil;

@synthesize readPipe;
@synthesize writePipe;
@synthesize commandProcessor;
@synthesize statistics;
@synthesize fileProcessor;
@synthesize sentCount;
@synthesize onlineContacts;
@synthesize conversationText;
@synthesize currentConversation;
@synthesize isLoggedIn;
@synthesize searchEngine;
@synthesize loggedInAs;
@synthesize selectedContact;
@synthesize contactsAvatars;

+ (Global *) _settings {
	@synchronized([Global class]) {
		if (!_settings)
			_settings = [[self alloc] init];
		return _settings;
	}
	return nil;
}

- (id) init {
    self = [super init];
    if(self != nil) {
        self.onlineContacts = [[NSMutableArray alloc] init];
        self.conversationText = [[NSMutableDictionary alloc] init];
        currentConversation = @"";
        isLoggedIn = NO;
        self.readPipe = [NSPipe pipe];
        self.writePipe = [NSPipe pipe];
        self.fileProcessor = [[FileProcessor alloc] init];
        self.statistics = [[Statistics alloc] init];
        self.searchEngine = [[SearchEngine alloc] init];
        self.loggedInAs = @"";
        self.selectedContact = -1;
        self.contactsAvatars = [[NSMutableDictionary alloc] init];
    }
    return self;
}

- (NSFileHandle *)writeHandle {
    if (!_writeHandle) {
        _writeHandle = [[self.writePipe fileHandleForWriting] retain];
    }
    return _writeHandle;
}

- (NSFileHandle *)readHandle {
    if (!_readHandle) {
        _readHandle = [[self.readPipe fileHandleForReading] retain];
    }
    return _readHandle;
}

- (void) addOnlineContacts:(id)object {
    [self.onlineContacts addObject:object];
}

- (void) removeOnlineContacts:(id)object {
    [self.onlineContacts removeObject:object];
}

- (CommandProcessor *) commandProcessor {
    if (!_commandProcessor) {
        _commandProcessor = [[CommandProcessor alloc] init];
    }
    return _commandProcessor;
}

- (void) addConversation:(NSString *)key:(id)conversation {
    [conversationText setObject:conversation forKey:key];
}

- (void) removeConversation:(NSString *)key {
    [conversationText removeObjectForKey:key];
}


- (void)dealloc {
    [super dealloc];
}

@end
