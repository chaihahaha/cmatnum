#include "stdafx.h"
#include "fBx12753.h"

inline int fBx12753(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_12_13, bmats.B_12_15, bmats.Bx12485, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12753.data[0][0], 0, sizeof(bmats.Bx12753.data[0][0])*bmats.Bx12753.shape[0]*bmats.Bx12753.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12753, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
