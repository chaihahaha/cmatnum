#include "fBx8681.h"
#include "stdafx.h"

inline int fBx8681(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_10_18, bmats.B_10_19, bmats.B_10_20, bmats.B_10_21, bmats.B_10_22, bmats.B_10_23, bmats.Bx7712, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx8681, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
