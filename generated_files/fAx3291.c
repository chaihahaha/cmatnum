#include "fAx3291.h"
#include "stdafx.h"

inline int fAx3291(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.A_9_17, bmats.A_9_18, bmats.A_9_19, bmats.A_9_20, bmats.A_9_21, bmats.A_9_22, bmats.A_9_23, bmats.A_9_24, bmats.A_9_27, bmats.A_9_28, bmats.A_9_29, bmats.A_9_30, bmats.A_9_31, bmats.A_9_32, bmats.Ax3157, };
    double A_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, };
    matlincomb_double_contiguous(bmats.Ax3291, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
