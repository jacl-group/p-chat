cmake_minimum_required(VERSION 3.10.2)
project(poco-chat)

add_subdirectory(src)
add_subdirectory(external/mstch)
include_directories(${mstch_INCLUDE_DIR})

