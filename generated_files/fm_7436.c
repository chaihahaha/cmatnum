#include "fm_7436.h"
#include "stdafx.h"

inline int fm_7436(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_10_29, bmats.A_10_30, bmats.A_17_17, bmats.A_17_19, bmats.A_17_25, bmats.A_17_26, bmats.A_17_29, bmats.A_17_30, bmats.A_17_31, bmats.A_17_32, bmats.A_30_1, bmats.A_30_2, bmats.Ax1763, bmats.Ax426, bmats.Ax6620, };
    double A_coeffs[15] = {-1, 16, 1, 1, 1, -16, 1, 1, 1, 1, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_1_26, bmats.B_26_14, bmats.B_30_17, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_17_14.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_17.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_26.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
