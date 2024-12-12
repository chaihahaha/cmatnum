#include "stdafx.h"
#include "fBx11038.h"

inline int fBx11038(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_22_22, bmats.B_24_22, bmats.B_25_22, bmats.B_29_22, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11038.data[0][0], 0, sizeof(bmats.Bx11038.data[0][0])*bmats.Bx11038.shape[0]*bmats.Bx11038.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11038, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
