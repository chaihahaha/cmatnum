#include "stdafx.h"
#include "fBx13075.h"

inline int fBx13075(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_31, bmats.B_31_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13075.data[0][0], 0, sizeof(bmats.Bx13075.data[0][0])*bmats.Bx13075.shape[0]*bmats.Bx13075.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13075, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
