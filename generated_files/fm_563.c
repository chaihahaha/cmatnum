#include "stdafx.h"
#include "fm_563.h"

inline int fm_563(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1037, bmats.Axx1482, bmats.Axx3130, bmats.Axx704, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_27_28, bmats.Bx1107, bmats.Bx13, bmats.Bx14, bmats.Bx15, bmats.Bx16, bmats.Bx17, bmats.Bx3110, bmats.Bx4227, bmats.Bx4652, bmats.Bx4879, bmats.Bx4880, bmats.Bx4881, bmats.Bx4882, bmats.Bx4883, bmats.Bx4884, bmats.Bx4885, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
