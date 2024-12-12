#include "stdafx.h"
#include "fm_1204.h"

inline int fm_1204(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2072, bmats.Axx2171, bmats.Axx753, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx10362, bmats.Bx10363, bmats.Bx10364, bmats.Bx10365, bmats.Bx10366, bmats.Bx10368, bmats.Bx10369, bmats.Bx10370, bmats.Bx10371, bmats.Bx4646, bmats.Bx6898, bmats.Bx810, bmats.Bx8109, bmats.Bx8660, bmats.Bx9756, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
