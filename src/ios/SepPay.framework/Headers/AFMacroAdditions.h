//
//  AFMacroAdditions.h
//  SepPayCores
//
//  Created by Izadpanah on 7/17/17.
//  Copyright © 2017 Sep. All rights reserved.
//

#ifndef AFMacroAdditions_h
#define AFMacroAdditions_h

#import <UIKit/UIKit.h>

#define AFIsSysVersionGreaterThan(__VERSION_STRING__)          ([[[UIDevice currentDevice] systemVersion] compare:(__VERSION_STRING__) options:NSNumericSearch] == NSOrderedDescending)
#define AFIsSysVersionGreaterThanOrEqualTo(__VERSION_STRING__) ([[[UIDevice currentDevice] systemVersion] compare:(__VERSION_STRING__) options:NSNumericSearch] != NSOrderedAscending)
#define AFIsSysVersionLessThan(__VERSION_STRING__)             ([[[UIDevice currentDevice] systemVersion] compare:(__VERSION_STRING__) options:NSNumericSearch] == NSOrderedAscending)
#define AFIsSysVersionLessThanOrEqualTo(__VERSION_STRING__)    ([[[UIDevice currentDevice] systemVersion] compare:(__VERSION_STRING__) options:NSNumericSearch] != NSOrderedDescending)

#define AFIOS6_0_0OrLater AFIsSysVersionGreaterThanOrEqualTo(@"6.0")
#define AFIOS6_1_0OrLater AFIsSysVersionGreaterThanOrEqualTo(@"6.1")
#define AFIOS7_0_0OrLater AFIsSysVersionGreaterThanOrEqualTo(@"7.0")
#define AFIOS7_1_0OrLater AFIsSysVersionGreaterThanOrEqualTo(@"7.1")
#define AFIOS8_0_0OrLater AFIsSysVersionGreaterThanOrEqualTo(@"8.0")
#define AFIOS8_1_0OrLater AFIsSysVersionGreaterThanOrEqualTo(@"8.1")
#define AFIOS8_1_1OrLater AFIsSysVersionGreaterThanOrEqualTo(@"8.1.1")
#define AFIOS8_2_0OrLater AFIsSysVersionGreaterThanOrEqualTo(@"8.2")
#define AFIOS8_3_0OrLater AFIsSysVersionGreaterThanOrEqualTo(@"8.3")

#endif
