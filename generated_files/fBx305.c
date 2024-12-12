#include "stdafx.h"
#include "fBx305.h"

inline int fBx305(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_26, bmats.B_26_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx305.data[0][0], 0, sizeof(bmats.Bx305.data[0][0])*bmats.Bx305.shape[0]*bmats.Bx305.shape[1]);
    matlincomb_double_contiguous(bmats.Bx305, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
