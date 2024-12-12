#include "stdafx.h"
#include "fBx12319.h"

inline int fBx12319(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_4, bmats.Bx12101, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12319.data[0][0], 0, sizeof(bmats.Bx12319.data[0][0])*bmats.Bx12319.shape[0]*bmats.Bx12319.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12319, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
