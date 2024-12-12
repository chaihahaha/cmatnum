#include "stdafx.h"
#include "fBx13256.h"

inline int fBx13256(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10480, bmats.Bx11408, bmats.Bx11835, bmats.Bx12064, bmats.Bx12210, bmats.Bx12530, bmats.Bx12858, bmats.Bx13024, bmats.Bx13254, bmats.Bx13255, bmats.Bx1782, bmats.Bx4084, bmats.Bx5432, bmats.Bx6628, bmats.Bx7713, bmats.Bx9107, bmats.Bx9855, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13256.data[0][0], 0, sizeof(bmats.Bx13256.data[0][0])*bmats.Bx13256.shape[0]*bmats.Bx13256.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13256, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
