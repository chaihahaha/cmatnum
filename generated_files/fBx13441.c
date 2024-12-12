#include "stdafx.h"
#include "fBx13441.h"

inline int fBx13441(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_18_32, bmats.B_19_32, bmats.B_26_32, bmats.Bx13350, bmats.Bx13382, bmats.Bx13440, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13441.data[0][0], 0, sizeof(bmats.Bx13441.data[0][0])*bmats.Bx13441.shape[0]*bmats.Bx13441.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13441, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
