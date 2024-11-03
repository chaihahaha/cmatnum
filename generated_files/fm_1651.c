#include "fm_1651.h"
#include "stdafx.h"

inline int fm_1651(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_17_15, bmats.A_17_16, bmats.A_19_19, bmats.A_19_20, bmats.A_20_19, bmats.A_20_20, bmats.A_4_17, bmats.A_4_18, bmats.Ax176, bmats.Ax4354, bmats.Ax4378, bmats.Ax4530, bmats.Ax660, };
    double A_coeffs[13] = {-1, -1, -1, 16, -1, 16, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_15_20, bmats.B_16_20, bmats.B_17_17, bmats.B_17_18, bmats.B_17_19, bmats.B_17_20, bmats.B_17_21, bmats.B_17_22, bmats.B_17_23, bmats.B_17_24, bmats.B_17_25, bmats.B_17_26, bmats.B_17_27, bmats.B_17_28, bmats.B_17_29, bmats.B_17_30, bmats.B_17_31, bmats.B_17_32, bmats.B_1_20, bmats.B_20_1, bmats.B_2_20, bmats.B_3_20, bmats.B_4_20, bmats.B_9_20, bmats.Bx11916, };
    double B_coeffs[25] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_20.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
