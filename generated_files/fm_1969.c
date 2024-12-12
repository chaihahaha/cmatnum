#include "stdafx.h"
#include "fm_1969.h"

inline int fm_1969(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1280, bmats.Axx1392, bmats.Axx1394, bmats.Axx2301, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_26_17, bmats.B_26_18, bmats.Bx12901, bmats.Bx12961, bmats.Bx12980, bmats.Bx12981, bmats.Bx3370, bmats.Bx4526, bmats.Bx8668, bmats.Bx8669, bmats.Bx9539, };
    double B_coeffs[11] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_17.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
