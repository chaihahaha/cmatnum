#include "stdafx.h"
#include "fm_643.h"

inline int fm_643(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx2861, bmats.Axx2891, bmats.Axx3018, bmats.Axx3019, bmats.Axx3021, bmats.Axx3024, bmats.Axx3025, bmats.Axx3028, bmats.Axx3030, bmats.Axx3031, bmats.Axx3033, bmats.Axx3036, bmats.Axx3038, bmats.Axx3039, bmats.Axx3042, bmats.Axx3044, bmats.Axx3053, bmats.Axx976, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4694, bmats.Bx5853, bmats.Bx5919, bmats.Bx5933, bmats.Bx5934, bmats.Bx5935, bmats.Bx5936, bmats.Bx5937, bmats.Bx5938, bmats.Bx5939, bmats.Bx5940, bmats.Bx5941, bmats.Bx5942, bmats.Bx5943, bmats.Bx5944, bmats.Bx5945, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
