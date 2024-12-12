#include "stdafx.h"
#include "fBx753.h"

inline int fBx753(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_25_30, bmats.B_30_9, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx753.data[0][0], 0, sizeof(bmats.Bx753.data[0][0])*bmats.Bx753.shape[0]*bmats.Bx753.shape[1]);
    matlincomb_double_contiguous(bmats.Bx753, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
