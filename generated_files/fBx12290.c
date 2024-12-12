#include "stdafx.h"
#include "fBx12290.h"

inline int fBx12290(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_11_3, bmats.B_12_3, bmats.B_5_3, bmats.B_7_3, bmats.B_9_3, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12290.data[0][0], 0, sizeof(bmats.Bx12290.data[0][0])*bmats.Bx12290.shape[0]*bmats.Bx12290.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12290, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
