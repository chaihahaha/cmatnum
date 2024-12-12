#include "stdafx.h"
#include "fm_340.h"

inline int fm_340(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1846, bmats.Axx3020, bmats.Axx396, bmats.Axx436, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_5_14, bmats.B_6_14, bmats.Bx1448, bmats.Bx1939, bmats.Bx1940, bmats.Bx1941, bmats.Bx1942, bmats.Bx1943, bmats.Bx1944, bmats.Bx1945, bmats.Bx1946, bmats.Bx1947, bmats.Bx1948, bmats.Bx1949, bmats.Bx1950, bmats.Bx1951, bmats.Bx1952, };
    double B_coeffs[17] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
