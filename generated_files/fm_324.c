#include "stdafx.h"
#include "fm_324.h"

inline int fm_324(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1304, bmats.Axx1900, bmats.Axx314, bmats.Axx347, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_26_26, bmats.B_26_30, bmats.B_30_30, bmats.Bx1031, bmats.Bx1692, bmats.Bx1693, bmats.Bx1694, bmats.Bx1695, bmats.Bx1696, bmats.Bx1697, bmats.Bx1698, bmats.Bx1699, bmats.Bx1700, bmats.Bx1701, bmats.Bx1702, bmats.Bx1703, bmats.Bx1704, bmats.Bx1705, };
    double B_coeffs[18] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
