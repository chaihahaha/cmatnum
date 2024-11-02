#include "fBx2481.h"

inline int fBx2481(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_30_18, bmats.B_30_19, bmats.B_30_20, bmats.B_30_21, bmats.B_30_23, bmats.B_30_24, bmats.B_30_31, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx2481, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
