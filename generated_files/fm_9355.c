#include "stdafx.h"
#include "fm_9355.h"

int fm_9355(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.A_14_17, bmats.A_14_18, bmats.A_18_11, bmats.A_18_12, bmats.A_28_19, bmats.A_28_28, bmats.A_28_30, bmats.A_28_32, bmats.Ax1766, bmats.Ax2269, bmats.Ax7442, };
    double A_coeffs[11] = {-1, 16, -1, 16, 1, 1, -16, 1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_12_30, bmats.B_18_28, bmats.B_30_2, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_28_2.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_28.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
