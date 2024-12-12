#include "stdafx.h"
#include "fm_1901.h"

inline int fm_1901(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1972, bmats.Axx2125, bmats.Axx2509, bmats.Axx2510, bmats.Axx2513, bmats.Axx2514, bmats.Axx2517, bmats.Axx2518, bmats.Axx2520, bmats.Axx2523, bmats.Axx2524, bmats.Axx2527, bmats.Axx2529, bmats.Axx2530, bmats.Axx2533, bmats.Axx2534, bmats.Axx2538, bmats.Axx963, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx12637, bmats.Bx12670, bmats.Bx12852, };
    double B_coeffs[3] = {-1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_2.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
