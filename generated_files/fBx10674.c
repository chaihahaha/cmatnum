#include "fBx10674.h"

inline int fBx10674(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_23_6, bmats.B_24_6, bmats.B_25_6, bmats.B_26_6, bmats.B_27_6, bmats.B_28_6, bmats.B_29_6, bmats.B_30_6, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx10674, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
