#include "fm_9259.h"
#include "stdafx.h"

inline int fm_9259(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.A_10_25, bmats.A_10_26, bmats.A_25_11, bmats.A_25_12, bmats.A_27_17, bmats.A_27_18, bmats.A_27_26, bmats.A_27_27, bmats.A_27_28, bmats.Ax2242, bmats.Ax2851, bmats.Ax6827, };
    double A_coeffs[12] = {16, -1, 16, -1, 1, 1, -16, 1, 1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_11_26, bmats.B_25_27, bmats.B_26_9, };
    double B_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, -1, &m.data[0][0], 1, &bmats.C_27_9.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_26.data[0][0], 1);    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_10_27.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
