#include "stdafx.h"
#include "fBx2339.h"

inline int fBx2339(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_14, bmats.B_3_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2339.data[0][0], 0, sizeof(bmats.Bx2339.data[0][0])*bmats.Bx2339.shape[0]*bmats.Bx2339.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2339, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
