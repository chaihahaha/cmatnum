#include "fBx2488.h"

inline int fBx2488(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_10_29, bmats.B_11_29, bmats.B_12_29, bmats.B_13_29, bmats.B_14_29, bmats.B_15_29, bmats.B_16_29, bmats.B_1_29, bmats.B_2_29, bmats.B_3_29, bmats.B_4_29, bmats.B_5_29, bmats.B_6_29, bmats.B_7_29, bmats.B_8_29, bmats.B_9_29, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx2488, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
