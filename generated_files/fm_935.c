#include "fm_935.h"
#include "stdafx.h"

inline int fm_935(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_18_25, bmats.A_18_26, bmats.A_25_25, bmats.A_25_26, bmats.A_30_15, bmats.A_30_16, bmats.A_9_29, bmats.A_9_30, bmats.Ax242, bmats.Ax280, bmats.Ax3220, bmats.Ax423, bmats.Ax676, };
    double A_coeffs[13] = {16, -1, 16, -1, -1, -1, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_25_14, bmats.B_30_22, bmats.Bx2480, bmats.Bx2481, bmats.Bx8279, };
    double B_coeffs[5] = {1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_25.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
