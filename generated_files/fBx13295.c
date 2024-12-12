#include "stdafx.h"
#include "fBx13295.h"

inline int fBx13295(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx1031, bmats.Bx10333, bmats.Bx11024, bmats.Bx11657, bmats.Bx12115, bmats.Bx12464, bmats.Bx12782, bmats.Bx12980, bmats.Bx13293, bmats.Bx13294, bmats.Bx3328, bmats.Bx4778, bmats.Bx6108, bmats.Bx7184, bmats.Bx7391, bmats.Bx8665, bmats.Bx9537, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13295.data[0][0], 0, sizeof(bmats.Bx13295.data[0][0])*bmats.Bx13295.shape[0]*bmats.Bx13295.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13295, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
