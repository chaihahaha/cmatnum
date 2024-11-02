#include "fAx4711.h"

inline int fAx4711(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 40;
    double_cmat A_mats[40] = {bmats.A_10_1, bmats.A_10_2, bmats.A_11_1, bmats.A_11_2, bmats.A_12_1, bmats.A_12_2, bmats.A_13_1, bmats.A_13_2, bmats.A_14_1, bmats.A_14_2, bmats.A_15_1, bmats.A_15_2, bmats.A_16_1, bmats.A_16_2, bmats.A_1_1, bmats.A_1_2, bmats.A_2_2, bmats.A_3_1, bmats.A_3_2, bmats.A_4_1, bmats.A_4_2, bmats.A_5_1, bmats.A_5_2, bmats.A_6_1, bmats.A_6_2, bmats.A_7_1, bmats.A_7_2, bmats.Ax1754, bmats.Ax2134, bmats.Ax2641, bmats.Ax2888, bmats.Ax3097, bmats.Ax3881, bmats.Ax4087, bmats.Ax4227, bmats.Ax4533, bmats.Ax4592, bmats.Ax4644, bmats.Ax4647, bmats.Ax742, };
    double A_coeffs[40] = {1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, -17, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax4711, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
