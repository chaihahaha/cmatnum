#include "stdafx.h"
#include "fBx3529.h"

inline int fBx3529(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_13_5, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx3529.data[0][0], 0, sizeof(bmats.Bx3529.data[0][0])*bmats.Bx3529.shape[0]*bmats.Bx3529.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3529, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
