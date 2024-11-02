#include "fm_1237.h"

inline int fm_1237(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_21_23, bmats.A_22_23, bmats.A_22_24, bmats.A_23_21, bmats.Ax354, bmats.Ax3820, };
    double A_coeffs[6] = {-17, -16, 1, 17, 1, 1, };
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_17_23, bmats.B_18_23, bmats.B_19_23, bmats.B_20_23, bmats.B_21_17, bmats.B_21_18, bmats.B_21_19, bmats.B_21_20, bmats.B_21_21, bmats.B_21_22, bmats.B_21_23, bmats.B_21_24, bmats.B_21_25, bmats.B_21_26, bmats.B_21_27, bmats.B_21_28, bmats.B_21_29, bmats.B_21_30, bmats.B_21_31, bmats.B_21_32, bmats.B_22_23, bmats.B_23_21, bmats.B_26_23, bmats.B_30_23, bmats.B_31_23, bmats.B_32_23, bmats.Bx9994, };
    double B_coeffs[27] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_23.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
