#include "fAx7035.h"
#include "stdafx.h"

inline int fAx7035(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_23_17, bmats.A_23_18, bmats.A_23_19, bmats.A_23_20, bmats.A_23_21, bmats.A_23_25, bmats.A_23_26, bmats.A_23_27, bmats.A_23_28, bmats.A_23_29, bmats.A_23_30, bmats.A_23_31, bmats.A_23_32, };
    double A_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(bmats.Ax7035, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
