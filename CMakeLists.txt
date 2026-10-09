cmake_minimum_required(VERSION 3.20)
project(cfmm C)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_definitions(-DUSE_ACCELERATE)
    add_definitions(-DACCELERATE_NEW_LAPACK)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED 11)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# Which generated fast-multiplication kernels to compile in.  fmm_32x32.c is
# ~25 MiB of generated code, so it can be dropped for quick iterations:
#   cmake .. -DCFMM_ALGORITHMS=3x3;3x3x6;4x4
set(CFMM_ALGORITHMS "3x3;3x3x6;4x4;32x32" CACHE STRING "generated fmm kernels to build")

set(CFMM_KERNELS)
foreach(alg IN LISTS CFMM_ALGORITHMS)
    list(APPEND CFMM_KERNELS src/fmm_${alg}.c)
    string(TOUPPER "${alg}" alg_upper)
    string(REPLACE "X" "_" alg_upper "${alg_upper}")
    list(APPEND CFMM_DEFS CFMM_HAVE_${alg_upper}=1)
endforeach()

add_executable(${PROJECT_NAME} src/cmat.c src/matmul.c src/benchmark.c ${CFMM_KERNELS})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${CFMM_DEFS})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_options(${PROJECT_NAME} PRIVATE -O3 -march=native -D_GNU_SOURCE -Wall -Wno-unused-variable)

include(FindBLAS)
if(BLAS_FOUND)
    target_compile_options(${PROJECT_NAME} PRIVATE ${BLAS_LINKER_FLAGS})
    target_link_libraries(${PROJECT_NAME} ${BLAS_LIBRARIES})
endif()

find_package(OpenMP)
if(OpenMP_C_FOUND)
    target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_C)
endif()

# ---------------------------------------------------------------------- #
# tests
# ---------------------------------------------------------------------- #
option(CFMM_BUILD_TESTS "build the correctness test-suite" ON)
if(CFMM_BUILD_TESTS)
    enable_testing()
    add_executable(test_fmm tests/test_fmm.c src/cmat.c src/matmul.c ${CFMM_KERNELS})
    target_compile_definitions(test_fmm PRIVATE ${CFMM_DEFS})
    target_include_directories(test_fmm PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
    target_compile_options(test_fmm PRIVATE -O2 -D_GNU_SOURCE)
    if(BLAS_FOUND)
        target_link_libraries(test_fmm ${BLAS_LIBRARIES})
    endif()
    add_test(NAME correctness COMMAND test_fmm)
endif()
