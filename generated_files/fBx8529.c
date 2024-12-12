#include "stdafx.h"
#include "fBx8529.h"

inline int fBx8529(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_4, bmats.B_13_8, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8529.data[0][0], 0, sizeof(bmats.Bx8529.data[0][0])*bmats.Bx8529.shape[0]*bmats.Bx8529.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8529, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
