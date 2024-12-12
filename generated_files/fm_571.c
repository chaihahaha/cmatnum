#include "stdafx.h"
#include "fm_571.h"

inline int fm_571(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1100, bmats.Axx1139, bmats.Axx3130, bmats.Axx733, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_21_28, bmats.B_22_28, bmats.Bx3619, bmats.Bx4981, bmats.Bx4982, bmats.Bx4983, bmats.Bx4984, bmats.Bx4985, bmats.Bx4986, bmats.Bx4987, bmats.Bx4988, bmats.Bx4989, bmats.Bx4990, bmats.Bx50, bmats.Bx51, bmats.Bx52, };
    double B_coeffs[16] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
