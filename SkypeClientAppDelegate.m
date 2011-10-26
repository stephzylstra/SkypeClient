//
//  SkypeClientAppDelegate.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "SkypeClientAppDelegate.h"
#import "Global.h"
#import <unistd.h>


@implementation SkypeClientAppDelegate
@synthesize selectContact;
@synthesize individualLastConversation;
@synthesize statsGeneral;
@synthesize convStarter;
@synthesize individualAverageLines;
@synthesize individualResponseTimeYou;
@synthesize individualResponseTimeThem;
@synthesize username;
@synthesize password;
@synthesize _tableview;
@synthesize loginButton;
@synthesize window;
@synthesize _convoTableView;
@synthesize loggedInUsername;
@synthesize loggedInImage;
@synthesize progressPanel;
@synthesize progress;


- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    // start up Skype runtime kit (needs to be running straight up)
    runtime = [[NSTask alloc] init];
    [runtime setLaunchPath:[@"~/Library/Application Support/SkypeClient/runtime/mac-x86-skypekit-novideo" stringByExpandingTildeInPath]];
    [runtime launch];   
    
    // sleep to make sure it has started up
    sleep(1);
    
    // set up mutex for threading
    lock = [[NSLock alloc] init];
    
    // start up C++ application which handles the data
    processor = [[NSTask alloc] init];
    
    [processor setLaunchPath:[@"~/Library/Application Support/SkypeClient/runtime/skypekitclient" stringByExpandingTildeInPath]];
    NSArray *arguments;
    arguments = [NSArray arrayWithObjects: @"-t", [@"~/Library/Application Support/SkypeClient/runtime/keypair.pem" stringByExpandingTildeInPath], nil];
    [processor setArguments: arguments];
    [processor setStandardInput:[[Global _settings] writePipe]];
    
    // set up reading from the C++ app
    [processor setStandardOutput:[[Global _settings] readPipe]];
    
    // actually launch the app
    [processor launch];
    
    // cause the read handle to start watching for new messages
    [[[Global _settings] readHandle] waitForDataInBackgroundAndNotify];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(stdoutDataAvailable:) name:NSFileHandleDataAvailableNotification object:[[Global _settings] readHandle]];
    
    // associate clicks on contact list with a conversation
    [_convoTableView setAction:@selector(chooseConversation:)];
    
    // tell table view to handle external dragging
    [_tableview registerForDraggedTypes:
     [NSArray arrayWithObjects:@"ConversationTableCell", NSFilenamesPboardType, @"public.utf8-plain-text", nil] ];
    [_tableview setDraggingSourceOperationMask:NSDragOperationCopy forLocal:NO];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(statisticsSelectionUpdated:) name:NSComboBoxSelectionDidChangeNotification object:nil];
    
}

-(void)applicationWillTerminate:(NSNotification *)aNotification {
    
    // need to shut down other processes
    kill([processor processIdentifier], SIGINT);
    kill([runtime processIdentifier], SIGINT);
    
    // free the memory allocated to other processes
    [processor release];
    [runtime release];
    
}

- (void)statisticsSelectionUpdated:(NSNotification *)notification {
    
    NSDateFormatter *df = [[NSDateFormatter alloc] init];
    [df setDoesRelativeDateFormatting:YES];
    [df setAMSymbol:@"am"];
    [df setPMSymbol:@"pm"];
    [df setDateStyle:NSDateFormatterShortStyle];
    [df setTimeStyle:NSDateFormatterShortStyle];
        
    [individualLastConversation setStringValue:[NSString stringWithFormat:@"Last conversation: %@", [df stringFromDate:[[[Global _settings] statistics] lastMessageTimeForContact:[self.selectContact objectValueOfSelectedItem] whenLoggedInAs:[[Global _settings] loggedInAs]]]]];
        
    [individualAverageLines setStringValue:[NSString stringWithFormat:@"Lines: %u", [[[Global _settings] statistics] averageLinesForContact:[selectContact objectValueOfSelectedItem] whenLoggedInAs:[[Global _settings] loggedInAs]]]];
        
    NSArray *responseTimes = [[[Global _settings] statistics] averageResponseTimeForContact:[self.selectContact objectValueOfSelectedItem] whenLoggedInAs:[[Global _settings] loggedInAs]];
        
    [individualResponseTimeYou setStringValue:[NSString stringWithFormat:@"You: %@", [[[Global _settings] statistics] stringFromTime:[[responseTimes objectAtIndex:0] longLongValue]]]];
    
    [individualResponseTimeThem setStringValue:[NSString stringWithFormat:@"Them: %@", [[[Global _settings] statistics] stringFromTime:[[responseTimes objectAtIndex:1] longLongValue]]]];
    
    NSNumber *percentageYouHaveStarted = [[[[Global _settings] statistics] percentageOfChatsStarted: [[Global _settings] loggedInAs]] objectForKey:[self.selectContact objectValueOfSelectedItem]];
    
    // graph doesn't work if one of the values is 0/100
    if ([percentageYouHaveStarted intValue] == 100) percentageYouHaveStarted = [NSNumber numberWithInt:99];
    if ([percentageYouHaveStarted intValue] == 0) percentageYouHaveStarted = [NSNumber numberWithInt:1];

    
    NSInteger percentageTheyHaveStarted = 100 - [percentageYouHaveStarted intValue];
    
    NSString *urlText = [NSString stringWithFormat:@"http://stephaniezylstra.com/private/studio3/conv_started_graph.php?you=%u&them=%u", [percentageYouHaveStarted intValue], percentageTheyHaveStarted];
    
    [[convStarter mainFrame] loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:urlText]]]; 
}

- (void)stdoutDataAvailable:(NSNotification *)notification {

    NSFileHandle *handle = (NSFileHandle *)[((NSNotification *)notification) object];
    [lock lock];
    NSString *str = [[NSString alloc] initWithData:[handle availableData] encoding:NSUTF8StringEncoding];
    [handle waitForDataInBackgroundAndNotify];
    [[Global _settings] messageListeners];
    [lock unlock];
    
    [self performSelectorOnMainThread:@selector(processStdoutData:) withObject:str waitUntilDone:NO];

}

- (void) processStdoutData:(NSString *)str {
        
    if ([[[Global _settings] commandProcessor] isConversation:str]) {
        
        NSString *name = [[[Global _settings] commandProcessor] getConversationName:str];
        NSString *sender = [[[Global _settings] commandProcessor] getConversationSender:str];
        
        
        /*[[[NSApplication sharedApplication] dockTile]setBadgeLabel:sender];*/
        [NSApp requestUserAttention:NSInformationalRequest];
        
        NSArray *details = [[[Global _settings] conversationText] objectForKey:name];
        
        if (details == nil) {
            details = [[NSArray alloc]
                       initWithObjects:[[NSMutableArray alloc] init],[[NSMutableArray alloc] init], nil];
        }
        
        
        [[details objectAtIndex:0] addObject:sender];
        [[details objectAtIndex:1] addObject:[[[Global _settings] commandProcessor] getConversationMessage:str]];
        
        [[Global _settings] addConversation:name:details];
        
        [[[Global _settings] fileProcessor] writeToConversation:name withLoggedInAccount:[loggedInUsername stringValue] conversationLine: details];
        
    } else if ([[[Global _settings] commandProcessor] isLoginCheck:str]) {
        [[Global _settings] setIsLoggedIn:YES];
        [self initialiseAfterLogin];
    } else if ([[[Global _settings] commandProcessor] isInvalidLogin:str]) {
        password.stringValue = @"";
        [loginButton setTitle:@"Login"];
        [loginButton setEnabled:YES];
        [[NSAlert alertWithMessageText:@"Incorrect username/password combination" defaultButton:nil alternateButton:nil otherButton:nil informativeTextWithFormat:@""] runModal];
        
    } else if ([[[Global _settings] commandProcessor] isContactList:str]) {
        
        [NSThread detachNewThreadSelector:@selector(populateContacts:) toTarget:[[Global _settings] commandProcessor] withObject:str];
        
        [_convoTableView reloadData];
        [_convoTableView selectRowIndexes:[NSIndexSet indexSetWithIndex:index] byExtendingSelection:NO];
        [_convoTableView setSelectionHighlightStyle:NSTableViewSelectionHighlightStyleRegular];
        
        //[[[Global _settings] commandProcessor] populateContacts:str];
        
    } else if ([[[Global _settings] commandProcessor] isContactListChange:str]) {
        [[[Global _settings] commandProcessor] getContacts];
        
        [_convoTableView reloadData];
        [_convoTableView selectRowIndexes:[NSIndexSet indexSetWithIndex:index] byExtendingSelection:NO];
        [_convoTableView setSelectionHighlightStyle:NSTableViewSelectionHighlightStyleRegular];
        
    } else if ([[[Global _settings] commandProcessor] isAvatarCheck:str]) {
        [[[Global _settings] commandProcessor] contactHasAvatar:str];
        
    } else if ([[[Global _settings] commandProcessor] isFileTransfer:str]) {
        
        NSString *trimmed = [str stringByReplacingOccurrencesOfString:@"FILE: " withString:@""];
        
        NSString *name = [[[Global _settings] commandProcessor] getFilename:trimmed];
        NSString *sender = [[[Global _settings] commandProcessor] getFileSender:trimmed];
        NSString *identity = [[[Global _settings] commandProcessor] getFileConversation:trimmed];
        
        [NSApp requestUserAttention:NSInformationalRequest];
                
        NSArray *details = [[[Global _settings] conversationText] objectForKey:identity];
                
        if (details == nil) {
            details = [[NSArray alloc]
                       initWithObjects:[[NSMutableArray alloc] init],[[NSMutableArray alloc] init], nil];
        }
        
        
        [[details objectAtIndex:0] addObject:sender];
        
        NSString *message = [[@"FILE- " stringByAppendingString:name] stringByAppendingString:@"\n"];
        
        [[details objectAtIndex:1] addObject:message];
        
        [[Global _settings] addConversation:identity:details];
        
        [[[Global _settings] fileProcessor] writeToConversation:identity withLoggedInAccount:[loggedInUsername stringValue] conversationLine: details];
        
    } else {
        NSLog(@"%@", str);
    }
    
    
    [_tableview reloadData];
    if ([[(NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]] objectAtIndex:0] count] > 0) {
        [_tableview scrollRowToVisible:[[(NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]] objectAtIndex:0] count] - 1];
    }
    

    [statsGeneral reloadData];

    
    [self performSelectorOnMainThread:@selector(bgThreadIsDone:) withObject:nil waitUntilDone:NO];

}

- (IBAction)doLogin:(id)sender {
    
    [self.loginButton setTitle:@"Logging in..."];
    [self.loginButton setEnabled:NO];
    
    NSString *command = [[[[@"aL\n" stringByAppendingString:[username stringValue]] stringByAppendingString:@"\n"] stringByAppendingString:[password stringValue]] stringByAppendingString:@"\n"];
    
    NSData *sending = [command dataUsingEncoding:NSASCIIStringEncoding
                            allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
    
    [[Global _settings] setLoggedInAs:[username stringValue]];
    [loggedInUsername setStringValue:[username stringValue]];
    
}

- (void) initialiseAfterLogin {
    if ([[Global _settings] isLoggedIn]) {
        sleep(2);
        
        // set up automatic file transfer
        NSData *sending = [@"ef\n" dataUsingEncoding:NSASCIIStringEncoding
                                allowLossyConversion:YES];
        [[[Global _settings] writeHandle] writeData:sending];
        NSImage *userImage = [[NSImage alloc] initWithContentsOfFile:[[[@"~/Library/Application Support/SkypeClient/" stringByExpandingTildeInPath] stringByAppendingPathComponent:[loggedInUsername stringValue]] stringByAppendingPathExtension:@"jpg"]];
                
        [loggedInImage setImage:userImage];
        [[[Global _settings] commandProcessor] getContacts];
        [loginWindow close];
        [window makeKeyAndOrderFront:self];
        
        [NSTimer scheduledTimerWithTimeInterval:15 target:self selector:@selector(updateContactsAfterLogin:) userInfo:nil repeats:NO];
        [NSTimer scheduledTimerWithTimeInterval:30 target:self selector:@selector(updateContactsAfterLogin:) userInfo:nil repeats:NO];
        [NSTimer scheduledTimerWithTimeInterval:60 target:self selector:@selector(updateContactsAfterLogin:) userInfo:nil repeats:NO];
        [NSTimer scheduledTimerWithTimeInterval:100 target:self selector:@selector(updateContactsAfterLogin:) userInfo:nil repeats:NO];

    }
}

- (void) updateContactsAfterLogin:(NSTimer *)timer {
    [[[Global _settings] commandProcessor] getContacts];
}

- (void) chooseConversation:(id)sender {
    if (sender == _convoTableView && [_convoTableView selectedRow] < [[[Global _settings] onlineContacts] count]) {
        [[Global _settings] setSelectedContact:[_convoTableView selectedRow]];
        NSString *conversation = (NSString *)[[[Global _settings] onlineContacts] objectAtIndex:[_convoTableView selectedRow]];
        NSString *command = [[@"cu\n" stringByAppendingString:conversation] stringByAppendingString:@"\n"];
        NSData *sending = [command dataUsingEncoding:NSASCIIStringEncoding
                                allowLossyConversion:YES];
        [[[Global _settings] writeHandle] writeData:sending];
        [[Global _settings] setCurrentConversation:conversation];
        [_tableview reloadData];
        [_convoTableView reloadData];
    }
}

- (IBAction)test:(id)sender {
    [NSThread detachNewThreadSelector:@selector(bgThread:) toTarget:self withObject:nil];
}

- (void)bgThread:(NSConnection *)connection {
    
    [progressPanel makeKeyAndOrderFront:self];
    [progress startAnimation:nil];
    [statsGeneral setEnabled:NO];
    [statsGeneral reloadData];
    [statsWindow makeKeyAndOrderFront:self];
    [self performSelectorOnMainThread:@selector(statsUpdated:) withObject:[NSThread currentThread] waitUntilDone:YES];
    
}

- (void)sendFileTransfer:(NSString *)filename {
    NSString *entered = [NSString stringWithFormat:@"fs\n%@\n", [filename stringByStandardizingPath]];
    NSData  *sending = [entered dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending]; 
    [self performSelectorOnMainThread:@selector(bgThreadIsDone:) withObject:[NSThread currentThread] waitUntilDone:YES];
}

- (void)bgThreadIsDone:(id)obj {
    
}


- (void)statsUpdated:(id)obj {
    [progress stopAnimation:nil];
    [progressPanel close];
}



- (void)processSearch:(NSString *)searchTerm {
     [[[Global _settings] searchEngine] performSearch:searchTerm forUser:[loggedInUsername stringValue]];
     [[[Global _settings] conversationText] setValue:[[[Global _settings] searchEngine] searchResults] forKey:@"search"];
     [[Global _settings] setCurrentConversation:@"search"];
     [_tableview reloadData];
        
}

- (IBAction)doSearch:(id)sender {
    if (![[sender stringValue] isEqualToString:@""]) {
        [NSThread detachNewThreadSelector:@selector(processSearch:) toTarget:self withObject:[sender stringValue]];

    }
}


@end
