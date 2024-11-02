#include "fBx10243.h"

inline int fBx10243(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_10_23, bmats.B_11_23, bmats.B_14_23, bmats.B_7_23, bmats.B_8_23, bmats.B_9_23, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx10243, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
