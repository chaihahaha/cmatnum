#include "stdafx.h"
#include "fBx11924.h"

inline int fBx11924(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_4, bmats.Bx11923, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11924.data[0][0], 0, sizeof(bmats.Bx11924.data[0][0])*bmats.Bx11924.shape[0]*bmats.Bx11924.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11924, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
