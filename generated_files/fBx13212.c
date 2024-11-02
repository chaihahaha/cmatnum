#include "fBx13212.h"

inline int fBx13212(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 32;
    double_cmat B_mats[32] = {bmats.B_10_14, bmats.B_11_14, bmats.B_12_14, bmats.B_13_14, bmats.B_14_14, bmats.B_15_14, bmats.B_16_14, bmats.B_17_14, bmats.B_18_14, bmats.B_19_14, bmats.B_1_14, bmats.B_20_14, bmats.B_21_14, bmats.B_22_14, bmats.B_23_14, bmats.B_24_14, bmats.B_25_14, bmats.B_26_14, bmats.B_27_14, bmats.B_28_14, bmats.B_29_14, bmats.B_2_14, bmats.B_30_14, bmats.B_31_14, bmats.B_32_14, bmats.B_3_14, bmats.B_4_14, bmats.B_5_14, bmats.B_6_14, bmats.B_7_14, bmats.B_8_14, bmats.B_9_14, };
    double B_coeffs[32] = {1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13212, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
