#include "stdafx.h"
#include "fm_1676.h"

int fm_1676(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 5;
    double_cmat A_mats[5] = {bmats.A_19_29, bmats.A_19_30, bmats.Ax1109, bmats.Ax1868, bmats.Ax4508, };
    double A_coeffs[5] = {1, -16, 1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_17_19, bmats.B_18_19, bmats.B_20_19, bmats.B_23_19, bmats.B_24_19, bmats.B_26_19, bmats.B_27_19, bmats.B_30_1, bmats.B_30_19, bmats.B_32_19, bmats.B_3_30, bmats.Bx12409, bmats.Bx2491, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_19.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
