#include "stdafx.h"
#include "fBx850.h"

inline int fBx850(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_15_1, bmats.B_15_14, bmats.B_15_2, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx850.data[0][0], 0, sizeof(bmats.Bx850.data[0][0])*bmats.Bx850.shape[0]*bmats.Bx850.shape[1]);
    matlincomb_double_contiguous(bmats.Bx850, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
