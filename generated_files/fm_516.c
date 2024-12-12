#include "stdafx.h"
#include "fm_516.h"

inline int fm_516(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx286, bmats.Axx3376, bmats.Axx3389, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx2493, bmats.Bx4410, bmats.Bx4437, bmats.Bx4438, bmats.Bx4439, bmats.Bx4440, bmats.Bx4441, bmats.Bx4442, bmats.Bx4443, bmats.Bx4444, bmats.Bx4445, bmats.Bx4446, bmats.Bx4447, bmats.Bx4448, bmats.Bx4449, bmats.Bx4450, bmats.Bx4451, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
