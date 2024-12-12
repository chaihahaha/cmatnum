#include "stdafx.h"
#include "fm_316.h"

inline int fm_316(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1900, bmats.Axx316, bmats.Axx350, bmats.Axx878, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_25_25, bmats.B_25_30, bmats.B_30_30, bmats.Bx1571, bmats.Bx1572, bmats.Bx1573, bmats.Bx1574, bmats.Bx1575, bmats.Bx1576, bmats.Bx1577, bmats.Bx1578, bmats.Bx1579, bmats.Bx1580, bmats.Bx1581, bmats.Bx1582, bmats.Bx1583, bmats.Bx1584, bmats.Bx1585, };
    double B_coeffs[18] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
