#include "stdafx.h"
#include "fBx13012.h"

inline int fBx13012(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_18_1, bmats.B_18_15, bmats.B_18_16, bmats.B_18_2, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx13012.data[0][0], 0, sizeof(bmats.Bx13012.data[0][0])*bmats.Bx13012.shape[0]*bmats.Bx13012.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13012, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
