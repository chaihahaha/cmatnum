#include "fBx13381.h"

inline int fBx13381(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_17_32, bmats.B_18_32, bmats.B_19_32, bmats.B_25_32, bmats.B_26_32, bmats.B_28_32, bmats.B_30_32, bmats.B_32_32, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx13381, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
