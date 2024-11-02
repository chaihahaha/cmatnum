#include "fBx13274.h"

inline int fBx13274(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_11_7, bmats.B_13_7, bmats.B_14_7, bmats.B_15_7, bmats.B_16_7, bmats.B_17_7, bmats.B_18_7, bmats.B_19_7, bmats.B_1_7, bmats.B_20_7, bmats.B_21_7, bmats.B_22_7, bmats.B_23_7, bmats.B_24_7, bmats.B_25_7, bmats.B_26_7, bmats.B_27_7, bmats.B_28_7, bmats.B_29_7, bmats.B_30_7, bmats.B_31_7, bmats.B_32_7, bmats.B_3_7, bmats.B_4_7, bmats.B_5_7, bmats.B_6_7, bmats.Bx10249, };
    double B_coeffs[27] = {1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13274, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
