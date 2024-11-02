#include "fm_1733.h"

inline int fm_1733(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_18_19, bmats.A_18_20, bmats.A_19_19, bmats.A_19_20, bmats.A_25_15, bmats.A_25_16, bmats.A_3_25, bmats.A_3_26, bmats.Ax2863, bmats.Ax4351, bmats.Ax4354, bmats.Ax4495, bmats.Ax700, };
    double A_coeffs[13] = {16, -1, 16, -1, -1, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_16_19, bmats.B_19_9, bmats.B_1_19, bmats.B_25_17, bmats.B_25_21, bmats.B_25_25, bmats.B_25_27, bmats.B_25_28, bmats.B_25_29, bmats.B_25_30, bmats.B_2_19, bmats.B_3_19, bmats.Bx12271, bmats.Bx9522, };
    double B_coeffs[14] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_19.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
