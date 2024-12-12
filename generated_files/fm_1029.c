#include "stdafx.h"
#include "fm_1029.h"

inline int fm_1029(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1995, bmats.Axx2645, bmats.Axx2648, bmats.Axx2649, bmats.Axx2652, bmats.Axx2653, bmats.Axx2656, bmats.Axx2658, bmats.Axx2659, bmats.Axx2662, bmats.Axx2663, bmats.Axx2666, bmats.Axx2667, bmats.Axx2670, bmats.Axx2671, bmats.Axx2680, bmats.Axx78, bmats.Axx967, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.Bx8745, bmats.Bx9349, bmats.Bx9404, bmats.Bx9415, bmats.Bx9416, bmats.Bx9417, bmats.Bx9418, bmats.Bx9419, bmats.Bx9420, bmats.Bx9421, bmats.Bx9422, bmats.Bx9423, bmats.Bx9424, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
