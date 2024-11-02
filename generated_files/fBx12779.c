#include "fBx12779.h"

inline int fBx12779(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_13_18, bmats.B_14_18, bmats.B_15_18, bmats.B_16_18, bmats.B_1_18, bmats.B_2_18, bmats.B_3_18, bmats.B_4_18, bmats.B_5_18, bmats.B_6_18, bmats.B_7_18, bmats.B_8_18, bmats.B_9_18, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12779, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
