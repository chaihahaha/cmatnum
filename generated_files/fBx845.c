#include "stdafx.h"
#include "fBx845.h"

inline int fBx845(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_7, bmats.B_23_14, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx845.data[0][0], 0, sizeof(bmats.Bx845.data[0][0])*bmats.Bx845.shape[0]*bmats.Bx845.shape[1]);
    matlincomb_double_contiguous(bmats.Bx845, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
