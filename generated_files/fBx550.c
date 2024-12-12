#include "stdafx.h"
#include "fBx550.h"

inline int fBx550(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_3_10, bmats.B_3_13, bmats.B_3_3, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx550.data[0][0], 0, sizeof(bmats.Bx550.data[0][0])*bmats.Bx550.shape[0]*bmats.Bx550.shape[1]);
    matlincomb_double_contiguous(bmats.Bx550, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
