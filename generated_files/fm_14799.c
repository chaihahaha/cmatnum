#include "fm_14799.h"

inline int fm_14799(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_25_31, bmats.A_26_31, bmats.A_26_32, bmats.A_31_25, bmats.Ax627, bmats.Ax8485, };
    double A_coeffs[6] = {-17, -16, 1, 17, 1, 1, };
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_17_31, bmats.B_18_31, bmats.B_19_31, bmats.B_20_31, bmats.B_21_31, bmats.B_22_31, bmats.B_23_31, bmats.B_24_31, bmats.B_25_17, bmats.B_25_18, bmats.B_25_19, bmats.B_25_20, bmats.B_25_21, bmats.B_25_22, bmats.B_25_23, bmats.B_25_24, bmats.B_25_25, bmats.B_25_26, bmats.B_25_27, bmats.B_25_28, bmats.B_25_29, bmats.B_25_30, bmats.B_25_31, bmats.B_25_32, bmats.B_26_31, bmats.B_27_31, bmats.B_28_31, bmats.B_29_31, bmats.B_30_31, bmats.B_31_25, bmats.B_31_31, bmats.B_32_31, };
    double B_coeffs[32] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_31.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
