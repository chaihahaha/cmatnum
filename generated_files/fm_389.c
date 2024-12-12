#include "stdafx.h"
#include "fm_389.h"

inline int fm_389(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1602, bmats.Axx1924, bmats.Axx26, bmats.Axx823, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_16_13, bmats.Bx2500, bmats.Bx2624, bmats.Bx2625, bmats.Bx2626, bmats.Bx2627, bmats.Bx2628, bmats.Bx2629, bmats.Bx2630, bmats.Bx2631, bmats.Bx2632, bmats.Bx2633, bmats.Bx2634, bmats.Bx2635, bmats.Bx2636, bmats.Bx965, };
    double B_coeffs[16] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
