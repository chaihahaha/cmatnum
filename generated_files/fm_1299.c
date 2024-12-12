#include "stdafx.h"
#include "fm_1299.h"

inline int fm_1299(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2089, bmats.Axx3335, bmats.Axx442, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.Bx10973, bmats.Bx10991, bmats.Bx11008, bmats.Bx11009, bmats.Bx11010, bmats.Bx11011, bmats.Bx11012, bmats.Bx11013, bmats.Bx11014, bmats.Bx11015, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
