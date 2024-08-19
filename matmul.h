#ifndef MATMUL_H
#define MATMUL_H

#include "cmat.h"
#include <emmintrin.h>

#ifndef CLS
#define CLS 64
#endif

#define SM (CLS / sizeof(double))

static int matmul_float(struct float_cmat matA, struct float_cmat matB, struct float_cmat matC);

static int matmul_double_sse2(struct double_cmat matA, struct double_cmat matB, struct double_cmat matC);

#endif
