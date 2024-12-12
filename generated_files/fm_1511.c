#include "stdafx.h"
#include "fm_1511.h"

inline int fm_1511(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1956, bmats.Axx2438, bmats.Axx383, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_20_20, bmats.B_20_22, bmats.B_4_21, bmats.Bx11835, bmats.Bx11836, bmats.Bx11837, bmats.Bx11838, bmats.Bx11839, bmats.Bx11840, bmats.Bx11841, bmats.Bx11842, };
    double B_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_21.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
