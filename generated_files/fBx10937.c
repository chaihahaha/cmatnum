#include "stdafx.h"
#include "fBx10937.h"

inline int fBx10937(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_19, bmats.B_3_22, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx10937.data[0][0], 0, sizeof(bmats.Bx10937.data[0][0])*bmats.Bx10937.shape[0]*bmats.Bx10937.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10937, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
