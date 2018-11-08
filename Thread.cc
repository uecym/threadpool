//
//	 File Name: Thread.cc
//	 Author: 
//	 Mail: 
//   Function:创建线程
//	 Created Time: 2018年10月22日 星期一 09时55分02秒
//
//

#include "./Thread.h"


namespace ndsl{

namespace utils{

// 创建线程
bool Thread::create()
{ 
    ret_ = pthread_create(&tid, NULL, run, NULL;
    return ret_== 1;
}

// 线程运行函数
void Thread::run()
{
   while(running_)
    {
        if(!flag_)
        {
            continue;
        }
        thrFunc_(thrPrama_);
        flag_ = 0;
        backFlag_ =1;
    }
}


int Thread::join()
{  
    return pthread_join(tid, retval);
}


void Thread::wrapper(Func func,void *prama)
{
    thrFunc_= func
    thrPrama_  = prama;
    flag_=1;
}


} // utils

} // ndsl


