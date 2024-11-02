#include "fBx10008.h"

inline int fBx10008(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_24_7, bmats.B_25_7, bmats.B_26_7, bmats.B_27_7, bmats.B_28_7, bmats.B_29_7, bmats.B_30_7, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx10008, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
