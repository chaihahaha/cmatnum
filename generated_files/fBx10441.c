#include "stdafx.h"
#include "fBx10441.h"

inline int fBx10441(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_24_32, bmats.Bx10440, bmats.Bx1463, bmats.Bx8938, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx10441.data[0][0], 0, sizeof(bmats.Bx10441.data[0][0])*bmats.Bx10441.shape[0]*bmats.Bx10441.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10441, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
