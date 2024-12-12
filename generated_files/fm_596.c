#include "stdafx.h"
#include "fm_596.h"

inline int fm_596(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1272, bmats.Axx1307, bmats.Axx3047, bmats.Axx3058, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_19_28, bmats.B_24_28, bmats.Bx3982, bmats.Bx41, bmats.Bx4990, bmats.Bx5304, bmats.Bx5305, bmats.Bx5306, bmats.Bx5307, bmats.Bx5308, bmats.Bx5309, bmats.Bx5310, bmats.Bx5311, bmats.Bx5312, bmats.Bx5313, bmats.Bx5314, };
    double B_coeffs[16] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
