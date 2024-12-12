#include "stdafx.h"
#include "fm_1086.h"

inline int fm_1086(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1605, bmats.Axx1798, bmats.Axx2854, bmats.Axx474, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.Bx7896, bmats.Bx8651, bmats.Bx9193, bmats.Bx9592, bmats.Bx9593, bmats.Bx9594, bmats.Bx9595, bmats.Bx9596, bmats.Bx9597, bmats.Bx9598, bmats.Bx9599, bmats.Bx9600, bmats.Bx9601, bmats.Bx9602, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_24.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
