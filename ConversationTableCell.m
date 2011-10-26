//
//  ConversationTableCell.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 13/09/11.
//  Copyright 2011 Stephanie Zylstra. All rights reserved.
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
        NSArray *draggedTypeArray = [NSArray arrayWithObjects:
                                     NSFilenamesPboardType, nil];
        [self registerForDraggedTypes:draggedTypeArray];
    }
    
    return self;
}


- (void) setMode:(NSInteger) mode {
    switch (mode) {
        case TEXT_MODE:
            [_multilineText setHidden:NO];
            [_filename setHidden:YES];
            [_imageButton setHidden:YES];
            break;
            
        default:
            [_multilineText setHidden:YES];
            [_filename setHidden:NO];
            [_imageButton setHidden:NO];
            break;
    }
}

@end
