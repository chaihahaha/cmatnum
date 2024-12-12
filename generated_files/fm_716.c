#include "stdafx.h"
#include "fm_716.h"

inline int fm_716(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2022, bmats.Axx2087, bmats.Axx2853, bmats.Axx620, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx6393, bmats.Bx6501, bmats.Bx6554, bmats.Bx6568, bmats.Bx6569, bmats.Bx6570, bmats.Bx6571, bmats.Bx6572, bmats.Bx6573, bmats.Bx6574, bmats.Bx6575, bmats.Bx6576, bmats.Bx6577, bmats.Bx6578, bmats.Bx6579, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
