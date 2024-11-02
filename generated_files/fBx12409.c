#include "fBx12409.h"

inline int fBx12409(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_19_19, bmats.B_21_19, bmats.B_22_19, bmats.B_25_19, bmats.B_28_19, bmats.B_29_19, bmats.B_31_19, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12409, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
