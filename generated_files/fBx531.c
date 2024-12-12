#include "stdafx.h"
#include "fBx531.h"

inline int fBx531(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_15, bmats.B_2_18, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx531.data[0][0], 0, sizeof(bmats.Bx531.data[0][0])*bmats.Bx531.shape[0]*bmats.Bx531.shape[1]);
    matlincomb_double_contiguous(bmats.Bx531, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
