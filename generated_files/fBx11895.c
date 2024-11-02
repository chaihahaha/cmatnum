#include "fBx11895.h"

inline int fBx11895(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_20_20, bmats.B_22_20, bmats.B_24_20, bmats.B_25_20, bmats.B_26_20, bmats.B_28_20, bmats.B_30_20, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx11895, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
