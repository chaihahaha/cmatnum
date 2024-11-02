#include "fm_653.h"

inline int fm_653(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_27_30, bmats.A_30_27, bmats.A_31_27, bmats.A_31_28, bmats.Ax2222, bmats.Ax2656, };
    double A_coeffs[6] = {17, -17, -16, 1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_27_27, bmats.B_27_30, bmats.B_28_27, bmats.B_29_27, bmats.B_30_17, bmats.B_30_22, bmats.B_30_25, bmats.B_30_26, bmats.B_30_27, bmats.B_30_28, bmats.B_30_29, bmats.B_30_30, bmats.B_30_32, bmats.Bx2481, bmats.Bx5962, };
    double B_coeffs[15] = {-1, 1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_27.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
