#include "stdafx.h"
#include "fBx12761.h"

inline int fBx12761(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_14_2, bmats.B_9_2, bmats.Bx12659, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12761.data[0][0], 0, sizeof(bmats.Bx12761.data[0][0])*bmats.Bx12761.shape[0]*bmats.Bx12761.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12761, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}