#include "stdafx.h"
#include "fm_397.h"

inline int fm_397(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx121, bmats.Axx170, bmats.Axx2608, bmats.Axx434, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_11_14, bmats.B_1_14, bmats.Bx1184, bmats.Bx2149, bmats.Bx2741, bmats.Bx2742, bmats.Bx2743, bmats.Bx2744, bmats.Bx2745, bmats.Bx2746, bmats.Bx2747, bmats.Bx2748, bmats.Bx2749, bmats.Bx2750, bmats.Bx2751, bmats.Bx2752, bmats.Bx2754, };
    double B_coeffs[17] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
