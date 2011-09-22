//
//  SearchEngine.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 15/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



@interface SearchEngine : NSObject

@property (retain) NSMutableArray *searchResults;

- (void) performSearch:(NSString *)searchTerm forUser:(NSString *)loggedInUser;

@end
