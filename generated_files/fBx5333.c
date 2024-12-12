#include "stdafx.h"
#include "fBx5333.h"

inline int fBx5333(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_25, bmats.B_9_28, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx5333.data[0][0], 0, sizeof(bmats.Bx5333.data[0][0])*bmats.Bx5333.shape[0]*bmats.Bx5333.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5333, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
