#import <Cordova/CDV.h>

@interface BluebirdReader : CDVPlugin

- (void) search:(CDVInvokedUrlCommand *)command;
- (void) connect:(CDVInvokedUrlCommand *)command;

@end
