#include "stdafx.h"
#include "fm_8396.h"

int fm_8396(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_20_7, bmats.A_20_8, bmats.A_24_18, bmats.A_24_19, bmats.A_24_20, bmats.A_24_24, bmats.A_24_26, bmats.A_24_27, bmats.A_24_28, bmats.A_3_19, bmats.A_3_20, bmats.Ax3405, bmats.Ax4321, bmats.Ax6947, };
    double A_coeffs[14] = {-1, 16, 1, -16, 1, 1, 1, 1, 1, -1, 16, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_19_4, bmats.B_20_24, bmats.B_8_19, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_24_4.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_19.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_24.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
