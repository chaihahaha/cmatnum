#include "stdafx.h"
#include "fBx6019.h"

inline int fBx6019(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_9, bmats.B_25_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6019.data[0][0], 0, sizeof(bmats.Bx6019.data[0][0])*bmats.Bx6019.shape[0]*bmats.Bx6019.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6019, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
