#include "stdafx.h"
#include "fm_615.h"

inline int fm_615(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1963, bmats.Axx3365, bmats.Axx460, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4226, bmats.Bx5522, bmats.Bx5552, bmats.Bx5553, bmats.Bx5554, bmats.Bx5555, bmats.Bx5556, bmats.Bx5557, bmats.Bx5558, bmats.Bx5559, bmats.Bx5560, bmats.Bx5561, bmats.Bx5562, bmats.Bx5563, bmats.Bx5564, bmats.Bx5565, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
