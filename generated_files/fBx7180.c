#include "stdafx.h"
#include "fBx7180.h"

inline int fBx7180(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_15_26, bmats.B_1_26, bmats.B_2_26, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7180.data[0][0], 0, sizeof(bmats.Bx7180.data[0][0])*bmats.Bx7180.shape[0]*bmats.Bx7180.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7180, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
