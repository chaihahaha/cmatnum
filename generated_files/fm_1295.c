#include "stdafx.h"
#include "fm_1295.h"

inline int fm_1295(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1699, bmats.Axx37, bmats.Axx486, bmats.Axx924, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_32_22, bmats.Bx10664, bmats.Bx10897, bmats.Bx10976, bmats.Bx10977, bmats.Bx10978, bmats.Bx10979, bmats.Bx10980, bmats.Bx10981, bmats.Bx10982, };
    double B_coeffs[10] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
