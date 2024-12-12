#include "stdafx.h"
#include "fBx13345.h"

inline int fBx13345(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_31, bmats.B_31_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13345.data[0][0], 0, sizeof(bmats.Bx13345.data[0][0])*bmats.Bx13345.shape[0]*bmats.Bx13345.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13345, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
