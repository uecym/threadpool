//
// File Name: ThreadPool.h
// Author: cym
// Mail: 
//function:创建线程池
//
// Created Time: 2018年10月22日 星期一 09时55分44秒
//

#ifndef __NDSL_UTILS_THREADPOOL_H_
#define __NDSL_UTILS_THREADPOOL_H_


#include <list>
#include "Thread.h"

namespace ndsl
{

namespace utils
{

class ThreadPool
{
  public:
    using Func = void(*)(void *);
    bool ret_;
    int running_;
    int flag_;
    int s_ok;
    int s_fault;
    int threadNum_; //线程个数
 
  private:
   std::list<Thread *> threadPool_; // 线程的队列
   pthread_mutex_t *mutex_;
  public:

    ThreadPool(int threadNum);

    ~ThreadPool();

    void create(); // 创建线程池
    Thread *getThread(Func func,void *prama); // 取线程
//    int    giveBackThread(Thread *thread); // 放线程回池
    void clean(); // 线程队列清理
    size_t size();

 private:
  void join(); // 线程池清理
 };


} // utils

} // ndsl

#endif  // _THREADPOOL_H_







