#include "fm_14572.h"
#include "stdafx.h"

inline int fm_14572(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 19;
    double_cmat A_mats[19] = {bmats.A_26_17, bmats.A_26_18, bmats.A_26_19, bmats.A_26_20, bmats.A_26_21, bmats.A_26_22, bmats.A_26_23, bmats.A_26_24, bmats.A_26_25, bmats.A_26_26, bmats.A_26_27, bmats.A_26_28, bmats.A_26_29, bmats.A_26_30, bmats.A_26_31, bmats.A_26_32, bmats.A_27_25, bmats.A_27_26, bmats.Ax211, };
    double A_coeffs[19] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, 15, 15, -2, -2, -2, -2, -2, -1, 16, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_26_26, bmats.B_26_27, bmats.B_27_26, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_26.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_26.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_27.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
