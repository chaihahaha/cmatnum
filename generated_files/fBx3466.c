#include "stdafx.h"
#include "fBx3466.h"

inline int fBx3466(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_1, bmats.B_17_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx3466.data[0][0], 0, sizeof(bmats.Bx3466.data[0][0])*bmats.Bx3466.shape[0]*bmats.Bx3466.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3466, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
