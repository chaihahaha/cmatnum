#include "stdafx.h"
#include "fm_1089.h"

inline int fm_1089(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1436, bmats.Axx1440, bmats.Axx1744, bmats.Axx749, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_23_23, bmats.B_23_24, bmats.B_23_27, bmats.Bx108, bmats.Bx211, bmats.Bx212, bmats.Bx213, bmats.Bx214, bmats.Bx215, bmats.Bx216, bmats.Bx8862, bmats.Bx9205, bmats.Bx9210, bmats.Bx9625, bmats.Bx9626, bmats.Bx9627, };
    double B_coeffs[16] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_23_24.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
