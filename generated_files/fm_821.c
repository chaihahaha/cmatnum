#include "stdafx.h"
#include "fm_821.h"

inline int fm_821(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx130, bmats.Axx3042, bmats.Axx3337, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.Bx7241, bmats.Bx7507, bmats.Bx7531, bmats.Bx7532, bmats.Bx7533, bmats.Bx7534, bmats.Bx7535, bmats.Bx7536, bmats.Bx7537, bmats.Bx7538, bmats.Bx7539, bmats.Bx7540, bmats.Bx7541, bmats.Bx7542, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_8_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
