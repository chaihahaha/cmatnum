#include "stdafx.h"
#include "fBx6927.h"

inline int fBx6927(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_6, bmats.B_22_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6927.data[0][0], 0, sizeof(bmats.Bx6927.data[0][0])*bmats.Bx6927.shape[0]*bmats.Bx6927.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6927, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
