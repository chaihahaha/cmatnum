#include "stdafx.h"
#include "fBx10447.h"

inline int fBx10447(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_24_1, bmats.B_24_2, bmats.B_24_3, bmats.B_24_4, bmats.B_24_5, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx10447.data[0][0], 0, sizeof(bmats.Bx10447.data[0][0])*bmats.Bx10447.shape[0]*bmats.Bx10447.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10447, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
