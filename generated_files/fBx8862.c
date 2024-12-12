#include "stdafx.h"
#include "fBx8862.h"

inline int fBx8862(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_25, bmats.Bx5122, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8862.data[0][0], 0, sizeof(bmats.Bx8862.data[0][0])*bmats.Bx8862.shape[0]*bmats.Bx8862.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8862, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
