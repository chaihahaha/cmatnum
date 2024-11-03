#include "fBx9522.h"
#include "stdafx.h"

inline int fBx9522(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_25_18, bmats.B_25_19, bmats.B_25_20, bmats.B_25_22, bmats.B_25_23, bmats.B_25_24, bmats.B_25_26, bmats.B_25_31, bmats.B_25_32, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx9522, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
