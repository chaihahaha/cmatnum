#include "stdafx.h"
#include "fBx6415.h"

inline int fBx6415(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_7_11, bmats.B_8_7, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6415.data[0][0], 0, sizeof(bmats.Bx6415.data[0][0])*bmats.Bx6415.shape[0]*bmats.Bx6415.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6415, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
