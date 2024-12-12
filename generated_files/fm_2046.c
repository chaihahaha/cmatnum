#include "stdafx.h"
#include "fm_2046.h"

inline int fm_2046(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx2026, bmats.Axx2165, bmats.Axx2182, bmats.Axx2185, bmats.Axx2186, bmats.Axx2189, bmats.Axx2190, bmats.Axx2193, bmats.Axx2194, bmats.Axx2197, bmats.Axx2198, bmats.Axx2202, bmats.Axx523, bmats.Axx78, bmats.Axx86, bmats.Axx87, bmats.Axx943, bmats.Axx953, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_19_1, bmats.B_1_18, bmats.Bx10422, bmats.Bx11230, bmats.Bx11688, bmats.Bx12233, bmats.Bx12617, bmats.Bx13059, bmats.Bx13060, bmats.Bx13061, bmats.Bx13062, bmats.Bx3087, bmats.Bx4597, bmats.Bx6263, bmats.Bx7390, bmats.Bx792, bmats.Bx8648, bmats.Bx9745, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_1.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
