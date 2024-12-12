#include "stdafx.h"
#include "fBx11952.h"

inline int fBx11952(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_20, bmats.Bx11917, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11952.data[0][0], 0, sizeof(bmats.Bx11952.data[0][0])*bmats.Bx11952.shape[0]*bmats.Bx11952.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11952, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
