#include "stdafx.h"
#include "fm_562.h"

inline int fm_562(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1937, bmats.Axx2266, bmats.Axx832, bmats.Axx854, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_11_12, bmats.B_11_2, bmats.B_6_12, bmats.Bx3441, bmats.Bx4240, bmats.Bx4242, bmats.Bx4867, bmats.Bx4868, bmats.Bx4869, bmats.Bx4870, bmats.Bx4871, bmats.Bx4872, bmats.Bx4873, bmats.Bx4874, bmats.Bx4875, bmats.Bx4876, bmats.Bx4877, bmats.Bx4878, };
    double B_coeffs[18] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
