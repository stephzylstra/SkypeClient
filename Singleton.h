//
//  Singleton.h
//  SkypeClient
//
//  Created by Stephanie Zylstra on 8/08/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Singleton : NSObject {
}

+ (NSFileHandle *) writeHandle;
+ (NSFileHandle *) readHandle;
+ (NSPipe *) readPipe;
+ (NSPipe *) writePipe;
+ (NSMutableString *) currentConvo;
+ (void) setCurrentConvo:(NSString *)newVal;



@end


static NSMutableString *current = nil;
