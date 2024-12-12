#include "stdafx.h"
#include "fm_1002.h"

inline int fm_1002(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2516, bmats.Axx3336, bmats.Axx3395, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.Bx8252, bmats.Bx9096, bmats.Bx9118, bmats.Bx9119, bmats.Bx9120, bmats.Bx9121, bmats.Bx9122, bmats.Bx9123, bmats.Bx9124, bmats.Bx9125, bmats.Bx9126, bmats.Bx9127, bmats.Bx9128, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_25.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
