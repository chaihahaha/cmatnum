cmake_minimum_required(VERSION 3.10)
project(CFMM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED 11)
# Use file GLOB to find all .cpp and .h files in the current directory and subdirectories
file(GLOB_RECURSE SOURCE_FILES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/generated_files/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated_files/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated_files/pack_mats.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/fmm_32x32.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/fmm_32x32.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmat.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmat.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/matmul.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/matmul.c"
)
add_compile_options(-std=c11)
add_compile_options(-Ofast)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")

# Add the executable target
add_executable(fmm32x32 ${SOURCE_FILES})
target_include_directories(fmm32x32 PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/generated_files"
)
target_precompile_headers(fmm32x32 PRIVATE stdafx.h)

#find_package(OpenMP REQUIRED)
#
#if(OpenMP_CXX_FOUND)
#    target_link_libraries(fmm32x32 PRIVATE OpenMP::OpenMP_CXX)
#endif()

