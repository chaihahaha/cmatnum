#ifndef MATMUL_H
#define MATMUL_H

#include "cmat.h"
#include <emmintrin.h>

#ifndef CLS
#define CLS 64
#endif

#define SM (CLS / sizeof(double))

int matmul_float(float_cmat matA, float_cmat matB, float_cmat matC);

int matmul_double(double_cmat matC, double_cmat matA, double_cmat matB);

int matmul_double_sse2(double_cmat matC, double_cmat matA, double_cmat matB);

int matmul_double_strassen_winograd(double_cmat matC, double_cmat matA, double_cmat matB);

int matmul_double_schwartz2024(double_cmat matC, double_cmat matA, double_cmat matB);

int matmul_double_recursive_bilinear(double_cmat matC, double_cmat matA, double_cmat matB);
#endif
