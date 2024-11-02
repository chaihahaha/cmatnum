#include "fAx4141.h"

inline int fAx4141(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_17_5, bmats.A_17_6, bmats.A_18_5, bmats.A_18_6, bmats.A_19_5, bmats.A_19_6, bmats.A_20_5, bmats.A_20_6, bmats.A_21_5, bmats.A_21_6, bmats.A_22_5, bmats.A_22_6, bmats.A_23_5, bmats.A_23_6, bmats.A_24_5, bmats.A_24_6, bmats.A_25_5, bmats.A_25_6, bmats.A_26_5, bmats.A_26_6, bmats.A_27_5, bmats.A_27_6, bmats.A_28_5, bmats.A_28_6, bmats.A_29_5, bmats.A_29_6, bmats.A_30_5, bmats.A_30_6, bmats.A_31_5, bmats.A_31_6, bmats.A_32_5, bmats.A_32_6, bmats.Ax1625, bmats.Ax2077, bmats.Ax2439, bmats.Ax2780, bmats.Ax3068, bmats.Ax3309, bmats.Ax3535, bmats.Ax3822, bmats.Ax3964, bmats.Ax3967, bmats.Ax3970, bmats.Ax3973, bmats.Ax3976, bmats.Ax3979, bmats.Ax3982, bmats.Ax3985, };
    double A_coeffs[48] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4141, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
