#include "stdafx.h"
#include "fm_1023.h"

inline int fm_1023(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1396, bmats.Axx1420, bmats.Axx526, bmats.Axx572, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_17_25, bmats.B_27_25, bmats.B_28_25, bmats.Bx109, bmats.Bx6945, bmats.Bx8518, bmats.Bx9349, bmats.Bx9350, bmats.Bx9351, bmats.Bx9352, bmats.Bx9353, bmats.Bx9354, bmats.Bx9355, bmats.Bx9356, bmats.Bx9357, bmats.Bx9358, };
    double B_coeffs[16] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_25.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
