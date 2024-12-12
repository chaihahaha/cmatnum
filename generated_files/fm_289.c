#include "stdafx.h"
#include "fm_289.h"

inline int fm_289(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2273, bmats.Axx2873, bmats.Axx2879, bmats.Axx673, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_11_30, bmats.B_30_14, bmats.Bx1061, bmats.Bx1155, bmats.Bx1156, bmats.Bx1157, bmats.Bx1158, bmats.Bx1159, bmats.Bx1160, bmats.Bx1161, bmats.Bx1162, bmats.Bx1163, bmats.Bx1164, bmats.Bx1165, bmats.Bx1166, bmats.Bx1167, bmats.Bx1168, bmats.Bx1169, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
