#include "stdafx.h"
#include "fBx12757.h"

inline int fBx12757(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_18, bmats.Bx12756, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12757.data[0][0], 0, sizeof(bmats.Bx12757.data[0][0])*bmats.Bx12757.shape[0]*bmats.Bx12757.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12757, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
