#include "fm_1972.h"
#include "stdafx.h"

inline int fm_1972(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_10_32, bmats.A_17_25, bmats.A_17_26, bmats.Ax1566, bmats.Ax239, bmats.Ax4768, };
    double A_coeffs[6] = {-1, 1, -16, 1, 1, 1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_17_17, bmats.B_18_17, bmats.B_19_17, bmats.B_1_26, bmats.B_20_17, bmats.B_21_17, bmats.B_22_17, bmats.B_23_17, bmats.B_24_17, bmats.B_25_17, bmats.B_26_17, bmats.B_27_17, bmats.B_28_17, bmats.B_29_17, bmats.B_30_17, bmats.B_31_17, bmats.B_32_17, bmats.Bx7705, bmats.Bx8679, };
    double B_coeffs[19] = {-1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_17.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
