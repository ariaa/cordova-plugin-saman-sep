//
//  AFRSA.h
//  SepPayCores
//
//  Created by Izadpanah on 7/18/17.
//  Copyright © 2017 Sep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <CommonCrypto/CommonCrypto.h>

typedef NS_ENUM(CCOperation, AFRSAOperation) {
    AFRSAOperationEncrypt = kCCEncrypt,
    AFRSAOperationDecrypt = kCCDecrypt
};

typedef NS_ENUM(NSUInteger, AFRsaKeySizeInBits) {
    AFRSAKeySizeInBits2048 = 1 << 11,
    AFRSAKeySizeInBits1024 = 1 << 10
};

@interface AFRSA : NSObject
@property (nonatomic, readonly) SecKeyRef privateKey;
@property (nonatomic, readonly) SecKeyRef publicKey;

@property (nonatomic) SecPadding padding;
+ (instancetype)sharedAFRSA;
- (BOOL)generateKeys;
- (BOOL)generateKeys:(AFRsaKeySizeInBits)keySizeInBits;
- (BOOL)publicKeyFromDERData:(NSData *)data;
- (BOOL)keysFromPersonalInformationExchangeFile:(NSString *)filePath password:(NSString *)pwd;
- (BOOL)keysFromData:(NSData *)data password:(NSString *)pwd;
- (NSData *)encryptDataWithPublicKey:(NSData *)data;
- (NSData *)decryptDataWithPrivateKey:(NSData *)data;
- (NSData *)signDataWithPrivateKey:(NSData *)data;
- (BOOL) verifyDataWithPublicKey:(NSData *)data digitalSignature:(NSData *)digitalSignature;
@end
