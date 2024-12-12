#include "stdafx.h"
#include "fm_15128.h"

inline int fm_15128(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1915, bmats.Axx36, bmats.Axx86, bmats.Axx934, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_27_31, bmats.B_27_32, bmats.B_29_32, bmats.Bx12742, bmats.Bx13300, bmats.Bx13383, bmats.Bx13424, };
    double B_coeffs[7] = {-1, -2, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_32.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
