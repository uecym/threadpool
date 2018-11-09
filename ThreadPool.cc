//
// File Name: ThreadPool.c
// Author: 
// Mail:
// function: 线程池的创建
// Created Time: 2018年10月22日 星期一 09时56分35秒
//



#include <list>
#include "ThreadPool.h"
#include "pthread.h"
#include "Log.h"


namespace ndsl
{

namespace utils
{

ThreadPool::ThreadPool(int threadNum)
    :
     flag_(0),
     running_(true),
     threadNum_(threadNum),
     s_ok(1), 
     s_fault(0),
     ret_(0),
     mutex_(NULL)
    {}

 ThreadPool::~ThreadPool(){}

size_t ThreadPool:: size() {return threadPool_.size();}

void ThreadPool::create()
{   
    pthread_mutex_init(mutex_,NULL);

    for(int i=0;i<threadNum_;i++)
      {      
        Thread *thread = new Thread;
         ret_ = thread->create();

        if (!ret_) 
        {
            delete thread;
            LOG(LOG_ERROR_LEVEL, "ThreadPool create fail\n");
        }
        else 
        {

            threadPool_.push_back(thread);
            LOG(LOG_DEBUG_LEVEL,
                "ThreadPool create one thread, size = %ld\n",
                threadPool_.size());
        }

      }
     
}

Thread *ThreadPool::getThread(Func func,void *prama)
{
    if(!threadPool_.empty())
    {
        pthread_mutex_lock(mutex_); // 对线程池加锁
        Thread *thread = threadPool_.front();// 取一个线程
        threadPool_.pop_front();
        
        thread->wrapper(func,prama);  // 设置任务
        pthread_mutex_unlock(mutex_); //线程池开锁
         return thread;
    }
}

//int  ThreadPool::giveBackThread(Thread *thread)
//{
//    if(thread->backFlag_ !=1)
//        return s_fault;
//
//    pthread_mutex_lock(mutex_);
//    threadPool_.push_back(thread);
//    thread->backFlag_ = 0;
//    pthread_mutex_unlock(mutex_);
//    return s_ok;
//}

void ThreadPool::join()
    {
        std::list<Thread *>::iterator it;
            for (it = threadPool_.begin(); it != threadPool_.end(); ++it)
            {
                (*it)->join();
                LOG(LOG_DEBUG_LEVEL, "ThreadPool join %ld\n",  threadPool_.size());
                clean();
            }      
    }

void ThreadPool::clean()
    {
        while (threadPool_.begin() != threadPool_.end())
           {
            delete *threadPool_.begin();
             threadPool_.pop_front();
           }
    }


} // utils

} // ndsl





