#include "stdafx.h"
#include "fBx4213.h"

inline int fBx4213(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_15_28, bmats.B_1_28, bmats.B_2_28, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx4213.data[0][0], 0, sizeof(bmats.Bx4213.data[0][0])*bmats.Bx4213.shape[0]*bmats.Bx4213.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4213, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
