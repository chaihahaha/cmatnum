#include "stdafx.h"
#include "fm_1366.h"

inline int fm_1366(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1798, bmats.Axx1817, bmats.Axx2073, bmats.Axx2304, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_6_6, bmats.Bx11217, bmats.Bx11218, bmats.Bx11219, bmats.Bx11220, bmats.Bx11221, bmats.Bx11222, bmats.Bx11223, bmats.Bx11224, bmats.Bx11225, bmats.Bx11226, bmats.Bx11227, bmats.Bx11228, bmats.Bx11229, bmats.Bx11230, bmats.Bx3097, bmats.Bx4606, };
    double B_coeffs[17] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
