#include "stdafx.h"
#include "fm_339.h"

inline int fm_339(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1873, bmats.Axx2307, bmats.Axx2861, bmats.Axx2867, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_30_14, bmats.B_5_30, bmats.Bx1831, bmats.Bx1924, bmats.Bx1925, bmats.Bx1926, bmats.Bx1927, bmats.Bx1928, bmats.Bx1929, bmats.Bx1930, bmats.Bx1931, bmats.Bx1932, bmats.Bx1933, bmats.Bx1934, bmats.Bx1935, bmats.Bx1936, bmats.Bx1937, bmats.Bx1938, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
