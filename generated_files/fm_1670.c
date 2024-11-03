#include "fm_1670.h"
#include "stdafx.h"

inline int fm_1670(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_13_15, bmats.A_13_16, bmats.A_3_29, bmats.A_3_30, bmats.Ax4549, bmats.Ax568, };
    double A_coeffs[6] = {-1, -1, -16, 1, -1, -1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_10_19, bmats.B_11_19, bmats.B_14_19, bmats.B_29_11, bmats.B_29_12, bmats.B_29_13, bmats.B_29_14, bmats.B_29_15, bmats.B_29_16, bmats.B_3_13, bmats.Bx12422, bmats.Bx4638, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_19.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
