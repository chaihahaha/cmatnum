#include "stdafx.h"
#include "fBx4848.h"

inline int fBx4848(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_6, bmats.B_6_28, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4848.data[0][0], 0, sizeof(bmats.Bx4848.data[0][0])*bmats.Bx4848.shape[0]*bmats.Bx4848.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4848, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
