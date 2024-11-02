#include "fBx13310.h"

inline int fBx13310(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_13, bmats.B_11_13, bmats.B_12_13, bmats.B_13_13, bmats.B_14_13, bmats.B_15_13, bmats.B_16_13, bmats.B_17_13, bmats.B_18_13, bmats.B_19_13, bmats.B_1_13, bmats.B_20_13, bmats.B_21_13, bmats.B_22_13, bmats.B_23_13, bmats.B_24_13, bmats.B_25_13, bmats.B_26_13, bmats.B_27_13, bmats.B_28_13, bmats.B_29_13, bmats.B_2_13, bmats.B_30_13, bmats.B_31_13, bmats.B_32_13, bmats.B_3_13, bmats.B_4_13, bmats.B_5_13, bmats.B_6_13, bmats.B_7_13, bmats.B_8_13, bmats.B_9_13, };
    double B_coeffs[32] = {1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13310, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
