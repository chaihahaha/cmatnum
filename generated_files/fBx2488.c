#include "stdafx.h"
#include "fBx2488.h"

inline int fBx2488(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_10_29, bmats.B_3_29, bmats.B_4_29, bmats.B_5_29, bmats.B_6_29, bmats.B_7_29, bmats.B_9_29, bmats.Bx2484, bmats.Bx2485, bmats.Bx2487, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx2488.data[0][0], 0, sizeof(bmats.Bx2488.data[0][0])*bmats.Bx2488.shape[0]*bmats.Bx2488.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2488, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
