#include "stdafx.h"
#include "fBx12410.h"

inline int fBx12410(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_19, bmats.Bx12409, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12410.data[0][0], 0, sizeof(bmats.Bx12410.data[0][0])*bmats.Bx12410.shape[0]*bmats.Bx12410.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12410, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
