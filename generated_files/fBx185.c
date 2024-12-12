#include "stdafx.h"
#include "fBx185.h"

inline int fBx185(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_24, bmats.B_24_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx185.data[0][0], 0, sizeof(bmats.Bx185.data[0][0])*bmats.Bx185.shape[0]*bmats.Bx185.shape[1]);
    matlincomb_double_contiguous(bmats.Bx185, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
