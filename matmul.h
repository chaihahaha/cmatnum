#ifndef MATMUL_H
#define MATMUL_H

#include "cmat.h"
#include <emmintrin.h>

#ifndef CLS
#define CLS 64
#endif

#define SM (CLS / sizeof(double))

static int matmul_float(float_cmat matA, float_cmat matB, float_cmat matC);

static int matmul_double(double_cmat matA, double_cmat matB, double_cmat matC);

static int matmul_double_sse2(double_cmat matA, double_cmat matB, double_cmat matC);

static int matmul_double_strassen_winograd(double_cmat matA, double_cmat matB, double_cmat matC);

#endif
