#include "stdafx.h"
#include "fBx10378.h"

inline int fBx10378(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_7, bmats.B_7_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10378.data[0][0], 0, sizeof(bmats.Bx10378.data[0][0])*bmats.Bx10378.shape[0]*bmats.Bx10378.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10378, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
