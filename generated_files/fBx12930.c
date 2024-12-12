#include "stdafx.h"
#include "fBx12930.h"

inline int fBx12930(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12318, bmats.Bx12927, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12930.data[0][0], 0, sizeof(bmats.Bx12930.data[0][0])*bmats.Bx12930.shape[0]*bmats.Bx12930.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12930, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
