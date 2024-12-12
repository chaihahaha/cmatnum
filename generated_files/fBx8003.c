#include "stdafx.h"
#include "fBx8003.h"

inline int fBx8003(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_1, bmats.B_1_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8003.data[0][0], 0, sizeof(bmats.Bx8003.data[0][0])*bmats.Bx8003.shape[0]*bmats.Bx8003.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8003, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
