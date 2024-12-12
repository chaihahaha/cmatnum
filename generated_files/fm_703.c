#include "stdafx.h"
#include "fm_703.h"

inline int fm_703(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1044, bmats.Axx1064, bmats.Axx513, bmats.Axx792, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_24_27, bmats.Bx5225, bmats.Bx5650, bmats.Bx6417, bmats.Bx6418, bmats.Bx6419, bmats.Bx6420, bmats.Bx6421, bmats.Bx75, bmats.Bx76, bmats.Bx77, bmats.Bx78, bmats.Bx79, bmats.Bx80, bmats.Bx81, };
    double B_coeffs[15] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
