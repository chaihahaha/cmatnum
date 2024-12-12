#include "stdafx.h"
#include "fBx7821.h"

inline int fBx7821(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_5_26, bmats.Bx6762, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7821.data[0][0], 0, sizeof(bmats.Bx7821.data[0][0])*bmats.Bx7821.shape[0]*bmats.Bx7821.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7821, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
