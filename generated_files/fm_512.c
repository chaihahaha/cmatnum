#include "stdafx.h"
#include "fm_512.h"

inline int fm_512(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx120, bmats.Axx1554, bmats.Axx169, bmats.Axx1842, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_1_10, bmats.B_1_12, bmats.B_1_13, bmats.Bx2502, bmats.Bx4383, bmats.Bx4384, bmats.Bx4385, bmats.Bx4386, bmats.Bx4387, bmats.Bx4388, bmats.Bx4389, bmats.Bx4390, bmats.Bx4391, bmats.Bx4392, bmats.Bx4393, bmats.Bx4394, bmats.Bx4395, bmats.Bx695, };
    double B_coeffs[18] = {-1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
