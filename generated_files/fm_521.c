#include "stdafx.h"
#include "fm_521.h"

inline int fm_521(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1674, bmats.Axx246, bmats.Axx268, bmats.Axx3054, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_18_29, bmats.Bx2241, bmats.Bx2493, bmats.Bx3910, bmats.Bx4508, bmats.Bx4509, bmats.Bx4510, bmats.Bx4511, bmats.Bx4512, bmats.Bx4513, bmats.Bx4514, bmats.Bx4515, bmats.Bx4516, bmats.Bx4517, bmats.Bx4518, bmats.Bx4519, bmats.Bx4520, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
