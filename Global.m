//
//  Singleton.m - for objects that are used over the whole application
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Global.h"

@implementation Global

static Global* _settings = nil;

@synthesize listeners,readPipe,writePipe, commandProcessor, statistics, fileProcessor, sentCount, onlineContacts, conversationText, currentConversation, isLoggedIn;

+ (Global *) _settings
{
	@synchronized([Global class])
	{
		if (!_settings)
			_settings = [[self alloc] init];
        
        
		return _settings;
	}
	return nil;
}

- (id) init {
    self = [super init];
    if(self != nil) {
        self.listeners = [[NSMutableArray alloc] init];
        self.onlineContacts = [[NSMutableArray alloc] init];
        self.conversationText = [[NSMutableDictionary alloc] init];
        currentConversation = @"";
        sentCount = 0;
        isLoggedIn = NO;
        self.readPipe = [NSPipe pipe];
        self.writePipe = [NSPipe pipe];
        self.fileProcessor = [[FileProcessor alloc] init];
        self.statistics = [[Statistics alloc] init];
    }
    return self;
}

- (NSFileHandle *)writeHandle {
    if (!_writeHandle) {
        _writeHandle = [[self.writePipe fileHandleForWriting] retain];
    }
    return _writeHandle;
}

// get a reference to the read end of the pipe to the skype command processor
- (NSFileHandle *)readHandle {
    if (!_readHandle) {
        _readHandle = [[self.readPipe fileHandleForReading] retain];
    }
    return _readHandle;
}

- (void) addListener:(id)object {
    [self.listeners addObject:object];
}

- (void) removeListener:(id)object {
    [self.listeners removeObject:object];
}

- (void) addOnlineContacts:(id)object {
    [self.onlineContacts addObject:object];
}

- (void) removeOnlineContacts:(id)object {
    [self.onlineContacts removeObject:object];
}

- (void) messageListeners {
    for(int i=0; i<[self.listeners count]; i++) {
        [(GUIController *)[self.listeners objectAtIndex:i] dataUpdated];
    }
}

- (CommandProcessor *) commandProcessor {
    if (!_commandProcessor) {
        _commandProcessor = [[CommandProcessor alloc] init];
    }
    return _commandProcessor;
}

/*- (Statistics *) statistics {
    if (!_statistics) {
        _statistics = [[Statistics alloc] init];
    }
    return _statistics;
}*/

/*- (FileProcessor *) fileProcessor {
    if (!fp) {
        fp = [[FileProcessor alloc] init];
    }
    return fp;
}*/


- (void) addConversation:(NSString *)key:(id)conversation {
    [conversationText setObject:conversation forKey:key];
}

- (void) removeConversation:(NSString *)key {
    
}


- (void)dealloc {
    [listeners release];
    [super dealloc];
}

@end


/*
static NSMutableArray *listeners;
+ (NSMutableArray *)listeners { return listeners; }
+ (void)setListeners:(NSMutableArray *)newVar { listeners = newVar; }


// get a reference to the write end of the pipe to the skype command processor
+ (NSFileHandle *)writeHandle {
    static NSFileHandle *writeHandle;
    @synchronized(self) {
        if (!writeHandle) {
            writeHandle = [[[Global writePipe] fileHandleForWriting] retain];
        }
        return writeHandle;
    }
}

// get a reference to the read end of the pipe to the skype command processor
+ (NSFileHandle *)readHandle {
    static NSFileHandle *readHandle;
    @synchronized(self) {
        if (!readHandle) {
            readHandle = [[[Global readPipe] fileHandleForReading] retain];
        }
        return readHandle;
    }
}


+ (NSPipe *)readPipe {
    static NSPipe *readPipe;
    
    @synchronized(self) {
        if (!readPipe)
            readPipe = [NSPipe pipe];
        return readPipe;
    }
}


+ (NSPipe *)writePipe {
    static NSPipe *writePipe;
    
    @synchronized(self) {
        if (!writePipe)
            writePipe = [NSPipe pipe];
        return writePipe;
    }
}


+ (NSMutableString *) currentConvo {
    @synchronized(self) {
        if (current == nil) {
            current = [[NSString alloc] initWithFormat:@""];
        }
        return current;
    }
}

+ (void) setCurrentConvo:(NSString *)newVal {
    current = [newVal copy];
}


+ (IBOutlet NSTextView *) convoRecorded {
    if (convoRecorded == nil) {
        convoRecorded = [[NSTextView alloc] init];
    }
    return (IBOutlet NSTextView *) convoRecorded;
}

+ (void) flush {
    NSLog(@"GOING THROUGH STUFF %d",[listeners count]);
    for(int i=0; i<[listeners count]; i++) {
        [(GUIController *)[listeners objectAtIndex:i] newDataArrived];
    }
}

+ (void)addListener:(id)object {
    //NSMutableArray *jojo = [[NSMutableArray alloc] init];
    [listeners addObject:@""];
    NSLog(@"ADDED LISTENER");
    NSLog(@"NEW COUNT %lu",[listeners count]);
}

+ (void)removeListener:(id)object {
    [listeners removeObject:object];
}

//IBOutlet NSTextView *convoRecorded;



@end*/
