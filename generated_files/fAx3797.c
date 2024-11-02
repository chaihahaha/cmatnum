#include "fAx3797.h"

inline int fAx3797(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_23_1, bmats.A_23_10, bmats.A_23_11, bmats.A_23_12, bmats.A_23_13, bmats.A_23_14, bmats.A_23_15, bmats.A_23_16, bmats.A_23_2, bmats.A_23_3, bmats.A_23_4, bmats.A_23_5, bmats.A_23_6, bmats.A_23_9, bmats.Ax3713, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax3797, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
