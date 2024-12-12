#include "stdafx.h"
#include "fm_881.h"

inline int fm_881(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1761, bmats.Axx2125, bmats.Axx2569, bmats.Axx2572, bmats.Axx2574, bmats.Axx2575, bmats.Axx2577, bmats.Axx2580, bmats.Axx2582, bmats.Axx2583, bmats.Axx2586, bmats.Axx2587, bmats.Axx2590, bmats.Axx2591, bmats.Axx2594, bmats.Axx2595, bmats.Axx2605, bmats.Axx965, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.Bx7752, bmats.Bx8118, bmats.Bx8173, bmats.Bx8186, bmats.Bx8187, bmats.Bx8188, bmats.Bx8189, bmats.Bx8190, bmats.Bx8191, bmats.Bx8192, bmats.Bx8193, bmats.Bx8194, bmats.Bx8195, bmats.Bx8196, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_10.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
