#include "stdafx.h"
#include "fBx9527.h"

inline int fBx9527(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_9_17, bmats.B_9_18, bmats.B_9_19, bmats.B_9_20, bmats.B_9_21, bmats.B_9_22, bmats.B_9_24, bmats.Bx8631, bmats.Bx8657, };
    double B_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx9527.data[0][0], 0, sizeof(bmats.Bx9527.data[0][0])*bmats.Bx9527.shape[0]*bmats.Bx9527.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9527, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
