#include "stdafx.h"
#include "fBx12490.h"

inline int fBx12490(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12414, bmats.Bx12489, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12490.data[0][0], 0, sizeof(bmats.Bx12490.data[0][0])*bmats.Bx12490.shape[0]*bmats.Bx12490.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12490, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
