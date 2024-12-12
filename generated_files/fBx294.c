#include "stdafx.h"
#include "fBx294.h"

inline int fBx294(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_2, bmats.B_2_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx294.data[0][0], 0, sizeof(bmats.Bx294.data[0][0])*bmats.Bx294.shape[0]*bmats.Bx294.shape[1]);
    matlincomb_double_contiguous(bmats.Bx294, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
