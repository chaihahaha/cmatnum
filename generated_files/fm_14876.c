#include "stdafx.h"
#include "fm_14876.h"

inline int fm_14876(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx145, bmats.Axx152, bmats.Axx3291, bmats.Axx888, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 24;
    double_cmat B_mats[24] = {bmats.B_10_32, bmats.B_11_32, bmats.B_13_32, bmats.B_18_10, bmats.B_18_11, bmats.B_18_13, bmats.B_18_6, bmats.B_18_7, bmats.B_1_32, bmats.B_2_32, bmats.B_3_32, bmats.B_4_32, bmats.B_5_32, bmats.B_6_32, bmats.B_7_32, bmats.B_8_32, bmats.B_9_32, bmats.Bx10210, bmats.Bx12387, bmats.Bx13013, bmats.Bx13239, bmats.Bx13444, bmats.Bx4610, bmats.Bx806, };
    double B_coeffs[24] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
