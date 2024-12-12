#include "stdafx.h"
#include "fm_348.h"

inline int fm_348(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2042, bmats.Axx756, bmats.Axx777, bmats.Axx785, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_12_14, bmats.B_7_14, bmats.Bx1184, bmats.Bx1402, bmats.Bx2060, bmats.Bx2061, bmats.Bx2062, bmats.Bx2063, bmats.Bx2064, bmats.Bx2065, bmats.Bx2066, bmats.Bx2067, bmats.Bx2068, bmats.Bx2069, bmats.Bx2070, bmats.Bx2071, bmats.Bx2072, };
    double B_coeffs[17] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
