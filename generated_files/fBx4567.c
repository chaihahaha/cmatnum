#include "stdafx.h"
#include "fBx4567.h"

inline int fBx4567(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_28_12, bmats.B_28_15, bmats.B_28_16, bmats.Bx2946, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx4567.data[0][0], 0, sizeof(bmats.Bx4567.data[0][0])*bmats.Bx4567.shape[0]*bmats.Bx4567.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4567, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
