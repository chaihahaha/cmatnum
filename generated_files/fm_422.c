#include "stdafx.h"
#include "fm_422.h"

inline int fm_422(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx797, bmats.Axx811, bmats.Axx818, bmats.Axx852, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_13_13, bmats.B_14_13, bmats.Bx2497, bmats.Bx2504, bmats.Bx3100, bmats.Bx3101, bmats.Bx3102, bmats.Bx3103, bmats.Bx3104, bmats.Bx3105, bmats.Bx3106, bmats.Bx3108, bmats.Bx3109, };
    double B_coeffs[13] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
