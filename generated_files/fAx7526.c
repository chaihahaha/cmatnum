#include "fAx7526.h"

inline int fAx7526(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.A_29_19, bmats.A_29_20, bmats.A_29_21, bmats.A_29_22, bmats.A_29_24, bmats.A_29_25, bmats.A_29_26, bmats.A_29_27, bmats.A_29_28, bmats.A_29_30, bmats.A_29_31, bmats.A_29_32, };
    double A_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax7526, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
