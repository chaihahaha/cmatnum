#include "stdafx.h"
#include "fBx7166.h"

inline int fBx7166(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_27, bmats.B_19_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7166.data[0][0], 0, sizeof(bmats.Bx7166.data[0][0])*bmats.Bx7166.shape[0]*bmats.Bx7166.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7166, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
