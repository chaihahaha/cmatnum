#include "stdafx.h"
#include "fBx9673.h"

inline int fBx9673(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_6, bmats.B_6_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9673.data[0][0], 0, sizeof(bmats.Bx9673.data[0][0])*bmats.Bx9673.shape[0]*bmats.Bx9673.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9673, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
