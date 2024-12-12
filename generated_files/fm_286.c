#include "stdafx.h"
#include "fm_286.h"

inline int fm_286(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1722, bmats.Axx2123, bmats.Axx3379, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_30_30, bmats.Bx1089, bmats.Bx1110, bmats.Bx1111, bmats.Bx1112, bmats.Bx1113, bmats.Bx1114, bmats.Bx1115, bmats.Bx1116, bmats.Bx1117, bmats.Bx1118, bmats.Bx1119, bmats.Bx1120, bmats.Bx1121, bmats.Bx1122, bmats.Bx1123, bmats.Bx1124, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_11_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
