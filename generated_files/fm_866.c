#include "stdafx.h"
#include "fm_866.h"

inline int fm_866(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx435, bmats.Axx617, bmats.Axx635, bmats.Axx763, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_2_10, bmats.B_2_12, bmats.Bx2194, bmats.Bx8017, bmats.Bx8018, bmats.Bx8019, bmats.Bx8020, bmats.Bx8021, bmats.Bx8022, bmats.Bx8023, bmats.Bx8024, bmats.Bx8025, bmats.Bx8026, bmats.Bx8027, };
    double B_coeffs[14] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_10.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
