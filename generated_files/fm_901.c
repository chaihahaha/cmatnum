#include "stdafx.h"
#include "fm_901.h"

inline int fm_901(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1893, bmats.Axx2708, bmats.Axx944, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_16_10, bmats.Bx7338, bmats.Bx8287, bmats.Bx8390, bmats.Bx8391, bmats.Bx8392, bmats.Bx8393, bmats.Bx8394, bmats.Bx8395, bmats.Bx8396, bmats.Bx8397, bmats.Bx8398, bmats.Bx8399, bmats.Bx8400, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
