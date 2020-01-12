# Define library. Only source files here!
#project(PServer VERSION 0.1 LANGUAGES CXX)

message("PROJECT_NAME: ${PROJECT_NAME}")

# Collect using glob the source files
file(GLOB SOURCES "src/*.cpp" "include/${PROJECT_NAME}/*.hpp")
message("SOURCES: ${SOURCES}")

add_library(PServer SHARED ${SOURCES} src/IndexRequestHandler.cpp)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
message("${PROJECT_NAME} BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(PServer PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

# Define the libraries this project depends upon
target_link_libraries(PServer
        Poco::Net
        )