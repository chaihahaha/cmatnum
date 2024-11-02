#include "fBx11658.h"

inline int fBx11658(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_21_21, bmats.B_23_21, bmats.B_24_21, bmats.B_25_21, bmats.B_28_21, bmats.B_29_21, bmats.B_30_21, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx11658, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
