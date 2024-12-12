#include "stdafx.h"
#include "fm_752.h"

inline int fm_752(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1076, bmats.Axx1082, bmats.Axx2846, bmats.Axx433, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_18_27, bmats.B_30_27, bmats.Bx12, bmats.Bx3864, bmats.Bx5990, bmats.Bx7007, bmats.Bx7008, bmats.Bx7009, bmats.Bx7010, bmats.Bx7011, bmats.Bx7012, bmats.Bx7013, bmats.Bx7014, bmats.Bx7015, bmats.Bx7016, bmats.Bx7017, bmats.Bx90, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
