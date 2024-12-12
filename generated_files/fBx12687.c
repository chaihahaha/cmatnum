#include "stdafx.h"
#include "fBx12687.h"

inline int fBx12687(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_18_18, bmats.B_23_18, bmats.B_24_18, bmats.B_25_18, bmats.B_26_18, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12687.data[0][0], 0, sizeof(bmats.Bx12687.data[0][0])*bmats.Bx12687.shape[0]*bmats.Bx12687.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12687, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
