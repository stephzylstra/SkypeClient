//
//  FileProcessor.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 31/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "FileProcessor.h"
#import "Global.h"

@implementation FileProcessor

@synthesize rootPath, defaultImagePath;

- (id)init {
    self = [super init];
    if (self) {
        //[self setRootPath:[@"~/Library/Application Support/SkypeClient/" stringByExpandingTildeInPath]];
        //[self setDefaultImagePath:[@"~/Library/Application Support/SkypeClient/default.jpg" stringByExpandingTildeInPath]];
        self.rootPath = [@"~/Library/Application Support/SkypeClient/" stringByExpandingTildeInPath];
        self.defaultImagePath = [@"~/Library/Application Support/SkypeClient/default.jpg" stringByExpandingTildeInPath];
    }
    
    return self;
}

- (NSString *) filePath: (NSString *)conversation: (NSString *)loggedInAccount {
    NSString *path = [rootPath stringByAppendingPathComponent:loggedInAccount];
    BOOL isDir;
    if (!([[NSFileManager defaultManager] fileExistsAtPath:path isDirectory:&isDir]) && isDir) {
        [[NSFileManager defaultManager] createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];        
    }
    
    path = [path stringByAppendingPathComponent:conversation];
    
    NSLog(@"Using path: %@", path);
    
    return path;
}

- (NSString *) imagePath: (NSString *)loggedInAccount {
    BOOL isDir;
    if (!([[NSFileManager defaultManager] fileExistsAtPath:rootPath isDirectory:&isDir]) && isDir) {
        [[NSFileManager defaultManager] createDirectoryAtPath:rootPath withIntermediateDirectories:YES attributes:nil error:nil];        
    }
    NSString *path = [[rootPath stringByAppendingPathComponent:loggedInAccount] stringByAppendingString:@".jpg"];

    return path;
}


- (void) writeToConversation: (NSString *) conversation: (NSString *) loggedInAccount: (NSArray *) conversationLine {
    
    NSString *path = [self filePath:conversation :loggedInAccount];
            
    NSFileHandle *outputHandle = [NSFileHandle fileHandleForWritingAtPath:path];
    if(outputHandle == nil) {
        [[NSFileManager defaultManager] createFileAtPath:path contents:nil attributes:nil];
        outputHandle = [NSFileHandle fileHandleForWritingAtPath:path];
    } else {
        [outputHandle seekToEndOfFile];
    }
    
    NSString *line = [[[[conversationLine objectAtIndex:0] objectAtIndex:0] stringByAppendingString:@": "] stringByAppendingString:[[conversationLine objectAtIndex:1] objectAtIndex:0]];
    
    NSLog(@"about to write: %@", line);
    
    
   NSData *sending = [line dataUsingEncoding:NSASCIIStringEncoding
                            allowLossyConversion:YES];
    [outputHandle writeData:sending];

    
    
}


- (NSArray *) getConversation: (NSString *) conversation: (NSString *) loggedInAccount {
    
    NSString *path = [self filePath:conversation :loggedInAccount];
    
    if (![[NSFileManager defaultManager] fileExistsAtPath:path]) {
        NSLog(@"Didn't work");
        return nil;
    }
    
    NSLog(@"About to read");
    
    NSString *fileContents = [NSString stringWithContentsOfFile:path encoding:NSASCIIStringEncoding error:NULL];
    
    NSArray *lines = [fileContents componentsSeparatedByString:@"\n"];
    
    
    NSMutableArray *conversationMessages = [[NSArray alloc]
                                     initWithObjects:[[NSMutableArray alloc] init],[[NSMutableArray alloc] init], [[NSMutableArray alloc] init], nil];
    
    for (NSInteger i = 0; i < [lines count]; i++) {
        NSArray *components = [[lines objectAtIndex:i] componentsSeparatedByString:@": "];
        
        if ([components count] != 3) {
            NSLog(@"Invalid file");
            return nil;
        }
        
        [[conversationMessages objectAtIndex:0] addObject:[components objectAtIndex:0]]; // date/time
        [[conversationMessages objectAtIndex:1] addObject:[components objectAtIndex:1]]; // sender
        [[conversationMessages objectAtIndex:2] addObject:[components objectAtIndex:2]]; // message
        
    }
    
    return conversationMessages;
    //return nil;
}


- (BOOL) hasAvatar: (NSString *) contact {
    
    // TODO
    
   /*NSData *sending = [[[@"lv\n" stringByAppendingString:contact] stringByAppendingString:@"\n"] dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
        
    NSString *rawData = [[NSString alloc] initWithData:[[[Global _settings] readHandle] componentsSeparatedByString:Data] encoding:NSUTF8StringEncoding];
    
    return [rawData boolValue];*/
    
    return true;
}



- (void) testing123 {
    NSLog(@"This was okay");
}



- (NSImage *) getAvatar: (NSString *) contact {
    
    NSString *path = [self imagePath:contact];
    
    if (![[NSFileManager defaultManager] fileExistsAtPath:path]) {
        if ([self hasAvatar:contact]) {
            return [[NSImage alloc] initWithContentsOfFile:path];
        } else {
            return [[NSImage alloc] initWithContentsOfFile:defaultImagePath];
        }
    } else {
        return [[NSImage alloc] initWithContentsOfFile:path];
    }
}


@end
