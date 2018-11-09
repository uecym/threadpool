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
    
    using Func = void(*)(void*);
    Func thrFunc_;
    void *thrPrama_;

    int ret_;
    int flag_;
    bool running_;
    void **retval;
    int backFlag_;
    void *thrRet_; 
  private:
    pthread_t tid_;

  public:
    Thread()
    : 
      ret_(0),
      running_(true),
      flag_(0),
      retval(NULL),
      thrFunc_(NULL),
      thrPrama_(NULL),
      thrRet_(NULL),
      tid_(0)
    {};
    
    ~Thread(){};
    bool create(); // 线程的创建
    void wrapper(Func func,void *prama); // 把函数和参数打包进来
    int join();
  private:
    void* run(void *); // 线程运行函数

};

} // utils

} // ndsl

#endif  // __NDSL_UTILS_THREAD_H__i







