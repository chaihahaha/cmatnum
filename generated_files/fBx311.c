#include "stdafx.h"
#include "fBx311.h"

inline int fBx311(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_22, bmats.B_22_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx311.data[0][0], 0, sizeof(bmats.Bx311.data[0][0])*bmats.Bx311.shape[0]*bmats.Bx311.shape[1]);
    matlincomb_double_contiguous(bmats.Bx311, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
