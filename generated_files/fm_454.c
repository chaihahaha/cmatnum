#include "stdafx.h"
#include "fm_454.h"

inline int fm_454(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1805, bmats.Axx1873, bmats.Axx2952, bmats.Axx2954, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx3196, bmats.Bx3528, bmats.Bx3544, bmats.Bx3545, bmats.Bx3546, bmats.Bx3547, bmats.Bx3548, bmats.Bx3549, bmats.Bx3550, bmats.Bx3551, bmats.Bx3552, bmats.Bx3553, bmats.Bx3554, bmats.Bx3555, bmats.Bx3556, bmats.Bx3557, bmats.Bx3558, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
