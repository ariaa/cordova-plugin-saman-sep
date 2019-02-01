#import "CordovaSamanSEPPlugin.h"
#import <SepPay/SepPay.h>
#import <Cordova/CDVAvailability.h>

@implementation CordovaSamanSEPPlugin

- (void)pluginInitialize {
}

- (void)test:(CDVInvokedUrlCommand *)command {
  NSLog(@"test function called");
  NSString* merchantId = [command.arguments objectAtIndex:0];
  NSString* cellphone = [command.arguments objectAtIndex:1];
  NSString* concatenatedPaymentParams = [command.arguments objectAtIndex:2];
  NSString* additionalData = [command.arguments objectAtIndex:3];
  [[SepPayCore sharedInstance] initWithMerchantID: merchantId];
  // [[SepPayCore sharedInstance] startPaymentWithMSISDN:@"MSISDN" additionalDa- ta:@“ADDITIONAL-DATA" paymentParams:@“PAYMENT-PARAMS" completion:^(BOOL success, NSString *code, NSString *msg, NSString *urn, NSString *mrn) {
  // [[SepPayCore sharedInstance] startPaymentWithMSISDN:@"MSISDN" additionalDa- ta:@“ADDITIONAL-DATA" paymentParams:@“40|123456789|987654321" completion:^(BOOL success, NSString *code, NSString *msg, NSString *urn, NSString *mrn) {
  [[SepPayCore sharedInstance] startPaymentWithMSISDN:cellphone additionalData:additionalData paymentParams:concatenatedPaymentParams completion:^(BOOL success, NSString *code, NSString *msg, NSString *urn, NSString *mrn) {
    if (success) {
      // پرداخت موفق
      NSLog(@"successful payment");
    } else {
      // پرداخت ناموفق
      NSLog(@"payment failure");
    }
  ]};
}

- (void)echo:(CDVInvokedUrlCommand *)command {
  NSLog(@"echo Your message here");
  NSString* phrase = [command.arguments objectAtIndex:0];
  NSLog(@"%@", phrase);
}

- (void)getDate:(CDVInvokedUrlCommand *)command {
  NSLog(@"getDate Your message here");
  NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
  NSLocale *enUSPOSIXLocale = [NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"];
  [dateFormatter setLocale:enUSPOSIXLocale];
  [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ssZZZZZ"];

  NSDate *now = [NSDate date];
  NSString *iso8601String = [dateFormatter stringFromDate:now];

  CDVPluginResult *result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:iso8601String];
  [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

@end
