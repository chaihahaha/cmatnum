#include "stdafx.h"
#include "fm_349.h"

inline int fm_349(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx320, bmats.Axx3277, bmats.Axx356, bmats.Axx727, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_23_30, bmats.Bx1418, bmats.Bx1464, bmats.Bx2073, bmats.Bx2074, bmats.Bx2075, bmats.Bx2076, bmats.Bx2077, bmats.Bx2078, bmats.Bx2079, bmats.Bx2080, bmats.Bx2081, bmats.Bx2082, bmats.Bx2083, bmats.Bx2084, bmats.Bx2085, bmats.Bx2086, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
