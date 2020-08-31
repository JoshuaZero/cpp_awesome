cmake_minimum_required(VERSION 3.17)

project(test_demo)

set(CMAKE_CXX_STANDARD 14)

set(DEMO_SRC ../)
set(INCLUDE_BASE DEMO_SRC/basestruct)
set(INCLUDE_OPER DEMO_SRC/operator)

include_directories(${INCLUDE_BASE} ${INCLUDE_OPER})
message(STATUS "${DEMO_SRC} ${INCLUDE_BASE} ${INCLUDE_OPER}")

aux_source_directory(${DEMO_SRC}/basestruct SRC_BASE)
aux_source_directory(${DEMO_SRC}/operator SRC_OPER)
aux_source_directory(${DEMO_SRC}/test_demo SRC_DEMO)

message(STATUS "${DEMO_SRC}  ${SRC_DEMO} ${SRC_BASE} ${SRC_OPER}")

add_executable(test_demo demo.cpp ${SRC_BASE} ${SRC_OPER})
target_link_libraries(test_demo)

