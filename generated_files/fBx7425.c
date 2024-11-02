#include "fBx7425.h"

inline int fBx7425(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.B_27_19, bmats.B_27_20, bmats.B_27_21, bmats.B_27_22, bmats.B_27_24, bmats.B_27_25, bmats.B_27_26, bmats.B_27_27, bmats.B_27_28, bmats.B_27_29, bmats.B_27_30, bmats.B_27_31, bmats.B_27_32, };
    double B_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx7425, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
