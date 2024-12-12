#include "stdafx.h"
#include "fm_418.h"

inline int fm_418(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1683, bmats.Axx1817, bmats.Axx3376, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_32_29, bmats.Bx2494, bmats.Bx3022, bmats.Bx3047, bmats.Bx3048, bmats.Bx3049, bmats.Bx3050, bmats.Bx3051, bmats.Bx3052, bmats.Bx3053, bmats.Bx3054, bmats.Bx3055, bmats.Bx3056, bmats.Bx3057, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
