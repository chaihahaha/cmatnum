#include "fBx3057.h"

inline int fBx3057(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_29_11, bmats.B_29_12, bmats.B_29_13, bmats.B_29_14, bmats.B_29_15, bmats.B_29_16, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx3057, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
