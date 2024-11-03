#include "fm_14869.h"
#include "stdafx.h"

inline int fm_14869(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_17_31, bmats.A_17_32, bmats.A_32_1, bmats.A_32_2, bmats.Ax667, bmats.Ax8497, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_1_17, bmats.B_1_18, bmats.B_1_19, bmats.B_1_20, bmats.B_1_21, bmats.B_1_22, bmats.B_1_23, bmats.B_1_24, bmats.B_1_25, bmats.B_1_26, bmats.B_1_27, bmats.B_1_28, bmats.B_1_29, bmats.B_1_30, bmats.B_1_31, bmats.B_1_32, bmats.B_31_16, bmats.B_32_16, bmats.B_32_17, bmats.Bx13360, };
    double B_coeffs[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_16.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
