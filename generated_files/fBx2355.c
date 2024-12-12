#include "stdafx.h"
#include "fBx2355.h"

inline int fBx2355(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_13_30, bmats.B_19_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2355.data[0][0], 0, sizeof(bmats.Bx2355.data[0][0])*bmats.Bx2355.shape[0]*bmats.Bx2355.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2355, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
