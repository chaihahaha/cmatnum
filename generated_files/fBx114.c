#include "stdafx.h"
#include "fBx114.h"

inline int fBx114(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_26, bmats.B_25_22, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx114.data[0][0], 0, sizeof(bmats.Bx114.data[0][0])*bmats.Bx114.shape[0]*bmats.Bx114.shape[1]);
    matlincomb_double_contiguous(bmats.Bx114, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
