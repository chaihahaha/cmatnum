#include "stdafx.h"
#include "fm_554.h"

inline int fm_554(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2266, bmats.Axx629, bmats.Axx655, bmats.Axx741, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_10_12, bmats.B_10_14, bmats.Bx4764, bmats.Bx4765, bmats.Bx4766, bmats.Bx4767, bmats.Bx4768, bmats.Bx4769, bmats.Bx4770, bmats.Bx4771, bmats.Bx4772, bmats.Bx4773, bmats.Bx4774, bmats.Bx4775, bmats.Bx4776, bmats.Bx4777, };
    double B_coeffs[16] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_12.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
