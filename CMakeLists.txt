cmake_minimum_required(VERSION 3.20)
project(cfmm)
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_definitions(-DUSE_ACCELERATE)
    add_definitions(-DACCELERATE_NEW_LAPACK)
endif()


set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED 11)
# Use file GLOB to find all .cpp and .h files in the current directory and subdirectories
file(GLOB_RECURSE SOURCE_FILES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/fmm_32x32.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/fmm_32x32.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmat.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmat.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/matmul.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/matmul.c"
)
add_compile_options(-std=c11)
add_compile_options(-O3)
add_compile_options(-march=native)
add_compile_options(-D_GNU_SOURCE)

# set(JEMALLOC_ROOT "/opt/homebrew/Cellar/jemalloc/5.3.0")
# # Add jemalloc include directory
# include_directories("${JEMALLOC_ROOT}/include")
# # Add jemalloc library directory
# link_directories("${JEMALLOC_ROOT}/lib")


# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/main.c" PROPERTIES COMPILE_FLAGS "-O1")

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(${PROJECT_NAME} PRIVATE ACCELERATE_NEW_LAPACK)
endif()
include(FindBLAS)

if (BLAS_FOUND)
    target_compile_options(${PROJECT_NAME} PRIVATE ${BLAS_LINKER_FLAGS})
    target_link_libraries(${PROJECT_NAME} ${BLAS_LIBRARIES})
endif ()


#find_package(OpenMP REQUIRED)
#find_package(OpenMP REQUIRED)
#
#if(OpenMP_CXX_FOUND)
#    target_link_libraries(fmm32x32 PRIVATE OpenMP::OpenMP_CXX)
#endif()

