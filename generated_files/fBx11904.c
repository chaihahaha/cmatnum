#include "stdafx.h"
#include "fBx11904.h"

inline int fBx11904(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_13_4, bmats.B_5_4, bmats.B_6_4, bmats.B_9_4, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11904.data[0][0], 0, sizeof(bmats.Bx11904.data[0][0])*bmats.Bx11904.shape[0]*bmats.Bx11904.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11904, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}