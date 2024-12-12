#include "stdafx.h"
#include "fm_762.h"

inline int fm_762(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1557, bmats.Axx2506, bmats.Axx759, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_3_27, bmats.Bx6393, bmats.Bx7127, bmats.Bx7128, bmats.Bx7129, bmats.Bx7130, bmats.Bx7131, bmats.Bx7132, bmats.Bx7133, bmats.Bx7134, bmats.Bx7135, bmats.Bx7136, bmats.Bx7137, bmats.Bx7138, bmats.Bx7140, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
