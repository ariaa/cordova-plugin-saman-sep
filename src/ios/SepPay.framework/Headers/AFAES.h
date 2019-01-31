//
//  AFAES.h
//  SepPayCores
//
//  Created by Izadpanah on 7/18/17.
//  Copyright © 2017 Sep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>
@interface AFAES : NSObject

@property (nonatomic, copy, readonly) NSData *key;
@property (nonatomic, copy, readonly) NSData *iv;

+ (instancetype)sharedAFAES;

- (void)updateKeyWithKeySize:(unsigned int)keySize;
- (void)updateIV;

- (NSData *)AES128Encrypt:(NSData *)plainData;
- (NSData *)AES128Decrypt:(NSData *)cipherData;
- (NSData *)AES192Encrypt:(NSData *)plainData;
- (NSData *)AES192Decrypt:(NSData *)cipherData;
- (NSData *)AES256Encrypt:(NSData *)plainData;
- (NSData *)AES256Decrypt:(NSData *)cipherData;
- (NSData *)doCipher:(NSData *)data
                 key:(NSData *)key
                  iv:(NSData *)iv
           operation:(CCOperation)operation;

@end
