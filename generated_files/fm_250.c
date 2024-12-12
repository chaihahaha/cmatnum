#include "stdafx.h"
#include "fm_250.h"

inline int fm_250(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx114, bmats.Axx1368, bmats.Axx2274, bmats.Axx71, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_19_31, bmats.Bx553, bmats.Bx554, bmats.Bx555, bmats.Bx556, bmats.Bx557, bmats.Bx558, bmats.Bx559, bmats.Bx560, bmats.Bx561, bmats.Bx562, bmats.Bx563, bmats.Bx564, bmats.Bx565, bmats.Bx566, bmats.Bx567, bmats.Bx568, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
