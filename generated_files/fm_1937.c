#include "stdafx.h"
#include "fm_1937.h"

inline int fm_1937(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1402, bmats.Axx1424, bmats.Axx1698, bmats.Axx286, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_28_17, bmats.Bx11, bmats.Bx12876, bmats.Bx12949, bmats.Bx12950, bmats.Bx23, bmats.Bx39, bmats.Bx40, bmats.Bx42, bmats.Bx45, bmats.Bx49, bmats.Bx6285, };
    double B_coeffs[12] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_17.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
