#include "stdafx.h"
#include "fm_973.h"

inline int fm_973(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2031, bmats.Axx385, bmats.Axx662, bmats.Axx692, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_7_9, bmats.Bx6340, bmats.Bx8756, bmats.Bx8827, bmats.Bx8828, bmats.Bx8829, bmats.Bx8830, bmats.Bx8831, bmats.Bx8832, bmats.Bx8833, bmats.Bx8834, bmats.Bx8835, bmats.Bx8836, };
    double B_coeffs[13] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
