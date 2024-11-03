#include "fm_15085.h"
#include "stdafx.h"

inline int fm_15085(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 19;
    double_cmat A_mats[19] = {bmats.A_20_17, bmats.A_20_18, bmats.A_20_19, bmats.A_20_20, bmats.A_20_21, bmats.A_20_22, bmats.A_20_23, bmats.A_20_24, bmats.A_20_25, bmats.A_20_26, bmats.A_20_27, bmats.A_20_28, bmats.A_20_29, bmats.A_20_30, bmats.A_20_31, bmats.A_20_32, bmats.A_27_19, bmats.A_27_20, bmats.Ax69, };
    double A_coeffs[19] = {-2, -2, -2, 15, -2, -2, -2, -2, -2, -2, 15, -2, -2, -2, -2, -2, -1, 16, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_20_20, bmats.B_20_27, bmats.B_27_20, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_20.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_20.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_27.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
