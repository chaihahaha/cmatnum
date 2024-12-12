#include "stdafx.h"
#include "fBx10912.h"

inline int fBx10912(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_3_22, bmats.Bx10905, bmats.Bx10906, bmats.Bx10911, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx10912.data[0][0], 0, sizeof(bmats.Bx10912.data[0][0])*bmats.Bx10912.shape[0]*bmats.Bx10912.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10912, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
