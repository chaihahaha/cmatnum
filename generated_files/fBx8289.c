#include "stdafx.h"
#include "fBx8289.h"

inline int fBx8289(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.Bx8281, bmats.Bx8282, bmats.Bx8283, bmats.Bx8284, bmats.Bx8288, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx8289.data[0][0], 0, sizeof(bmats.Bx8289.data[0][0])*bmats.Bx8289.shape[0]*bmats.Bx8289.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8289, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
