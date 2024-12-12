#include "stdafx.h"
#include "fBx13209.h"

inline int fBx13209(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10226, bmats.Bx10879, bmats.Bx11626, bmats.Bx12078, bmats.Bx12424, bmats.Bx12764, bmats.Bx12960, bmats.Bx13207, bmats.Bx13208, bmats.Bx2488, bmats.Bx3088, bmats.Bx4621, bmats.Bx5959, bmats.Bx666, bmats.Bx7185, bmats.Bx8531, bmats.Bx9479, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13209.data[0][0], 0, sizeof(bmats.Bx13209.data[0][0])*bmats.Bx13209.shape[0]*bmats.Bx13209.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13209, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
