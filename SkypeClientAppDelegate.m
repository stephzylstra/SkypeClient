//
//  SkypeClientAppDelegate.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 4/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "SkypeClientAppDelegate.h"
#import "Singleton.h"


@implementation SkypeClientAppDelegate

@synthesize window;

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
    [processor setStandardInput:[Singleton writePipe]];
    
    
    // set up reading from the C++ app
    [processor setStandardOutput:[Singleton readPipe]];
        
    // actually launch the app
    [processor launch];
    
    
    // cause the read handle to start watching for new messages
    [[Singleton readHandle] waitForDataInBackgroundAndNotify];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(stdoutDataAvailable:) name:NSFileHandleDataAvailableNotification object:[Singleton readHandle]];
    
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
    NSString *str = [[NSString alloc] initWithData:[handle availableData] encoding:NSUTF8StringEncoding];
    [handle waitForDataInBackgroundAndNotify];
    [Singleton setCurrentConvo:[[[Singleton currentConvo] stringByAppendingString:str] copy]];
    NSLog(@"%@:)\n", str);
}


@end
