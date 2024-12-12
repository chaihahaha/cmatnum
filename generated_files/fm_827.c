#include "stdafx.h"
#include "fm_827.h"

inline int fm_827(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx135, bmats.Axx1967, bmats.Axx2628, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.Bx6528, bmats.Bx6896, bmats.Bx7191, bmats.Bx7594, bmats.Bx7595, bmats.Bx7596, bmats.Bx7597, bmats.Bx7598, bmats.Bx7599, bmats.Bx7600, bmats.Bx7601, bmats.Bx7602, bmats.Bx7603, bmats.Bx7604, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_10.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
