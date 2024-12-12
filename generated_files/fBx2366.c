#include "stdafx.h"
#include "fBx2366.h"

inline int fBx2366(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_12, bmats.B_28_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2366.data[0][0], 0, sizeof(bmats.Bx2366.data[0][0])*bmats.Bx2366.shape[0]*bmats.Bx2366.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2366, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
