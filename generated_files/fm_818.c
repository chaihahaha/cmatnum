#include "stdafx.h"
#include "fm_818.h"

inline int fm_818(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1373, bmats.Axx1386, bmats.Axx2220, bmats.Axx755, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_24_26, bmats.B_30_26, bmats.Bx139, bmats.Bx140, bmats.Bx141, bmats.Bx142, bmats.Bx143, bmats.Bx144, bmats.Bx7211, bmats.Bx7501, bmats.Bx7502, bmats.Bx7503, bmats.Bx7504, bmats.Bx7506, };
    double B_coeffs[14] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
