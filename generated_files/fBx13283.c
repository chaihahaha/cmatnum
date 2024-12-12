#include "stdafx.h"
#include "fBx13283.h"

inline int fBx13283(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10437, bmats.Bx11075, bmats.Bx11643, bmats.Bx12145, bmats.Bx12506, bmats.Bx12770, bmats.Bx12971, bmats.Bx13281, bmats.Bx13282, bmats.Bx1449, bmats.Bx3181, bmats.Bx5191, bmats.Bx6417, bmats.Bx7501, bmats.Bx8573, bmats.Bx9457, bmats.Bx9746, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13283.data[0][0], 0, sizeof(bmats.Bx13283.data[0][0])*bmats.Bx13283.shape[0]*bmats.Bx13283.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13283, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
