//
//  ConversationTableCell.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 13/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <AppKit/AppKit.h>
#define TEXT_MODE 1
#define FILE_MODE 2

@interface ConversationTableCell : NSTableCellView

@property (nonatomic, retain) IBOutlet NSTextField *multilineText;
@property (nonatomic, retain) IBOutlet NSTextField *filename;
@property (nonatomic, retain) IBOutlet NSButton *imageButton;

- (void) setMode:(NSInteger) mode;

@end
