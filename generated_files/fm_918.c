#include "fm_918.h"

inline int fm_918(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_31, bmats.A_12_32, bmats.A_25_11, bmats.A_25_12, bmats.A_2_10, bmats.A_2_9, bmats.A_9_10, bmats.A_9_9, bmats.Ax2242, bmats.Ax2923, bmats.Ax2944, bmats.Ax3213, bmats.Ax757, };
    double A_coeffs[13] = {-1, -1, -1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 23;
    double_cmat B_mats[23] = {bmats.B_12_12, bmats.B_12_14, bmats.B_12_5, bmats.B_12_7, bmats.B_12_9, bmats.B_17_9, bmats.B_18_9, bmats.B_19_9, bmats.B_20_9, bmats.B_21_9, bmats.B_22_9, bmats.B_23_9, bmats.B_24_9, bmats.B_25_9, bmats.B_26_9, bmats.B_27_9, bmats.B_28_9, bmats.B_29_9, bmats.B_30_9, bmats.B_31_9, bmats.B_32_9, bmats.B_9_28, bmats.Bx6289, };
    double B_coeffs[23] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_9.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
