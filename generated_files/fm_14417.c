#include "stdafx.h"
#include "fm_14417.h"

int fm_14417(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 19;
    double_cmat A_mats[19] = {bmats.A_28_17, bmats.A_28_18, bmats.A_28_19, bmats.A_28_20, bmats.A_28_21, bmats.A_28_22, bmats.A_28_23, bmats.A_28_24, bmats.A_28_25, bmats.A_28_26, bmats.A_28_27, bmats.A_28_28, bmats.A_28_29, bmats.A_28_30, bmats.A_28_31, bmats.A_28_32, bmats.A_29_27, bmats.A_29_28, bmats.Ax1966, };
    double A_coeffs[19] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 15, 15, -2, -2, -2, -1, 16, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_28_28, bmats.B_28_29, bmats.B_29_28, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_28.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_28.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
