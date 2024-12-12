#include "stdafx.h"
#include "fBx12575.h"

inline int fBx12575(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_3, bmats.Bx12331, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12575.data[0][0], 0, sizeof(bmats.Bx12575.data[0][0])*bmats.Bx12575.shape[0]*bmats.Bx12575.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12575, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
