#include "stdafx.h"
#include "fm_1629.h"

inline int fm_1629(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1889, bmats.Axx2852, bmats.Axx3396, bmats.Axx824, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_4_4, bmats.Bx10425, bmats.Bx12221, bmats.Bx12222, bmats.Bx12223, bmats.Bx12224, bmats.Bx12225, bmats.Bx12226, bmats.Bx12227, bmats.Bx12228, bmats.Bx12229, bmats.Bx12230, bmats.Bx12231, bmats.Bx12232, bmats.Bx12233, bmats.Bx7399, bmats.Bx9749, };
    double B_coeffs[17] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_20.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
