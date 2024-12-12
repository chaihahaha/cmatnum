#include "stdafx.h"
#include "fm_306.h"

inline int fm_306(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2373, bmats.Axx2780, bmats.Axx2877, bmats.Axx2881, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_30_14, bmats.B_7_30, bmats.Bx1418, bmats.Bx1419, bmats.Bx1420, bmats.Bx1421, bmats.Bx1422, bmats.Bx1423, bmats.Bx1424, bmats.Bx1425, bmats.Bx1426, bmats.Bx1427, bmats.Bx1428, bmats.Bx1429, bmats.Bx1430, bmats.Bx1431, bmats.Bx1432, bmats.Bx1433, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
