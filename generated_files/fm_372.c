#include "stdafx.h"
#include "fm_372.h"

inline int fm_372(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx149, bmats.Axx1934, bmats.Axx514, bmats.Axx561, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_4_14, bmats.B_6_14, bmats.Bx1448, bmats.Bx1784, bmats.Bx2423, bmats.Bx2424, bmats.Bx2425, bmats.Bx2426, bmats.Bx2427, bmats.Bx2428, bmats.Bx2429, bmats.Bx2430, bmats.Bx2431, bmats.Bx2432, bmats.Bx2433, bmats.Bx2434, bmats.Bx2435, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
