//
//  ConversationTableCell.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 13/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "ConversationTableCell.h"

@implementation ConversationTableCell
@synthesize multilineText = _multilineText;
@synthesize filename = _filename;
@synthesize imageButton = _imageButton;


- (id)init {
    self = [super init];
    if (self) {
        [_imageButton setImagePosition:NSImageOnly];
        
        // Initialization code here.
    }
    
    return self;
}

@end
