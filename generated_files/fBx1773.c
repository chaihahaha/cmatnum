#include "stdafx.h"
#include "fBx1773.h"

inline int fBx1773(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_14, bmats.B_4_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1773.data[0][0], 0, sizeof(bmats.Bx1773.data[0][0])*bmats.Bx1773.shape[0]*bmats.Bx1773.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1773, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
