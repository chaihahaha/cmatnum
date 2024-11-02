#include "fBx7184.h"

inline int fBx7184(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_10_26, bmats.B_11_26, bmats.B_12_26, bmats.B_13_26, bmats.B_14_26, bmats.B_15_26, bmats.B_16_26, bmats.B_1_26, bmats.B_2_26, bmats.B_3_26, bmats.B_4_26, bmats.B_5_26, bmats.B_6_26, bmats.B_7_26, bmats.B_8_26, bmats.B_9_26, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7184, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
