#include "stdafx.h"
#include "fBx10240.h"

inline int fBx10240(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_19_7, bmats.B_21_7, bmats.B_22_7, bmats.Bx10009, bmats.Bx10238, bmats.Bx10239, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx10240.data[0][0], 0, sizeof(bmats.Bx10240.data[0][0])*bmats.Bx10240.shape[0]*bmats.Bx10240.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10240, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
