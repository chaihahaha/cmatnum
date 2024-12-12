#include "stdafx.h"
#include "fBx7184.h"

inline int fBx7184(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_3_26, bmats.B_4_26, bmats.B_6_26, bmats.Bx7179, bmats.Bx7180, bmats.Bx7183, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx7184.data[0][0], 0, sizeof(bmats.Bx7184.data[0][0])*bmats.Bx7184.shape[0]*bmats.Bx7184.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7184, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
