#include "stdafx.h"
#include "fm_899.h"

inline int fm_899(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1604, bmats.Axx18, bmats.Axx1808, bmats.Axx703, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_16_10, bmats.B_16_9, bmats.Bx7313, bmats.Bx8261, bmats.Bx8267, bmats.Bx8370, bmats.Bx8371, bmats.Bx8372, bmats.Bx8373, bmats.Bx8374, bmats.Bx8375, bmats.Bx8376, bmats.Bx8377, bmats.Bx8378, };
    double B_coeffs[14] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
