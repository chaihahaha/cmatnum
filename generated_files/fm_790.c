#include "stdafx.h"
#include "fm_790.h"

inline int fm_790(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1631, bmats.Axx188, bmats.Axx1940, bmats.Axx2137, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_10_10, bmats.Bx7375, bmats.Bx7376, bmats.Bx7377, bmats.Bx7378, bmats.Bx7379, bmats.Bx7380, bmats.Bx7381, bmats.Bx7382, bmats.Bx7383, bmats.Bx7384, bmats.Bx7385, bmats.Bx7386, bmats.Bx7387, bmats.Bx7388, bmats.Bx7389, bmats.Bx7390, };
    double B_coeffs[17] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
