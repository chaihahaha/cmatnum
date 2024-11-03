#include "fm_1621.h"
#include "stdafx.h"

inline int fm_1621(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_3_15, bmats.A_3_16, bmats.A_4_19, bmats.A_4_20, bmats.Ax4431, bmats.Ax585, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_15_20, bmats.B_16_20, bmats.B_19_1, bmats.B_19_10, bmats.B_19_11, bmats.B_19_12, bmats.B_19_13, bmats.B_19_14, bmats.B_19_15, bmats.B_19_16, bmats.B_19_2, bmats.B_19_3, bmats.B_19_4, bmats.B_19_5, bmats.B_19_6, bmats.B_19_7, bmats.B_19_8, bmats.B_19_9, bmats.B_1_20, bmats.B_2_20, bmats.B_3_20, bmats.B_4_20, bmats.B_4_3, bmats.B_9_20, bmats.Bx11916, };
    double B_coeffs[25] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_20.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
