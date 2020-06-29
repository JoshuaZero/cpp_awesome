#/*================================================================
#*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
#*   
#*       FileName：CMakeLists.txt
#*         Author：joshua_zero@outlook.com
#*     CreateTime：2020-06-28 16:04:13
#*    Describtion：
#*  Last Modified: 2020-06-28 16:04:13
#*
#================================================================*/
cmake_minimum_required(VERSION 2.8)

project(cpp_awesome)#c cxx

if(release)
  message(STATUS "release version set")
  set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
else() 
  message(STATUS "debug version set ${PROJECT_SOURCE_DIR} ")
  set(CMAKE_CXX_FLAGS_DEBUG   "-O0" )             # 调试包不优化
endif()  

set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall ")
  
set(SRC_ROOT "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include")

include_directories(${SRC_ROOT})

link_directories(${INCLUDE_ROOT})

#add_dependencies()

#add_subdirectory(${SRC_ROOT})

#add_library(cpp_lib ${INCLUDE_ROOT})

add_executable(cpp_demo ${SRC_ROOT})

#target_link_libraries(cpp_demo )


