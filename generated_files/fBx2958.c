#include "stdafx.h"
#include "fBx2958.h"

inline int fBx2958(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_12_17, bmats.B_1_13, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2958.data[0][0], 0, sizeof(bmats.Bx2958.data[0][0])*bmats.Bx2958.shape[0]*bmats.Bx2958.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2958, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
