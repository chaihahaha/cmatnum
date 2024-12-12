#include "stdafx.h"
#include "fBx640.h"

inline int fBx640(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_31, bmats.B_15_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx640.data[0][0], 0, sizeof(bmats.Bx640.data[0][0])*bmats.Bx640.shape[0]*bmats.Bx640.shape[1]);
    matlincomb_double_contiguous(bmats.Bx640, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
