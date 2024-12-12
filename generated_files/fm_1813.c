#include "stdafx.h"
#include "fm_1813.h"

inline int fm_1813(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1076, bmats.Axx1082, bmats.Axx2420, bmats.Axx871, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_27_18, bmats.B_27_29, bmats.Bx10229, bmats.Bx1107, bmats.Bx12427, bmats.Bx12478, bmats.Bx12687, bmats.Bx12740, bmats.Bx12741, bmats.Bx12742, bmats.Bx12744, bmats.Bx4524, bmats.Bx7418, };
    double B_coeffs[13] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_18.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
