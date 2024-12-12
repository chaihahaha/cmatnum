#include "stdafx.h"
#include "fm_965.h"

inline int fm_965(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1902, bmats.Axx400, bmats.Axx428, bmats.Axx698, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_6_9, bmats.Bx6817, bmats.Bx8746, bmats.Bx8747, bmats.Bx8748, bmats.Bx8749, bmats.Bx8750, bmats.Bx8751, bmats.Bx8752, bmats.Bx8753, bmats.Bx8754, bmats.Bx8755, bmats.Bx8756, };
    double B_coeffs[13] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
