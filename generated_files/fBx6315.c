#include "stdafx.h"
#include "fBx6315.h"

inline int fBx6315(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_7_9, bmats.B_9_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6315.data[0][0], 0, sizeof(bmats.Bx6315.data[0][0])*bmats.Bx6315.shape[0]*bmats.Bx6315.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6315, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
