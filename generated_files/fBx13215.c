#include "stdafx.h"
#include "fBx13215.h"

inline int fBx13215(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 28;
    double_cmat B_mats[28] = {bmats.B_10_30, bmats.B_11_30, bmats.B_12_30, bmats.B_3_30, bmats.B_4_30, bmats.B_5_30, bmats.B_6_30, bmats.B_7_30, bmats.B_8_30, bmats.B_9_30, bmats.Bx10261, bmats.Bx10893, bmats.Bx11448, bmats.Bx12085, bmats.Bx12426, bmats.Bx12661, bmats.Bx12864, bmats.Bx13213, bmats.Bx13214, bmats.Bx2506, bmats.Bx4651, bmats.Bx5989, bmats.Bx7209, bmats.Bx746, bmats.Bx793, bmats.Bx8280, bmats.Bx867, bmats.Bx9489, };
    double B_coeffs[28] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13215.data[0][0], 0, sizeof(bmats.Bx13215.data[0][0])*bmats.Bx13215.shape[0]*bmats.Bx13215.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13215, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
