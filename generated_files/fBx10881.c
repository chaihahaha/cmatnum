#include "stdafx.h"
#include "fBx10881.h"

inline int fBx10881(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_17_6, bmats.B_18_6, bmats.B_31_6, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10881.data[0][0], 0, sizeof(bmats.Bx10881.data[0][0])*bmats.Bx10881.shape[0]*bmats.Bx10881.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10881, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}