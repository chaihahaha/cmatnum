#include "stdafx.h"
#include "fm_608.h"

inline int fm_608(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx138, bmats.Axx2409, bmats.Axx2891, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4354, bmats.Bx5432, bmats.Bx5461, bmats.Bx5462, bmats.Bx5463, bmats.Bx5464, bmats.Bx5465, bmats.Bx5466, bmats.Bx5467, bmats.Bx5468, bmats.Bx5469, bmats.Bx5470, bmats.Bx5471, bmats.Bx5472, bmats.Bx5473, bmats.Bx5474, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
