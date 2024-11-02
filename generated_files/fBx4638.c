#include "fBx4638.h"

inline int fBx4638(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_29_1, bmats.B_29_10, bmats.B_29_2, bmats.B_29_3, bmats.B_29_4, bmats.B_29_5, bmats.B_29_6, bmats.B_29_7, bmats.B_29_8, bmats.B_29_9, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx4638, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
