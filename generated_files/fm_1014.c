#include "stdafx.h"
#include "fm_1014.h"

inline int fm_1014(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2088, bmats.Axx22, bmats.Axx2338, bmats.Axx746, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_16_8, bmats.Bx7314, bmats.Bx9248, bmats.Bx9249, bmats.Bx9250, bmats.Bx9251, bmats.Bx9252, bmats.Bx9253, bmats.Bx9254, bmats.Bx9255, bmats.Bx9256, bmats.Bx9259, };
    double B_coeffs[12] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_8.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
