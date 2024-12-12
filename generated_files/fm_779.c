#include "stdafx.h"
#include "fm_779.h"

inline int fm_779(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1966, bmats.Axx319, bmats.Axx3248, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_31_18, bmats.Bx7180, bmats.Bx7181, bmats.Bx7254, bmats.Bx7255, bmats.Bx7256, bmats.Bx7257, bmats.Bx7258, bmats.Bx7259, bmats.Bx7260, bmats.Bx7261, bmats.Bx7262, bmats.Bx7263, bmats.Bx7264, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_31_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
