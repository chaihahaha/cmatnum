#include "stdafx.h"
#include "fm_447.h"

inline int fm_447(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx252, bmats.Axx292, bmats.Axx3118, bmats.Axx3295, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_27_29, bmats.Bx1107, bmats.Bx2493, bmats.Bx2859, bmats.Bx3442, bmats.Bx3443, bmats.Bx3444, bmats.Bx3445, bmats.Bx3446, bmats.Bx3447, bmats.Bx3448, bmats.Bx3449, bmats.Bx3450, bmats.Bx3451, bmats.Bx3452, bmats.Bx3453, bmats.Bx3454, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
