//
//  NSData+AF.h
//  SepPayCores
//
//  Created by Izadpanah on 7/17/17.
//  Copyright © 2017 Sep. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>

@interface NSData (AFBase64)
- (NSString *)base64EncodedString;
- (NSData *)base64EncodedData;
+ (NSData *)base64DecodeDataWithString:(NSString *)base64String;
+ (NSData *)base64DecodedDataWithData:(NSData *)base64Data;
- (NSData *)base64DecodedData;
@end

@interface NSData (AFMessageDigest)
- (NSData *)MD5;
- (NSData *)SHA1;
- (NSData *)SHA224;
- (NSData *)SHA256;
- (NSData *)SHA384;
- (NSData *)SHA512;
@end

@interface NSData (AFHex)
- (NSData *)enccodeToHexData;
- (NSData *)decodeFromHexData;
- (NSData *)encodeToHexString;
@end

@interface NSData (AFCryptoPRNG)
+ (NSData *)generateSecureRandomData:(size_t)length;
@end

@interface NSData (AFHmac)
+ (NSData *)generateHmacKeyForAlgorithm:(CCHmacAlgorithm)algorithm;
- (NSData *)HmacWithAlgorithm:(CCHmacAlgorithm)algorithm key:(NSData *)key;
@end

@interface NSData (AFSymmetricKeyGenerator)
+ (NSData *)generateSymmetricKeyForAlgorithm:(CCAlgorithm)algorithm;
+ (NSData *)generateSymmetricKeyForAlgorithm:(CCAlgorithm)algorithm keySize:(unsigned int)keySize;
@end

@interface NSData (AFIVGenerator)
+ (NSData *)generateIVForAlgorithm:(CCAlgorithm)algorithm;
@end

@interface NSData (AFSymmetricEncryptionDecryption)
- (NSData *)doBlockCipherWithAlgorithm:(CCAlgorithm)algorithm key:(NSData *)key iv:(NSData *)iv operation:(CCOperation)operation isPKCS7Padding:(BOOL)isPKCS7Padding;
- (NSData *)doBlockCipherWithAlgorithm:(CCAlgorithm)algorithm key:(NSData *)key iv:(NSData *)iv operation:(CCOperation)operation isPKCS7Padding:(BOOL)isPKCS7Padding isECB:(BOOL)isECB;
@end
