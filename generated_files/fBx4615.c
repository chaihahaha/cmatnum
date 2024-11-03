#include "fBx4615.h"
#include "stdafx.h"

inline int fBx4615(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_13_1, bmats.B_13_10, bmats.B_13_13, bmats.B_13_3, bmats.B_13_4, bmats.B_13_6, bmats.B_13_7, bmats.B_13_8, bmats.B_13_9, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx4615, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
