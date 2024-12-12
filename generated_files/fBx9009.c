#include "stdafx.h"
#include "fBx9009.h"

inline int fBx9009(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_20, bmats.B_20_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9009.data[0][0], 0, sizeof(bmats.Bx9009.data[0][0])*bmats.Bx9009.shape[0]*bmats.Bx9009.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9009, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
