#include "stdafx.h"
#include "fBx9019.h"

inline int fBx9019(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_9, bmats.B_3_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9019.data[0][0], 0, sizeof(bmats.Bx9019.data[0][0])*bmats.Bx9019.shape[0]*bmats.Bx9019.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9019, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
