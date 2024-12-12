#include "stdafx.h"
#include "fBx7436.h"

inline int fBx7436(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_28_18, bmats.B_28_23, bmats.Bx4555, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7436.data[0][0], 0, sizeof(bmats.Bx7436.data[0][0])*bmats.Bx7436.shape[0]*bmats.Bx7436.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7436, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
