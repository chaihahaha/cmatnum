#include "stdafx.h"
#include "fm_1912.h"

inline int fm_1912(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx117, bmats.Axx641, bmats.Axx787, bmats.Axx79, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_31_17, bmats.B_31_26, bmats.B_31_27, bmats.B_31_28, bmats.B_31_30, bmats.Bx12095, bmats.Bx12440, bmats.Bx12741, bmats.Bx12874, bmats.Bx12875, bmats.Bx12879, bmats.Bx3111, bmats.Bx315, };
    double B_coeffs[13] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_17.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
