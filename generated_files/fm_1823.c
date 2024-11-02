#include "fm_1823.h"

inline int fm_1823(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_17_17, bmats.A_17_18, bmats.A_18_17, bmats.A_18_18, bmats.A_28_15, bmats.A_28_16, bmats.A_2_27, bmats.A_2_28, bmats.Ax158, bmats.Ax2312, bmats.Ax4655, bmats.Ax4666, bmats.Ax688, };
    double A_coeffs[13] = {-1, 16, -1, 16, -1, -1, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_16_18, bmats.B_18_12, bmats.B_1_18, bmats.B_28_18, bmats.B_28_23, bmats.B_28_25, bmats.B_28_26, bmats.B_28_28, bmats.B_28_29, bmats.B_28_30, bmats.B_28_31, bmats.B_28_32, bmats.B_2_18, bmats.Bx12672, bmats.Bx6292, };
    double B_coeffs[15] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_18.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
