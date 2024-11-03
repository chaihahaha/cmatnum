#include "fBx9493.h"
#include "stdafx.h"

inline int fBx9493(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_30_18, bmats.B_30_19, bmats.B_30_20, bmats.B_30_21, bmats.B_30_31, bmats.Bx2480, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx9493, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
