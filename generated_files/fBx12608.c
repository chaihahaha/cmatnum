#include "stdafx.h"
#include "fBx12608.h"

inline int fBx12608(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_3, bmats.Bx12375, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12608.data[0][0], 0, sizeof(bmats.Bx12608.data[0][0])*bmats.Bx12608.shape[0]*bmats.Bx12608.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12608, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
