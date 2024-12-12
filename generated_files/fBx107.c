#include "stdafx.h"
#include "fBx107.h"

inline int fBx107(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_27, bmats.B_23_19, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx107.data[0][0], 0, sizeof(bmats.Bx107.data[0][0])*bmats.Bx107.shape[0]*bmats.Bx107.shape[1]);
    matlincomb_double_contiguous(bmats.Bx107, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
