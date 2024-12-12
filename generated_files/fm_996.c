#include "stdafx.h"
#include "fm_996.h"

inline int fm_996(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1935, bmats.Axx2304, bmats.Axx3241, bmats.Axx3400, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_19_12, bmats.B_19_13, bmats.B_19_9, bmats.B_9_25, bmats.Bx807, bmats.Bx8185, bmats.Bx8274, bmats.Bx8330, bmats.Bx8996, bmats.Bx9059, bmats.Bx9060, bmats.Bx9061, bmats.Bx9062, bmats.Bx9063, bmats.Bx9064, bmats.Bx9065, bmats.Bx9066, bmats.Bx9067, bmats.Bx9068, };
    double B_coeffs[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_25.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
