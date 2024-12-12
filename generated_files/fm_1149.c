#include "stdafx.h"
#include "fm_1149.h"

inline int fm_1149(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1802, bmats.Axx2567, bmats.Axx491, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_2_24, bmats.Bx10171, bmats.Bx10172, bmats.Bx10173, bmats.Bx10174, bmats.Bx10175, bmats.Bx10176, bmats.Bx10177, bmats.Bx10178, bmats.Bx10179, bmats.Bx10180, bmats.Bx7041, bmats.Bx9788, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_24.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
