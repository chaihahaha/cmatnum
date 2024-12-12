#include "stdafx.h"
#include "fm_1152.h"

inline int fm_1152(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1006, bmats.Axx1603, bmats.Axx1605, bmats.Axx1663, bmats.Axx1666, bmats.Axx1809, bmats.Axx1870, bmats.Axx2071, bmats.Axx2141, bmats.Axx2168, bmats.Axx2208, bmats.Axx3282, bmats.Axx3292, bmats.Axx3359, bmats.Axx696, bmats.Axx708, bmats.Axx888, bmats.Axx945, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_11_24, bmats.Bx10145, bmats.Bx10201, bmats.Bx10202, bmats.Bx10203, bmats.Bx10204, bmats.Bx10205, bmats.Bx10206, bmats.Bx10207, bmats.Bx10208, bmats.Bx10209, bmats.Bx10210, bmats.Bx7055, bmats.Bx7401, bmats.Bx9820, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_24.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
