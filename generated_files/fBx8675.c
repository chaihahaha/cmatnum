#include "stdafx.h"
#include "fBx8675.h"

inline int fBx8675(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx6106, bmats.Bx7687, bmats.Bx8674, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx8675.data[0][0], 0, sizeof(bmats.Bx8675.data[0][0])*bmats.Bx8675.shape[0]*bmats.Bx8675.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8675, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
