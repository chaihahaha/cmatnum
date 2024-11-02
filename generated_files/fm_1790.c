#include "fm_1790.h"

inline int fm_1790(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_14_31, bmats.A_14_32, bmats.A_18_13, bmats.A_18_14, bmats.A_1_1, bmats.A_1_2, bmats.A_2_1, bmats.A_2_2, bmats.Ax4647, bmats.Ax4659, bmats.Ax4661, bmats.Ax512, bmats.Ax745, };
    double A_coeffs[13] = {-1, -1, -1, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_14_12, bmats.B_17_2, bmats.B_18_2, bmats.B_2_30, bmats.B_32_2, bmats.Bx12667, bmats.Bx3105, bmats.Bx3115, };
    double B_coeffs[8] = {-1, -1, -1, 1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_2.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
