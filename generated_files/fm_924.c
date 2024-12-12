#include "stdafx.h"
#include "fm_924.h"

inline int fm_924(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx173, bmats.Axx2894, bmats.Axx672, bmats.Axx701, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_13_9, bmats.B_4_9, bmats.Bx1336, bmats.Bx8348, bmats.Bx8523, bmats.Bx8524, bmats.Bx8525, bmats.Bx8526, bmats.Bx8527, bmats.Bx8530, };
    double B_coeffs[10] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
