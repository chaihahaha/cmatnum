#include "stdafx.h"
#include "fm_449.h"

inline int fm_449(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1600, bmats.Axx2996, bmats.Axx690, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_30_13, bmats.Bx2509, bmats.Bx3467, bmats.Bx3468, bmats.Bx3469, bmats.Bx3470, bmats.Bx3471, bmats.Bx3472, bmats.Bx3473, bmats.Bx3474, bmats.Bx3475, bmats.Bx3476, bmats.Bx3477, bmats.Bx3478, bmats.Bx3479, bmats.Bx3480, bmats.Bx3482, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
