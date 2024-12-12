#include "stdafx.h"
#include "fBx151.h"

inline int fBx151(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_25, bmats.B_25_22, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx151.data[0][0], 0, sizeof(bmats.Bx151.data[0][0])*bmats.Bx151.shape[0]*bmats.Bx151.shape[1]);
    matlincomb_double_contiguous(bmats.Bx151, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
