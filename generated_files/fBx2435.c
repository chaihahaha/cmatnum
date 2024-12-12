#include "stdafx.h"
#include "fBx2435.h"

inline int fBx2435(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_4_12, bmats.B_4_4, bmats.B_4_6, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx2435.data[0][0], 0, sizeof(bmats.Bx2435.data[0][0])*bmats.Bx2435.shape[0]*bmats.Bx2435.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2435, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
