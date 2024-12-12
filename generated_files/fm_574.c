#include "stdafx.h"
#include "fm_574.h"

inline int fm_574(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1705, bmats.Axx2093, bmats.Axx3365, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx4226, bmats.Bx4991, bmats.Bx5020, bmats.Bx5021, bmats.Bx5022, bmats.Bx5023, bmats.Bx5024, bmats.Bx5025, bmats.Bx5026, bmats.Bx5027, bmats.Bx5028, bmats.Bx5029, bmats.Bx5030, bmats.Bx5031, bmats.Bx5032, bmats.Bx5033, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
