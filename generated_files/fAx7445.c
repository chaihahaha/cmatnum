#include "fAx7445.h"

inline int fAx7445(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.A_28_17, bmats.A_28_18, bmats.A_28_19, bmats.A_28_21, bmats.A_28_22, bmats.A_28_23, bmats.A_28_24, bmats.A_28_25, bmats.A_28_26, bmats.A_28_27, bmats.A_28_29, };
    double A_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax7445, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
