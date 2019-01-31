//
//  NSString+AF.h
//  SepPayCores
//
//  Created by Izadpanah on 7/17/17.
//  Copyright © 2017 Sep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (AFHex)
- (NSString *)encodeToHexString;
- (NSString *)decodeFromHexString;
@end
