#include "stdafx.h"
#include "fBx12634.h"

inline int fBx12634(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_19_20, bmats.B_19_31, bmats.B_19_32, bmats.Bx11784, bmats.Bx5314, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12634.data[0][0], 0, sizeof(bmats.Bx12634.data[0][0])*bmats.Bx12634.shape[0]*bmats.Bx12634.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12634, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}