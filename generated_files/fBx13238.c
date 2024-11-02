#include "fBx13238.h"

inline int fBx13238(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_10_32, bmats.B_11_32, bmats.B_12_32, bmats.B_13_32, bmats.B_14_32, bmats.B_1_32, bmats.B_2_32, bmats.B_3_32, bmats.B_4_32, bmats.B_5_32, bmats.B_6_32, bmats.B_7_32, bmats.B_8_32, bmats.B_9_32, };
    double B_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13238, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
