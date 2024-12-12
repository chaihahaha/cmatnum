#include "stdafx.h"
#include "fm_431.h"

inline int fm_431(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx256, bmats.Axx273, bmats.Axx2811, bmats.Axx846, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_25_29, bmats.Bx1615, bmats.Bx2493, bmats.Bx3213, bmats.Bx3214, bmats.Bx3215, bmats.Bx3216, bmats.Bx3217, bmats.Bx3218, bmats.Bx3219, bmats.Bx3220, bmats.Bx3221, bmats.Bx3222, bmats.Bx3223, bmats.Bx3224, bmats.Bx3225, bmats.Bx3226, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
