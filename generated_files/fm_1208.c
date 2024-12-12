#include "stdafx.h"
#include "fm_1208.h"

inline int fm_1208(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2946, bmats.Axx3360, bmats.Axx395, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_32_23, bmats.Bx10376, bmats.Bx10392, bmats.Bx10393, bmats.Bx10394, bmats.Bx10395, bmats.Bx10396, bmats.Bx10397, bmats.Bx10398, bmats.Bx9996, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
