#include "fm_9970.h"
#include "stdafx.h"

inline int fm_9970(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_7_15, bmats.A_7_16, bmats.Ax573, };
    double A_coeffs[3] = {-16, 1, 1, };
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_7_15, };
    double B_coeffs[1] = {1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_1.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_2.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_3.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_4.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_5.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_6.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_7.data[0][0], 1);    cblas_daxpy(BL*BL, 17, &m.data[0][0], 1, &bmats.C_15_7.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_8.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_9.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_10.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_11.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_12.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_13.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_14.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_15.data[0][0], 1);    cblas_daxpy(BL*BL, 2, &m.data[0][0], 1, &bmats.C_7_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_15.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_16.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
