#include "stdafx.h"
#include "fm_14839.h"

inline int fm_14839(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx112, bmats.Axx1595, bmats.Axx2474, bmats.Axx84, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_30_31, bmats.B_31_31, bmats.Bx10374, bmats.Bx11190, bmats.Bx11880, bmats.Bx12201, bmats.Bx12626, bmats.Bx12816, bmats.Bx13213, bmats.Bx13390, bmats.Bx2480, bmats.Bx9701, };
    double B_coeffs[12] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
