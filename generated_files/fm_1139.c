#include "stdafx.h"
#include "fm_1139.h"

inline int fm_1139(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1398, bmats.Axx1417, bmats.Axx1734, bmats.Axx2767, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_17_24, bmats.Bx10079, bmats.Bx10080, bmats.Bx10081, bmats.Bx10082, bmats.Bx10083, bmats.Bx10084, bmats.Bx10085, bmats.Bx10086, bmats.Bx10087, bmats.Bx9306, bmats.Bx9382, };
    double B_coeffs[12] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_24.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
