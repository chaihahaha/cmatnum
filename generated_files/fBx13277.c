#include "stdafx.h"
#include "fBx13277.h"

inline int fBx13277(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10246, bmats.Bx10423, bmats.Bx11068, bmats.Bx11718, bmats.Bx12136, bmats.Bx12497, bmats.Bx12767, bmats.Bx13002, bmats.Bx13275, bmats.Bx13276, bmats.Bx1418, bmats.Bx3692, bmats.Bx5088, bmats.Bx6323, bmats.Bx7475, bmats.Bx8837, bmats.Bx9625, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13277.data[0][0], 0, sizeof(bmats.Bx13277.data[0][0])*bmats.Bx13277.shape[0]*bmats.Bx13277.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13277, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
