#include "stdafx.h"
#include "fm_1275.h"

inline int fm_1275(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1007, bmats.Axx1008, bmats.Axx1523, bmats.Axx1733, bmats.Axx1735, bmats.Axx1935, bmats.Axx2114, bmats.Axx3049, bmats.Axx3126, bmats.Axx3289, bmats.Axx3291, bmats.Axx3360, bmats.Axx3380, bmats.Axx380, bmats.Axx4, bmats.Axx76, bmats.Axx790, bmats.Axx942, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.Bx10561, bmats.Bx10809, bmats.Bx10853, bmats.Bx10863, bmats.Bx10864, bmats.Bx10865, bmats.Bx10866, bmats.Bx10867, bmats.Bx10868, bmats.Bx10869, bmats.Bx10870, };
    double B_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
