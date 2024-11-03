#include "fm_7519.h"
#include "stdafx.h"

inline int fm_7519(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_17_17, bmats.A_17_19, bmats.A_17_20, bmats.A_17_29, bmats.A_17_30, bmats.A_17_31, bmats.A_17_32, bmats.A_26_1, bmats.A_26_2, bmats.A_4_25, bmats.A_4_26, bmats.Ax2866, bmats.Ax3108, bmats.Ax6610, };
    double A_coeffs[14] = {1, 1, -16, 1, 1, 1, 1, 16, -1, -1, 16, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_1_20, bmats.B_20_10, bmats.B_26_17, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_17_10.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_17.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_20.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
