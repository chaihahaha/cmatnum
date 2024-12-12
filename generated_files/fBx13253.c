#include "stdafx.h"
#include "fBx13253.h"

inline int fBx13253(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10817, bmats.Bx11334, bmats.Bx11764, bmats.Bx12188, bmats.Bx12407, bmats.Bx12656, bmats.Bx12852, bmats.Bx13016, bmats.Bx13252, bmats.Bx2316, bmats.Bx3939, bmats.Bx5304, bmats.Bx553, bmats.Bx6580, bmats.Bx8118, bmats.Bx9006, bmats.Bx9761, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13253.data[0][0], 0, sizeof(bmats.Bx13253.data[0][0])*bmats.Bx13253.shape[0]*bmats.Bx13253.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13253, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
