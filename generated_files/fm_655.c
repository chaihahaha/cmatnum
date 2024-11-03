#include "fm_655.h"
#include "stdafx.h"

inline int fm_655(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_11_29, bmats.A_11_30, bmats.A_19_27, bmats.A_19_28, bmats.A_27_27, bmats.A_27_28, bmats.A_30_15, bmats.A_30_16, bmats.Ax2230, bmats.Ax2567, bmats.Ax28, bmats.Ax402, bmats.Ax676, };
    double A_coeffs[13] = {-1, 16, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_27_14, bmats.B_30_22, bmats.Bx2480, bmats.Bx2481, bmats.Bx5976, };
    double B_coeffs[5] = {1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_27.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
