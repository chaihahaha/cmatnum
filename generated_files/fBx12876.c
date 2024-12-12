#include "stdafx.h"
#include "fBx12876.h"

inline int fBx12876(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_23_17, bmats.B_25_17, bmats.B_26_17, bmats.B_29_17, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12876.data[0][0], 0, sizeof(bmats.Bx12876.data[0][0])*bmats.Bx12876.shape[0]*bmats.Bx12876.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12876, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
