#include "stdafx.h"
#include "fBx12984.h"

inline int fBx12984(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12916, bmats.Bx12978, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12984.data[0][0], 0, sizeof(bmats.Bx12984.data[0][0])*bmats.Bx12984.shape[0]*bmats.Bx12984.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12984, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}