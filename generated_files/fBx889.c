#include "stdafx.h"
#include "fBx889.h"

inline int fBx889(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_11_14, bmats.B_15_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx889.data[0][0], 0, sizeof(bmats.Bx889.data[0][0])*bmats.Bx889.shape[0]*bmats.Bx889.shape[1]);
    matlincomb_double_contiguous(bmats.Bx889, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
