#include "stdafx.h"
#include "fm_611.h"

inline int fm_611(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1882, bmats.Axx447, bmats.Axx496, bmats.Axx831, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_16_12, bmats.B_5_12, bmats.Bx3481, bmats.Bx4777, bmats.Bx5501, bmats.Bx5502, bmats.Bx5503, bmats.Bx5504, bmats.Bx5505, bmats.Bx5506, bmats.Bx5507, bmats.Bx5508, bmats.Bx5509, bmats.Bx5510, bmats.Bx5511, bmats.Bx5512, };
    double B_coeffs[16] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
