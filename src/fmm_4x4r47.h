#ifndef FMM_4X4R47_H
#define FMM_4X4R47_H

#include "cmat.h"

/* Instrumentation: how often the recursive path / the BLAS fallback ran. */
extern unsigned long fmm_4x4r47_fast_calls;
extern unsigned long fmm_4x4r47_blas_calls;

int fmm_4x4r47(double_cmat C, double_cmat A, double_cmat B);

#endif
