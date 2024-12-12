#include "stdafx.h"
#include "fm_580.h"

inline int fm_580(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx3070, bmats.Axx417, bmats.Axx861, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_20_12, bmats.B_23_12, bmats.Bx2072, bmats.Bx4694, bmats.Bx5096, bmats.Bx5097, bmats.Bx5098, bmats.Bx5099, bmats.Bx5100, bmats.Bx5101, bmats.Bx5102, bmats.Bx5103, bmats.Bx5104, bmats.Bx5105, bmats.Bx5106, bmats.Bx5107, bmats.Bx5108, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
