#include "fBx12291.h"

inline int fBx12291(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_10_3, bmats.B_11_3, bmats.B_12_3, bmats.B_13_3, bmats.B_3_3, bmats.B_4_3, bmats.B_5_3, bmats.B_7_3, bmats.B_8_3, bmats.B_9_3, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx12291, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
