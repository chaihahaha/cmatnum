#include "stdafx.h"
#include "fBx10884.h"

inline int fBx10884(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx10880, bmats.Bx10881, bmats.Bx10883, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10884.data[0][0], 0, sizeof(bmats.Bx10884.data[0][0])*bmats.Bx10884.shape[0]*bmats.Bx10884.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10884, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
