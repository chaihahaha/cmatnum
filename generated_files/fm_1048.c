#include "fm_1048.h"

inline int fm_1048(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.A_24_30, bmats.A_30_24, bmats.A_31_23, bmats.A_31_24, bmats.Ax3381, bmats.Ax3521, };
    double A_coeffs[6] = {17, -17, 1, -16, 1, 1, };
    int n_B_mats = 20;
    double_cmat B_mats[20] = {bmats.B_17_24, bmats.B_18_24, bmats.B_19_24, bmats.B_20_24, bmats.B_21_24, bmats.B_22_24, bmats.B_23_24, bmats.B_24_24, bmats.B_24_30, bmats.B_25_24, bmats.B_26_24, bmats.B_27_24, bmats.B_28_24, bmats.B_29_24, bmats.B_30_22, bmats.B_30_23, bmats.B_30_24, bmats.B_31_24, bmats.B_32_24, bmats.Bx9493, };
    double B_coeffs[20] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_30_24.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
