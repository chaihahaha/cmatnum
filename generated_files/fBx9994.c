#include "fBx9994.h"

inline int fBx9994(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_23_23, bmats.B_24_23, bmats.B_25_23, bmats.B_27_23, bmats.B_28_23, bmats.B_29_23, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx9994, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
