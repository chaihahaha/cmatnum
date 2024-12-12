#include "stdafx.h"
#include "fBx4555.h"

inline int fBx4555(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_28_29, bmats.B_28_31, bmats.B_28_32, bmats.Bx1231, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx4555.data[0][0], 0, sizeof(bmats.Bx4555.data[0][0])*bmats.Bx4555.shape[0]*bmats.Bx4555.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4555, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
