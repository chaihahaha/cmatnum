#include "stdafx.h"
#include "fBx9271.h"

inline int fBx9271(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx9209, bmats.Bx9270, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9271.data[0][0], 0, sizeof(bmats.Bx9271.data[0][0])*bmats.Bx9271.shape[0]*bmats.Bx9271.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9271, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
