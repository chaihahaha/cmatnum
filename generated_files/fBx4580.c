#include "stdafx.h"
#include "fBx4580.h"

inline int fBx4580(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_12_28, bmats.B_12_31, bmats.B_12_32, bmats.Bx2961, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx4580.data[0][0], 0, sizeof(bmats.Bx4580.data[0][0])*bmats.Bx4580.shape[0]*bmats.Bx4580.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4580, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
