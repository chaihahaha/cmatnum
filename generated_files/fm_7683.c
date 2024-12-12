#include "stdafx.h"
#include "fm_7683.h"

inline int fm_7683(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 17;
    double_cmat A_mats[17] = {bmats.A_32_24, bmats.Axx2322, bmats.Axx40, bmats.Axx41, bmats.Axx44, bmats.Axx45, bmats.Axx48, bmats.Axx49, bmats.Axx51, bmats.Axx52, bmats.Axx53, bmats.Axx55, bmats.Axx59, bmats.Axx61, bmats.Axx7, bmats.Axx8, bmats.Axx951, };
    double A_coeffs[17] = {15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_32, bmats.Bx13100, };
    double B_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_24.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_32.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
