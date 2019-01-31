//
//  SepPayCore.h
//  SepPay
//
//  Created by Izadpanah on 7/17/17.
//  Copyright © 2017 Sep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SepPayCore : NSObject
@property BOOL ziaprod;
@property NSString *bid;
@property NSString *log;
typedef void (^PaymentStatusBlock)(BOOL success,NSString *code, NSString *msg, NSString *urn, NSString *mrn);
@property (nonatomic, copy) PaymentStatusBlock paymentStatusBlock;
+ (instancetype)sharedInstance;
+ (void)clearKeys;
- (instancetype)initWithMerchantID:(NSString *)merchantID;
- (void)startPaymentWithMSISDN:(NSString *)msisdn additionalData:(NSString *)additionalData paymentParams:(NSString *)paymentParams completion:(PaymentStatusBlock)completion;
typedef void (^RESTResponseBlock)(BOOL success, NSDictionary *response);
@property (nonatomic, copy) RESTResponseBlock responseBlock;
- (void)getInternetListWithCompletion:(RESTResponseBlock)completionBlock;
- (void)getChargeListWithCompletion:(RESTResponseBlock)completionBlock;
@end
