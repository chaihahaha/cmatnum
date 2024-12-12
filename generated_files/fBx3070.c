#include "stdafx.h"
#include "fBx3070.h"

inline int fBx3070(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_13_29, bmats.B_13_30, bmats.B_13_31, bmats.Bx3069, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx3070.data[0][0], 0, sizeof(bmats.Bx3070.data[0][0])*bmats.Bx3070.shape[0]*bmats.Bx3070.shape[1]);
    matlincomb_double_contiguous(bmats.Bx3070, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
