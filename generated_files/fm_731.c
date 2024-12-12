#include "stdafx.h"
#include "fm_731.h"

inline int fm_731(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2303, bmats.Axx2345, bmats.Axx874, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx5633, bmats.Bx6723, bmats.Bx6750, bmats.Bx6751, bmats.Bx6752, bmats.Bx6753, bmats.Bx6754, bmats.Bx6755, bmats.Bx6756, bmats.Bx6757, bmats.Bx6758, bmats.Bx6759, bmats.Bx6760, bmats.Bx6761, bmats.Bx6762, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
