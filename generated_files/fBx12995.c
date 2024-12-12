#include "stdafx.h"
#include "fBx12995.h"

inline int fBx12995(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_19_17, bmats.B_21_17, bmats.B_24_17, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12995.data[0][0], 0, sizeof(bmats.Bx12995.data[0][0])*bmats.Bx12995.shape[0]*bmats.Bx12995.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12995, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
