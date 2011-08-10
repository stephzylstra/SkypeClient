//
//  Singleton.m - for objects that are used over the whole application
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Global.h"
#import "GUIController.h"

@implementation Global

static Global* _settings = nil;

@synthesize listeners,readPipe,writePipe,convo;

+(Global*)_settings
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
        self.listeners = [[[NSMutableArray alloc] init] autorelease];
        convo = @"";
        self.readPipe = [NSPipe pipe];
        self.writePipe = [NSPipe pipe];
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

- (void)addListener:(id)object {
    [self.listeners addObject:object];
}

- (void)removeListener:(id)object {
    [self.listeners removeObject:object];
}

- (void)messageListeners {
    NSLog(@"ZZ NEW COUNT %lu",[listeners count]);
    for(int i=0; i<[self.listeners count]; i++) {
        [(GUIController *)[self.listeners objectAtIndex:i] dataUpdated];
        NSLog(@"XX %@",[self.listeners objectAtIndex:i]);
    }
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