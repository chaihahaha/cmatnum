#include "stdafx.h"
#include "fm_672.h"

inline int fm_672(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2642, bmats.Axx3015, bmats.Axx759, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_10_27, bmats.Bx4811, bmats.Bx6040, bmats.Bx6125, bmats.Bx6126, bmats.Bx6127, bmats.Bx6128, bmats.Bx6129, bmats.Bx6130, bmats.Bx6131, bmats.Bx6132, bmats.Bx6133, bmats.Bx6134, bmats.Bx6135, bmats.Bx6136, bmats.Bx6137, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
