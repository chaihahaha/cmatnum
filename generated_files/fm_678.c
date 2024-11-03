#include "fm_678.h"
#include "stdafx.h"

inline int fm_678(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.A_19_27, bmats.A_19_28, bmats.A_27_19, bmats.A_27_27, bmats.Ax2567, bmats.Ax2714, bmats.Ax28, };
    double A_coeffs[7] = {-16, 1, -1, -1, 1, 1, 1, };
    int n_B_mats = 31;
    double_cmat B_mats[31] = {bmats.B_17_27, bmats.B_18_27, bmats.B_19_27, bmats.B_20_27, bmats.B_21_27, bmats.B_22_27, bmats.B_23_27, bmats.B_24_27, bmats.B_25_27, bmats.B_26_27, bmats.B_27_17, bmats.B_27_18, bmats.B_27_19, bmats.B_27_20, bmats.B_27_21, bmats.B_27_22, bmats.B_27_23, bmats.B_27_24, bmats.B_27_25, bmats.B_27_26, bmats.B_27_27, bmats.B_27_28, bmats.B_27_29, bmats.B_27_30, bmats.B_27_31, bmats.B_27_32, bmats.B_28_27, bmats.B_29_27, bmats.B_30_27, bmats.B_31_27, bmats.B_32_27, };
    double B_coeffs[31] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_27.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
