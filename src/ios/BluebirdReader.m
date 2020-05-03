#import "BluebirdReader.h"
#include "libs/include/BTReader.h"

@implementation BluebirdReader

BTReader *pBTReader;

- (void) search:(CDVInvokedUrlCommand *)command
{
    pBTReader = [[BTReader alloc] init];
    [pBTReader BT_StartScan];
    CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void) connect:(CDVInvokedUrlCommand *)command
{
    // NSString *myarg = [command.arguments objectAtIndex:0];

    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Mooooooooooo"];

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
