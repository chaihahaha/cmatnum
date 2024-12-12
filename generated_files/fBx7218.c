#include "stdafx.h"
#include "fBx7218.h"

inline int fBx7218(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_30_26, bmats.Bx7215, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7218.data[0][0], 0, sizeof(bmats.Bx7218.data[0][0])*bmats.Bx7218.shape[0]*bmats.Bx7218.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7218, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
