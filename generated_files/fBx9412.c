#include "stdafx.h"
#include "fBx9412.h"

inline int fBx9412(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_3, bmats.B_3_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9412.data[0][0], 0, sizeof(bmats.Bx9412.data[0][0])*bmats.Bx9412.shape[0]*bmats.Bx9412.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9412, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
