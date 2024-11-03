#include "fm_1674.h"
#include "stdafx.h"

inline int fm_1674(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_14_31, bmats.A_14_32, bmats.A_19_13, bmats.A_19_14, bmats.A_3_3, bmats.A_3_4, bmats.A_4_3, bmats.A_4_4, bmats.Ax4339, bmats.Ax4363, bmats.Ax4482, bmats.Ax515, bmats.Ax745, };
    double A_coeffs[13] = {-1, -1, -1, 16, 16, -1, 16, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_14_12, bmats.B_17_3, bmats.B_18_3, bmats.B_19_3, bmats.B_32_3, bmats.B_3_30, bmats.Bx12263, bmats.Bx3105, bmats.Bx3115, };
    double B_coeffs[9] = {-1, -1, -1, -1, -1, 1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_3.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
