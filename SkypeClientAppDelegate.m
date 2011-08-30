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
@synthesize username;
@synthesize password;
@synthesize _tableview;
@synthesize window;
@synthesize _convoTableView;

    
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    // start up Skype runtime kit (needs to be running straight up)
    runtime = [[NSTask alloc] init];
    [runtime setLaunchPath:@"/Users/stephaniezylstra/Desktop/mac-x86-skypekit-novideo_3.4.1.741_371149/bin/mac-x86/mac-x86-skypekit-novideo"];
    [runtime launch];   
    
    // sleep to make sure it has started up
    sleep(1);
    
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
    
}

-(void)applicationWillTerminate:(NSNotification *)aNotification {
    
    // need to shut down other processes
    kill([processor processIdentifier], SIGINT);
    kill([runtime processIdentifier], SIGINT);
    
    // free the memory allocated to other processes
    [processor release];
    [runtime release];
    
}

- (void)stdoutDataAvailable:(NSNotification *)notification {
    NSFileHandle *handle = (NSFileHandle *)[notification object];
    NSString *str = [[[NSString alloc] initWithData:[handle availableData] encoding:NSUTF8StringEncoding] autorelease];
    [handle waitForDataInBackgroundAndNotify];
    [[Global _settings] messageListeners];
    
    NSLog(@"%@", str);
    
    if ([[[Global _settings] commandProcessor] isConversation:str]) {
        
        NSString *name = [[[Global _settings] commandProcessor] getConversationName:str];
        NSString *sender = [[[Global _settings] commandProcessor] getConversationSender:str];

        
        /*[[[NSApplication sharedApplication] dockTile]setBadgeLabel:sender];*/
        [NSApp requestUserAttention:NSInformationalRequest];
        
        /*[[Global _settings] addConvoLine:[[[Global _settings] commandProcessor] getConversationMessage:str]];
        
        [[Global _settings] addConvoSpeakers:sender];*/
        
        NSArray *details = [[[[Global _settings] conversationText] objectForKey:name] autorelease];
        
        if (details == nil) {
            details = [[NSArray alloc]
                    initWithObjects:[[NSMutableArray alloc] init],[[NSMutableArray alloc] init], nil];
        }
        
                
        [[details objectAtIndex:0] addObject:sender];
        [[details objectAtIndex:1] addObject:[[[Global _settings] commandProcessor] getConversationMessage:str]];
        
        [[Global _settings] addConversation:name:details];
        
    } else if ([[[Global _settings] commandProcessor] isLoginCheck:str]) {
        [[Global _settings] setIsLoggedIn:YES];
        [self initialiseAfterLogin];
        
    } else if ([[[Global _settings] commandProcessor] isContactListChange:str]) {
        [[[Global _settings] commandProcessor] getContacts];
    } else {
        NSLog(@"%@", str);
    }
    
    
    [_tableview reloadData];
    if ([[(NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]] objectAtIndex:0] count] > 0) {
        [_tableview scrollRowToVisible:[[(NSArray *)[[[Global _settings] conversationText] objectForKey:[[Global _settings] currentConversation]] objectAtIndex:0] count] - 1];
    }
    [_convoTableView reloadData];

}

- (IBAction)doLogin:(id)sender {
    
    
    NSString *command = [[[[@"aL\n" stringByAppendingString:[username stringValue]] stringByAppendingString:@"\n"] stringByAppendingString:[password stringValue]] stringByAppendingString:@"\n"];
    
    NSData *sending = [command dataUsingEncoding:NSASCIIStringEncoding
                            allowLossyConversion:YES];
    [[[Global _settings] writeHandle] writeData:sending];
        
    //[_tableview reloadData];
    
}

- (void) initialiseAfterLogin {
    NSLog(@"inside initialise");
    if ([[Global _settings] isLoggedIn]) {
        sleep(5);
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


@end
