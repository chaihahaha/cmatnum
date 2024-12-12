#include "stdafx.h"
#include "fm_711.h"

inline int fm_711(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1040, bmats.Axx1061, bmats.Axx1848, bmats.Axx2339, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_25_27, bmats.Bx4708, bmats.Bx5650, bmats.Bx6082, bmats.Bx6513, bmats.Bx6514, bmats.Bx6515, bmats.Bx82, bmats.Bx83, bmats.Bx84, bmats.Bx85, bmats.Bx86, bmats.Bx87, bmats.Bx88, bmats.Bx89, };
    double B_coeffs[15] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
