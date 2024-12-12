#include "stdafx.h"
#include "fBx11240.h"

inline int fBx11240(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx10391, bmats.Bx11239, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11240.data[0][0], 0, sizeof(bmats.Bx11240.data[0][0])*bmats.Bx11240.shape[0]*bmats.Bx11240.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11240, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
