#include "stdafx.h"
#include "fBx11191.h"

inline int fBx11191(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_22, bmats.B_22_21, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11191.data[0][0], 0, sizeof(bmats.Bx11191.data[0][0])*bmats.Bx11191.shape[0]*bmats.Bx11191.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11191, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
