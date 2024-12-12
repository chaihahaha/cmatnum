#include "stdafx.h"
#include "fm_14012.h"

inline int fm_14012(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 17;
    double_cmat A_mats[17] = {bmats.A_7_6, bmats.Axx1751, bmats.Axx2078, bmats.Axx425, bmats.Axx426, bmats.Axx486, bmats.Axx546, bmats.Axx600, bmats.Axx651, bmats.Axx693, bmats.Axx733, bmats.Axx751, bmats.Axx753, bmats.Axx755, bmats.Axx757, bmats.Axx759, bmats.Axx789, };
    double A_coeffs[17] = {15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_7_7, bmats.Bx13145, };
    double B_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_6.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_7.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
