#include "fm_1689.h"
#include "stdafx.h"

inline int fm_1689(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_19_32, bmats.A_26_19, bmats.A_26_20, bmats.A_32_19, bmats.Ax31, bmats.Ax4562, };
    double A_coeffs[6] = {17, -16, 1, -17, 1, 1, };
    int n_B_mats = 26;
    double_cmat B_mats[26] = {bmats.B_17_19, bmats.B_18_19, bmats.B_19_32, bmats.B_20_19, bmats.B_23_19, bmats.B_24_19, bmats.B_26_19, bmats.B_27_19, bmats.B_30_19, bmats.B_32_17, bmats.B_32_18, bmats.B_32_19, bmats.B_32_20, bmats.B_32_21, bmats.B_32_22, bmats.B_32_23, bmats.B_32_24, bmats.B_32_25, bmats.B_32_26, bmats.B_32_27, bmats.B_32_28, bmats.B_32_29, bmats.B_32_30, bmats.B_32_31, bmats.B_32_32, bmats.Bx12409, };
    double B_coeffs[26] = {-1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_19.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
