#include "stdafx.h"
#include "fm_357.h"

inline int fm_357(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1781, bmats.Axx304, bmats.Axx326, bmats.Axx727, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_18_18, bmats.B_18_30, bmats.B_18_31, bmats.Bx1464, bmats.Bx2196, bmats.Bx2197, bmats.Bx2198, bmats.Bx2199, bmats.Bx2200, bmats.Bx2201, bmats.Bx2202, bmats.Bx2203, bmats.Bx2204, bmats.Bx2205, bmats.Bx2206, bmats.Bx2207, bmats.Bx2208, bmats.Bx2209, };
    double B_coeffs[18] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
