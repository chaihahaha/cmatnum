#include "stdafx.h"
#include "fBx867.h"

inline int fBx867(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_15_30, bmats.B_1_30, bmats.B_2_30, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx867.data[0][0], 0, sizeof(bmats.Bx867.data[0][0])*bmats.Bx867.shape[0]*bmats.Bx867.shape[1]);
    matlincomb_double_contiguous(bmats.Bx867, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
