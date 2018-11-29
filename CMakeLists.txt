# FileName CMakeList.cc
#
# Function:
# auther: cym
# email:

#include_dirctories(include/ndsl/utils)  


include_directories(./)
set(UTILS_NDSL_SRC Thread.cc ThreadPool.cc)
add_library(ndsl SHARED ${UTILS_NDSL_SRC})

#  target_link_libraries(ndsl Log.cc)
