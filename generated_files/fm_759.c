#include "stdafx.h"
#include "fm_759.h"

inline int fm_759(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx513, bmats.Axx582, bmats.Axx607, bmats.Axx735, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_12_11, bmats.B_3_11, bmats.B_6_11, bmats.B_7_11, bmats.Bx2343, bmats.Bx5984, bmats.Bx696, bmats.Bx7093, bmats.Bx7094, bmats.Bx7095, bmats.Bx7096, bmats.Bx7097, bmats.Bx7098, bmats.Bx7099, bmats.Bx7100, bmats.Bx7101, bmats.Bx7102, bmats.Bx7104, };
    double B_coeffs[18] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
