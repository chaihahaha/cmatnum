#include "stdafx.h"
#include "fm_14852.h"

inline int fm_14852(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1017, bmats.Axx1622, bmats.Axx1892, bmats.Axx2126, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_15_15, bmats.Bx12653, bmats.Bx12849, bmats.Bx13062, bmats.Bx13066, bmats.Bx13070, bmats.Bx13073, bmats.Bx13075, bmats.Bx13077, bmats.Bx13079, bmats.Bx13081, bmats.Bx13083, bmats.Bx13085, bmats.Bx13087, bmats.Bx13089, bmats.Bx13091, bmats.Bx13092, };
    double B_coeffs[17] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
