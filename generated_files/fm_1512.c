#include "stdafx.h"
#include "fm_1512.h"

inline int fm_1512(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx3177, bmats.Axx3355, bmats.Axx3395, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.Bx11538, bmats.Bx11827, bmats.Bx11843, bmats.Bx11844, bmats.Bx11845, bmats.Bx11846, bmats.Bx11847, bmats.Bx11848, bmats.Bx11849, };
    double B_coeffs[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_21.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
