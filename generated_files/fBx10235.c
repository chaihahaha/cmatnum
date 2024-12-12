#include "stdafx.h"
#include "fBx10235.h"

inline int fBx10235(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_23_23, bmats.B_28_23, bmats.Bx9995, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx10235.data[0][0], 0, sizeof(bmats.Bx10235.data[0][0])*bmats.Bx10235.shape[0]*bmats.Bx10235.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10235, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
