#include "fBx13218.h"

inline int fBx13218(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_10_15, bmats.B_12_15, bmats.B_13_15, bmats.B_14_15, bmats.B_15_15, bmats.B_16_15, bmats.B_1_15, bmats.B_2_15, bmats.B_3_15, bmats.B_4_15, bmats.B_5_15, bmats.B_6_15, bmats.B_7_15, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13218, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
