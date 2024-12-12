#include "stdafx.h"
#include "fm_14870.h"

inline int fm_14870(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx32, bmats.Axx400, bmats.Axx616, bmats.Axx907, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_2_16, bmats.B_2_5, bmats.Bx10366, bmats.Bx12820, bmats.Bx13033, bmats.Bx13444, bmats.Bx13445, bmats.Bx13446, bmats.Bx13447, bmats.Bx2225, };
    double B_coeffs[10] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_16.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
