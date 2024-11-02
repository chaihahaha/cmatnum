#include "fAx3553.h"

inline int fAx3553(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_8_17, bmats.A_8_18, bmats.A_8_19, bmats.A_8_20, bmats.A_8_21, bmats.A_8_22, bmats.A_8_25, bmats.A_8_26, bmats.A_8_27, bmats.A_8_28, bmats.A_8_29, bmats.A_8_30, bmats.A_8_31, bmats.A_8_32, bmats.Ax3419, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax3553, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
