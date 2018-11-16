

////
// @file ThreadTest.cc
// @brief
// 测试Thread 和ThreadPool
//
// @author cym
// @email 13005834351@qq.com
//



#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Thread.h"
#include "ThreadPool.h"

void *add(void *)
{
    int c;
    c = 4+5;
    return (void *)1;
}
using namespace ndsl::utils;
TEST_CASE("test")
{    
    SECTION("thread")
    {
      Thread thread;
     bool ret= thread.create();
      REQUIRE(ret == true);

    }

    SECTION("threadpool")
    {
        ThreadPool threadpool(6);
        threadpool.create(); 
        threadpool.getThread(add,NULL);      
        REQUIRE(threadpool.size()==5);

        threadpool.join();
        REQUIRE(threadpool.size()== 0 );
    }


}




