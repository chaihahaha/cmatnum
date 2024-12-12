#include "stdafx.h"
#include "fm_241.h"

inline int fm_241(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1542, bmats.Axx197, bmats.Axx226, bmats.Axx820, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_2_15, bmats.Bx411, bmats.Bx412, bmats.Bx413, bmats.Bx414, bmats.Bx415, bmats.Bx416, bmats.Bx417, bmats.Bx418, bmats.Bx419, bmats.Bx420, bmats.Bx421, bmats.Bx422, bmats.Bx423, bmats.Bx424, bmats.Bx425, };
    double B_coeffs[16] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_15.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
