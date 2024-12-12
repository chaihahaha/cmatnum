#include "stdafx.h"
#include "fBx78.h"

inline int fBx78(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_27, bmats.B_24_20, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx78.data[0][0], 0, sizeof(bmats.Bx78.data[0][0])*bmats.Bx78.shape[0]*bmats.Bx78.shape[1]);
    matlincomb_double_contiguous(bmats.Bx78, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
