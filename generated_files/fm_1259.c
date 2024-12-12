#include "stdafx.h"
#include "fm_1259.h"

inline int fm_1259(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx157, bmats.Axx1594, bmats.Axx1735, bmats.Axx3288, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.Bx10561, bmats.Bx10675, bmats.Bx10717, bmats.Bx10727, bmats.Bx10728, bmats.Bx10729, bmats.Bx10730, bmats.Bx10731, bmats.Bx10732, bmats.Bx10733, bmats.Bx10734, };
    double B_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
