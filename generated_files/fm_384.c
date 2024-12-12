#include "stdafx.h"
#include "fm_384.h"

inline int fm_384(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1043, bmats.Axx2018, bmats.Axx3248, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_14_29, bmats.Bx2485, bmats.Bx2560, bmats.Bx2561, bmats.Bx2562, bmats.Bx2563, bmats.Bx2564, bmats.Bx2565, bmats.Bx2566, bmats.Bx2567, bmats.Bx2568, bmats.Bx2569, bmats.Bx2570, bmats.Bx2571, bmats.Bx2572, bmats.Bx869, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
