#include "stdafx.h"
#include "fBx2544.h"

inline int fBx2544(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx2493, bmats.Bx2543, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2544.data[0][0], 0, sizeof(bmats.Bx2544.data[0][0])*bmats.Bx2544.shape[0]*bmats.Bx2544.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2544, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
