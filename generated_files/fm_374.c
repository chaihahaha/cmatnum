#include "stdafx.h"
#include "fm_374.h"

inline int fm_374(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1785, bmats.Axx2902, bmats.Axx3398, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_21_14, bmats.B_30_14, bmats.B_4_5, bmats.Bx1766, bmats.Bx2450, bmats.Bx2451, bmats.Bx2452, bmats.Bx2453, bmats.Bx2454, bmats.Bx2455, bmats.Bx2456, bmats.Bx2457, bmats.Bx2458, bmats.Bx2459, bmats.Bx2460, bmats.Bx2461, bmats.Bx2462, bmats.Bx2463, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
