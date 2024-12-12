#include "stdafx.h"
#include "fm_1785.h"

inline int fm_1785(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx142, bmats.Axx1515, bmats.Axx1521, bmats.Axx1896, bmats.Axx1935, bmats.Axx1955, bmats.Axx1980, bmats.Axx2132, bmats.Axx2156, bmats.Axx2473, bmats.Axx2540, bmats.Axx2938, bmats.Axx3350, bmats.Axx3396, bmats.Axx394, bmats.Axx531, bmats.Axx538, bmats.Axx998, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_3_3, bmats.Bx10427, bmats.Bx11233, bmats.Bx11691, bmats.Bx12639, bmats.Bx12640, bmats.Bx12641, bmats.Bx12642, bmats.Bx12643, bmats.Bx12644, bmats.Bx12645, bmats.Bx12646, bmats.Bx12647, bmats.Bx12648, bmats.Bx12649, bmats.Bx12650, bmats.Bx12651, };
    double B_coeffs[17] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_19.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
