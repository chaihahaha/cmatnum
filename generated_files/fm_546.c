#include "stdafx.h"
#include "fm_546.h"

inline int fm_546(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx109, bmats.Axx1723, bmats.Axx2013, bmats.Axx88, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_31_28, bmats.Bx4229, bmats.Bx4259, bmats.Bx4665, bmats.Bx4666, bmats.Bx4667, bmats.Bx4668, bmats.Bx4669, bmats.Bx4670, bmats.Bx4671, bmats.Bx4672, bmats.Bx4673, bmats.Bx4674, };
    double B_coeffs[13] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
