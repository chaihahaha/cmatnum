#include "stdafx.h"
#include "fBx7765.h"

inline int fBx7765(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_5_14, bmats.Bx7764, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7765.data[0][0], 0, sizeof(bmats.Bx7765.data[0][0])*bmats.Bx7765.shape[0]*bmats.Bx7765.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7765, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
