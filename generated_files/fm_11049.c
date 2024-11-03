#include "fm_11049.h"
#include "stdafx.h"

inline int fm_11049(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_9_23, bmats.A_9_24, bmats.Ax3325, };
    double A_coeffs[3] = {1, -16, 1, };
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_25_8, };
    double B_coeffs[1] = {1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_17_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_18_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_19_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_20_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_21_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_22_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_23_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_24_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_25_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_26_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_27_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_28_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_29_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_30_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_31_8.data[0][0], 1);    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_32_8.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_17.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_19.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_20.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_21.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_22.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_23.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_24.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_25.data[0][0], 1);    cblas_daxpy(BL*BL, 17, &m.data[0][0], 1, &bmats.C_24_25.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_26.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_27.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_28.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_29.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_30.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_31.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_32.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
