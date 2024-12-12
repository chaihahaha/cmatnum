#include "stdafx.h"
#include "fBx8326.h"

inline int fBx8326(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_25, bmats.B_9_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8326.data[0][0], 0, sizeof(bmats.Bx8326.data[0][0])*bmats.Bx8326.shape[0]*bmats.Bx8326.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8326, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
