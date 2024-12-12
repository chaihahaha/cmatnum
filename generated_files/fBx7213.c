#include "stdafx.h"
#include "fBx7213.h"

inline int fBx7213(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_24_26, bmats.B_25_26, bmats.B_31_26, bmats.B_32_26, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx7213.data[0][0], 0, sizeof(bmats.Bx7213.data[0][0])*bmats.Bx7213.shape[0]*bmats.Bx7213.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7213, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
