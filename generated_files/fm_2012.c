#include "fm_2012.h"

inline int fm_2012(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_17_3, bmats.A_17_4, bmats.A_1_1, bmats.A_1_2, bmats.A_2_1, bmats.A_2_2, bmats.A_3_31, bmats.A_3_32, bmats.Ax4309, bmats.Ax4647, bmats.Ax4659, bmats.Ax4788, bmats.Ax775, };
    double A_coeffs[13] = {16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_17_1, bmats.B_18_1, bmats.B_1_19, bmats.B_32_1, bmats.B_3_1, bmats.B_3_10, bmats.B_3_11, bmats.B_3_12, bmats.B_3_13, bmats.B_3_14, bmats.B_3_15, bmats.B_3_16, bmats.B_3_2, bmats.B_3_3, bmats.B_3_4, bmats.B_3_5, bmats.B_3_6, bmats.B_3_7, bmats.B_3_8, bmats.B_3_9, bmats.Bx12865, };
    double B_coeffs[21] = {-1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_1.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
