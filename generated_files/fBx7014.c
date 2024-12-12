#include "stdafx.h"
#include "fBx7014.h"

inline int fBx7014(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_22, bmats.B_22_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7014.data[0][0], 0, sizeof(bmats.Bx7014.data[0][0])*bmats.Bx7014.shape[0]*bmats.Bx7014.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7014, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
