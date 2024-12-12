#include "stdafx.h"
#include "fBx12762.h"

inline int fBx12762(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_11_2, bmats.B_12_2, bmats.B_2_2, bmats.Bx12739, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12762.data[0][0], 0, sizeof(bmats.Bx12762.data[0][0])*bmats.Bx12762.shape[0]*bmats.Bx12762.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12762, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
