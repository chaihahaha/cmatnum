#include "stdafx.h"
#include "fm_702.h"

inline int fm_702(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2111, bmats.Axx488, bmats.Axx710, bmats.Axx736, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_8_11, bmats.Bx5209, bmats.Bx5633, bmats.Bx5957, bmats.Bx6406, bmats.Bx6407, bmats.Bx6408, bmats.Bx6409, bmats.Bx6410, bmats.Bx6411, bmats.Bx6412, bmats.Bx6413, bmats.Bx6414, bmats.Bx6415, bmats.Bx6416, };
    double B_coeffs[15] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
