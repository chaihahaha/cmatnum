#include "stdafx.h"
#include "fm_405.h"

inline int fm_405(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2062, bmats.Axx2960, bmats.Axx2962, bmats.Axx673, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_11_30, bmats.B_30_13, bmats.Bx2859, bmats.Bx2860, bmats.Bx2861, bmats.Bx2862, bmats.Bx2863, bmats.Bx2864, bmats.Bx2865, bmats.Bx2866, bmats.Bx2867, bmats.Bx2868, bmats.Bx2869, bmats.Bx2870, bmats.Bx2871, bmats.Bx2872, bmats.Bx2873, bmats.Bx2874, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
