//
//  ALContext.h
//  AppLord
//
//  Created by fengnianji on 15/11/9.
//  Copyright © 2015年 cnbluebox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ALModule, ALService;
@interface ALContext : NSObject

/**
 *  Get the singletion
 */
+ (instancetype)sharedContext;

@property(nonatomic, strong)  NSOperationQueue    *taskQueue;
@end

@interface ALContext (Service)

/**
 *  Register a service with it's implement class
 */
- (void)registerService:(Protocol *)proto withImpl:(Class)implClass;

/**
 *  Find the service implement of the protocol, return nil if not registered, create instance
 *  if not create
 */
- (__nullable id)findService:(Protocol *)serviceProtocol;

/**
 *  Just like `findService`, but you can pass a service's class name
 */
- (__nullable id)findServiceByName:(NSString *)name;

/**
 *  Figure out if a service is registered
 */
- (BOOL)existService:(NSString *)serviceName;


@end


@interface ALContext (Module)

/**
 *  register a module with it's class name
 */
- (void)registerModule:(Class)moduleClass;

/**
 *  init all the module registered
 */
- (void)loadModules;

/**
 *  Find the module instance
 */
- (__nullable id)findModule:(Class)moduleClass;


/**
移除cache

 @param cacheCls cache 的cls
 */
- (void)removeCacheForClass:(Class)cacheCls;
@end

@interface ALContext (Task)

/**
 *  the max concurrent of default operation queue
 */
@property (nonatomic, assign) NSInteger maxConcurrentOperationCount;

/**
 *  batch run tasks, async on current thread.
 */
- (void)addAsyncTasks:(NSArray<NSOperation *> *)tasks;

/**
 *  add a task in the default background operation queue.
 */
- (void)addTask:(NSOperation *)task;
/**
 当前请TaskQueue

 @return 返回队列对象
 */
- (NSOperationQueue *)currentTaskQueue;
/**
 取消队列
 */
- (void)cancelAllTasks;

@end

@interface ALContext (Object)

- (void)setObject:(id _Nonnull)value forKey:(NSString *)key;
- (nullable id)objectForKey:(NSString *)key;

- (nullable NSString *)stringForKey:(NSString *)key;
- (nullable NSDictionary *)dictionaryForKey:(NSString *)key;
- (nullable NSArray *)arrayForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
