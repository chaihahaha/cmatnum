#include "stdafx.h"
#include "fm_1311.h"

inline int fm_1311(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1100, bmats.Axx1139, bmats.Axx1508, bmats.Axx287, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_28_21, bmats.B_28_22, bmats.Bx11039, bmats.Bx11048, bmats.Bx11049, bmats.Bx11051, bmats.Bx11052, };
    double B_coeffs[7] = {-1, -2, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_22.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
