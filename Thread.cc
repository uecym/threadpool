//
//	 File Name: Thread.cc
//	 Author: 
//	 Mail: 
//   Function:创建线程
//	 Created Time: 2018年10月22日 星期一 09时55分02秒
//
//

#include "./Thread.h"
#include "Log.h"

namespace ndsl{

namespace utils{

Thread::Thread()
        : 
         ret_(0),
         running_(true),
         flag_(0),
         retval(NULL),
         thrFunc_(NULL),
         thrPrama_(NULL),
         thrRet_(NULL),
         tid_(0)
        {}
Thread::~Thread(){}
// 创建线程
bool Thread::create()
{ 
    ret_ = pthread_create(&tid_,NULL,&Thread::run,(void *)this);
    return ret_== true;
}

// 线程运行函数
 void * Thread::run(void *p)
{
   Thread * thread = (Thread *)(p);
   while(thread->running_)
    {
        if(!thread->flag_)
        {
            continue;
        }   
        thread->thrRet_=thread->thrFunc_(thread->thrPrama_);
    
        return thread->thrRet_;
    }   
}

int Thread::join()
{  
    return pthread_join(tid_, retval);
}


void Thread::wrapper(Func func,void *prama)
{
    thrFunc_= func;
    thrPrama_  = prama;
    flag_=1;
}


} // utils

} // ndsl


