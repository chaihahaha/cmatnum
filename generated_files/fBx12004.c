#include "stdafx.h"
#include "fBx12004.h"

inline int fBx12004(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx10105, bmats.Bx12003, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12004.data[0][0], 0, sizeof(bmats.Bx12004.data[0][0])*bmats.Bx12004.shape[0]*bmats.Bx12004.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12004, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
