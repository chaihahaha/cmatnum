#include "stdafx.h"
#include "fm_607.h"

inline int fm_607(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1841, bmats.Axx3365, bmats.Axx3395, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4226, bmats.Bx5418, bmats.Bx5447, bmats.Bx5448, bmats.Bx5449, bmats.Bx5450, bmats.Bx5451, bmats.Bx5452, bmats.Bx5453, bmats.Bx5454, bmats.Bx5455, bmats.Bx5456, bmats.Bx5457, bmats.Bx5458, bmats.Bx5459, bmats.Bx5460, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
