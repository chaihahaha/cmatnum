#include "stdafx.h"
#include "fBx7219.h"

inline int fBx7219(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_14_10, bmats.B_16_10, bmats.Bx7208, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7219.data[0][0], 0, sizeof(bmats.Bx7219.data[0][0])*bmats.Bx7219.shape[0]*bmats.Bx7219.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7219, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
