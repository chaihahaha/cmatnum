#include "stdafx.h"
#include "fm_1845.h"

inline int fm_1845(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2025, bmats.Axx665, bmats.Axx678, bmats.Axx797, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_13_2, bmats.B_9_11, bmats.B_9_16, bmats.B_9_2, bmats.B_9_6, bmats.Bx11082, bmats.Bx11085, bmats.Bx12701, bmats.Bx12762, bmats.Bx12774, bmats.Bx1570, bmats.Bx688, bmats.Bx7588, };
    double B_coeffs[13] = {-1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_2.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
