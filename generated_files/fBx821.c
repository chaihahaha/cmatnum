#include "stdafx.h"
#include "fBx821.h"

inline int fBx821(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_15_15, bmats.B_15_16, bmats.B_15_3, bmats.B_15_8, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx821.data[0][0], 0, sizeof(bmats.Bx821.data[0][0])*bmats.Bx821.shape[0]*bmats.Bx821.shape[1]);
    matlincomb_double_contiguous(bmats.Bx821, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
