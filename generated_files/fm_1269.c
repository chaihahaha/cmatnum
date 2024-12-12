#include "stdafx.h"
#include "fm_1269.h"

inline int fm_1269(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1818, bmats.Axx2077, bmats.Axx574, bmats.Axx599, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_3_7, bmats.Bx10050, bmats.Bx10253, bmats.Bx10809, bmats.Bx10810, bmats.Bx10811, bmats.Bx10812, bmats.Bx10813, bmats.Bx10814, bmats.Bx10815, bmats.Bx10816, };
    double B_coeffs[11] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
