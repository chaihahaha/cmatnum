#include "fm_7124.h"

inline int fm_7124(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.A_18_18, bmats.A_18_19, bmats.A_18_21, bmats.A_18_22, bmats.A_18_23, bmats.A_18_24, bmats.A_18_25, bmats.A_18_26, bmats.A_18_32, bmats.A_28_1, bmats.A_28_2, bmats.A_7_27, bmats.A_7_28, bmats.Ax2303, bmats.Ax2633, bmats.Ax6388, };
    double A_coeffs[16] = {1, 1, 1, 1, -16, 1, 1, 1, 1, -1, 16, -1, 16, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_23_12, bmats.B_28_18, bmats.B_2_23, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_18_12.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_23.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
