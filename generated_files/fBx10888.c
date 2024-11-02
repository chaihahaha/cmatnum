#include "fBx10888.h"

inline int fBx10888(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_10_6, bmats.B_11_6, bmats.B_12_6, bmats.B_13_6, bmats.B_6_6, bmats.B_7_6, bmats.B_8_6, bmats.B_9_6, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx10888, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
