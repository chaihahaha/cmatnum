cmake_minimum_required(VERSION 3.10)
project(MyEigenProject)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Add the path to the Eigen library
include_directories("D:/libs/eigen-master")
# Use file GLOB to find all .cpp and .h files in the current directory and subdirectories
file(GLOB_RECURSE SOURCE_FILES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/generated_files/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated_files/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated_files/pack_mats.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/fmm_22x22.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/fmm_22x22.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h"
)
add_compile_options(-std=c++14)
# Add the executable target
add_executable(MyExecutable ${SOURCE_FILES})
target_include_directories(MyExecutable PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated_files"
)
target_precompile_headers(MyExecutable PRIVATE stdafx.h)
