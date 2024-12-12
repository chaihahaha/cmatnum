#include "stdafx.h"
#include "fm_311.h"

inline int fm_311(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx130, bmats.Axx1720, bmats.Axx3379, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_24_14, bmats.B_30_30, bmats.Bx1465, bmats.Bx1497, bmats.Bx1498, bmats.Bx1499, bmats.Bx1500, bmats.Bx1501, bmats.Bx1502, bmats.Bx1503, bmats.Bx1504, bmats.Bx1505, bmats.Bx1506, bmats.Bx1507, bmats.Bx1508, bmats.Bx1509, bmats.Bx1510, bmats.Bx1511, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
