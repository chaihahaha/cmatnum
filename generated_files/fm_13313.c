#include "stdafx.h"
#include "fm_13313.h"

inline int fm_13313(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1485, bmats.Axx908, bmats.Axx948, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx12200, bmats.Bx12628, bmats.Bx12817, bmats.Bx13034, bmats.Bx13095, bmats.Bx13096, bmats.Bx13097, bmats.Bx13098, bmats.Bx13099, bmats.Bx13100, bmats.Bx3007, bmats.Bx4522, bmats.Bx6203, bmats.Bx699, bmats.Bx7677, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
