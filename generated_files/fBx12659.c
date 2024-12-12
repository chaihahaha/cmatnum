#include "stdafx.h"
#include "fBx12659.h"

inline int fBx12659(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_10_2, bmats.B_15_2, bmats.B_4_2, bmats.B_7_2, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12659.data[0][0], 0, sizeof(bmats.Bx12659.data[0][0])*bmats.Bx12659.shape[0]*bmats.Bx12659.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12659, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
