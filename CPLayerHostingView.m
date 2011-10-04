//
//  CPLayerHostingView.m
//  SkypeClient
//
//  Created by Stephanie Zylstra on 12/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "CPLayerHostingView.h"
#import "CorePlot/CorePlot.h"

@implementation CPLayerHostingView

- (id)initWithFrame:(NSRect)frame {
    self = [super initWithFrame:frame];
    /*
    if (self) {
        // create an CPXYGraph and host it inside the view
        CPTheme *theme = [CPTheme themeNamed:kCPPlainWhiteTheme];
        graph = (CPTPieChart *)[theme newGraph];	
        chartView.hostedLayer = graph;
        
        graph.paddingLeft = 10.0;
        graph.paddingTop = 10.0;
        graph.paddingRight = 10.0;
        graph.paddingBottom = 10.0;
    }
    
    */

    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    // Drawing code here.
}

@end
