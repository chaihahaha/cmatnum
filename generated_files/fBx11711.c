#include "stdafx.h"
#include "fBx11711.h"

inline int fBx11711(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_22_1, bmats.B_22_2, bmats.B_22_3, bmats.B_22_4, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11711.data[0][0], 0, sizeof(bmats.Bx11711.data[0][0])*bmats.Bx11711.shape[0]*bmats.Bx11711.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11711, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
