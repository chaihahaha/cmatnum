#include "stdafx.h"
#include "fm_434.h"

inline int fm_434(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1732, bmats.Axx278, bmats.Axx3376, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx2493, bmats.Bx3227, bmats.Bx3256, bmats.Bx3257, bmats.Bx3258, bmats.Bx3259, bmats.Bx3260, bmats.Bx3261, bmats.Bx3262, bmats.Bx3263, bmats.Bx3264, bmats.Bx3265, bmats.Bx3266, bmats.Bx3267, bmats.Bx3268, bmats.Bx3269, bmats.Bx3270, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
