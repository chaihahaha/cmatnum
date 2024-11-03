#include "fm_7597.h"
#include "stdafx.h"

inline int fm_7597(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_17_17, bmats.A_17_18, bmats.A_17_19, bmats.A_17_30, bmats.A_17_31, bmats.A_17_32, bmats.A_20_1, bmats.A_20_2, bmats.A_2_19, bmats.A_2_20, bmats.Ax4318, bmats.Ax4527, bmats.Ax6602, };
    double A_coeffs[13] = {1, -16, 1, 1, 1, 1, 16, -1, -1, 16, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_18_4, bmats.B_1_18, bmats.B_20_17, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_17_4.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_17.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_18.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
