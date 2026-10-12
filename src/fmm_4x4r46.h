#ifndef FMM_4X4R46_H
#define FMM_4X4R46_H

#include "cmat.h"

/* Instrumentation: how often the recursive path / the BLAS fallback ran. */
extern unsigned long fmm_4x4r46_fast_calls;
extern unsigned long fmm_4x4r46_blas_calls;

int fmm_4x4r46(double_cmat C, double_cmat A, double_cmat B);

#endif
