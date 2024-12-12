#include "stdafx.h"
#include "fm_660.h"

inline int fm_660(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx178, bmats.Axx218, bmats.Axx651, bmats.Axx681, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_15_11, bmats.B_15_9, bmats.B_9_11, bmats.Bx4664, bmats.Bx5995, bmats.Bx5996, bmats.Bx5997, bmats.Bx5998, bmats.Bx5999, bmats.Bx6000, bmats.Bx6001, bmats.Bx6002, bmats.Bx6003, bmats.Bx6004, };
    double B_coeffs[14] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
