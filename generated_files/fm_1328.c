#include "fm_1328.h"

inline int fm_1328(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_22_24, bmats.A_24_22, bmats.A_25_21, bmats.A_25_22, bmats.Ax128, bmats.Ax4014, };
    double A_coeffs[6] = {17, -17, 1, -16, 1, 1, };
    int n_B_mats = 21;
    double_cmat B_mats[21] = {bmats.B_22_24, bmats.B_24_17, bmats.B_24_18, bmats.B_24_19, bmats.B_24_20, bmats.B_24_21, bmats.B_24_22, bmats.B_24_23, bmats.B_24_24, bmats.B_24_25, bmats.B_24_26, bmats.B_24_27, bmats.B_24_28, bmats.B_24_29, bmats.B_24_30, bmats.B_24_31, bmats.B_24_32, bmats.B_25_22, bmats.B_28_22, bmats.B_29_22, bmats.Bx11061, };
    double B_coeffs[21] = {1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_22.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
