#include "fm_1992.h"

inline int fm_1992(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_17_5, bmats.A_17_6, bmats.A_22_31, bmats.A_22_32, bmats.Ax4827, bmats.Ax639, };
    double A_coeffs[6] = {1, -16, -1, -1, -1, -1, };
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_17_1, bmats.B_17_22, bmats.B_18_1, bmats.B_32_1, bmats.B_6_17, bmats.B_6_18, bmats.B_6_19, bmats.B_6_20, bmats.B_6_21, bmats.B_6_22, bmats.B_6_23, bmats.B_6_24, bmats.B_6_25, bmats.B_6_26, bmats.B_6_27, bmats.B_6_28, bmats.B_6_29, bmats.B_6_30, bmats.B_6_31, bmats.B_6_32, bmats.Bx12865, };
    double B_coeffs[21] = {-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_1.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
