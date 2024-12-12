#include "stdafx.h"
#include "fm_1231.h"

inline int fm_1231(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2438, bmats.Axx3253, bmats.Axx822, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.Bx10020, bmats.Bx10244, bmats.Bx10480, bmats.Bx10481, bmats.Bx10482, bmats.Bx10483, bmats.Bx10484, bmats.Bx10485, bmats.Bx10486, bmats.Bx10487, bmats.Bx10489, };
    double B_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_23.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
