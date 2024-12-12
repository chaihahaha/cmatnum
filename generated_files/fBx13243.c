#include "stdafx.h"
#include "fBx13243.h"

inline int fBx13243(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx10096, bmats.Bx10701, bmats.Bx11583, bmats.Bx11997, bmats.Bx12320, bmats.Bx12567, bmats.Bx12931, bmats.Bx13045, bmats.Bx13242, bmats.Bx2147, bmats.Bx347, bmats.Bx4423, bmats.Bx5773, bmats.Bx6933, bmats.Bx7979, bmats.Bx9370, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13243.data[0][0], 0, sizeof(bmats.Bx13243.data[0][0])*bmats.Bx13243.shape[0]*bmats.Bx13243.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13243, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
