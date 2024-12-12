#include "stdafx.h"
#include "fm_290.h"

inline int fm_290(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1648, bmats.Axx723, bmats.Axx836, bmats.Axx858, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_12_12, bmats.B_12_14, bmats.B_2_14, bmats.Bx1170, bmats.Bx1171, bmats.Bx1172, bmats.Bx1173, bmats.Bx1174, bmats.Bx1175, bmats.Bx1176, bmats.Bx1177, bmats.Bx1178, bmats.Bx1179, bmats.Bx1180, bmats.Bx1181, bmats.Bx1182, bmats.Bx1183, bmats.Bx1184, };
    double B_coeffs[18] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_12_14.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
