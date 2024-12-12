#include "stdafx.h"
#include "fBx8117.h"

inline int fBx8117(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_2_10, bmats.B_3_2, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8117.data[0][0], 0, sizeof(bmats.Bx8117.data[0][0])*bmats.Bx8117.shape[0]*bmats.Bx8117.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8117, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
