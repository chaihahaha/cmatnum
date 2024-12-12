#include "stdafx.h"
#include "fm_518.h"

inline int fm_518(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1015, bmats.Axx1489, bmats.Axx1524, bmats.Axx1594, bmats.Axx1694, bmats.Axx1728, bmats.Axx2073, bmats.Axx2087, bmats.Axx2123, bmats.Axx2302, bmats.Axx2638, bmats.Axx2854, bmats.Axx3376, bmats.Axx3400, bmats.Axx378, bmats.Axx475, bmats.Axx620, bmats.Axx726, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_13_29, bmats.B_17_13, bmats.Bx4383, bmats.Bx4467, bmats.Bx4468, bmats.Bx4469, bmats.Bx4470, bmats.Bx4471, bmats.Bx4472, bmats.Bx4473, bmats.Bx4474, bmats.Bx4475, bmats.Bx4476, bmats.Bx4477, bmats.Bx4478, bmats.Bx4479, bmats.Bx4480, bmats.Bx808, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
