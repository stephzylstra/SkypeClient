//
//  SearchEngine.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 15/09/11.
//  Copyright 2011 Stephanie Zylstra. All rights reserved.
//


// This class is used to help provide a better search experience for the user.


@interface SearchEngine : NSObject

@property (retain) NSMutableArray *searchResults;

// find search results when logged in as given user
- (void) performSearch:(NSString *)searchTerm forUser:(NSString *)loggedInUser;

@end
