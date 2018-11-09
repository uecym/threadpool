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

// 创建线程
bool Thread::create()
{ 
    ret_ = pthread_create(&tid_, NULL, run,this);
    return ret_== 1;
}

// 线程运行函数
 void* Thread::run(void *p)
{
   while(running_)
    {
        if(!flag_)
        {
            continue;
        }
        
        Thread *pthis = (Thread *)p;
        pthis->thrRet_ = pthis->thrFunc_(pthis->thrPrama_);
    
        return pthis->thrRet_;
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


