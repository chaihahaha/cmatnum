#include "stdafx.h"
#include "fm_1663.h"

inline int fm_1663(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx2091, bmats.Axx2376, bmats.Axx2377, bmats.Axx2380, bmats.Axx2381, bmats.Axx2384, bmats.Axx2385, bmats.Axx2388, bmats.Axx2389, bmats.Axx2392, bmats.Axx2393, bmats.Axx2396, bmats.Axx2397, bmats.Axx2400, bmats.Axx2402, bmats.Axx2406, bmats.Axx2861, bmats.Axx958, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.Bx12349, bmats.Bx12355, bmats.Bx12381, bmats.Bx12388, bmats.Bx12389, bmats.Bx12390, bmats.Bx12391, bmats.Bx12392, };
    double B_coeffs[8] = {-1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_4.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
