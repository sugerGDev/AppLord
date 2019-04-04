//
//  ALModule.h
//  AppLord
//
//  Created by fengnianji on 15/11/9.
//  Copyright © 2015年 cnbluebox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALContext.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ALModule <NSObject>

/**
 *  module did create
 */
- (void)moduleDidInit:(ALContext *)context;
//


@optional


/**
 是否需要缓存，默认不缓存在内存中
 
 @return 是否缓存在内存中
 */
- (BOOL)needCache;


/**
 *  config when load this module, init when main thread is idle
 */
+ (BOOL)loadAfterLaunch;

@end

NS_ASSUME_NONNULL_END
