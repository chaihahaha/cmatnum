#include "stdafx.h"
#include "fBx12129.h"

inline int fBx12129(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_28_21, bmats.B_28_27, bmats.Bx6287, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12129.data[0][0], 0, sizeof(bmats.Bx12129.data[0][0])*bmats.Bx12129.shape[0]*bmats.Bx12129.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12129, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
