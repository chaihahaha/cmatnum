#include "stdafx.h"
#include "fm_1933.h"

inline int fm_1933(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1001, bmats.Axx1594, bmats.Axx1703, bmats.Axx1748, bmats.Axx1869, bmats.Axx1870, bmats.Axx192, bmats.Axx2168, bmats.Axx2599, bmats.Axx2641, bmats.Axx3048, bmats.Axx3240, bmats.Axx3255, bmats.Axx3343, bmats.Axx538, bmats.Axx586, bmats.Axx998, bmats.Axx999, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_17_3, bmats.Bx11599, bmats.Bx11693, bmats.Bx12237, bmats.Bx12673, bmats.Bx12748, bmats.Bx12778, bmats.Bx12925, bmats.Bx12934, bmats.Bx12938, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_18.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
