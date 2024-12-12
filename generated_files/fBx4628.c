#include "stdafx.h"
#include "fBx4628.h"

inline int fBx4628(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx3033, bmats.Bx4627, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4628.data[0][0], 0, sizeof(bmats.Bx4628.data[0][0])*bmats.Bx4628.shape[0]*bmats.Bx4628.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4628, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
