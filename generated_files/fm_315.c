#include "stdafx.h"
#include "fm_315.h"

inline int fm_315(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1977, bmats.Axx675, bmats.Axx688, bmats.Axx702, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_15_14, bmats.B_9_14, bmats.Bx1448, bmats.Bx1557, bmats.Bx1558, bmats.Bx1559, bmats.Bx1560, bmats.Bx1561, bmats.Bx1562, bmats.Bx1563, bmats.Bx1564, bmats.Bx1565, bmats.Bx1566, bmats.Bx1567, bmats.Bx1568, bmats.Bx1569, bmats.Bx1570, };
    double B_coeffs[17] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
