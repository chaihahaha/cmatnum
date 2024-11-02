#include "fm_1591.h"

inline int fm_1591(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_20_28, bmats.A_23_19, bmats.A_23_20, bmats.A_28_20, bmats.Ax4420, bmats.Ax88, };
    double A_coeffs[6] = {17, 1, -16, -17, 1, 1, };
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_20_28, bmats.B_22_20, bmats.B_28_17, bmats.B_28_18, bmats.B_28_19, bmats.B_28_20, bmats.B_28_21, bmats.B_28_22, bmats.B_28_23, bmats.B_28_24, bmats.B_28_25, bmats.B_28_26, bmats.B_28_27, bmats.B_28_28, bmats.B_28_29, bmats.B_28_30, bmats.B_28_31, bmats.B_28_32, bmats.B_29_20, bmats.B_30_20, bmats.Bx12088, };
    double B_coeffs[21] = {1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_20.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
