#include "stdafx.h"
#include "fBx6085.h"

inline int fBx6085(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_11, bmats.B_9_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6085.data[0][0], 0, sizeof(bmats.Bx6085.data[0][0])*bmats.Bx6085.shape[0]*bmats.Bx6085.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6085, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}