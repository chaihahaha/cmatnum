#include "stdafx.h"
#include "fm_735.h"

inline int fm_735(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1048, bmats.Axx1069, bmats.Axx1444, bmats.Axx367, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_22_27, bmats.Bx100, bmats.Bx101, bmats.Bx102, bmats.Bx103, bmats.Bx104, bmats.Bx5019, bmats.Bx5650, bmats.Bx6297, bmats.Bx6800, bmats.Bx6801, bmats.Bx6802, bmats.Bx6803, bmats.Bx6804, bmats.Bx6805, };
    double B_coeffs[15] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_22_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
