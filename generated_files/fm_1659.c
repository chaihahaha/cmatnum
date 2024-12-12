#include "stdafx.h"
#include "fm_1659.h"

inline int fm_1659(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1986, bmats.Axx2336, bmats.Axx2567, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_18_27, bmats.B_2_20, bmats.Bx10773, bmats.Bx12050, bmats.Bx12343, bmats.Bx12365, bmats.Bx12366, bmats.Bx12367, bmats.Bx12368, bmats.Bx12369, bmats.Bx440, };
    double B_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_20.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
