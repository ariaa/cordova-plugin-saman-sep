#import <Cordova/CDVPlugin.h>

@interface CordovaSamanSEPPlugin : CDVPlugin {
}

// The hooks for our plugin commands
- (void)test:(CDVInvokedUrlCommand *)command;
- (void)echo:(CDVInvokedUrlCommand *)command;
- (void)getDate:(CDVInvokedUrlCommand *)command;

@end
