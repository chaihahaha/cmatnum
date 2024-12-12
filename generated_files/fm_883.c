#include "stdafx.h"
#include "fm_883.h"

inline int fm_883(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1207, bmats.Axx1249, bmats.Axx571, bmats.Axx889, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_20_26, bmats.Bx157, bmats.Bx158, bmats.Bx159, bmats.Bx6641, bmats.Bx7241, bmats.Bx7740, bmats.Bx8207, bmats.Bx8208, bmats.Bx8209, bmats.Bx8210, bmats.Bx8211, bmats.Bx8212, bmats.Bx8213, };
    double B_coeffs[14] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
