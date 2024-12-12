#include "stdafx.h"
#include "fBx12198.h"

inline int fBx12198(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_4_3, bmats.B_6_4, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12198.data[0][0], 0, sizeof(bmats.Bx12198.data[0][0])*bmats.Bx12198.shape[0]*bmats.Bx12198.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12198, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
