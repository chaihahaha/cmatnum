#include "fBx12748.h"

inline int fBx12748(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_10_18, bmats.B_11_18, bmats.B_12_18, bmats.B_15_18, bmats.B_3_18, bmats.B_6_18, bmats.B_7_18, bmats.B_8_18, bmats.B_9_18, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12748, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
