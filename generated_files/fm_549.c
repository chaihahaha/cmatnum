#include "stdafx.h"
#include "fm_549.h"

inline int fm_549(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2436, bmats.Axx2716, bmats.Axx3366, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4212, bmats.Bx4636, bmats.Bx4695, bmats.Bx4696, bmats.Bx4697, bmats.Bx4698, bmats.Bx4699, bmats.Bx4700, bmats.Bx4701, bmats.Bx4702, bmats.Bx4703, bmats.Bx4704, bmats.Bx4705, bmats.Bx4706, bmats.Bx4707, bmats.Bx4708, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
