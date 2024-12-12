#include "stdafx.h"
#include "fBx6896.h"

inline int fBx6896(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_27_10, bmats.B_28_10, bmats.B_29_10, bmats.B_30_10, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx6896.data[0][0], 0, sizeof(bmats.Bx6896.data[0][0])*bmats.Bx6896.shape[0]*bmats.Bx6896.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6896, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
