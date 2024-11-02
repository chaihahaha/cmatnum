#include "fBx13268.h"

inline int fBx13268(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 25;
    double_cmat B_mats[25] = {bmats.B_14_6, bmats.B_15_6, bmats.B_16_6, bmats.B_17_6, bmats.B_18_6, bmats.B_19_6, bmats.B_1_6, bmats.B_20_6, bmats.B_21_6, bmats.B_22_6, bmats.B_23_6, bmats.B_24_6, bmats.B_25_6, bmats.B_26_6, bmats.B_27_6, bmats.B_28_6, bmats.B_29_6, bmats.B_2_6, bmats.B_30_6, bmats.B_31_6, bmats.B_32_6, bmats.B_3_6, bmats.B_4_6, bmats.B_5_6, bmats.Bx10888, };
    double B_coeffs[25] = {1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13268, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
