#include "stdafx.h"
#include "fm_14417.h"

inline int fm_14417(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 17;
    double_cmat A_mats[17] = {bmats.A_28_29, bmats.Axx1038, bmats.Axx1140, bmats.Axx1205, bmats.Axx1258, bmats.Axx1308, bmats.Axx1352, bmats.Axx1380, bmats.Axx1426, bmats.Axx1446, bmats.Axx1463, bmats.Axx1469, bmats.Axx1652, bmats.Axx291, bmats.Axx362, bmats.Axx563, bmats.Axx939, };
    double A_coeffs[17] = {15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_28_28, bmats.Bx3015, };
    double B_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_28.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_28.data[0][0], 1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
