#ifndef FMM_4X4_H
#define FMM_4X4_H

#include "cmat.h"

/* Instrumentation: how often the recursive path / the BLAS fallback ran. */
extern unsigned long fmm_4x4_fast_calls;
extern unsigned long fmm_4x4_blas_calls;

int fmm_4x4(double_cmat C, double_cmat A, double_cmat B);

#endif
