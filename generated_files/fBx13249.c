#include "stdafx.h"
#include "fBx13249.h"

inline int fBx13249(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10153, bmats.Bx10749, bmats.Bx11276, bmats.Bx11750, bmats.Bx12355, bmats.Bx12591, bmats.Bx12675, bmats.Bx12847, bmats.Bx13014, bmats.Bx13248, bmats.Bx2196, bmats.Bx3910, bmats.Bx426, bmats.Bx5853, bmats.Bx7007, bmats.Bx8028, bmats.Bx8985, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13249.data[0][0], 0, sizeof(bmats.Bx13249.data[0][0])*bmats.Bx13249.shape[0]*bmats.Bx13249.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13249, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
