#include "stdafx.h"
#include "fBx868.h"

inline int fBx868(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_31_17, bmats.B_31_30, bmats.B_31_31, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx868.data[0][0], 0, sizeof(bmats.Bx868.data[0][0])*bmats.Bx868.shape[0]*bmats.Bx868.shape[1]);
    matlincomb_double_contiguous(bmats.Bx868, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
