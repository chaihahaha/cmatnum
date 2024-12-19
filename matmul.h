#ifndef MATMUL_H
#define MATMUL_H

#include "cmat.h"
#ifdef USE_ACCELERATE
#include "cblas_new.h"
#else
#include "cblas.h"
#endif

int matmul_float(float_cmat matA, float_cmat matB, float_cmat matC);

int matmul_double(double_cmat matC, double_cmat matA, double_cmat matB);

int matmul_double_blas(double_cmat C, double_cmat A_slice, double_cmat B_slice);

int matmul_double_strassen_winograd(double_cmat matC, double_cmat matA, double_cmat matB);

int matmul_double_schwartz2024(double_cmat matC, double_cmat matA, double_cmat matB);

int matmul_double_recursive_bilinear(double_cmat matC, double_cmat matA, double_cmat matB);
#endif
