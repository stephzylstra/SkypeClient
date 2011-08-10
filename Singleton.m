//
//  Singleton.m - for objects that are used over the whole application
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Singleton.h"

@implementation Singleton

- (id)init {
    self = [super init];
    return self;
}


// get a reference to the write end of the pipe to the skype command processor
+ (NSFileHandle *)writeHandle {
    static NSFileHandle *writeHandle;
    @synchronized(self) {
        if (!writeHandle) {
            writeHandle = [[[Singleton writePipe] fileHandleForWriting] retain];
        }
        return writeHandle;
    }
}

// get a reference to the read end of the pipe to the skype command processor
+ (NSFileHandle *)readHandle {
    static NSFileHandle *readHandle;
    @synchronized(self) {
        if (!readHandle) {
            readHandle = [[[Singleton readPipe] fileHandleForReading] retain];
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



@end
