cmake_minimum_required(VERSION 3.3)
project(TestApp)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(PLATFORM_LINUX)
add_compile_definitions(CARBON_BUILD_DLL=0)

add_subdirectory(./libs/Carbon/)

add_executable(Application ./src/TestApp.cpp)
target_include_directories(Application PUBLIC ./libs/Carbon/src/)
target_link_libraries(Application PRIVATE Carbon)
