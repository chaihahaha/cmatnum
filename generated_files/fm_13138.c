#include "fm_13138.h"
#include "stdafx.h"

inline int fm_13138(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_21_17, bmats.A_21_18, bmats.Ax182, };
    double A_coeffs[3] = {-1, 16, -1, };
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_5_18, };
    double B_coeffs[1] = {1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_1.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_2.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_3.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_4.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_5.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_6.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_7.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_9.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_10.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_11.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_12.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_13.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_14.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_15.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_16.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_18.data[0][0], 1);    cblas_daxpy(BL*BL, 17, &m.data[0][0], 1, &bmats.C_2_21.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
