#include "stdafx.h"
#include "fBx12830.h"

inline int fBx12830(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_2_18, bmats.B_2_31, bmats.B_2_32, bmats.Bx12613, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12830.data[0][0], 0, sizeof(bmats.Bx12830.data[0][0])*bmats.Bx12830.shape[0]*bmats.Bx12830.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12830, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
