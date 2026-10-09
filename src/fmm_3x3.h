#ifndef FMM_3X3_H
#define FMM_3X3_H

#include "cmat.h"

/* Instrumentation: how often the recursive path / the BLAS fallback ran. */
extern unsigned long fmm_3x3_fast_calls;
extern unsigned long fmm_3x3_blas_calls;

int fmm_3x3(double_cmat C, double_cmat A, double_cmat B);

#endif
