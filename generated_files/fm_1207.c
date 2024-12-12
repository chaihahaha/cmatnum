#include "stdafx.h"
#include "fm_1207.h"

inline int fm_1207(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2712, bmats.Axx2856, bmats.Axx822, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.Bx10243, bmats.Bx10245, bmats.Bx10384, bmats.Bx10385, bmats.Bx10386, bmats.Bx10387, bmats.Bx10388, bmats.Bx10389, bmats.Bx10390, bmats.Bx10391, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
