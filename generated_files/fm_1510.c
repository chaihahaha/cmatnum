#include "stdafx.h"
#include "fm_1510.h"

inline int fm_1510(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1999, bmats.Axx2351, bmats.Axx3398, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_20_5, bmats.Bx11407, bmats.Bx11827, bmats.Bx11828, bmats.Bx11829, bmats.Bx11830, bmats.Bx11831, bmats.Bx11832, bmats.Bx11833, bmats.Bx11834, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
