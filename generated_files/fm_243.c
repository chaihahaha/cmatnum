#include "stdafx.h"
#include "fm_243.h"

inline int fm_243(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1876, bmats.Axx203, bmats.Axx3258, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_2_2, bmats.Bx442, bmats.Bx443, bmats.Bx444, bmats.Bx445, bmats.Bx446, bmats.Bx447, bmats.Bx448, bmats.Bx449, bmats.Bx450, bmats.Bx451, bmats.Bx452, bmats.Bx453, bmats.Bx454, bmats.Bx455, bmats.Bx456, bmats.Bx457, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_15.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
