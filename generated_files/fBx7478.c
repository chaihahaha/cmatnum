#include "stdafx.h"
#include "fBx7478.h"

inline int fBx7478(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_10, bmats.B_7_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7478.data[0][0], 0, sizeof(bmats.Bx7478.data[0][0])*bmats.Bx7478.shape[0]*bmats.Bx7478.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7478, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
