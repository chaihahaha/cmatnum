#include "stdafx.h"
#include "fBx12877.h"

inline int fBx12877(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_19_17, bmats.B_20_17, bmats.B_21_17, bmats.B_22_17, bmats.B_24_17, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12877.data[0][0], 0, sizeof(bmats.Bx12877.data[0][0])*bmats.Bx12877.shape[0]*bmats.Bx12877.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12877, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
