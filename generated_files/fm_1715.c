#include "stdafx.h"
#include "fm_1715.h"

inline int fm_1715(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1270, bmats.Axx1289, bmats.Axx280, bmats.Axx2994, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_23_19, bmats.Bx11341, bmats.Bx12497, bmats.Bx12498, bmats.Bx12499, bmats.Bx12500, bmats.Bx12501, };
    double B_coeffs[7] = {-2, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_19.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
