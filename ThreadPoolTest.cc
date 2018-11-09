

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

void add()
{
    int c;
    c = 4+5;
}

TEST_CASE("ThreadPool", "[thread]")
{   
  
    ThreadPool threadpool(6);
    
    threadpool.create(); 
    SECTION("getThread")
    {
        Thread *thread = threadpool.getThread(add,NULL);      
        REQUIRE(threadpool.size()=5);
    }

    SECTION("join")
    {
        threadpool.join();
        REQUIRE(threadpool.size()= 0 );
    }


}




