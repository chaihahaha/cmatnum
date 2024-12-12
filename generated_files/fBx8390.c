#include "stdafx.h"
#include "fBx8390.h"

inline int fBx8390(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_9_32, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx8390.data[0][0], 0, sizeof(bmats.Bx8390.data[0][0])*bmats.Bx8390.shape[0]*bmats.Bx8390.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8390, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
