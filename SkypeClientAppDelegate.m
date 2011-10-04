//
//  SkypeClientAppDelegate.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "SkypeClientAppDelegate.h"
#import "Global.h"


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
@synthesize window;
@synthesize _convoTableView;
@synthesize loggedInUsername;
@synthesize loggedInImage;


- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    // start up Skype runtime kit (needs to be running straight up)
    runtime = [[NSTask alloc] init];
    [runtime setLaunchPath:@"/Users/stephaniezylstra/Desktop/mac-x86-skypekit-novideo_3.4.1.741_371149/bin/mac-x86/mac-x86-skypekit-novideo"];
    [runtime launch];   
    
    // sleep to make sure it has started up
    sleep(1);
    
    // set up mutex for threading
    lock = [[NSLock alloc] init];
    
    // start up C++ application which handles the data
    processor = [[NSTask alloc] init];
    [processor setLaunchPath:@"/Users/stephaniezylstra/Desktop/skypekit-sdk_sdk-3.4.1.11_342604/interfaces/skype/cpp_embedded/build/skypekitclient"];
    NSArray *arguments;
    arguments = [NSArray arrayWithObjects: @"-t", @"/Users/stephaniezylstra/Desktop/skypekit-sdk_sdk-3.4.1.11_342604/interfaces/skype/cpp_embedded/build/keypair.crt", nil];
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

    
    NSString *urlText = [NSString stringWithString:@"http://stephaniezylstra.com/private/studio3/conv_started_graph.php?you=20&them=80"];
    [[convStarter mainFrame] loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:urlText]]]; 
    
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
    NSLog(@"%@", [self.selectContact objectValueOfSelectedItem]);
    
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
    
    NSInteger percentageTheyHaveStarted = 100 - [percentageYouHaveStarted intValue];
    
    NSString *urlText = [NSString stringWithFormat:@"http://stephaniezylstra.com/private/studio3/conv_started_graph.php?you=%u&them=%u", [percentageYouHaveStarted intValue], percentageTheyHaveStarted];
    
    NSLog(@"URL text is %@", urlText);
    
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
        
    } else if ([[[Global _settings] commandProcessor] isContactListChange:str]) {
        [[[Global _settings] commandProcessor] getContacts];
        
    } else if ([[[Global _settings] commandProcessor] isFileTransfer:str]) {
        
        NSString *trimmed = [str stringByReplacingOccurrencesOfString:@"FILE: " withString:@""];
        
        NSString *name = [[[Global _settings] commandProcessor] getFilename:trimmed];
        NSString *sender = [[[Global _settings] commandProcessor] getFileSender:trimmed];
        NSString *identity = [[[Global _settings] commandProcessor] getFileConversation:trimmed];
        
        
        /*[[[NSApplication sharedApplication] dockTile]setBadgeLabel:sender];*/
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
    [_convoTableView reloadData];
    [statsGeneral reloadData];

    
    [self performSelectorOnMainThread:@selector(bgThreadIsDone:) withObject:nil waitUntilDone:NO];

}

- (IBAction)doLogin:(id)sender {
    
    NSString *command = [[[[@"aL\n" stringByAppendingString:[username stringValue]] stringByAppendingString:@"\n"] stringByAppendingString:[password stringValue]] stringByAppendingString:@"\n"];
    
    NSData *sending = [command dataUsingEncoding:NSASCIIStringEncoding
                            allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
    
    [[Global _settings] setLoggedInAs:[username stringValue]];
    [loggedInUsername setStringValue:[username stringValue]];
    
}

- (void) initialiseAfterLogin {
    if ([[Global _settings] isLoggedIn]) {
        sleep(9);
        
        // set up automatic file transfer
        NSData *sending = [@"ef\n" dataUsingEncoding:NSASCIIStringEncoding
                                allowLossyConversion:YES];
        [[[Global _settings] writeHandle] writeData:sending];

        
        NSImage *userImage = [[NSImage alloc] initWithContentsOfFile:[[[@"~/Library/Application Support/SkypeClient/" stringByExpandingTildeInPath] stringByAppendingPathComponent:[loggedInUsername stringValue]] stringByAppendingPathExtension:@"jpg"]];
                
        [loggedInImage setImage:userImage];
        [[[Global _settings] commandProcessor] getContacts];
        
        //[loginWindow orderOut:self];
        
        
        [loginWindow close];
        [window makeKeyAndOrderFront:self];
        //[NSApp activateIgnoringOtherApps:YES];
    }
}

- (void) chooseConversation:(id)sender {
    
    if (sender == _convoTableView && [_convoTableView selectedRow] < [[[Global _settings] onlineContacts] count]) {
        
        NSString *conversation = (NSString *)[[[Global _settings] onlineContacts] objectAtIndex:[_convoTableView selectedRow]];
        
        NSString *command = [[@"cu\n" stringByAppendingString:conversation] stringByAppendingString:@"\n"];
        
        NSData *sending = [command dataUsingEncoding:NSASCIIStringEncoding
                                allowLossyConversion:YES];
        [[[Global _settings] writeHandle] writeData:sending];
        
        [[Global _settings] setCurrentConversation:conversation];
        
        [_tableview reloadData];
        
        
    }
    
}

- (IBAction)test:(id)sender {
        
    [NSThread detachNewThreadSelector:@selector(bgThread:) toTarget:self withObject:nil];
        
}

- (void)bgThread:(NSConnection *)connection {
        
    [statsGeneral setEnabled:NO];
    
    [statsGeneral reloadData];

    [statsWindow makeKeyAndOrderFront:self];
    
}

- (void)sendFileTransfer:(NSString *)filename {
    
    NSString *entered = [NSString stringWithFormat:@"fs\n%@\n", [filename stringByStandardizingPath]];
    NSData  *sending = [entered dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending]; 

    [self performSelectorOnMainThread:@selector(bgThreadIsDone:) withObject:[NSThread currentThread] waitUntilDone:YES];
}

- (void)bgThreadIsDone:(id)obj {
    
    /*if (obj != nil) {
        NSLog(@"BG thread %@ finished", obj);
    }
    else {
        NSLog(@"BG thread finished");

    }*/
}

- (void)processSearch:(NSString *)searchTerm {
    NSLog(@"Processing search");
    
    [[[Global _settings] searchEngine] performSearch:searchTerm forUser:[loggedInUsername stringValue]];
     
     [[[Global _settings] conversationText] setValue:[[[Global _settings] searchEngine] searchResults] forKey:@"search"];
     
     [[Global _settings] setCurrentConversation:@"search"];
     
     [_tableview reloadData];
        
}

- (IBAction)doSearch:(id)sender {
    
    NSLog(@"Searching for %@", [sender stringValue]);
    if (![[sender stringValue] isEqualToString:@""]) {
        [NSThread detachNewThreadSelector:@selector(processSearch:) toTarget:self withObject:[sender stringValue]];

    }
}


@end
