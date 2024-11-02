#include "fBx12142.h"

inline int fBx12142(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_10_20, bmats.B_13_20, bmats.B_14_20, bmats.B_15_20, bmats.B_16_20, bmats.B_1_20, bmats.B_2_20, bmats.B_3_20, bmats.B_4_20, bmats.B_5_20, bmats.B_6_20, bmats.B_7_20, bmats.B_8_20, bmats.B_9_20, };
    double B_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12142, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
