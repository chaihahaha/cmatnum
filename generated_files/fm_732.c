#include "stdafx.h"
#include "fm_732.h"

inline int fm_732(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1630, bmats.Axx2066, bmats.Axx378, bmats.Axx538, };
    double A_coeffs[4] = {-1, -1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx6393, bmats.Bx6692, bmats.Bx6749, bmats.Bx6763, bmats.Bx6764, bmats.Bx6765, bmats.Bx6766, bmats.Bx6767, bmats.Bx6768, bmats.Bx6769, bmats.Bx6770, bmats.Bx6771, bmats.Bx6772, bmats.Bx6773, bmats.Bx6774, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_5_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
