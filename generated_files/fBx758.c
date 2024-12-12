#include "stdafx.h"
#include "fBx758.h"

inline int fBx758(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_30, bmats.B_30_4, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx758.data[0][0], 0, sizeof(bmats.Bx758.data[0][0])*bmats.Bx758.shape[0]*bmats.Bx758.shape[1]);
    matlincomb_double_contiguous(bmats.Bx758, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
