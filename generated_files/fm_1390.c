#include "stdafx.h"
#include "fm_1390.h"

inline int fm_1390(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1011, bmats.Axx1489, bmats.Axx1526, bmats.Axx1609, bmats.Axx1778, bmats.Axx1820, bmats.Axx1935, bmats.Axx2091, bmats.Axx2166, bmats.Axx2304, bmats.Axx2854, bmats.Axx2892, bmats.Axx3356, bmats.Axx3400, bmats.Axx418, bmats.Axx475, bmats.Axx639, bmats.Axx726, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_12_22, bmats.B_13_22, bmats.B_7_22, bmats.B_8_22, bmats.Bx10908, bmats.Bx11258, bmats.Bx11328, bmats.Bx11374, bmats.Bx11375, bmats.Bx11376, bmats.Bx11377, bmats.Bx11378, bmats.Bx11379, bmats.Bx11380, bmats.Bx11381, bmats.Bx7153, bmats.Bx7400, bmats.Bx9819, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
