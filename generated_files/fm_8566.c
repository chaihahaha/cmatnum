#include "fm_8566.h"
#include "stdafx.h"

inline int fm_8566(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 10;
    double_cmat A_mats[10] = {bmats.A_15_23, bmats.A_15_24, bmats.A_23_23, bmats.A_23_31, bmats.A_23_32, bmats.A_24_7, bmats.A_24_8, bmats.Ax3399, bmats.Ax3421, bmats.Ax7052, };
    double A_coeffs[10] = {-1, 16, 1, -16, 1, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_24_23, bmats.B_31_8, bmats.B_7_31, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_23_8.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_23.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_31.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
