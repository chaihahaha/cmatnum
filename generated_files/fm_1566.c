#include "fm_1566.h"
#include "stdafx.h"

inline int fm_1566(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_20_31, bmats.A_30_19, bmats.A_30_20, bmats.A_31_20, bmats.Ax1569, bmats.Ax4408, };
    double A_coeffs[6] = {17, 1, -16, -17, 1, 1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_17_20, bmats.B_18_20, bmats.B_19_20, bmats.B_20_31, bmats.B_21_20, bmats.B_23_20, bmats.B_27_20, bmats.B_29_20, bmats.B_31_17, bmats.B_31_18, bmats.B_31_19, bmats.B_31_20, bmats.B_31_21, bmats.B_31_22, bmats.B_31_23, bmats.B_31_24, bmats.B_31_25, bmats.B_31_26, bmats.B_31_27, bmats.B_31_28, bmats.B_31_29, bmats.B_31_30, bmats.B_31_31, bmats.B_31_32, bmats.B_32_20, bmats.Bx11895, };
    double B_coeffs[26] = {-1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_20.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
