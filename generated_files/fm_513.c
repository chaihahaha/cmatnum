#include "stdafx.h"
#include "fm_513.h"

inline int fm_513(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2267, bmats.Axx247, bmats.Axx267, bmats.Axx676, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_17_17, bmats.B_17_29, bmats.B_17_30, bmats.Bx2493, bmats.Bx4396, bmats.Bx4397, bmats.Bx4398, bmats.Bx4399, bmats.Bx4400, bmats.Bx4401, bmats.Bx4402, bmats.Bx4403, bmats.Bx4404, bmats.Bx4405, bmats.Bx4406, bmats.Bx4407, bmats.Bx4408, bmats.Bx4409, };
    double B_coeffs[18] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
