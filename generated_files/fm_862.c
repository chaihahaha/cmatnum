#include "stdafx.h"
#include "fm_862.h"

inline int fm_862(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2621, bmats.Axx3337, bmats.Axx395, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.Bx7241, bmats.Bx7946, bmats.Bx7967, bmats.Bx7968, bmats.Bx7969, bmats.Bx7970, bmats.Bx7971, bmats.Bx7972, bmats.Bx7973, bmats.Bx7974, bmats.Bx7975, bmats.Bx7976, bmats.Bx7977, bmats.Bx7978, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
