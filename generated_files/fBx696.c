#include "stdafx.h"
#include "fBx696.h"

inline int fBx696(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_14_11, bmats.B_3_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx696.data[0][0], 0, sizeof(bmats.Bx696.data[0][0])*bmats.Bx696.shape[0]*bmats.Bx696.shape[1]);
    matlincomb_double_contiguous(bmats.Bx696, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
