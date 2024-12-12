#include "stdafx.h"
#include "fm_981.h"

inline int fm_981(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx385, bmats.Axx456, bmats.Axx694, bmats.Axx734, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_3_9, bmats.B_7_9, bmats.B_8_9, bmats.Bx6433, bmats.Bx7499, bmats.Bx8436, bmats.Bx8561, bmats.Bx8909, bmats.Bx8910, bmats.Bx8911, bmats.Bx8912, bmats.Bx8913, bmats.Bx8914, bmats.Bx8915, bmats.Bx8917, };
    double B_coeffs[15] = {-1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
