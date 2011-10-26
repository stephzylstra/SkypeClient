//
//  SearchEngine.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 15/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "SearchEngine.h"
#import "Global.h"

@implementation SearchEngine

@synthesize searchResults;

- (id)init {
    self = [super init];
    if (self) {
        // Initialization ca ode here.
        self.searchResults = [[NSMutableArray alloc] init];
        [self.searchResults addObject:[[NSMutableArray alloc] init]];
        [self.searchResults addObject:[[NSMutableArray alloc] init]];

    }
    
    return self;
}

- (void) performSearch:(NSString *)searchTerm forUser:(NSString *)loggedInUser {
    
    if ([[[self searchResults] objectAtIndex:0] count] > 0) {
                    
        [[[self searchResults] objectAtIndex:0] removeAllObjects];
        [[[self searchResults] objectAtIndex:1] removeAllObjects];
        
    }

    //[[self searchResults] removeAllObjects];
    
    NSString *filePath = [[@"~/Library/Application Support/SkypeClient/" stringByAppendingString:loggedInUser] stringByExpandingTildeInPath];
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:filePath error:NULL];
    
    // make sure we are comparing all contacts
    for (int i = 0; i < [files count]; i++) {
        
        if ([[files objectAtIndex:i] characterAtIndex:0] == '.') {
            continue;
        }
    
        NSArray *conv = [[[Global _settings] fileProcessor] getConversation:[files objectAtIndex:i] :loggedInUser];
        
       for (int j = 0; j < [[conv objectAtIndex:0] count]; j++) {
            
            NSRange range = [[[conv objectAtIndex:2] objectAtIndex:j] rangeOfString:searchTerm];
            
            if (range.location != NSNotFound) {
                
                [[[self searchResults] objectAtIndex:0] addObject:[[conv objectAtIndex:1] objectAtIndex:j]];
                [[[self searchResults] objectAtIndex:1] addObject:[[conv objectAtIndex:2] objectAtIndex:j]];

            } 
                                   
        } 
        
        
    }
        
}

@end
