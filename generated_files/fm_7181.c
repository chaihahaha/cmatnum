#include "fm_7181.h"
#include "stdafx.h"

inline int fm_7181(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_18_18, bmats.A_18_19, bmats.A_18_20, bmats.A_18_21, bmats.A_18_24, bmats.A_18_25, bmats.A_18_26, bmats.A_18_32, bmats.A_25_1, bmats.A_25_2, bmats.A_4_25, bmats.A_4_26, bmats.Ax2866, bmats.Ax3507, bmats.Ax6381, };
    double A_coeffs[15] = {1, 1, -16, 1, 1, 1, 1, 1, -1, 16, 16, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_20_9, bmats.B_25_18, bmats.B_2_20, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_18_9.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_18.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_20.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
