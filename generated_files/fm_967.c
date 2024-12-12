#include "stdafx.h"
#include "fm_967.h"

inline int fm_967(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2700, bmats.Axx3128, bmats.Axx944, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_6_14, bmats.Bx8283, bmats.Bx8745, bmats.Bx8762, bmats.Bx8763, bmats.Bx8764, bmats.Bx8765, bmats.Bx8766, bmats.Bx8767, bmats.Bx8768, bmats.Bx8769, bmats.Bx8770, bmats.Bx8771, bmats.Bx8772, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
