#include "fAx3713.h"

inline int fAx3713(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 48;
    double_cmat A_mats[48] = {bmats.A_10_23, bmats.A_10_24, bmats.A_11_23, bmats.A_11_24, bmats.A_12_23, bmats.A_12_24, bmats.A_13_23, bmats.A_13_24, bmats.A_14_23, bmats.A_14_24, bmats.A_15_23, bmats.A_15_24, bmats.A_16_23, bmats.A_16_24, bmats.A_1_23, bmats.A_1_24, bmats.A_2_23, bmats.A_2_24, bmats.A_3_23, bmats.A_3_24, bmats.A_4_23, bmats.A_4_24, bmats.A_5_23, bmats.A_5_24, bmats.A_6_23, bmats.A_6_24, bmats.A_7_23, bmats.A_7_24, bmats.A_8_23, bmats.A_8_24, bmats.A_9_23, bmats.A_9_24, bmats.Ax1427, bmats.Ax2028, bmats.Ax2457, bmats.Ax2729, bmats.Ax3005, bmats.Ax3325, bmats.Ax3421, bmats.Ax3424, bmats.Ax3427, bmats.Ax3430, bmats.Ax3433, bmats.Ax3436, bmats.Ax3439, bmats.Ax3442, bmats.Ax3445, bmats.Ax3448, };
    double A_coeffs[48] = {-16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, -16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Ax3713, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
