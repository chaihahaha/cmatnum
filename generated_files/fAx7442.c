#include "fAx7442.h"

inline int fAx7442(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.A_28_17, bmats.A_28_18, bmats.A_28_20, bmats.A_28_21, bmats.A_28_22, bmats.A_28_23, bmats.A_28_24, bmats.A_28_25, bmats.A_28_26, bmats.A_28_27, bmats.A_28_29, bmats.A_28_31, };
    double A_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax7442, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
