cmake_minimum_required(VERSION 2.8.2)
option(test "Build all tests." ON)
set(PROJECT_NAME stockprices)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

set (CMAKE_CXX_COMPILER "g++")
set (CMAKE_C_COMPILER "gcc")

find_package(GTest REQUIRED)
enable_testing()
add_executable(runTests test_file.cpp)
add_executable(main main.cpp)
add_library(stocksLib stockprices.cpp)
target_link_libraries(main stocksLib)

include_directories(${PROJECT_SOURCE_DIR}/stockprices)
target_link_libraries(runTests gtest gtest_main)
add_test(NAME test1 COMMAND runTests)