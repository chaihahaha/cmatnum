#include "stdafx.h"
#include "fm_1662.h"

inline int fm_1662(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1521, bmats.Axx1671, bmats.Axx1824, bmats.Axx1896, bmats.Axx1909, bmats.Axx1942, bmats.Axx1954, bmats.Axx2132, bmats.Axx2473, bmats.Axx2540, bmats.Axx3242, bmats.Axx3349, bmats.Axx3399, bmats.Axx538, bmats.Axx824, bmats.Axx888, bmats.Axx993, bmats.Axx996, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_13_20, bmats.B_4_20, bmats.Bx10783, bmats.Bx11235, bmats.Bx12111, bmats.Bx12350, bmats.Bx12382, bmats.Bx12383, bmats.Bx12384, bmats.Bx12385, bmats.Bx12386, bmats.Bx12387, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_20.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
