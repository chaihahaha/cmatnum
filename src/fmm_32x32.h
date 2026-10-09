#ifndef FMM_32x32_H
#define FMM_32x32_H

#include <stdio.h>
#include <stdlib.h>
#include "cmat.h"

/* Instrumentation: how often the recursive path / the BLAS fallback ran. */
extern unsigned long fmm_32x32_fast_calls;
extern unsigned long fmm_32x32_blas_calls;

int fmm_32x32(double_cmat C, double_cmat A, double_cmat B);

#endif
