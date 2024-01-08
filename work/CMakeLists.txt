cmake_minimum_required(VERSION 3.18)

project(sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O2 -Wall")

set(LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../library)
include_directories(${LIBRARY_DIR})

add_executable(main main.cpp)
