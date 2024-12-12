#include "stdafx.h"
#include "fBx12119.h"

inline int fBx12119(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_20_20, bmats.B_25_20, bmats.Bx11896, bmats.Bx12089, bmats.Bx12118, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12119.data[0][0], 0, sizeof(bmats.Bx12119.data[0][0])*bmats.Bx12119.shape[0]*bmats.Bx12119.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12119, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
