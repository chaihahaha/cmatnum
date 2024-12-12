#include "stdafx.h"
#include "fm_1786.h"

inline int fm_1786(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1778, bmats.Axx2125, bmats.Axx2441, bmats.Axx2444, bmats.Axx2446, bmats.Axx2447, bmats.Axx2450, bmats.Axx2451, bmats.Axx2454, bmats.Axx2455, bmats.Axx2458, bmats.Axx2459, bmats.Axx2462, bmats.Axx2463, bmats.Axx2466, bmats.Axx2467, bmats.Axx2471, bmats.Axx961, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_20_3, bmats.Bx10420, bmats.Bx11228, bmats.Bx11686, bmats.Bx12185, bmats.Bx12652, bmats.Bx12653, bmats.Bx12654, bmats.Bx12655, bmats.Bx12656, bmats.Bx3085, bmats.Bx4595, bmats.Bx6261, bmats.Bx7388, bmats.Bx790, bmats.Bx8646, bmats.Bx9743, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_3.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
