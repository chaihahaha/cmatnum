#include "fBx2480.h"

inline int fBx2480(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_30_17, bmats.B_30_25, bmats.B_30_26, bmats.B_30_27, bmats.B_30_28, bmats.B_30_29, bmats.B_30_30, bmats.B_30_32, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx2480, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
