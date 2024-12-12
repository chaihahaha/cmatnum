#include "stdafx.h"
#include "fBx13247.h"

inline int fBx13247(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10171, bmats.Bx10765, bmats.Bx11290, bmats.Bx11734, bmats.Bx12365, bmats.Bx12600, bmats.Bx12678, bmats.Bx12824, bmats.Bx13009, bmats.Bx13246, bmats.Bx2226, bmats.Bx3849, bmats.Bx473, bmats.Bx5878, bmats.Bx7029, bmats.Bx8049, bmats.Bx8939, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13247.data[0][0], 0, sizeof(bmats.Bx13247.data[0][0])*bmats.Bx13247.shape[0]*bmats.Bx13247.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13247, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
