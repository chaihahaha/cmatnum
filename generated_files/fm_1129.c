#include "stdafx.h"
#include "fm_1129.h"

inline int fm_1129(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1551, bmats.Axx399, bmats.Axx427, bmats.Axx471, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_6_10, bmats.B_6_8, bmats.Bx5004, bmats.Bx9592, bmats.Bx9974, bmats.Bx9975, bmats.Bx9976, bmats.Bx9977, bmats.Bx9978, bmats.Bx9979, bmats.Bx9980, bmats.Bx9981, bmats.Bx9982, };
    double B_coeffs[13] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_8.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
