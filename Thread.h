//
// File Name: Thread.h
// Author: cym
// Mail:
// Function:创建线程执行任务
//
// Created Time: 2018年10月22日 星期一 09时55分24秒
//

#ifndef __NDSL_UTILS_THREAD_H__
#define __NDSL_UTILS_THREAD_H__


#include<pthread.h>

namespace ndsl
{

namespace utils 
{

class Thread
{
  public:
    
    using Func = void* (*)(void*);

  private:
    Func thrFunc_;
    void *thrPrama_;

    bool ret_;
    int flag_;
    bool running_;
    void **retval;
    void *thrRet_; 
    pthread_t tid_;

  public:
    bool create(); // 线程的创建
    void wrapper(Func func,void *prama); // 把函数和参数打包进来
    int join();
  private:
    static void* run(void *); // 线程运行函数

};

} // utils

} // ndsl

#endif  // __NDSL_UTILS_THREAD_H__i







