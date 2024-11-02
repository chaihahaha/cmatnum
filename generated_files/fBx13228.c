#include "fBx13228.h"

inline int fBx13228(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_14_31, bmats.B_17_31, bmats.B_18_31, bmats.B_19_31, bmats.B_20_31, bmats.B_21_31, bmats.B_22_31, bmats.B_23_31, bmats.B_24_31, bmats.B_25_31, bmats.B_26_31, bmats.B_27_31, bmats.B_28_31, bmats.B_29_31, bmats.B_30_31, bmats.B_31_31, bmats.B_32_31, bmats.Bx13226, };
    double B_coeffs[18] = {-1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, };
    matlincomb_double_contiguous(bmats.Bx13228, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
