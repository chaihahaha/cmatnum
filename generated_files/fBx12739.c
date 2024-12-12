#include "stdafx.h"
#include "fBx12739.h"

inline int fBx12739(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_5_2, bmats.B_8_2, bmats.Bx12738, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12739.data[0][0], 0, sizeof(bmats.Bx12739.data[0][0])*bmats.Bx12739.shape[0]*bmats.Bx12739.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12739, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
