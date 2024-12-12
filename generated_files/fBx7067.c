#include "stdafx.h"
#include "fBx7067.h"

inline int fBx7067(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_19, bmats.B_3_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7067.data[0][0], 0, sizeof(bmats.Bx7067.data[0][0])*bmats.Bx7067.shape[0]*bmats.Bx7067.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7067, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
