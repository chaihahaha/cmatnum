#include "stdafx.h"
#include "fBx1259.h"

inline int fBx1259(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_17, bmats.B_1_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1259.data[0][0], 0, sizeof(bmats.Bx1259.data[0][0])*bmats.Bx1259.shape[0]*bmats.Bx1259.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1259, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
