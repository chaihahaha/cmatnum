#include "stdafx.h"
#include "fm_765.h"

inline int fm_765(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1005, bmats.Axx1018, bmats.Axx1524, bmats.Axx1556, bmats.Axx1740, bmats.Axx1747, bmats.Axx1935, bmats.Axx2017, bmats.Axx2066, bmats.Axx2073, bmats.Axx2099, bmats.Axx2303, bmats.Axx2374, bmats.Axx2853, bmats.Axx3007, bmats.Axx3292, bmats.Axx3366, bmats.Axx418, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx6393, bmats.Bx7093, bmats.Bx7153, bmats.Bx7166, bmats.Bx7167, bmats.Bx7168, bmats.Bx7169, bmats.Bx7170, bmats.Bx7171, bmats.Bx7172, bmats.Bx7173, bmats.Bx7174, bmats.Bx7175, bmats.Bx7176, bmats.Bx7177, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
