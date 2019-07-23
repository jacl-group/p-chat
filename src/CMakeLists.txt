cmake_minimum_required(VERSION 3.10.0)
project(poco_chat)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Include Boost as an imported target
find_package(Boost 1.65 COMPONENTS program_options unit_test_framework log REQUIRED)
#add_library(boost INTERFACE IMPORTED)
#set_property(TARGET boost PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
message("Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}")
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")

# If the threads library is needed
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# POCO library and components
find_package(Poco 2.0.0 REQUIRED COMPONENTS Foundation Net Util
        PATHS /home/cenicol/local
        )
#add_library(poco INTERFACE IMPORTED)
#set_property(TARGET poco PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Poco_INCLUDE_DIR})
message("Poco_INCLUDE_DIR: ${Poco_INCLUDE_DIR}")
message("Poco_LIBRARIES: ${Poco_LIBRARIES}")

add_subdirectory(app)
add_subdirectory(PServer)
