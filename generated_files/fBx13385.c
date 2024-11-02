#include "fBx13385.h"

inline int fBx13385(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_17_15, bmats.B_18_15, bmats.B_19_15, bmats.B_20_15, bmats.B_21_15, bmats.B_22_15, bmats.B_23_15, bmats.B_24_15, bmats.B_25_15, bmats.B_26_15, bmats.B_27_15, bmats.B_28_15, bmats.B_29_15, bmats.B_30_15, bmats.B_31_15, bmats.B_32_15, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13385, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
