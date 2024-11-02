#include "fBx13289.h"

inline int fBx13289(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_17_25, bmats.B_18_25, bmats.B_19_25, bmats.B_20_25, bmats.B_21_25, bmats.B_22_25, bmats.B_23_25, bmats.B_24_25, bmats.B_25_25, bmats.B_26_25, bmats.B_27_25, bmats.B_28_25, bmats.B_29_25, bmats.B_30_25, bmats.B_31_25, bmats.B_32_25, bmats.Bx8279, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, };
    matlincomb_double_contiguous(bmats.Bx13289, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
