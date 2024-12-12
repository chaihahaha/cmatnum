#include "stdafx.h"
#include "fm_727.h"

inline int fm_727(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1049, bmats.Axx1073, bmats.Axx1444, bmats.Axx494, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_21_27, bmats.Bx5551, bmats.Bx5650, bmats.Bx6703, bmats.Bx6704, bmats.Bx6705, bmats.Bx6706, bmats.Bx6707, bmats.Bx6708, bmats.Bx6709, bmats.Bx6710, bmats.Bx96, bmats.Bx97, bmats.Bx98, bmats.Bx99, };
    double B_coeffs[15] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
