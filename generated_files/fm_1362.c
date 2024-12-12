#include "stdafx.h"
#include "fm_1362.h"

inline int fm_1362(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2286, bmats.Axx3128, bmats.Axx446, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_22_6, bmats.B_31_6, bmats.Bx10883, bmats.Bx11195, bmats.Bx11196, bmats.Bx11197, bmats.Bx11198, bmats.Bx11200, bmats.Bx6798, bmats.Bx7854, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
