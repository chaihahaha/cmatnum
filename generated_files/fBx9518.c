#include "stdafx.h"
#include "fBx9518.h"

inline int fBx9518(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_9_1, bmats.B_9_10, bmats.B_9_16, bmats.Bx6527, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9518.data[0][0], 0, sizeof(bmats.Bx9518.data[0][0])*bmats.Bx9518.shape[0]*bmats.Bx9518.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9518, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
