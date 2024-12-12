#include "stdafx.h"
#include "fm_1103.h"

inline int fm_1103(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx209, bmats.Axx2731, bmats.Axx2733, bmats.Axx732, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx2718, bmats.Bx387, bmats.Bx4590, bmats.Bx6256, bmats.Bx7288, bmats.Bx785, bmats.Bx8641, bmats.Bx9245, bmats.Bx9728, bmats.Bx9738, bmats.Bx9746, bmats.Bx9747, bmats.Bx9748, bmats.Bx9749, bmats.Bx9750, bmats.Bx9751, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_8.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
