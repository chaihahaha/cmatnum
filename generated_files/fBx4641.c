#include "fBx4641.h"

inline int fBx4641(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_13_17, bmats.B_13_18, bmats.B_13_19, bmats.B_13_20, bmats.B_13_21, bmats.B_13_22, bmats.B_13_23, bmats.B_13_24, bmats.B_13_25, bmats.B_13_26, bmats.B_13_27, bmats.B_13_28, bmats.B_13_29, bmats.B_13_30, bmats.B_13_31, bmats.B_13_32, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx4641, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
