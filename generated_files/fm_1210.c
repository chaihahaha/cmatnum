#include "stdafx.h"
#include "fm_1210.h"

inline int fm_1210(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2035, bmats.Axx2114, bmats.Axx3087, bmats.Axx603, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_7_7, bmats.Bx10407, bmats.Bx10408, bmats.Bx10409, bmats.Bx10410, bmats.Bx10411, bmats.Bx10412, bmats.Bx10413, bmats.Bx10414, bmats.Bx10415, bmats.Bx10416, bmats.Bx10417, bmats.Bx10418, bmats.Bx10419, bmats.Bx10420, bmats.Bx10421, bmats.Bx10422, };
    double B_coeffs[17] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
