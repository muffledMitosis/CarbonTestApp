cmake_minimum_required(VERSION 3.3)
project(TestApp)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)



add_compile_definitions(PLATFORM_LINUX)
add_compile_definitions(CARBON_BUILD_DLL=0)

add_subdirectory(./libs/Carbon/)

add_executable(Application ./src/TestApp.cpp)

set_target_properties(Application PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

target_include_directories(Application PUBLIC ./libs/Carbon/src/)
target_link_libraries(Application PUBLIC Carbon)
