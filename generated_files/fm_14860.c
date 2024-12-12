#include "stdafx.h"
#include "fm_14860.h"

inline int fm_14860(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1017, bmats.Axx1022, bmats.Axx1499, bmats.Axx1544, bmats.Axx1545, bmats.Axx1752, bmats.Axx2027, bmats.Axx2083, bmats.Axx2171, bmats.Axx2636, bmats.Axx2896, bmats.Axx2927, bmats.Axx3124, bmats.Axx3273, bmats.Axx3370, bmats.Axx367, bmats.Axx689, bmats.Axx735, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx13204, bmats.Bx13227, bmats.Bx13437, };
    double B_coeffs[3] = {-1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_31.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
