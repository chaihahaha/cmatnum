#include "stdafx.h"
#include "fm_1080.h"

inline int fm_1080(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2076, bmats.Axx2967, bmats.Axx711, bmats.Axx738, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_12_11, bmats.B_12_8, bmats.Bx7432, bmats.Bx7672, bmats.Bx9257, bmats.Bx9466, bmats.Bx9471, bmats.Bx9534, bmats.Bx9550, bmats.Bx9551, };
    double B_coeffs[10] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_8.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
