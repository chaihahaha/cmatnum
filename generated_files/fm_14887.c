#include "stdafx.h"
#include "fm_14887.h"

inline int fm_14887(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1741, bmats.Axx39, bmats.Axx689, bmats.Axx918, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_20_32, bmats.Bx11841, bmats.Bx12508, bmats.Bx12525, bmats.Bx13258, bmats.Bx13366, bmats.Bx13381, bmats.Bx13440, bmats.Bx2449, };
    double B_coeffs[9] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
