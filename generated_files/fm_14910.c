#include "stdafx.h"
#include "fm_14910.h"

inline int fm_14910(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx24, bmats.Axx442, bmats.Axx788, bmats.Axx822, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_7_1, bmats.B_7_11, bmats.B_7_15, bmats.B_7_16, bmats.B_7_6, bmats.B_7_9, bmats.Bx11237, bmats.Bx13356, bmats.Bx13460, bmats.Bx13465, bmats.Bx684, bmats.Bx8836, };
    double B_coeffs[12] = {-1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_16.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
