#include "stdafx.h"
#include "fBx2019.h"

inline int fBx2019(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_14, bmats.B_6_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2019.data[0][0], 0, sizeof(bmats.Bx2019.data[0][0])*bmats.Bx2019.shape[0]*bmats.Bx2019.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2019, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
