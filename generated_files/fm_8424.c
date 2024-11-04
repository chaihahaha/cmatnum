#include "stdafx.h"
#include "fm_8424.h"

int fm_8424(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.A_17_7, bmats.A_17_8, bmats.A_24_18, bmats.A_24_20, bmats.A_24_22, bmats.A_24_23, bmats.A_24_24, bmats.A_24_25, bmats.A_24_26, bmats.A_24_27, bmats.A_24_28, bmats.A_9_17, bmats.A_9_18, bmats.Ax3338, bmats.Ax3414, bmats.Ax6959, };
    double A_coeffs[16] = {-1, 16, 1, 1, 1, 1, 1, -16, 1, 1, 1, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_17_24, bmats.B_25_1, bmats.B_8_25, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_24_1.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_24.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_25.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
