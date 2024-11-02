#include "fm_887.h"

inline int fm_887(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 5;
    double_cmat A_mats[5] = {bmats.A_25_29, bmats.A_25_30, bmats.Ax1100, bmats.Ax1868, bmats.Ax3157, };
    double A_coeffs[5] = {1, -16, 1, 1, 1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_17_25, bmats.B_18_25, bmats.B_19_25, bmats.B_25_25, bmats.B_26_25, bmats.B_27_25, bmats.B_28_25, bmats.B_29_25, bmats.B_30_1, bmats.B_30_25, bmats.B_9_30, bmats.Bx2491, bmats.Bx8256, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_14_25.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
