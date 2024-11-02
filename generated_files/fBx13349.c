#include "fBx13349.h"

inline int fBx13349(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_17_32, bmats.B_18_32, bmats.B_19_32, bmats.B_20_32, bmats.B_25_32, bmats.B_26_32, bmats.B_27_32, bmats.B_28_32, bmats.B_29_32, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13349, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
