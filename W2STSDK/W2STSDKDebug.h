//
//  W2STSDKDebug.h
//  W2STApp
//
//  Created by Giovanni Visentini on 21/04/15.
//  Copyright (c) 2015 STMicroelectronics. All rights reserved.
//
#ifndef W2STApp_W2STSDKDebug_h
#define W2STApp_W2STSDKDebug_h

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "W2STSDKNode.h"

@protocol W2STSDKDebugOutputDelegate;

@interface W2STSDKDebug : NSObject

@property (readonly,strong) W2STSDKNode* node;
@property (nonatomic,weak,setter=setDelegate:,getter=getDelegate) id<W2STSDKDebugOutputDelegate> delegate;

-(id) initWithNode:(W2STSDKNode *)node device:(CBPeripheral *)device
         termChart:(CBCharacteristic*)termChar
          errChart:(CBCharacteristic*)errChar;
-(void) writeMessage:(NSString*)msg;

@end

@protocol W2STSDKDebugOutputDelegate
@required
-(void) debug:(W2STSDKDebug*)debug didStdOutRecived:(NSString*) msg;
-(void) debug:(W2STSDKDebug*)debug didStdErrRecived:(NSString*) msg;
-(void) debug:(W2STSDKDebug*)debug didStdInSend:(NSString*) msg error:(NSError*)error;
@end

#endif
