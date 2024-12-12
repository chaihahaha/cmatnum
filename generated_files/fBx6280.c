#include "stdafx.h"
#include "fBx6280.h"

inline int fBx6280(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_3, bmats.Bx6279, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6280.data[0][0], 0, sizeof(bmats.Bx6280.data[0][0])*bmats.Bx6280.shape[0]*bmats.Bx6280.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6280, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
