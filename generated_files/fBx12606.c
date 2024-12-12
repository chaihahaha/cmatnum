#include "stdafx.h"
#include "fBx12606.h"

inline int fBx12606(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_19, bmats.B_18_2, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12606.data[0][0], 0, sizeof(bmats.Bx12606.data[0][0])*bmats.Bx12606.shape[0]*bmats.Bx12606.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12606, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
