#include "fm_7683.h"
#include "stdafx.h"

inline int fm_7683(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 19;
    double_cmat A_mats[19] = {bmats.A_24_31, bmats.A_24_32, bmats.A_32_17, bmats.A_32_18, bmats.A_32_19, bmats.A_32_20, bmats.A_32_21, bmats.A_32_22, bmats.A_32_23, bmats.A_32_24, bmats.A_32_25, bmats.A_32_26, bmats.A_32_27, bmats.A_32_28, bmats.A_32_29, bmats.A_32_30, bmats.A_32_31, bmats.A_32_32, bmats.Ax621, };
    double A_coeffs[19] = {-1, 16, -2, -2, -2, -2, -2, -2, -2, 15, -2, -2, -2, -2, -2, -2, -2, 15, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_24_32, bmats.B_32_24, bmats.B_32_32, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_24.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_32.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_32.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
