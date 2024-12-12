#include "stdafx.h"
#include "fBx8857.h"

inline int fBx8857(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_21, bmats.B_5_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8857.data[0][0], 0, sizeof(bmats.Bx8857.data[0][0])*bmats.Bx8857.shape[0]*bmats.Bx8857.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8857, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
